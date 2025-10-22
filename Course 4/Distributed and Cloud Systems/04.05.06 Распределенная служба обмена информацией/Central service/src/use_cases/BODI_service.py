from typing import List
from src.domain.entities import BODI 
from src.gateways.database.BODI_repository import BODIRepository

    
class BODIService:
    def __init__(self, bodi_repository: BODIRepository):
        self.bodi_repository = bodi_repository

    async def get_all(self) -> List[BODI]:
        bodi_records = await self.bodi_repository.get_all()
        return [BODI.model_validate(bodi) for bodi in bodi_records]
    
    async def delete_all_bodis(self):
        await self.bodi_repository.delete_all()
