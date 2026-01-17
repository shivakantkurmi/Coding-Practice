# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary 
FROM employee
WHERE salary < (
    select MAX(salary) from employee
);
