# 🔑 Keys in Database Management Systems (DBMS)

A comprehensive guide to understanding all types of database keys — how they work, why they matter, and how to use them.

---

## 📌 What Are Keys?

A **key** is a field (or set of fields) in a table used to:
- Uniquely identify records
- Avoid duplicate data
- Create relationships between tables

**Example:**

| StudentID | Name | CGPA |
|-----------|------|------|
| 101       | Ali  | 3.4  |
| 102       | Sara | 3.8  |

> `StudentID` uniquely identifies each student → it's a **key**.

---

## 🧠 Types of Keys

| Key Type      | Purpose                                      |
|---------------|----------------------------------------------|
| Primary Key   | Uniquely identifies each record              |
| Candidate Key | Any column(s) that could be a primary key    |
| Super Key     | Any unique combination of attributes         |
| Alternate Key | Candidate key not chosen as primary          |
| Foreign Key   | Links two tables via a primary key reference |
| Composite Key | Primary key made of multiple columns         |
| Unique Key    | Ensures all values in a column are unique    |

---

## 1️⃣ Primary Key

Uniquely identifies every row in a table.

**Rules:**
- Cannot be `NULL`
- Cannot have duplicate values
- Only **one** per table

```sql
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    CGPA FLOAT
);
```

---

## 2️⃣ Candidate Key

Any column (or combination) that **can** uniquely identify a record.
A table may have multiple candidate keys — one becomes the Primary Key.

**Example:**

| StudentID | Email           | Name |
|-----------|-----------------|------|
| 101       | ali@gmail.com   | Ali  |
| 102       | sara@gmail.com  | Sara |

Both `StudentID` and `Email` can uniquely identify students → both are **Candidate Keys**.

---

## 3️⃣ Super Key

Any set of columns that uniquely identifies a row — including combinations with extra (redundant) attributes.

**Example super keys from the table above:**
- `StudentID`
- `Email`
- `StudentID + Name`
- `Email + Name`

> ✅ All Candidate Keys are Super Keys  
> ❌ Not all Super Keys are Candidate Keys

---

## 4️⃣ Alternate Key

Candidate keys that were **not** selected as the Primary Key.

**Example:**
- Candidate Keys: `StudentID`, `Email`
- Primary Key chosen: `StudentID`
- **Alternate Key → `Email`**

---

## 5️⃣ Foreign Key

Creates a **relationship** between two tables by referencing the Primary Key of another table. Ensures **referential integrity**.

```sql
CREATE TABLE Courses (
    CourseID INT,
    StudentID INT,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID)
);
```

**Students Table**

| StudentID | Name |
|-----------|------|
| 101       | Ali  |
| 102       | Sara |

**Courses Table**

| CourseID | StudentID |
|----------|-----------|
| CS101    | 101       |
| CS102    | 102       |

> `StudentID` in `Courses` → **Foreign Key** referencing `Students`

---

## 6️⃣ Composite Key

A Primary Key made up of **two or more columns** — used when no single column is unique on its own.

```sql
PRIMARY KEY (StudentID, CourseID)
```

**Course Registration Table**

| StudentID | CourseID |
|-----------|----------|
| 101       | CS101    |
| 101       | CS102    |

- `StudentID` alone → not unique
- `CourseID` alone → not unique
- `StudentID + CourseID` together → **unique** ✅

---

## 7️⃣ Unique Key

Ensures all values in a column are unique — similar to Primary Key but with key differences:

| Feature       | Primary Key    | Unique Key              |
|---------------|----------------|-------------------------|
| Duplicates    | ❌ Not allowed  | ❌ Not allowed           |
| NULL values   | ❌ Not allowed  | ✅ Allowed (usually one) |
| Per table     | Only **one**   | Multiple allowed        |

```sql
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Email VARCHAR(100) UNIQUE
);
```

---

## 🎯 Real-World Example: University System

**Tables:**
- `Students(StudentID, Name)`
- `Courses(CourseID, Title)`
- `Enrollment(StudentID, CourseID)`

**Key Assignments:**

| Key             | Column(s)                    | Table        |
|-----------------|------------------------------|--------------|
| Primary Key     | `StudentID`                  | Students     |
| Primary Key     | `CourseID`                   | Courses      |
| Composite Key   | `StudentID + CourseID`       | Enrollment   |
| Foreign Key     | `StudentID`                  | Enrollment   |
| Foreign Key     | `CourseID`                   | Enrollment   |

---

## 📚 Summary

```
Super Key ⊇ Candidate Key ⊇ Primary Key
                         ⊇ Alternate Key
```

- **Super Key** is the broadest — any unique combination
- **Candidate Keys** are minimal super keys
- **Primary Key** is the one chosen from candidates
- **Alternate Keys** are the remaining candidates
- **Foreign Key** links tables
- **Composite Key** uses multiple columns
- **Unique Key** enforces uniqueness without being the primary key

---

*Happy querying! 🚀*