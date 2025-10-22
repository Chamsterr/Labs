FROM python:3.12 as builder
RUN pip install poetry==1.4.2
ENV POETRY_NO_INTERACTION=1 \
    POETRY_VIRTUALENVS_IN_PROJECT=1 \
    POETRY_VIRTUALENVS_CREATE=1 \
    POETRY_CACHE_DIR=/tmp/poetry_cache
WORKDIR /app
COPY pyproject.toml poetry.lock ./
RUN --mount=type=cache,target=$POETRY_CACHE_DIR poetry export -f requirements.txt --output requirements.txt --without-hashes
RUN pip wheel --no-cache-dir --no-deps --wheel-dir /wheels -r requirements.txt

FROM python:3.12-slim as runtime
ENV VIRTUAL_ENV=/app/.venv \
    PATH="/app/.venv/bin:$PATH" \
    PYTHONDONTWRITEBYTECODE=1 \
    PYTHONUNBUFFERED=1 \
    PYTHONPATH=/app

COPY --from=builder /wheels /wheels
RUN pip install --no-cache-dir /wheels/*

WORKDIR /app
COPY . .

RUN useradd -m user
RUN chown -R user:user /app

USER user

WORKDIR /app

HEALTHCHECK --interval=5m --timeout=3s CMD curl --fail http://localhost:8000/= || exit 1
CMD ["bash", "-c", "alembic upgrade head && uvicorn src.app.main:app --host 0.0.0.0 --port 8000 --reload"]