# Write your MySQL query statement below
Select Students.student_id As student_id,
    student_name,
    Subjects.subject_name As subject_name,
    Count(Examinations.subject_name) As attended_exams
From Students
Cross Join Subjects
Left Join Examinations
On Students.student_id = Examinations.student_id
    And (Subjects.subject_name = Examinations.subject_name)
Group By Students.student_id, Subjects.subject_name
Order By Students.student_id Asc, Subjects.subject_name Asc
