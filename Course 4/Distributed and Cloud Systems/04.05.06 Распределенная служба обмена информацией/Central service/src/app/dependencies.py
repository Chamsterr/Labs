from src.use_cases.time_sync import TimeSyncService
from src.app.config import settings
from sqlalchemy.ext.asyncio import AsyncSession
from fastapi import Depends
from src.gateways.database.BODI_repository import BODIRepository
from src.use_cases.BODI_service import BODIService
from src.use_cases.pull_replication_service import PullReplicationService
from src.use_cases.push_replication_service import PushReplicationService
from src.app.database import get_async_session

def get_time_sync_service() -> TimeSyncService:
    return TimeSyncService(settings.sources)


async def get_bodi_service(session: AsyncSession = Depends(get_async_session)):
    repository = BODIRepository(session)
    service = BODIService(repository)
    return service


async def get_pull_replication_service(session: AsyncSession = Depends(get_async_session)):
    repository = BODIRepository(session)
    service = PullReplicationService(repository)
    return service

async def get_push_replication_service(session: AsyncSession = Depends(get_async_session)):
    repository = BODIRepository(session)
    service = PushReplicationService(repository)
    return service