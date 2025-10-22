from typing import List
from sqlalchemy.ext.asyncio import AsyncSession
from sqlalchemy.dialects.postgresql import insert as pg_insert
from sqlalchemy.future import select
from sqlalchemy import text

from .models import BODI

class BODIRepository:
    def __init__(self, session: AsyncSession):
        self.session = session

    async def get_all(self):
        result = await self.session.execute(select(BODI))
        return result.scalars().all()

    async def bulk_insert_or_update(self, bodi_data: List[BODI]):
        if not bodi_data:
            return

        stmt = pg_insert(BODI).values([bodi.__dict__ for bodi in bodi_data])
        
        stmt = stmt.on_conflict_do_update(
            index_elements=['IST', 'TABL', 'POK', 'UT', 'SUB', 'OTN', 'OBJ', 'VID', 'PER', 'DATV_SET'],
            set_={c.name: c for c in stmt.excluded if c.name != 'DATV_SET'}
        )

        await self.session.execute(stmt)
    
    async def delete_all(self):
        await self.session.execute(text("DELETE FROM bodi"))
        await self.session.commit()