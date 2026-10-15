# Write your MySQL query statement below
SELECT Tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15