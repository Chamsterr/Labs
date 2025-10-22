from fastapi import Depends, FastAPI
from datetime import datetime
from src.app.routers.BODI_router import router as bodi_router
from src.app.config import settings

app = FastAPI()

app.include_router(bodi_router, prefix="/api", tags=["BODI"])

@app.get("/")
async def root():
    return {"message": "Welcome to the Central Client API"}

@app.get("/time")
async def get_current_time():
    current_time = datetime.now().isoformat()
    return {"timestamp": current_time}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=settings.CLIENT_PORT)