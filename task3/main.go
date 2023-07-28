package main

import (
    "database/sql"
    "fmt"
    "log"
    "encoding/json"
    _ "github.com/lib/pq"
)

type User struct {
    UserId int `json:"user_id"`
    Name string `json:"name"`
    Age int `json:"age"`
    Phone sql.NullString `json:"phone,omitempty"`
}

type Response struct {
    StatusCode int `json:"status_code"`
    Data []User `json:"data"`
}

func main() {
    db, err := sql.Open("postgres", "host=localhost port=5432 user=postgres password=postgres dbname=mydb sslmode=disable")
    if err != nil {
        log.Fatal(err)
    }
    defer db.Close()

    rows, err := db.Query("SELECT user_id, name, age, phone FROM public.user_table")
    if err != nil {
        log.Fatal(err)
    }
    defer rows.Close()

    var users []User
    for rows.Next() {
        var user User
        err := rows.Scan(&user.UserId, &user.Name, &user.Age, &user.Phone)
        if err != nil {
            log.Fatal(err)
        }
        users = append(users, user)
    }
    if err := rows.Err(); err != nil {
        log.Fatal(err)
    }

    response := Response{
        StatusCode: 200,
        Data: users,
    }

    jsonResponse, err := json.Marshal(response)
    if err != nil {
        log.Fatal(err)
    }

    fmt.Println(string(jsonResponse))
}
