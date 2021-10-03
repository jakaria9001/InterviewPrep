## Employee Salary
Consider the table given as -


## Table Name: employeesalary

id	dept	salary
12	IT	1000
14	HR	200
15	TECH	300
18	IT	700
Write a SQL query to return the rows where the department is HR and have a salary less than 500 or more than 1000.

## Output Schema:
```
id	dept	salary
```
### NOTE:

Output column name has to match the given output schema.

## Code: 
```
/* YOUR QUERY GOES HERE
   Example: SELECT * FROM EMPLOYEE; 
*/
select * from employeesalary where dept='HR' and (salary<500 or salary>1000);

```
