from dataclasses import dataclass
from typing import Optional
from datetime import datetime
from pydantic import BaseModel, Field

@dataclass
class TimeSyncResult:
    source: str
    time_difference: float
    error: str | None

class BODI(BaseModel):
    IST: str
    TABL: str
    POK: str
    UT: Optional[str] = Field(default="00")
    SUB: str
    OTN: Optional[str] = Field(default="00")
    OBJ: Optional[str] = Field(default="0000000000000000")
    VID: str
    PER: str
    DATV: datetime
    DATV_SET: datetime
    ZNC: float
    PP: str

    class Config:
        from_attributes = True
