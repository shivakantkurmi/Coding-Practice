# Write your MySQL query statement 
-- select customer_number
-- from Orders
-- group by customer_number
-- order by count(*) desc
-- limit 1

WITH cte AS (
    SELECT customer_number, COUNT(*) AS cnt
    FROM Orders
    GROUP BY customer_number
)
SELECT customer_number
FROM cte
WHERE cnt = (SELECT MAX(cnt) FROM cte);
