SELECT name FROM people, stars, movies
WHERE people.id = stars.person_id
AND movies.id = stars.movie_id
AND year = 2004
ORDER BY birth;