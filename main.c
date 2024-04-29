#include<stdio.h>
#include<stdlib.h>

struct Student {
    int id ; 
    char name[1000] ; 
    int age ;
    char dob[20] ; 
    char *address[1000]  ;
    char branch[25]  ; 
    char div[10] ;
    char course[50] ; 

    struct Student *next;   

}; 
struct Student *head = NULL; 
void createStudent() 
{
    struct Student *newStud = (struct Student *)malloc(sizeof(struct Student)) ;
    struct Student *p = head; 

    if(newStud == NULL) 
    {
        printf("Out of memory space \n") ; 
    }

    printf("Enter student name : \n") ; 
    scanf("%s", &newStud->name) ; 
    printf("Enter roll number : \n") ; 
    scanf("%d", &newStud->id) ; 
    printf("Enter date of birth : \n") ;
    scanf("%s", &newStud->dob) ; 
    printf("Enter age of the student : \n ") ;
    scanf("%d", &newStud->age) ; 
    printf("Enter branch of the student: \n") ; 
    scanf("%s", &newStud->branch) ; 
    printf("Enter course of the student : \n") ;
    scanf("%s", &newStud->branch) ; 
    printf("Enter division of the student : \n") ;
    scanf("%S", &newStud->div) ; 

    if(head == NULL) 
    {
        head = newStud; 
    }
    else{
        while(p->next != NULL) 
        {
            p = p->next; 
        }
        p->next = newStud ; 
        newStud->next = NULL ; 
    }

}


int main()
{
   
}