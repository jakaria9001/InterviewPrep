## Problem Statement
Write a SQL query to print department name along with department wise average salary. The average salary should be rounded to 2 decimal places.

## Output Schema:
```
department_name,average_salary
```
### NOTE:

Output column name has to match the given output schema.

### Example Output:
```
department_name,average_salary
IT,15500
```
### Schema Design:
![Department Schema](https://s3.ap-south-1.amazonaws.com/scaler-production-domestic/public_assets/assets/000/000/265/original/Schema.png?1622099980)

## Code: 
```
/* SELECT D.deptname AS department_name, E. */

select  d.deptname department_name , cast(avg(e.salary) as decimal(10,2)) average_salary from department d
inner join employee e on d.deptid = e.deptid group by d.deptname order by average_salary;


```
