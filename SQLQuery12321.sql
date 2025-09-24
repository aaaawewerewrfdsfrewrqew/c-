USE Academy;
GO

CREATE TABLE Departments (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Financing MONEY NOT NULL CHECK (Financing >= 0) DEFAULT 0,
    Name NVARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE Faculties (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Dean NVARCHAR(MAX) NOT NULL,
    Name NVARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE Groups (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Name NVARCHAR(10) NOT NULL UNIQUE,
    Rating INT NOT NULL CHECK (Rating BETWEEN 0 AND 5),
    Year INT NOT NULL CHECK (Year BETWEEN 1 AND 5)
);

CREATE TABLE Teachers (
    Id INT PRIMARY KEY IDENTITY(1,1),
    EmploymentDate DATE NOT NULL CHECK (EmploymentDate >= '1990-01-01'),
    IsAssistant BIT NOT NULL DEFAULT 0,
    IsProfessor BIT NOT NULL DEFAULT 0,
    Name NVARCHAR(MAX) NOT NULL,
    Position NVARCHAR(MAX) NOT NULL,
    Premium MONEY NOT NULL CHECK (Premium >= 0) DEFAULT 0,
    Salary MONEY NOT NULL CHECK (Salary > 0),
    Surname NVARCHAR(MAX) NOT NULL
);

SELECT Name, Financing, Id
FROM Departments;


SELECT Name AS [Group Name], Rating AS [Group Rating]
FROM Groups;


SELECT 
    Surname,
    (Salary * 100.0 / NULLIF(Premium, 0)) AS [Salary vs Premium %],
    (Salary * 100.0 / (Salary + Premium)) AS [Salary vs Total %]
FROM Teachers;


SELECT 'The dean of faculty ' + Name + ' is ' + Dean AS FacultyInfo
FROM Faculties;

SELECT Surname
FROM Teachers
WHERE IsProfessor = 1 AND Salary > 1050;

SELECT Name
FROM Departments
WHERE Financing < 11000 OR Financing > 25000;

SELECT Name
FROM Faculties
WHERE Name <> 'Computer Science';

SELECT Surname, Position
FROM Teachers
WHERE IsProfessor = 0;

SELECT Surname, Position, Salary, Premium
FROM Teachers
WHERE IsAssistant = 1 AND Premium BETWEEN 160 AND 550;

SELECT Surname, Salary
FROM Teachers
WHERE IsAssistant = 1;

SELECT Surname, Position
FROM Teachers
WHERE EmploymentDate < '2000-01-01';

SELECT Name AS [Name of Department]
FROM Departments
WHERE Name < 'Software Development';

SELECT Surname
FROM Teachers
WHERE IsAssistant = 1 AND (Salary + Premium) <= 1200;

SELECT Name
FROM Groups
WHERE Year = 5 AND Rating BETWEEN 2 AND 4;

SELECT Surname
FROM Teachers
WHERE IsAssistant = 1 AND (Salary < 550 OR Premium < 200);
