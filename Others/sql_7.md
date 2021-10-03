## Problem Statement
Write a SQL query to print oldest employee name department wise along with department name.

## Output Schema:
```
oldest_employee_name,department_name
```
### NOTE:

Output column name has to match the given output schema.

### Example Output:
```
oldest_employee_name,department_name
Rakesh,IT
```
### Schema Design:
![Department Schema](https://s3.ap-south-1.amazonaws.com/scaler-production-domestic/public_assets/assets/000/000/265/original/Schema.png?1622099980)

## Code: 
```
/* YOUR QUERY GOES HERE
   Example: SELECT * FROM EMPLOYEE; 
*/
SELECT e.empname oldest_employee_name, d.deptname department_name FROM employee e 
INNER JOIN department d ON e.deptid=d.deptid 
group by d.deptname order by e.dob DESC;

```
