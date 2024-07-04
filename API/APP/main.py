from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import mysql.connector
from dotenv import load_dotenv
import os

app = FastAPI()

class IPRecord(BaseModel):
    ip: str

load_dotenv("config.cfg")

DB_HOST = os.getenv('DB_HOST')
DB_USER = os.getenv('DB_USER')
DB_PASSWORD = os.getenv('DB_PASSWORD')
DB_DATABASE = os.getenv('DB_DATABASE')

@app.post("/register_ip/")
async def register_ip(record: IPRecord):
    try:
        connection = mysql.connector.connect(
            host=DB_HOST,
            user=DB_USER,
            password=DB_PASSWORD,
            database=DB_DATABASE
        )
        cursor = connection.cursor()
        query = "INSERT INTO victim (ip) VALUES (%s)"
        cursor.execute(query, (record.ip,))
        connection.commit()
        cursor.close()
        connection.close()
    except mysql.connector.Error as err:
        pass

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=3993)
