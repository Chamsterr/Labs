from src.app.config import settings
from sqlalchemy.ext.asyncio import AsyncSession
from fastapi import Depends
from src.gateways.database.BODI_repository import BODIRepository
from src.use_cases.BODI_service import BODIService
from src.app.database import get_async_session


async def get_bodi_service(session: AsyncSession = Depends(get_async_session)):
    repository = BODIRepository(session)
    service = BODIService(repository)
    return service
