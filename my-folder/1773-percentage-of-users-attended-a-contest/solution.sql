# Write your MySQL query statement below

select contest_id, round(count(user_id)/(Select count(*) from Users)*100,2) as percentage
from Users join Register using (user_id)
group by contest_id
order by percentage desc, contest_id
