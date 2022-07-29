-- write a SQL query to list the titles of all movies
-- in which both Johnny Depp and Helena Bonham Carter starred

SELECT title FROM movies, people, stars
WHERE people.id = stars.person_id
AND movies.id = stars.movie_id
AND name = "Helena Bonham Carter"
INTERSECT
SELECT title FROM movies, people, stars
WHERE people.id = stars.person_id
AND movies.id = stars.movie_id
AND name = "Johnny Depp";