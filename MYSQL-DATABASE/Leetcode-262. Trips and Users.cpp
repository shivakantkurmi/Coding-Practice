# Write your MySQL query statement below
SELECT 
    request_at AS Day,
    ROUND(SUM(CASE WHEN status IN ('cancelled_by_client', 'cancelled_by_driver') THEN 1 ELSE 0 END)/COUNT(*) , 2) AS "Cancellation Rate"
FROM Trips t
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
  AND t.client_Id NOT IN (SELECT users_id FROM Users WHERE banned = 'Yes')
  AND t.driver_Id NOT IN (SELECT users_id FROM Users WHERE banned = 'Yes')
GROUP BY request_at;
