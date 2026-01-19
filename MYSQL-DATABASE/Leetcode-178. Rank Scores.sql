# Write your MySQL query statement below
WITH cte AS(
    SELECT score , DENSE_RANK() OVER( order by score DESC ) as rn
    FROM scores
)
SELECT score , rn as 'rank'
FROM cte
ORDER BY rn ;
