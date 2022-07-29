-- write a SQL query to list the names of all people who
-- starred in a movie in which Kevin Bacon also starred

SELECT DISTINCT(name) FROM people, stars, movies
WHERE people.id = stars.person_id
AND movies.id = stars.movie_id
AND movies.id IN
(SELECT movies.id FROM movies, people, stars
WHERE people.id = stars.person_id
AND movies.id = stars.movie_id
AND birth = 1958
AND name = "Kevin Bacon")
EXCEPT
SELECT name FROM people
WHERE name = "Kevin Bacon";