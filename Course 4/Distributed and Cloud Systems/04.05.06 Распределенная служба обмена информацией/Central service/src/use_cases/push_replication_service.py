import logging
import httpx
import os
import json
from sqlalchemy.ext.asyncio import AsyncSession
from src.domain.entities import BODI
from src.gateways.database.BODI_repository import BODIRepository
from src.app.config import settings

logging.basicConfig(filename="logs/push_replication.log", level=logging.INFO)
logger = logging.getLogger(__name__)

class PushReplicationService:
    def __init__(self, bodi_repository: BODIRepository):
        self.bodi_repository = bodi_repository


    async def push_data_to_clients(self):
        results = []

        bodi_data = await self.bodi_repository.get_all()

        for source in settings.sources:
            table_name = source.table_name
            endpoint_url = source.url

            filtered_bodi_data = [BODI.model_validate(bodi).model_dump(mode='json') for bodi in bodi_data if bodi.TABL == table_name]

            if filtered_bodi_data:
                try:
                    async with httpx.AsyncClient() as client:
                        response = await client.post(
                            f"{endpoint_url}api/bodi",
                            json=filtered_bodi_data 
                        )
                        logger.info(f"Response from {table_name} at {endpoint_url}: {response.status_code}")
                        response.raise_for_status()

                        results.append({"source": table_name, "status": "success"})
                except httpx.HTTPStatusError as e:
                    logger.error(f"Error pushing data to {table_name} at {endpoint_url}: {str(e)}")
                    results.append({"source": table_name, "status": "failed", "error": str(e)})
                except Exception as e:
                    logger.error(f"Unexpected error for {table_name} at {endpoint_url}: {str(e)}")
                    results.append({"source": table_name, "status": "failed", "error": str(e)})
            else:
                logger.info(f"No data to replicate for table {table_name}")
                results.append({"source": table_name, "status": "no_data"})

        return results
