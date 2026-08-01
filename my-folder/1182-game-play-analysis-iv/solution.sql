# Write your MySQL query statement below

select Round(count(distinct a1.player_id)/(select count(distinct player_id) from Activity),2) as fraction
from Activity a1 join Activity a2 on a1.player_id=a2.player_id
where a1.event_date=(
    select min(event_date) from Activity
    where player_id=a1.player_id
)
and Date_add(a1.event_date, interval 1 day)=a2.event_date
