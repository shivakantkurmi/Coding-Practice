# Write your MySQL query statement below
WITH cte AS(
    SELECT e.id,e.name,e.salary,d.name as department
    FROM employee e 
    JOIN department d 
    ON e.departmentId=d.id
)
SELECT department as Department , name as Employee, salary as Salary
FROM cte
WHERE (department,salary) IN (
    SELECT department, MAX(salary) 
    FROM cte
    GROUP BY department
);
