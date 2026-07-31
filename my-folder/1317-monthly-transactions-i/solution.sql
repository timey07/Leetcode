# Write your MySQL query statement below

select Date_format(trans_date, '%Y-%m') as month,country,count(*) as trans_count,
sum(state='approved') as approved_count, sum(amount) as trans_total_amount,
sum(Case when state='approved' THEN amount ELSE 0 end) as approved_total_amount
from Transactions
group by month, country 
