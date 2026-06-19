# Cinema Management System

A console-based C++ application for managing a cinema system.

The project was developed as a university Object-Oriented Programming coursework assignment. It demonstrates the use of classes, inheritance, polymorphism, dynamic memory management, custom containers, and command-based interaction.

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

## Running the Project

The program starts from the `main()` function inside `Cinema.cpp`.

No separate build file is required. When compiling manually, all `.cpp` files should be included because the project is split into multiple source files.

### Using an IDE

Open the project in a C++ IDE such as Visual Studio, CLion, Code::Blocks, or another editor that supports C++ projects.

Make sure that all `.cpp` files are included in the project, then run the project normally. The entry point is `Cinema.cpp`.

### Using g++ directly

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

## Commands

Commands are entered in the console while the program is running.

### Authentication Commands

#### `register <firstName> <lastName> <password>`

Registers a new regular user in the system.

Example:

```text
register John Smith pass123
```

#### `login <firstName> <lastName> <password>`

Logs a user into the system.

Example:

```text
login John Smith pass123
```

Demo admin login:

```text
login Admin Admin 0000
```

#### `logout`

Logs out the currently logged-in user.

Example:

```text
logout
```

### Customer Commands

#### `list_movies`

Shows all upcoming movies in the cinema catalog.

Example:

```text
list_movies
```

#### `buy_ticket <movieId> <row> <column>`

Buys a ticket for a selected movie and seat.

Arguments:

- `movieId` - the ID of the movie
- `row` - selected seat row
- `column` - selected seat column

Example:

```text
buy_ticket 1 2 3
```

#### `list_tickets`

Shows all tickets bought by the currently logged-in user.

Example:

```text
list_tickets
```

#### `list_history`

Shows the watched movie history of the currently logged-in user.

Example:

```text
list_history
```

#### `rate_movie <movieId> <rating>`

Rates a movie that the current user has already watched.

Arguments:

- `movieId` - the ID of the movie
- `rating` - rating value, usually from 1 to 5

Example:

```text
rate_movie 1 5
```

#### `exit`

Exits the application.

Example:

```text
exit
```

## Admin Commands

Admin commands are available after logging in as an administrator.

### `open_haul <rows> <columns>`

Opens a new cinema hall with the given number of rows and columns.

Arguments:

- `rows` - number of seat rows
- `columns` - number of seat columns

Example:

```text
open_haul 5 8
```

### `add_movie <genre> <title> <releaseYear> <length> <hallId> <day> <month> <year> <startHour> <startMinute> <endHour> <endMinute> <genreSpecificData>`

Adds a new movie to the cinema catalog.

Common arguments:

- `genre` - movie genre: `action`, `drama`, or `documentary`
- `title` - movie title
- `releaseYear` - release year of the movie
- `length` - movie length in minutes
- `hallId` - ID of the hall where the movie will be projected
- `day month year` - projection date
- `startHour startMinute` - projection start time
- `endHour endMinute` - projection end time
- `genreSpecificData` - additional arguments depending on the movie type

#### Action movie example

```text
add_movie action FastMovie 2024 120 1 10 6 2025 18 30 20 30 15
```

The last argument is the action intensity.

#### Drama movie example

```text
add_movie drama LifeStory 2023 110 1 11 6 2025 19 00 21 00 true
```

The last argument shows whether the drama movie has comedy elements.

#### Documentary movie example

```text
add_movie documentary HistoryFilm 2022 90 1 12 6 2025 17 00 18 30 history true
```

The last arguments are the documentary theme and whether the movie is based on true events.

### `remove_movie <movieId>`

Removes a movie from the cinema catalog.

If the movie has not been projected yet, the system returns money to users who bought tickets for it. If the movie has already been projected, it is removed from users' watched movie history.

Arguments:

- `movieId` - the ID of the movie

Example:

```text
remove_movie 1
```

### `update_movie_title <movieId> <newTitle>`

Changes the title of a movie.

Arguments:

- `movieId` - the ID of the movie
- `newTitle` - the new title of the movie

Example:

```text
update_movie_title 1 NewTitle
```

### `update_movie_haul <movieId> <newHallId>`

Moves a movie to another hall if the new hall is available for the movie's projection date and time.

Arguments:

- `movieId` - the ID of the movie
- `newHallId` - the ID of the new hall

Example:

```text
update_movie_haul 1 2
```

### `list_users`

Shows all users registered in the system, including the administrator.

Example:

```text
list_users
```

### `list_user_tickets <userId>`

Shows the tickets of a selected user.

Arguments:

- `userId` - the ID of the user

Example:

```text
list_user_tickets 1
```

### `list_user_history <userId>`

Shows the watched movie history of a selected user.

Arguments:

- `userId` - the ID of the user

Example:

```text
list_user_history 1
```

### `remove_user <userId>`

Removes a user from the system.

Arguments:

- `userId` - the ID of the user

Example:

```text
remove_user 1
```

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
