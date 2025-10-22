import httpx
import logging

logging.basicConfig(filename="logs/app.log", level=logging.INFO)
logger = logging.getLogger(__name__)

class TimeGateway:
    @staticmethod
    async def get_time(url):
        try:
            async with httpx.AsyncClient() as client:
                response = await client.get(url, timeout=5.0)
                response.raise_for_status()
                return response.json()
        except (httpx.HTTPError, httpx.RequestError) as e:
            logger.error(f"Error getting time from {url}: {e}")
            raise
