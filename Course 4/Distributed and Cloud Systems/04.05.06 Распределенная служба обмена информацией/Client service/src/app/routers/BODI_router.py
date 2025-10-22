from fastapi import APIRouter, Depends, HTTPException
from typing import List
from src.domain.entities import BODI
from src.use_cases.BODI_service import BODIService
from src.app.dependencies import get_bodi_service

router = APIRouter()

@router.get("/bodi", response_model=List[BODI])
async def get_all_bodi(service: BODIService = Depends(get_bodi_service)):
    return await service.get_all()

@router.delete("/bodi", status_code=204)
async def delete_all_bodi(service: BODIService = Depends(get_bodi_service)):
    try:
        await service.delete_all_bodis()
        return {"message": "All BODI records have been deleted."}
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Error deleting records: {str(e)}")


@router.post("/bodi/generate", response_model=List[BODI], status_code=201)
async def generate_random_bodis(
    count: int = 10, 
    service: BODIService = Depends(get_bodi_service)
):
    try:
        random_bodis = await service.generate_random_bodis(count)
        return random_bodis
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Error generating BODI data: {str(e)}")


@router.post("/bodi", response_model=List[BODI], status_code=201)
async def create_bodi(
    bodi_list: List[BODI], 
    service: BODIService = Depends(get_bodi_service)
):
    try:
        created_bodis = await service.create_bodis(bodi_list)
        return created_bodis
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Error creating BODI records: {str(e)}")