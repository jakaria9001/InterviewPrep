## Problem Statement
Write a SQL query to delete duplicate rows in employee table.

Output should be the employee schema with unique entries.

## Output Schema:
```
employee_id,employee_name,manager_id,department_id,salary,DOB
```
### NOTE:

Output column name has to match the given output schema.

### Example Output:
```
employee_id,employee_name,manager_id,department_id,salary,DOB 
1,emp 1,0,1,6000,1982-08-06
```
### Schema Design:
![Movie Schema](https://s3.ap-south-1.amazonaws.com/scaler-production-domestic/public_assets/assets/000/000/265/original/Schema.png?1622099980)

## Code: 
```
/* YOUR QUERY GOES HERE
   Example: SELECT * FROM EMPLOYEE; 


SELECT * FROM employee WHERE COUNT(*)=1;


With CTE_Duplicates as
   (select *, row_number() over(partition by * ) rownumber 
   from employee  )
   delete from CTE_Duplicates where rownumber!=1
   
employee_id,employee_name,manager_id,department_id,salary,DOB
*/
select * from employee ; 

```
