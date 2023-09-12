SELECT DISTINCT city
FROM station
WHERE city NOT LIKE 'a%'
AND city NOT LIKE '%a'
AND city NOT LIKE 'e%'
AND city NOT LIKE '%e'
AND city NOT LIKE 'i%'
AND city NOT LIKE '%i'
AND city NOT LIKE 'o%'
AND city NOT LIKE '%o'
AND city NOT LIKE 'u%'
AND city NOT LIKE '%u'