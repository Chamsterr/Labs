Client 1
```
CLIENT_PORT=8001 TABLE_NAME="TBL1"  docker-compose up --build
```

Client 2
```
CLIENT_PORT=8002 TABLE_NAME="TBL2"  docker-compose up --build
```

Central
```
docker-compose up --build
```

## Уласевич
Ничего не сказал плохого. Показавыл репликации только, потому что сихнронизация времени просто для галочки.