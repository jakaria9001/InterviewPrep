// Q2 : Student details and marks average : 

#include <stdio.h>


struct Student {
    int roll_no;
    char name[30];
    int age;
    float c_marks, maths_marks, phy_marks;
};

//main function
int main() {
	
    struct Student students[5];
    
    // Input details of students : 
    for(int i=0; i<5; i++){
	    printf("Enter details of Student %d :\n",i+1);
        
        printf("Enter roll no. :\n");
        scanf("%d", &students[i].roll_no);
        printf("Enter name :\n");
        scanf("%s",students[i].name);
        printf("Enter Age :\n");
        scanf("%d", &students[i].age);
        
        printf("Enter C marks :\n");
        scanf("%f", &students[i].c_marks);
        printf("Enter Maths marks :\n");
        scanf("%f", &students[i].maths_marks);
        printf("Enter Physics marks :\n");
        scanf("%f", &students[i].phy_marks);
        printf("\n");
    }
    // Display details and average marks : 
    for(int i=0; i<5; i++) {
	    printf("Student %d Details : \n",i+1);
	    
	    printf("Roll No - %d\n", students[i].roll_no);
	    printf("Name - %s\n", students[i].name);
	    printf("Age - %d\n", students[i].age);
	    
	    printf("Marks in C - %f\n", students[i].c_marks);
	    
	    printf("Marks in Maths - %f\n", students[i].maths_marks);
	    
	    printf("Marks in Physics - %f\n", students[i].phy_marks);
	    
	    float average = (students[i].c_marks + students[i].maths_marks + students[i].phy_marks)/3;
	    printf("Average Marks: %f\n\n", average);
	}
  return 0;
}