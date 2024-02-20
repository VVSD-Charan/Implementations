
# SQL queries

<ol>
<li>
Customer Table : <br>

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
<br>
<li>

Table: Views<br>

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

<br>

<li>

Table: Tweets <br>

Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15. <br><br>

+----------------+---------+<br>
| Column Name    | Type    |<br>
+----------------+---------+<br>
| tweet_id       | int     |<br>
| content        | varchar |<br>
+----------------+---------+<br>

```

SELECT tweet_id FROM Tweets WHERE char_length(content) > 15;

```

### length() vs char_length() 
LENGTH() returns the length of the string measured in bytes. <br>
CHAR_LENGTH() returns the length of the string measured in characters. <br>

Using length() works similar to char_length() in most of the cases but in case of UTF-8 , as different characters may take up different bytes , length() will give false results.

</li> <br>

<li>

Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null. <br><br>

Table: Employees <br>

+---------------+---------+<br>
| Column Name   | Type    |<br>
+---------------+---------+<br>
| id            | int     |<br>
| name          | varchar |<br>
+---------------+---------+<br>

```

select eu.unique_id as unique_id, e.name as name FROM Employees AS e LEFT JOIN EmployeeUNI AS eu ON
e.id = eu.id;

```

### Types of Outer Joins
<ol>
    <li>Left Outer Join</li>
    <li>Right Outer Join</li>
    <li>Full Outer Join</li>
</ol>

### Left outer Join

The left join operation returns all record from left table and matching records from the right table. On a matching element not found in right table, NULL is represented in that case.

### Right outer Join

The right join operation returns all record from right table and matching records from the left table. On a matching element not found in left table, NULL is represented in that case.

### Full outer Join

A full outer join returns all rows from both tables being joined, regardless of whether there is a match or not. If there is no matching value in one of the tables, the result set will still include that row, with NULL values for columns from the other table.
</li>

<li>

Write a solution to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits. <br>

Table: Visits <br><br>

+-------------+---------+<br>
| Column Name | Type    |<br>
+-------------+---------+<br>
| visit_id    | int     |<br>
| customer_id | int     |<br>
+-------------+---------+<br><br>

Table: Transactions<br><br>

+----------------+---------+<br>
| Column Name    | Type    |<br>
+----------------+---------+<br>
| transaction_id | int     |<br>
| visit_id       | int     |<br>
| amount         | int     |<br>
+----------------+---------+<br><br>

```

SELECT V.customer_id , COUNT(V.visit_id) as count_no_trans
FROM Visits as V
LEFT JOIN Transactions as T
ON V.visit_id = T.visit_id
WHERE T.transaction_id IS NULL
GROUP BY V.customer_id

```

### Approaching step by step

We need to find all those visits where transactions didnot occur . So, even if there are no matching transactions we need to fetch all visits. So , initially we can perform left JOIN

```

FROM Visits as V
LEFT JOIN Transactions as T
ON V.visit_id = T.visit_id

```

Now we will get entire data and if there are no transactions for a visit , then we will get all values belonging to transactions as NULL. We are interested only in those rows which donot have matching transaction data . So , we can now remove all those rows which have matching data. Since rows with no matching data will have transaction_id as NULL , we can use that condition.

```

FROM Visits as V
LEFT JOIN Transactions as T
ON V.visit_id = T.visit_id
WHERE T.transaction_id IS NULL

```

Now we will get all the rows which have visits but no transactions associated with them. Now , we need to find those customer_id's and count of their visits.

```

SELECT V.customer_id , COUNT(V.visit_id) as count_no_trans
FROM Visits as V
LEFT JOIN Transactions as T
ON V.visit_id = T.visit_id
WHERE T.transaction_id IS NULL
GROUP BY V.customer_id

```
</li>

<li>

Write a solution to find all dates' Id with higher temperatures compared to its previous dates (yesterday).<br>

Table: Weather<br><br>

+---------------+---------+<br>
| Column Name   | Type    |<br>
+---------------+---------+<br>
| id            | int     |<br>
| recordDate    | date    |<br>
| temperature   | int     |<br>
+---------------+---------+<br><br>

We can use SELF JOIN to obtain solution. We need to compare dates such that difference between dates should be one and the temperature next day should be greater than the temperature on before date.<br>

Using INNER JOIN with same table can still get us the required solution <br>

```

SELECT w1.id FROM Weather AS w1 INNER JOIN Weather AS w2 WHERE
DATEDIFF(w1.recordDate,w2.recordDate) = 1 AND w1.temperature > w2.temperature;

```

Using self Join,

```

SELECT w1.id FROM Weather w1 , Weather w2 WHERE DATEDIFF(w1.recordDate,w2.recordDate) = 1 AND w1.temperature > w2.temperature

```

Using subdate function

```

SELECT w1.id from Weather w1 , Weather w2 WHERE subdate(w1.recordDate,1) = w2.recordDate AND w1.temperature > w2.temperature;

```

### DATEDIFF() function in SQL
It can be of three parameters <br>
<strong>DATEDIFF(date1,date2)</strong> => returns an integer denoting number of days between date1 and date2 <br>
<strong>DATEDIFF(interval,date1,date2) => returns difference between dates in terms of an interval. Interval can be month,year,weeks,hours,muntes,seconds.</strong>



### SUBDATE() funtcion in SQL
<strong>SUBDATE(DATE,x)</strong> returns date obtained after subtracting x days from given date . <br>
<strong>SUBDATE(DATE,x unit)</strong> returns "units" after deleting x units from given date.


</li>

<li>

Write a solution to find the average time each machine takes to complete a process.<br>

The time to complete a process is the 'end' timestamp minus the 'start' timestamp. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run. <br>

Table: Activity <br><br>

+----------------+---------+<br>
| Column Name    | Type    |<br>
+----------------+---------+<br>
| machine_id     | int     |<br>
| process_id     | int     |<br>
| activity_type  | enum    |<br>
| timestamp      | float   |<br>
+----------------+---------+<br><br>

First we need to perform self Join to obtain start time and end time of a process belonging to same machine.

```

FROM Activity as A1 , Activity as A2 WHERE A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id AND A1.activity_type = "start" AND  A2.activity_type = "end" 

```

After obtaining the table which contains start and end timestamps of process belonging to a machine , we need to return machine_id's and average processing time (ending timestamp - starting timestamp). So, we need to group the data by machine_id so that we can perform average aggregation

```

SELECT A1.machine_id , ROUND(AVG(A2.timestamp - A1.timestamp),3) AS processing_time
FROM Activity as A1 , Activity as A2 WHERE A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id AND A1.activity_type = "start" AND  A2.activity_type = "end" 
GROUP BY A1.machine_id;

```


</li>

</ol>