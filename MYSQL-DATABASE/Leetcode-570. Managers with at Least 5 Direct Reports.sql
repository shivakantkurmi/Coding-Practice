# Write your MySQL query statement below
WITH cte AS(
    SELECT e1.id,e1.name,e1.managerId
    FROM employee e1
    JOIN employee e2 
    ON e1.id=e2.managerId
)
select name 
FROM cte
GROUP BY id
HAVING count(*)>=5;
