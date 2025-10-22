from typing import AsyncGenerator

from sqlalchemy.ext.asyncio import AsyncSession, create_async_engine
from sqlalchemy.orm import declarative_base, sessionmaker

from src.app.config import settings

DATABASE_URL = "postgresql+asyncpg://postgres:postgres@db:5432/postgres"
Base = declarative_base()

engin = create_async_engine(DATABASE_URL)
async_session_maker = sessionmaker(engin, class_=AsyncSession, expire_on_commit=False)


async def get_async_session() -> AsyncGenerator[AsyncSession, None]:
    async with async_session_maker.begin() as session:
        yield session
