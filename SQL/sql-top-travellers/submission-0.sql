select distinct(u.name), 
    coalesce(sum(r.distance) over(partition by user_id), 0) as travelled_distance
from users u
left join rides r
on u.id = r.user_id
order by travelled_distance desc, name asc; 
