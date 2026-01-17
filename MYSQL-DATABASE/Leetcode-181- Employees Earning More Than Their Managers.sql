WITH cte as 
(
select E.id, E.name as employee , E.salary, E.managerid, ee.name as manager, ee.salary as mgr_salary
from Employee E
left join Employee EE 
on e.managerid=ee.id
)
select employee
from cte
where salary>mgr_salary
