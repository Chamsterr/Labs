from pydantic import HttpUrl, Field
from pydantic_settings import BaseSettings
from typing import List

class SourceConfig(BaseSettings):
    table_name: str
    url: HttpUrl

class Settings(BaseSettings):
    sources: List[SourceConfig] = Field(..., env='SOURCES')


settings = Settings()