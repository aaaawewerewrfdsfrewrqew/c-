CREATE DATABASE Academy;

USE Academy;

CREATE TABLE Groups (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(10) NOT NULL UNIQUE
        CHECK (LEN(Name) > 0),
    Rating INT NOT NULL
        CHECK (Rating BETWEEN 0 AND 5),
    Year INT NOT NULL
        CHECK (Year BETWEEN 1 AND 5)
);


CREATE TABLE Departments (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    Financing MONEY NOT NULL 
        CHECK (Financing >= 0)
        DEFAULT 0,
    Name NVARCHAR(100) NOT NULL UNIQUE
        CHECK (LEN(Name) > 0)
);

CREATE TABLE Faculties (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL UNIQUE
        CHECK (LEN(Name) > 0)
);

CREATE TABLE Teachers (
    Id INT IDENTITY(1,1) PRIMARY KEY,
    EmploymentDate DATE NOT NULL
        CHECK (EmploymentDate >= '1990-01-01'),
    Name NVARCHAR(MAX) NOT NULL
        CHECK (LEN(Name) > 0),
    Premium MONEY NOT NULL 
        CHECK (Premium >= 0)
        DEFAULT 0,
    Salary MONEY NOT NULL
        CHECK (Salary > 0),
    Surname NVARCHAR(MAX) NOT NULL
        CHECK (LEN(Surname) > 0)
);