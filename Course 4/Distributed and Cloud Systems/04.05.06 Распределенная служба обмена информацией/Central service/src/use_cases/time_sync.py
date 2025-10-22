import logging
from src.gateways.time_gateway import TimeGateway
from datetime import datetime

logging.basicConfig(filename="logs/app.log", level=logging.INFO)
logger = logging.getLogger(__name__)

class TimeSyncService:
    def __init__(self, sources):
        self.sources = sources

    async def sync_time(self, source):
        try:
            remote_time = await TimeGateway.get_time(f"{source.url}time")
            local_time = datetime.now().timestamp()
            
            remote_datetime = datetime.fromisoformat(remote_time['timestamp'])
            
            remote_timestamp = remote_datetime.timestamp()
            
            time_difference = abs(remote_timestamp - local_time)
            
            logger.info(f"Time difference with {source.table_name}: {time_difference} seconds")
            return {"source": source.table_name, "time_difference": time_difference}
        except Exception as e:
            logger.error(f"Error syncing time with {source.table_name}: {e}")
            return {"source": source.table_name, "status": "unavailable", "error": str(e)}
        
    async def sync_all_times(self):
        time_results = []
        for source in self.sources:
            time_result = await self.sync_time(source)
            time_results.append(time_result)
        return time_results
