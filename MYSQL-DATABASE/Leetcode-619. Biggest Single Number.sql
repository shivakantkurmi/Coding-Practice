# Write your MySQL query statement below
WITH CTE AS
(SELECT num FROM Mynumbers
GROUP BY num
HAVING COUNT(num)=1)

select max(num) as num from cte;
