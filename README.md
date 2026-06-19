# Cinema Management System

A console-based C++ application for managing a cinema system.  
The project was developed as a university Object-Oriented Programming coursework assignment and demonstrates the use of classes, inheritance, polymorphism, dynamic memory management, custom containers, and command-based interaction.

## Overview

The system models a small cinema management platform with:

- cinema halls and seat layouts
- different movie types
- user accounts with different roles
- movie screenings
- ticket purchasing
- user ticket history
- movie rating
- administrative commands for managing movies, halls, and users

The application runs through a command-line interface.

## Main Features

### Customer functionality

- register a new account
- log in and log out
- browse available movies
- buy tickets for a selected movie and seat
- view purchased tickets
- view watched movie history
- rate already watched movies

### Admin functionality

- add new movies
- remove movies
- open new cinema halls
- close or move screenings through hall/movie management commands
- update movie titles
- move movies to another hall
- view all users
- view a user's ticket history
- view a user's watched movie history
- remove users from the system

## Movie Types

The project uses inheritance and polymorphism to support different movie categories.

### Action Movie

Action movies have an additional `actionIntensity` attribute.  
The ticket price is calculated from a base action movie price and the intensity of the action scenes.

### Drama Movie

Drama movies can contain comedy elements.  
If a drama movie has comedy elements, the ticket price is increased.

### Documentary Movie

Documentary movies have a theme and can be based on true events.  
If a documentary is based on true events, the ticket price is increased.

## Object-Oriented Design

The project demonstrates several OOP concepts:

- inheritance for different movie types
- polymorphism through the base `Movie` class
- encapsulation of users, tickets, halls, movies, and sessions
- command-based execution through separate command classes
- custom `Vector<T>` implementation
- custom string class
- dynamic memory management
- role-based access for customer and admin commands

## Project Structure

```text
Cinema.cpp                   Entry point and command loop
System.h / System.cpp         Main system container and access logic
Movie.h / Movie.cpp           Base movie abstraction
ActionMovie.*                 Action movie implementation
DramaMovie.*                  Drama movie implementation
DocumentaryMovie.*            Documentary movie implementation
User.*                        Base user class
Customer.*                    Customer functionality
Admin.*                       Admin functionality
Ticket.*                      Ticket model
Haul.*                        Cinema hall model
Session.*                     Login/session state
CommandFactory.*              Creates command objects from user input
*Command.*                    Individual command implementations
Vector.h                      Custom dynamic array template
mystring.*                    Custom string implementation
Utility.h                     Date/time helper structures and functions
```

## Build and Run

### Using CMake

```bash
cmake -S . -B build
cmake --build build
```

Then run the executable from the generated build directory.

On Linux/macOS:

```bash
./build/cinema
```

On Windows, depending on the generator:

```bash
build\Debug\cinema.exe
```

or:

```bash
build\cinema.exe
```

### Using g++ directly

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o cinema
./cinema
```

On Windows with MinGW:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o cinema.exe
cinema.exe
```

## Commands

### Authentication

```text
register <firstName> <lastName> <password>
login <firstName> <lastName> <password>
logout
```

Example customer flow:

```text
register John Smith pass123
login John Smith pass123
```

For the demo admin account, use the admin password:

```text
0000
```

Example:

```text
login Admin Admin 0000
```

### Customer commands

```text
list_movies
buy_ticket <movieId> <row> <column>
list_tickets
list_history
rate_movie <movieId> <rating>
logout
exit
```

### Admin commands

```text
add_movie <genre> <title> <releaseYear> <length> <hallId> <day> <month> <year> <startHour> <startMinute> <endHour> <endMinute> <genreSpecificData>
open_haul <rows> <columns>
remove_movie <movieId>
remove_user <userId>
update_movie_title <movieId> <newTitle>
update_movie_haul <movieId> <newHallId>
list_users
list_user_tickets <userId>
list_user_history <userId>
logout
exit
```

## Add Movie Examples

Before adding a movie, the admin should open a hall:

```text
login Admin Admin 0000
open_haul 5 8
```

### Action movie

```text
add_movie action FastMovie 2024 120 1 10 6 2025 18 30 20 30 15
```

The last argument is the action intensity.

### Drama movie

```text
add_movie drama LifeStory 2023 110 1 11 6 2025 19 00 21 00 true
```

The last argument shows whether the movie has comedy elements.

### Documentary movie

```text
add_movie documentary HistoryFilm 2022 90 1 12 6 2025 17 00 18 30 history true
```

The last arguments are the documentary theme and whether it is based on true events.

## Example Session

```text
> login Admin Admin 0000
> open_haul 5 8
> add_movie action FastMovie 2024 120 1 10 6 2025 18 30 20 30 15
> logout
> register John Smith pass123
> login John Smith pass123
> list_movies
> buy_ticket 1 2 3
> list_tickets
> rate_movie 1 5
> logout
> exit
```

## Notes

- This is an educational OOP project, not a production-ready cinema platform.
- Commands currently use single-token values, so movie titles with spaces should be written as one word or with underscores.
- The project does not use external libraries.
- The focus is on object-oriented design, manual memory management, and command-line interaction.

## License

This project is licensed under the Unlicense.
