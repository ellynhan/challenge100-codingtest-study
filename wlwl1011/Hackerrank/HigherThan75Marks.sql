SELECT name
FROM students
WHERE marks > 75
--이름의 끝 3글자 기준 정렬, 만약 같으면 id 순으로 정렬 
ORDER BY RIGHT(name,3),id  