WITH outside_q1 AS (
    SELECT DISTINCT product_id
    FROM Sales
    WHERE sale_date < '2019-01-01'
       OR sale_date > '2019-03-31'
)
SELECT DISTINCT p.product_id, p.product_name
FROM Product p JOIN sales s ON s.product_id=p.product_id
WHERE p.product_id NOT IN (SELECT product_id FROM outside_q1);



--2nd WAY 
# Write your MySQL query statement below
SELECT
    p.product_id, p.product_name
FROM product p
JOIN sales s ON s.product_id = p.product_id
WHERE s.sale_date BETWEEN '2019-01-01' AND '2019-03-31'
AND NOT EXISTS (
    SELECT 1 
    FROM Sales s 
    WHERE s.product_id = p.product_id
      AND (s.sale_date < '2019-01-01' OR s.sale_date > '2019-03-31')
)
GROUP BY p.product_id
