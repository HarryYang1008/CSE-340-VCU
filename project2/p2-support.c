#define _GNU_SOURCE		//strcasestr is a nonstandard GNU extension, 
//we need this line while serching for matching last name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"



void create_record (char *ID, char *first_name, char *last_name, char *email, double salary, date hire_date, dataBase_ptr db)// specify parameters. Clues are in the initalize function.
{

  //define function. Clues are in the initalize function
  //do not forget to increase total number of employees in the database
    strcpy(db->emp[db->total].ID, ID);
    strcpy(db->emp[db->total].first_name, first_name);
    strcpy(db->emp[db->total].last_name, last_name);
    strcpy(db->emp[db->total].email, email);
    db->emp[db->total].salary = salary;
    db->emp[db->total].hire_date = hire_date;
    db->total++;
}


void print_title ()// you can keep this fuction or remove if needed
{
  printf ("No. ID    Name          Email        Salary     Hire Date\n");
  printf ("--- ----- ------------- ------------ ---------- --/--/----\n");

}

void display_all_employees(dataBase_ptr db) {
    print_title();
    for (int i = 0; i < db->total; ++i) {
        employee e = db->emp[i];

        char name_combined[14];
        snprintf(name_combined, sizeof(name_combined), "%s %s", e.first_name, e.last_name);

        printf("%-3d %-5s %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n",
               i, e.ID,
               name_combined,
               e.email,
               e.salary,
               e.hire_date.month, e.hire_date.day, e.hire_date.year);
    }
}


void sort_by_id(dataBase_ptr db)
{
    for (int i = 0; i < db->total - 1; i++) {
        for (int j = i + 1; j < db->total; j++) {
            if (strcmp(db->emp[i].ID, db->emp[j].ID) > 0) {
                employee temp = db->emp[i];
                db->emp[i] = db->emp[j];
                db->emp[j] = temp;
            }
        }
    }
}

void sort_by_hire_date(dataBase_ptr db)
{
    for (int i = 0; i < db->total - 1; i++) {
        for (int j = i + 1; j < db->total; j++) {
            if (db->emp[i].hire_date.year > db->emp[j].hire_date.year ||
                (db->emp[i].hire_date.year == db->emp[j].hire_date.year &&
                 db->emp[i].hire_date.month > db->emp[j].hire_date.month) ||
                (db->emp[i].hire_date.year == db->emp[j].hire_date.year &&
                 db->emp[i].hire_date.month == db->emp[j].hire_date.month &&
                 db->emp[i].hire_date.day > db->emp[j].hire_date.day)) {
                employee temp = db->emp[i];
                db->emp[i] = db->emp[j];
                db->emp[j] = temp;
            }
        }
    }
}


void search_employee_and_display(dataBase_ptr db) {
    char id[idSIZE];
    char formatted_id[idSIZE];
    printf("Enter the ID you are searching for:\n");
    scanf("%s", id);

    int id_num = atoi(id);
    snprintf(formatted_id, sizeof(formatted_id), "%05d", id_num);
    for (int i = 0; i < db->total; ++i) {
        if (strcmp(db->emp[i].ID, formatted_id) == 0) {
            employee *emp = &db->emp[i];

            print_title();
            char name_combined[14];
            snprintf(name_combined, sizeof(name_combined), "%s %s", emp->first_name, emp->last_name);

            printf("%-3d %-5s %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n",
                   i, emp->ID, name_combined, emp->email,
                   emp->salary, emp->hire_date.month, emp->hire_date.day, emp->hire_date.year);
            return;
        }
    }

    printf("Employee with ID %s not found.\n", id);
}


void search_employee_by_lastname(dataBase_ptr db, const char *lastname) {
    print_title();
    for (int i = 0; i < db->total; ++i) {
        if (strcasestr(db->emp[i].last_name, lastname)) {
            employee e = db->emp[i];

            char name_combined[14];
            snprintf(name_combined, sizeof(name_combined), "%s %s", e.first_name, e.last_name);

            printf("%-3d %-5s %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n",
                   i, e.ID, name_combined, e.email, e.salary,
                   e.hire_date.month, e.hire_date.day, e.hire_date.year);
        }
    }
}



void delete_employee_by_id(dataBase_ptr db, const char *id) {
    for (int i = 0; i < db->total; ++i) {
        if (strcmp(db->emp[i].ID, id) == 0) {
            employee deleted_employee = db->emp[i];

            for (int j = i; j < db->total - 1; j++) {
                db->emp[j] = db->emp[j + 1];
            }
            db->total--;

            print_title();

            char name_combined[14];
            snprintf(name_combined, sizeof(name_combined), "%s %s", deleted_employee.first_name, deleted_employee.last_name);

            printf("%-3d %-5s %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n",
                   i, deleted_employee.ID,
                   name_combined, deleted_employee.email, deleted_employee.salary,
                   deleted_employee.hire_date.month, deleted_employee.hire_date.day, deleted_employee.hire_date.year);
            return;
        }
    }
    printf("Employee with ID %s not found.\n", id);
}



void free_database(dataBase_ptr db)
{
    if (db->emp) {
        free(db->emp);
    }
    free(db);
}

//fix save function. Save array into file: database_updated in the same format with the 
//database file.
void save (dataBase_ptr db)// this function is for saving the database into a text file
{
  FILE *dbfu;
  dbfu = fopen ("database_updated", "w");//open an Std IO file to write into
  if (dbfu == NULL)
  {
    printf ("File cannot be created");
    return;
  }
  for (int i = 0; i < db->total; i++)
  {
      fprintf(dbfu, "%s %s %s %s %.2f %d/%d/%d\n",
              db->emp[i].ID, db->emp[i].first_name, db->emp[i].last_name,
              db->emp[i].email, db->emp[i].salary,
              db->emp[i].hire_date.month, db->emp[i].hire_date.day, db->emp[i].hire_date.year);

  }

  fclose (dbfu);//close file after writing
  return;

}

void display_menu (struct DataBase *db)
{
  int input = 0;
  while (input != 8)
  {
    puts
      ("\n**************************************************************");
    printf
      (  "********** Employee Database - Total Employees: %03d **********\n", db->total
      );//you need to fix this line so that total employees in the database is printed
    puts
      ("**************************************************************\n");
    puts ("Choose one of the menu options below:");
    puts ("1. Sort by ID");
    puts ("2. Sort by Hire Date");
    puts ("3. Display all employees");
    puts ("4. Search employees by ID");
    puts ("5. Search employees by Last Name");
    puts ("6. Delete employee by ID");
    puts ("7. Save");
    puts ("8. Exit");

    scanf ("%d", &input);

    switch (input)
    {
      case 1:
        //call the function you defined for sorting by ID
        sort_by_id(db);
        break;
      case 2:
        //call the function you defined for sorting by Hire Date
        sort_by_hire_date(db);
        break;
      case 3:
        //call the function you defined for displaying employees
        display_all_employees(db);
        break;
      case 4:
        //call the function you defined for searching employees by ID
          search_employee_and_display(db);
          break;
      case 5:
        //call the function you defined for searching employees by Last Name
      {
          char lastname[nameSIZE];
          printf("Enter the last name you are searching for:\n");
          scanf("%s", lastname);
          search_employee_by_lastname(db, lastname);
          break;
      }
      case 6:
        //call the function you defined for deleting employee by ID
      {
          char id[idSIZE];
          char formatted_id[idSIZE];
          printf("Enter the ID you are searching for:\n");
          scanf("%s", id);
          int id_num = atoi(id);
          snprintf(formatted_id, sizeof(formatted_id), "%05d", id_num);
          delete_employee_by_id(db, formatted_id);
          break;
      }
      case 7:
        save (db);
        break;
      case 8:
        //free all allocated memory
        free_database(db);
        printf("Bye!\n");
        break;

    }
  }

}
