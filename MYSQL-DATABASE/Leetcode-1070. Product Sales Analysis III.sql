# Write your MySQL query statement below
with groupSales as(
select
    product_id,
    min(year) first_year
from sales
group by product_id
)

select
    s2.product_id,
    s2.first_year,
    s1.quantity,
    s1.price
from sales s1
join groupSales s2
on  s1.product_id = s2.product_id and s1.year = s2.first_year;
