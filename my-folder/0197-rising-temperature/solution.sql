# Write your MySQL query statement below

select id from Weather w1 where temperature > (select temperature from Weather where recordDate= DATE_SUB(w1.recordDate, INTERVAL 1 DAY)) 
