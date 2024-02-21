# Theory based

### Triggers in SQL

Triggers are stored programs / procedures which are automatically executed or fired when some events occur. Those events can be :

<ol>
    <li>DML (statements like DELETE , INSERT , UPDATE)</li>
    <li>DDL (statements like CREATE , ALTER , DROP)</li>
    <li>Database operations (like LOGON,LOGOFF,STARTUP,STARTDOWN)</li>
</ol>

Trigger can be fired on a table , view , schema , database with which the event is associated.<br>

Benefits of triggers :
<li>Gain strong control over security.</li>
<li>Enforcing referential integrity.</li>
<li>Event logging and access to store information of table.</li>
<li>Auditing operations on table.</li>
<li>Synchronous replication of tables.</li>
<li>Preventing invalid transactions.</li>

```

CREATE [OR REPLACE] TRIGGER trigger_name
{BEFORE | AFTER}
{INSERT [OR] | UPDATE [OR] | DELETE}
ON table_name
[FOR EACH ROW]

DECLARE
Declaration - statements
BEGIN
Executable - statements
END

```

CREATE [OR REPLACE] TRIGGER trigger_name => Creates or replaces an existing trigger with trigger_name.<br>

{BEFORE | AFTER} => This specifies when the trigger will be executed.<br>

{INSERT [OR] | UPDATE [OR] | DELETE} => This specifies DML operation.<br>

ON table_name => Specifies name of table associated with the trigger.<br>

[FOR EACH ROW] => Specifies row-level trigger i.e the trigger will be executed for each row being affected. Otherwise trigger will be executed only when SQL statement is executed , which is called table level trigger. <br><br>

Creating trigger to find out salary differences after for each row which is effected <br>

```

CREATE TRIGGER salary_difference
BEFORE INSERT OR DELETE OR UPDATE ON emp
FOR EACH ROW
DECLARE
salary_difference NUMBER;

BEGIN
salary_difference := :new.salary - :old.salary;
dbms_output.put_line('Old Salary : ' || :old.salary);
dbms_output.put_line('New Salary : ' || :new.salary);
dbms_output.put_line('Salary Difference : ' || salary_difference);
END;

```


### Views in SQL

View is a virtual table containing a subset of data retrieved from one or more database tables (or other views). Views take very little space, simplify complex queries, limit access to the data for security reasons, enable data independence, and summarize data from multiple tables. <br>
<strong> A view always shows up-to-date data! The database engine recreates the view, every time a user queries it.</strong>
<br>
We cannot use a view if the base table is deleted . Using view after deleting base table throws an error. <br><br>

### Normalization vs DeNormalization

Normalization is a process of database design that includes organizing and restructuring data in a way to reduce data redundancy, dependency, duplication, and inconsistency. This leads to enhanced data integrity, more tables within the database, more efficient data access and security control, and greater query flexibility. <br>

Denormalization is the process opposite of normalization: it introduces data redundancy and combines data from multiple tables. Denormalization optimizes the performance of the database infrastructure in situations when read operations are more important than write operations since it helps avoid complex joins and reduces the time of query running.<br><br>

# SYNTAX based

### CASE in SQL

Case is the way to implement the if-then-else logic in SQL. This function sequentially checks the provided conditions in the WHEN clauses and returns the value from the corresponding THEN clause when the first condition is satisfied. If none of the conditions is satisfied, the function returns the value from the ELSE clause in case it's provided, otherwise, it returns NULL.

```

CASE
    WHEN condition_1 THEN value_1
    WHEN condition_2 THEN value_2
    WHEN condition_3 THEN value_3
    ...
    ELSE value
END;

```
<br><br>

### DELETE vs TRUNCATE in SQL

DELETE is a reverseible DML (Data Manipulation Language) , which is used to delete one or multiple rows from a table based on 'WHERE' condition provided. <br>

TRUNCATE is an irreversible DML (Data Manipulation Language) command used to delete all rows of a table. <br><br>

### DROP vs TRUNCATE in SQL

DROP deletes a table from database completely , including table structure and all the associated constraints , relationship with all tables and privileges. <br>
TRUNCATE deletes all rows from a table without effecting table structure and constraints. <br>

DROP works slower than truncate. Both are irreversible DDL (Data Definition Language) commands. <br><br>

### BETWEEN vs IN

BETWEEN operator selects records whose column value lies in between given range. It selects data which lies in between two values. <br>

IN operator defines whether the column values lies in given set of values. It returns records which have columnn data in given set of values. <br><br>

### WHERE vs HAVING

WHERE clause is used in row operations. WHERE caluse cannot be used with aggregate functions . It can be used with SELECT , UPDATE , DELETE statements.<br>

This clause is implemented in column operations. It can work with aggregate functions. This clause can be used with SELECT statement only.<br><br>

### Pattern Matching 

For matching pattern we can use LIKE operator in combination with the '%' and '_' wildcards. The '%' wildcard represents any number of characters including 0. The '_' wildcard exactly represents one character. <br><br>

# FUNCTIONS IN SQL

### AGGREGATE functions in SQL

<ol>
    <li>AVG() => Returns average value</li>
    <li>SUM() => Returns sum of all values</li>
    <li>MIN() => Returns minimum value.</li>
    <li>MAX() => Returns maximum value.</li>
    <li>COUNT() => returns number of rows including those with NULL values</li>
    <li>FIRST() => returns first value of column</li>
    <li>LAST() => returns last value from column</li>
</ol>
<br><br>

### Character Manipulation functions

<ol>
    <li>CONCAT() => Joins two or more strings</li>
    <li>SUBSTR() => returns string present between start and end index values</li>
    <li>LENGTH() => return length of string including blank spaces</li>
    <li>REPLACE() => replaces all occurances of a substring in the string with another string</li>
    <li>TRIM() => Removes blank spaces if present from starting and ending of string</li>
</ol>

# COMPILER RELATED

### Appearence of statements in SELECT query

SELECT – FROM – JOIN – ON – WHERE – GROUP BY – HAVING – ORDER BY – LIMIT

### Order of execution by interpreter

FROM – JOIN – ON – WHERE – GROUP BY – HAVING – SELECT – ORDER BY – LIMIT


