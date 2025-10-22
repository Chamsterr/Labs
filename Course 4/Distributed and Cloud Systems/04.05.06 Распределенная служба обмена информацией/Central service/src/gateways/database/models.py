from sqlalchemy import Column, String, Float, DateTime
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.schema import PrimaryKeyConstraint

Base = declarative_base()

class BODI(Base):
    __tablename__ = 'bodi'

    IST = Column(String(3), nullable=False)
    TABL = Column(String(5), nullable=False)
    POK = Column(String(4), nullable=False)
    UT = Column(String(2), default='00', nullable=False)
    SUB = Column(String(6), nullable=False)
    OTN = Column(String(2), default='00', nullable=False)
    OBJ = Column(String(16), default='0000000000000000', nullable=False)
    VID = Column(String(2), nullable=False)
    PER = Column(String(2), nullable=False)
    DATV = Column(DateTime, nullable=False)
    DATV_SET = Column(DateTime, nullable=False)
    ZNC = Column(Float, nullable=False)
    PP = Column(String(2), nullable=False)

    __table_args__ = (
        PrimaryKeyConstraint('IST', 'TABL', 'POK', 'UT', 'SUB', 'OTN', 'OBJ', 'VID', 'PER', 'DATV_SET'),
    )

    def __repr__(self):
        return f"<BODI(IST={self.IST}, TABL={self.TABL}, POK={self.POK}, ZNC={self.ZNC})>"
