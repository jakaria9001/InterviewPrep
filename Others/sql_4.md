## Problem Statement
Write and sql to find out the employees who are getting more sal than average sal of their dept. Make sure you use the column names as written in the table. Return ENAME, SAL and DEPTNO.

## Table Name: emp

|EMPNO |	ENAME	| JOB |	MGR |	HIREDATE |	SAL |	COMM | DEPTNO |
| --- | ---  | ---  | ---  | ---  | ---  | ---  | --- | 
| 7369 | 	SMITH | CLERK | 7902 | 1980-12-17 | 800 |	NULL |	20 |
| 7499	 | ALLEN | 	SALESMAN | 	7698 | 	1981-02-20	 | 1600	 | 300	 | 30 | 

## Code: 
```
SELECT ename, sal, deptno FROM emp as e1 where SAL > (SELECT AVG(SAL) FROM emp e2 where e1.deptno=e2.deptno) ;
```
