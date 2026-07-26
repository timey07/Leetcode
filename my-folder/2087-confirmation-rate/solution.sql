# Write your MySQL query statement below

select s.user_id,round(ifnull(sum(action='confirmed')/count(action),0),2) as confirmation_rate
from Signups s left join Confirmations using (user_id)
group by s.user_id
