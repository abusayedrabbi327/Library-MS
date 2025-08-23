Library Management System (C)

A simple, console-based Library Management System written in C. It supports basic student registration, listing/searching of students, maintaining an in-memory catalog of books during a session, and issuing a book to a student with file-based persistence for some records. The program presents a text-menu interface after a password login. 

Table of Contents

Demo (What it does)

Project Structure

Build & Run

Usage Guide

Login

Main Menu

Add Student

Search / List Students

Books Module

Issue a Book

Data Files

Known Limitations & Bugs

Roadmap / Suggested Improvements

Coding Notes

Contributing

License

Demo (What it does)

Login prompt → requires a hardcoded password to proceed. On success, you land on the main menu. 

Add Student → stores student ID, name, and department to studentinfo.txt. 

Search / List Students → prints the content of studentinfo.txt to the console. 

Books module → lets you add books, list them, filter by author or title, and count books (in memory for the current run). 

Issue Book → saves a student–book association to issueBook.txt. 

Project Structure
.
├─ Lpro.c                # Main C source with all features
├─ studentinfo.txt       # Created/appended at runtime for student data
└─ issueBook.txt         # Created/overwritten at runtime for issue records


All logic is contained in Lpro.c (functions: main, menu, Addstudent, search_student, Books, issue_book). 

Build & Run
Prerequisites

C compiler (GCC/Clang/MSVC)

Linux / macOS
gcc -Wall -Wextra -o lms Lpro.c
./lms

Windows (MinGW)
gcc -Wall -Wextra -o lms.exe Lpro.c
lms.exe


No external libraries are required; the program uses only <stdio.h> and <string.h>. 

Usage Guide
Login

The program starts by asking:

ID (any string is accepted; the hardcoded userid is not actually validated)

Password → must be student (case-sensitive) to proceed. 

Expected flow (example):

Hello please Enter your details
Enter your ID(011221xxx): 011221123
Enter your password(student): student

successfully Logged in


(Then the main menu.)

Main Menu

You’ll see:

a. Add student
b. Search Student
c. Book
d. issue book;
e. Exit


Enter a single character (a–e). The menu is implemented by menu() and dispatches to the corresponding functions. 

Add Student

Prompts for student ID, name, department.

Appends a formatted record to studentinfo.txt.

Returns you to the menu.
Implemented in Addstudent(). Uses fprintf like:

Student ID:<id>
 Name:<name>
Department:<dept>


Search / List Students

Reads studentinfo.txt and prints tokens line by line.

Implemented in search_student(). 

Note: Output is word/token-based because it uses fscanf(..., "%s", ...), so spaces in names appear as separate tokens. See Known Limitations for improvements. 

Books Module

Select c at the main menu to enter Books():
You’ll see a sub-menu:

1. Add book information
2. Display book information
3. List all books by given author
4. List the title of specified book
5. Count books
6. Exit and main menu...


Add book → enter: book name, Book_AuthorName, Book_code (int), price (float)

Display → prints all books added this session

List by author → enter author name; shows matching books

List by title → enter exact book name; shows that book

Count → prints the number of books added this session

Exit → returns to menu()

Book data is stored in memory only (array books[100] inside Books()), so it does not persist after leaving the program. 

Issue a Book

Prompts for Student ID and Book Code.

Writes a single record to issueBook.txt (overwrites the file each time).
Implemented in issue_book(). Example format:

Student ID:<id>
Book Code:<code>


Data Files

studentinfo.txt — Appended with each student you add. Persisted across runs. 

issueBook.txt — Overwritten on each issue operation (contains only the most recent issue). 

There is no file for the book catalog; all book info is in memory during the Books() session.