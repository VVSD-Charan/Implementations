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



