from pydantic import HttpUrl, Field
from pydantic_settings import BaseSettings
from typing import List

class SourceConfig(BaseSettings):
    name: str
    url: HttpUrl

class Settings(BaseSettings):
    port: int = 8001
    TABLE_NAME : str
    # central_sources: SourceConfig


settings = Settings()