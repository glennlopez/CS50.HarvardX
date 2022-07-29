SELECT name FROM directors, ratings, people, movies
WHERE people.id = directors.person_id
AND movies.id = directors.movie_id
AND ratings.movie_id = movies.id
AND rating >= 9;