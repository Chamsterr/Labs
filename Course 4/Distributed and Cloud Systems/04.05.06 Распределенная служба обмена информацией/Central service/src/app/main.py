from fastapi import Depends, FastAPI
from datetime import datetime
from src.app.dependencies import get_time_sync_service
from src.use_cases.time_sync import TimeSyncService
from src.app.routers.BODI_router import router as bodi_router

app = FastAPI()

@app.get("/sync-time")
async def sync_times(time_sync_service: TimeSyncService = Depends(get_time_sync_service)):
    time_results = await time_sync_service.sync_all_times()
    return {"time_sync_results": time_results}

@app.get("/status")
async def get_status():
    return {"status": "Central web service is running", "timestamp": datetime.now().isoformat()}




app.include_router(bodi_router, prefix="/api", tags=["BODI"])

@app.get("/")
async def root():
    return {"message": "Welcome to the Central Service API"}



if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)