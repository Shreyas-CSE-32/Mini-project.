#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct Student {
    int id;
    char name[1000];
    int age;
    char dob[20];
    char address[1000];
    char branch[25];
    char div[10];
    char course[50];

    struct Student *next;
}; 

struct Student *head = NULL; 

void createStudent() {
    struct Student *newStud = (struct Student *)malloc(sizeof(struct Student));
    struct Student *p = head; 

    if(newStud == NULL) {
        printf("Out of memory space \n");
        return;
    }

    printf("Enter student name : \n");
    scanf("%s", newStud->name);
    printf("Enter roll number : \n");
    scanf("%d", &newStud->id);
    printf("Enter date of birth : \n");
    scanf("%s", newStud->dob);
    printf("Enter age of the student : \n ");
    scanf("%d", &newStud->age);
    printf("Enter branch of the student: \n");
    scanf("%s", newStud->branch);
    printf("Enter course of the student : \n");
    scanf("%s", newStud->course);
    printf("Enter division of the student : \n");
    scanf("%s", newStud->div);

    FILE *fp = fopen("main.csv", "a") ;
    fprintf(fp, "%d,", newStud->id) ;  
    fprintf(fp, "%s,", newStud->name) ;
    fprintf(fp, "%d,", newStud->age) ; 
    fprintf(fp, "%s,",newStud->course) ; 
    fprintf(fp, "%s,", newStud->branch); 
    fprintf(fp, "%s,", newStud->div) ; 
    fprintf(fp, "%s",newStud->dob) ; 
 
   
    if(head == NULL) {
        head = newStud; 
    } else {
        while(p->next != NULL) {
            p = p->next; 
        }
        p->next = newStud; 
        newStud->next = NULL; 
    }
}

void search() 
{
    FILE *fp = fopen("main.csv", "r") ; 
     char buffer[100];
     char roll[100]; 
    printf("Enter name of the student to search : \n") ; 
    scanf("%s", roll);  
    printf("Information of the student with roll number : %s\n", roll) ; 
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
       buffer[strcspn(buffer, "\n")] = '\0';
        if (strstr(buffer, roll) != NULL) { 
            printf("%s\n", buffer);
           
        }
        printf("\n") ; 
    }


}

int main() {
    
    search() ; 
    return 0;
}
