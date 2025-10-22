from fastapi import APIRouter, Depends, HTTPException
from typing import List
from src.domain.entities import BODI
from src.use_cases.BODI_service import BODIService
from src.use_cases.pull_replication_service import PullReplicationService
from src.app.dependencies import get_bodi_service, get_pull_replication_service

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


@router.get("/replicate/pull", status_code=201)
async def pull_replication(
    replication_service: PullReplicationService = Depends(get_pull_replication_service),
):
    results = await replication_service.pull_data_from_clients()
    
    failed_results = [result for result in results if result["status"] == "failed"]
    
    if failed_results:
        raise HTTPException(status_code=500, detail={"status": "Replication partially successful", "errors": failed_results})
    
    return {"status": "Replication successful", "results": results}

from fastapi import APIRouter, Depends, HTTPException
from src.use_cases.push_replication_service import PushReplicationService
from src.app.dependencies import get_push_replication_service


@router.post("/replicate/push", status_code=200)
async def push_replication(
    service: PushReplicationService = Depends(get_push_replication_service)
):
    """
    Запускает выталкивающую репликацию данных из центральной базы данных
    в территориальные базы данных.
    """
    try:
        replication_result = await service.push_data_to_clients()
        return {"message": "Push replication completed", "results": replication_result}
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"Error during push replication: {str(e)}")
