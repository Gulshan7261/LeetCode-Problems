# Write your MySQL query statement below
SELECT w1. id
FROM Weather w1
INNER JOIN Weather W2
WHERE DATEDIFF(W1.recordDate, W2.recordDate) = 1
AND W1.temperature > W2.temperature