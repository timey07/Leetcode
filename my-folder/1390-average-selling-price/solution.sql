# Write your MySQL query statement below

select Prices.product_id, round(ifnull(sum(price*units)/sum(units),0),2) as average_price 
from Prices left join UnitsSold on Prices.product_id=UnitsSold.product_id 
and purchase_date between start_date and end_date
group by Prices.product_id
