## The Short Straw
Write a SQL query to display the department_location and minimum salary for the least paid in each department location.

## Output Schema:
```
department_location, min_sal
```
### NOTE:

Output column name has to match the given output schema.

### Example Output:
```
department_location, min_sal
India, 11000
Singapore, 12000
```


### Schema Design:
![Department Schema](https://s3-us-west-2.amazonaws.com/ib-assessment-tests/problem_images/SQL_EmployeesDB.png)

## Code: 
```

select d.department_location , min(s.salary) as min_sal from departments d
INNER JOIN  salaries s group by d.department_location;


```
