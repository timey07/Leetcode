# Write your MySQL query statement below

select user_id, 
Concat(SUBSTRING(Upper(name),1,1),SUBSTRING(Lower(name),2)) as name
from Users
order by user_id
