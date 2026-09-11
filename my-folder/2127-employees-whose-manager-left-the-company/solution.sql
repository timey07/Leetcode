# Write your MySQL query statement below
select e2.employee_id
from Employees e1 right join Employees e2
on e1.employee_id=e2.manager_id
where e1.employee_id is NULL and e2.salary<30000
and e2.manager_id is not NULL 
order by e2.employee_id
