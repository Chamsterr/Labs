import logging
import httpx
from sqlalchemy.ext.asyncio import AsyncSession
from src.domain.entities import BODI
from src.gateways.database.BODI_repository import BODIRepository
from src.app.config import settings


logging.basicConfig(filename="logs/app.log", level=logging.INFO)
logger = logging.getLogger(__name__)


class PullReplicationService:
    def __init__(self, bodi_repository: BODIRepository):
        self.bodi_repository = bodi_repository

    async def pull_data_from_clients(self):
        results = []
        for source in settings.sources:
            try:
                async with httpx.AsyncClient() as client:
                    response = await client.get(f"{source.url}api/bodi")
                    logger.info(f"{response} - source {source}")
                    response.raise_for_status()
                    bodies_data = response.json()
                    bodi_objects = [BODI(**item) for item in bodies_data]

                    await self.bodi_repository.bulk_insert_or_update(bodi_objects)
                    results.append({"source": response.json(), "status": "success"})
            except httpx.HTTPStatusError as e:
                results.append({"source": source.table_name, "status": "http failed", "error": str(e)})
            except Exception as e:
                results.append({"source": source.table_name, "status": "fatal failed", "error": str(e)})

        return results