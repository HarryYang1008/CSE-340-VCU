////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.h
// Description    : Header file for project2 
// Author         : ***Type Author Name ***
// Date           : ***Type the date Date you completed***
// Notes          : ***Type bug fixes/other with dates for your records 

#ifndef P2Header //To prevent double inclusion of header
#define P2Header //To prevent double inclusion of header

#include <stdio.h>
#define byID 1
#define byNAME 2
#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 10
#define emailSIZE 20


typedef struct date// do not modify
{
  int day; 
  int month;
  int year;
}date;

typedef struct Employee
{
    char ID[idSIZE];
    char first_name[nameSIZE];
    char last_name[nameSIZE];
    char email[emailSIZE];
    double salary;
    date hire_date;
} employee, *employee_ptr;

typedef struct DataBase
{
  //a pointer to first element of empoloyee array
  employee *emp;
  //number of employees in database
  int total;
}*dataBase_ptr;

// Functional Prototypes

// Function     : initialize
// Description  : This function creates an array in the database
//                then initalializes each array elemet with the data 
//                in the given file
// Inputs       : a pointer to DataBase struct
// Output       : none
void initialize (dataBase_ptr db);

//Write formal comments for each function header. 
//In the same format with the initialize function
void create_record(char *ID, char *first_name, char *last_name, char *email, double salary, date hire_date, dataBase_ptr db);
//specify parameters types. Clues are in the initalize function.

void print_title ();

void display_menu (dataBase_ptr);

//other function headers here


void display_all_employees(dataBase_ptr db);
void sort_by_id(dataBase_ptr db);
void sort_by_hire_date(dataBase_ptr db);
void search_employee_and_display(dataBase_ptr db);
void search_employee_by_lastname(dataBase_ptr db, const char *lastname);
void delete_employee_by_id(dataBase_ptr db, const char *id);
void free_database(dataBase_ptr db);




void save(dataBase_ptr);


#endif //To prevent double inclusion of header
