with cte as (
    select *, DENSE_RANK() over (partition by departmentId order by salary desc) as rnk
    FROM Employee
)

select  d.name as Department, cte.name as Employee, cte.salary as Salary
from Department as d
inner join cte
on d.id = cte.departmentId
where rnk <= 3
