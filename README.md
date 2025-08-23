# 📚 Library Management System (C)

A simple console-based **Library Management System** implemented in **C**. It provides basic functionalities for managing students, books, and issuing books through a text-based interface. Data is partially stored in text files for persistence.

---

## 📑 Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Build & Run](#build--run)
- [Usage](#usage)
  - [Login](#login)
  - [Main Menu Options](#main-menu-options)
  - [Books Module](#books-module)
  - [Issue Book](#issue-book)
- [Data Files](#data-files)
- [Known Issues](#known-issues)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

---

## ✅ Features
- **Login System** with basic password authentication
- **Student Management**
  - Add new students (ID, Name, Department)
  - View all students
- **Book Management** (in-memory during session)
  - Add books (Title, Author, Code, Price)
  - Display all books
  - Search books by author or title
  - Count total books
- **Book Issue System**
  - Issue a book to a student
- **File Storage**
  - `studentinfo.txt` → stores student details
  - `issueBook.txt` → stores the last issued book record

---

## 📂 Project Structure
