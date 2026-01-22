# Write your MySQL query statement below
WITH grouped AS (
	SELECT *, id - ROW_NUMBER() OVER() gn
	FROM stadium 
	WHERE people >= 100 
) 
SELECT id, visit_date, people
FROM grouped 
WHERE gn IN (
	SELECT gn 
	FROM grouped  
	GROUP BY gn
	HAVING COUNT(*) >= 3
);
