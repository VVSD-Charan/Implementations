
# SQL queries

<ol>
<li>
Customer Table : <br><br>

Find the names of the customer that are not referred by the customer with id = 2. <br><br>

+-------------+---------+<br>
| Column Name | Type    |<br>
+-------------+---------+<br>
| id          | int     |<br>
| name        | varchar |<br>
| referee_id  | int     |<br>
+-------------+---------+<br>

```

SELECT name from Customer WHERE referee_id is NULL OR referee_id <> 2;

```

### COALESCE

We can also use COALESCE , it replaces NULL values with zero before checking the values . Handling NULLs is a tricky part . So, SQL has included the COALESCE() function which helps us to handle NULL values in queries. 

The syntax for COALESCE function is COALESCE(column_name , value). If the value of a cell belonging to column is NULL then using this function will replace NULL with the value given in COALESCE function. 

```

SELECT name FROM Customer WHERE COALESCE(referee_id,0) <> 2;

```
</li>
<br><br>
<li>

Table: Views<br><br>

Write a solution to find all the authors that viewed at least one of their own articles. Return all those author_ids under column named as id and all these id's must be unique in ascending order. <br><br>

+---------------+---------+<br>
| Column Name   | Type    |<br>
+---------------+---------+<br>
| article_id    | int     |<br>
| author_id     | int     |<br>
| viewer_id     | int     |<br>
| view_date     | date    |<br>
+---------------+---------+<br>

```

SELECT DISTINCT author_id AS id from Views WHERE author_id = viewer_id ORDER BY author_id;

```

### Aliasing in sql

SQL aliases are used to give a temporary name to columns of a table or table itself so that the names will be readable. ALIASES exist only during entire duration of query. An alias is created using <strong>AS</strong> keyword.

### DISTINCT in sql

In a table , columns often contain many duplicate values . If we just need unique values , then we can obtain them using the DISTINCT statement. 

Syntax to obtain distinct values is

```

SELECT DISTINCT column_name FROM table_name

```

To count number of distinct values , we can use count

```

SELECT COUNT(DISTINCT column_name) FROM table_name

```

</li>
</ol>