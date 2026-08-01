# Write your MySQL query statement below

select s1.product_id,s1.year as first_year, quantity, price
from Sales s1 join
(select product_id, min(year) as year from Sales group by product_id)t
on t.product_id=s1.product_id
and t.year=s1.year
