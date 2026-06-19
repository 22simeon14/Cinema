# Cinema

A console-based C++ application for managing a small cinema system.

This project was created as a university Object-Oriented Programming course project.  
The main goal is to demonstrate basic OOP principles in C++ through a command-line cinema management system.

## What the project does

The system supports:

- user registration and login
- administrator login
- movie catalog
- different movie types
- cinema halls and seats
- movie sessions
- ticket buying
- user tickets and movie history
- movie rating
- basic admin management commands

## User roles

The project has two types of users:

- regular users
- administrator

Regular users can browse movies, buy tickets, view their tickets and history, and rate watched movies.

The administrator can add and remove movies, open and close halls, update movie information, view users, and remove users.

## Movie types

The system supports several movie types:

- Action movie
- Drama movie
- Documentary movie

Each movie type has its own additional data and ticket price calculation logic.

## Running the project

The program starts from the `main()` function inside `Cinema.cpp`.

No separate build file is required.

### Using an IDE

Open the project in a C++ IDE such as Visual Studio, CLion, Code::Blocks or another editor that supports C++ projects.

Make sure that all `.cpp` files are included in the project, then run the project normally.  
The entry point is `Cinema.cpp`.

### Using g++

From the project folder, compile all `.cpp` files:

```bash
g++ -std=c++17 *.cpp -o cinema
```

Then run the program.

On Linux/macOS:

```bash
./cinema
```

On Windows with MinGW:

```bash
cinema.exe
```

## Example commands

Register a user:

```text
register John Smith pass123
```

Log in:

```text
login John Smith pass123
```

List available movies:

```text
list_movies
```

Buy a ticket:

```text
buy_ticket 1 2 3
```

Show user tickets:

```text
list_tickets
```

Show watched movie history:

```text
list_history
```

Rate a movie:

```text
rate_movie 1 5
```

Log out:

```text
logout
```

Exit the program:

```text
exit
```

## Administrator

The administrator account is used to manage the cinema system.

Example admin login:

```text
login Admin Admin 0000
```

Example admin commands:

```text
open_haul 5 8
add_movie action FastMovie 2024 120 1 10 6 2025 18 30 20 30 15
list_users
remove_movie 1
```

## Notes

- This is an educational project, not a production-ready application.
- The project is fully console-based.
- The command interface expects simple one-word values for most inputs.
- The focus of the project is object-oriented programming, inheritance, polymorphism, dynamic memory management, and command-based program flow.
