# Write your MySQL query statement below
-- SELECT name AS Customers 
-- FROM customers 
-- WHERE id NOT IN (
--     SELECT customerId 
--     FROM orders
-- )


WITH co AS(
    SELECT c.name as name , o.id as orderid
    FROM customers c
    LEFT JOIN orders o
    on c.id=o.customerId
)
SELECT name as Customers
FROM co
WHERE orderid IS NULL;
