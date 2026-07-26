# Write your MySQL query statement below

select st.student_id,st.student_name,s.subject_name, count(e.subject_name) as attended_exams from Students st cross join Subjects s left join Examinations e using (student_id,subject_name)
group by st.student_id,s.subject_name,st.student_name
order by st.student_id,s.subject_name
