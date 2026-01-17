# Write your MySQL query statement below
SELECT p.firstName,p.lastName,a.city,a.state
FROM address a
RIGHT JOIN person p
ON p.personId=a.personId
