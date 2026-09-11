# Write your MySQL query statement below
(select name as results from
MovieRating m join Users u on m.user_id=u.user_id 
group by u.user_id
order by count(rating) desc, u.name
limit 1)

Union all

(select title as results from
MovieRating mr join Movies m on mr.movie_id=m.movie_id
where created_at>='2020-02-01' and created_at<='2020-02-29'
group by m.movie_id
order by avg(rating) desc, m.title
limit 1)
