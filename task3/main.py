import psycopg2
import json

class User:
    def __init__(self, user_id, name, age, phone):
        self.user_id = user_id
        self.name = name
        self.age = age
        self.phone = phone

    def to_dict(self):
        return {
            "user_id": self.user_id,
            "name": self.name,
            "age": self.age,
            "phone": self.phone
        }

class Response:
    def __init__(self, status_code, data):
        self.status_code = status_code
        self.data = data

    def to_dict(self):
        return {
            "status_code": self.status_code,
            "data": [user.to_dict() for user in self.data]
        }

def main():
    conn = psycopg2.connect(host="localhost", port=5432, user="postgres", password="postgres", dbname="mydb")
    cur = conn.cursor()

    cur.execute("SELECT user_id, name, age, phone FROM public.user_table")

    users = []
    for row in cur.fetchall():
        user = User(row[0], row[1], row[2], row[3])
        users.append(user)

    response = Response(200, users)

    jsonResponse = json.dumps(response.to_dict())
    print(jsonResponse)

    cur.close()
    conn.close()

if __name__ == "__main__":
    main()
  
