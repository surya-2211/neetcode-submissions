select student_id, exam_id, score
from (
    select *,
        row_number() over(
            partition by student_id
            order by score desc, exam_id asc
        ) as rn
    from exam_results
) t
where rn = 1
order by student_id;