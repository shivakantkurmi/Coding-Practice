# Write your MySQL query statement below
-- DELETE  p1
-- FROM person p1
-- JOIN person p2 
-- ON p1.id>p2.id && p1.email=p2.email;


-- Second Way 
DELETE FROM person 
WHERE id NOT IN (
    SELECT id 
    FROM (
        SELECT id,email,ROW_NUMBER() OVER(PARTITION BY email ORDER BY id) as rn
        FROM person
    ) AS P
    WHERE rn=1
);

