-- Write your query below

select name
from customers
where id Not in (

select customer_id 
from orders

);
