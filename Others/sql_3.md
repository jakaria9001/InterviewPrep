## Movie Character
Write a SQL Query to find the movie_title and name of director (first and last names combined) who directed a movie that casted a role as 'SeanMaguire'.

## Output Schema:
```
director_name,movie_title
```
### NOTE:

Output column name has to match the given output schema.
Any name is the concatenation(without any delimiter) of first and last name if present
(E.g. if director_first_name is 'Alfred' and director_last_name is 'Hitchcock' then director_name is 'AlfredHitchcock')
### Example Output:
```
director_name, movie_title <br>
AlfredHitchcock, Vertigo <br>
```
### Schema Design:
![Movie Schema](
https://s3-us-west-2.amazonaws.com/ib-assessment-tests/problem_images/sql_course.jpg)

## Code: 
```
SELECT CONCAT(d.director_first_name, d.director_last_name) AS director_name, m.movie_title FROM  directors d
INNER JOIN movies_directors md ON md.director_id=d.director_id
INNER JOIN movies m ON m.movie_id=md.movie_id
INNER JOIN movies_cast mc ON mc.movie_id = m.movie_id
where mc.role =  'SeanMaguire';

```
