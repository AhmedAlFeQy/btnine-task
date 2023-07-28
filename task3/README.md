

# These programs modify the PostgreSQL driver source code in Go and Python to return outputs in JSON string format. The programs can be compiled and run on any system with Go and Python installed, respectively.

# Development Environment

 - Operating System: Windows 10
 - IDE: Visual Studio Code
 - Compiler: Go 1.17 and Python 3.9.5
 - 
# How to Use the Driver

  1- Install Go and PostgreSQL driver for Go or Python and psycopg2 for Python on your system.
  
  2- Modify the PostgreSQL connection string in the source code to match your database configuration.
  
  3- Compile and run the Go or Python program to connect to the database and fetch data from the public.user_table table.

The program will output the data in JSON string format, with a status_code field set to 200 and a data field containing an array of user objects with fields user_id, name, age, and phone (if present).
