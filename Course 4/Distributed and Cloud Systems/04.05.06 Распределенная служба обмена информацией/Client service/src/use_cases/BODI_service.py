from typing import List
from sqlalchemy.ext.asyncio import AsyncSession
from faker import Faker
from src.domain.entities import BODI
from src.gateways.database.BODI_repository import BODIRepository
import random
from datetime import datetime
from src.app.config import settings

fake = Faker()

class BODIService:
    def __init__(self, bodi_repository: BODIRepository):
        self.bodi_repository = bodi_repository

    async def get_all(self) -> List[BODI]:
        bodi_records = await self.bodi_repository.get_all()
        return [BODI.model_validate(bodi) for bodi in bodi_records]

    async def generate_random_bodis(self, count: int = 10) -> List[BODI]:
        """Генерация случайных объектов BODI"""
        random_bodis = []
        for _ in range(count):
            bodi = BODI(
                IST=fake.random_element(elements=("001", "002", "003")),
                TABL=settings.TABLE_NAME,
                POK=fake.random_element(elements=("POK1", "POK2")),
                UT=f"{random.randint(0, 99):02d}",
                SUB=f"{random.randint(100000, 999999)}",
                OTN=f"{random.randint(0, 99):02d}",
                OBJ=f"{random.randint(0, 9999999999999999):016d}",
                VID=f"{random.randint(0, 99):02d}",
                PER=f"{random.randint(0, 99):02d}",
                DATV=fake.date_time_this_year(),
                DATV_SET=datetime.utcnow(),
                ZNC=round(random.uniform(0, 100), 2),
                PP=f"{random.randint(0, 99):02d}"
            )
            random_bodis.append(bodi)

        await self.bodi_repository.bulk_insert_or_update(random_bodis)
        return random_bodis

    async def delete_all_bodis(self):
        await self.bodi_repository.delete_all()

    async def create_bodis(self, bodi_list: List[BODI]) -> List[BODI]:
        await self.bodi_repository.bulk_insert_or_update(bodi_list)
        return bodi_list