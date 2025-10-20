SELECT DISTINCT lr.Name AS LectureRoom
FROM Lectures l
JOIN Teachers t ON l.TeacherId = t.Id
JOIN Schedules s ON l.Id = s.LectureId
JOIN LectureRooms lr ON s.LectureRoomId = lr.Id
WHERE t.Name = 'Edward' AND t.Surname = 'Hopper';

SELECT DISTINCT t.Surname
FROM Assistants a
JOIN Teachers t ON a.TeacherId = t.Id
JOIN Lectures l ON t.Id = l.TeacherId
JOIN GroupsLectures gl ON l.Id = gl.LectureId
JOIN Groups g ON gl.GroupId = g.Id
WHERE g.Name = 'F505';

SELECT DISTINCT s.Name AS Subject
FROM Lectures l
JOIN Subjects s ON l.SubjectId = s.Id
JOIN Teachers t ON l.TeacherId = t.Id
JOIN GroupsLectures gl ON l.Id = gl.LectureId
JOIN Groups g ON gl.GroupId = g.Id
WHERE t.Name = 'Alex' AND t.Surname = 'Carmack' AND g.Year = 5;

SELECT DISTINCT t.Surname
FROM Teachers t
WHERE t.Id NOT IN (
    SELECT DISTINCT l.TeacherId
    FROM Lectures l
    JOIN Schedules s ON l.Id = s.LectureId
    WHERE s.DayOfWeek = 1
);

SELECT lr.Name, lr.Building
FROM LectureRooms lr
WHERE lr.Id NOT IN (
    SELECT s.LectureRoomId
    FROM Schedules s
    WHERE s.DayOfWeek = 3 AND s.Week = 2 AND s.Class = 3
);

SELECT DISTINCT t.Name, t.Surname
FROM Teachers t
JOIN Departments d ON d.HeadId = t.Id
JOIN Faculties f ON f.Id = d.FacultyId
WHERE f.Name = 'Computer Science'
AND t.Id NOT IN (
    SELECT c.TeacherId
    FROM Curators c
    JOIN GroupsCurators gc ON c.Id = gc.CuratorId
    JOIN Groups g ON gc.GroupId = g.Id
    JOIN Departments d2 ON g.DepartmentId = d2.Id
    WHERE d2.Name = 'Software Development'
);

SELECT DISTINCT Building
FROM (
    SELECT Building FROM Faculties
    UNION
    SELECT Building FROM Departments
    UNION
    SELECT Building FROM LectureRooms
) AS AllBuildings;

SELECT t.Name, t.Surname, 'Dean' AS Role
FROM Deans d
JOIN Teachers t ON d.TeacherId = t.Id
UNION ALL
SELECT t.Name, t.Surname, 'Head'
FROM Heads h
JOIN Teachers t ON h.TeacherId = t.Id
UNION ALL
SELECT t.Name, t.Surname, 'Teacher'
FROM Teachers t
WHERE t.Id NOT IN (
    SELECT TeacherId FROM Deans
    UNION SELECT TeacherId FROM Heads
    UNION SELECT TeacherId FROM Curators
    UNION SELECT TeacherId FROM Assistants
)
UNION ALL
SELECT t.Name, t.Surname, 'Curator'
FROM Curators c
JOIN Teachers t ON c.TeacherId = t.Id
UNION ALL
SELECT t.Name, t.Surname, 'Assistant'
FROM Assistants a
JOIN Teachers t ON a.TeacherId = t.Id;

SELECT DISTINCT s.DayOfWeek
FROM Schedules s
JOIN LectureRooms lr ON s.LectureRoomId = lr.Id
WHERE lr.Building = 6 AND lr.Name IN ('A311', 'A104');