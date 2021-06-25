#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[20];
    int idNum;
    float salary;
    struct Employee* next;
} employee;

void newSelection() {
    printf("Press any key to continue...\n");
    getchar();
    system("color 7");
    system("cls");
}

void showEmployees(employee *head)
{
    int counter = 1;
    employee *current = head;
    if(current == NULL){
        system("color 4");
        printf("There are no employees in the list!\n");
    }
    while(current != NULL)
    {
        printf("(%d) [%s]\tID Number: [%d]\tSalary: [%.02lf]\n",counter,current->name ,current->idNum, current->salary);
        current = current->next;
        counter++;
    }
    newSelection();
}

void addEmployee(employee **head)
{
    char name[20];
    employee *newWorker;
    newWorker = (employee*)malloc(sizeof(employee));
    printf("Enter new employee's name: ");
    gets(name);
    strcpy(newWorker->name, &name);
    int id = 0;
    printf("Enter a ID number: ");
    scanf("%d", &id);
    newWorker->idNum = id;
    float salary = 0;
    printf("Enter a salary: ");
    scanf("%f", &salary);
    newWorker->salary = salary;
    newWorker->next = NULL;
    if(*head == NULL) {
        *head = newWorker;
        system("color A");
        printf("Employee was added!\n");
        getchar();
        newSelection();
        return;
    }
    employee *current = *head;
    while(current != NULL){
        if(current->idNum > newWorker->idNum)
        {
            newWorker->next = *head;
            *head = newWorker;
            break;
        }
        else if(current->idNum < newWorker->idNum && current->next == NULL)
        {
            current->next = newWorker;
            break;
        }
        else if(current->idNum < newWorker->idNum && current->next->idNum > newWorker->idNum)
        {
            newWorker->next = current->next;
            current->next = newWorker;
            break;
        }
        current = current->next;
    }
    system("color A");
    printf("Employee was added!\n");
    getchar();
    newSelection();
    return;
}

void removeEmployee(employee **head)
{
    employee *current = *head;
    if(current == NULL)
    {
        system("color 4");
        printf("There are no employees in the list!\n");
        newSelection();
        return;
    }
    employee *worker;
    int id = 0;
    printf("Enter employee's ID number: ");
    scanf("%d", &id);
    if(current->idNum == id){
        system("color A");
        printf("[%s] ID Number: [%d] was removed!\n", current->name, current->idNum);
        worker = head;
        *head = current->next;
        free(worker);
        getchar();
        newSelection();
        return;
    }
    while(current->next != NULL) {
        worker = current->next;
        if(worker->idNum == id && worker->next != NULL){
            current->next = worker->next;
            system("color A");
            printf("[%s] ID Number: [%d] was removed!\n", worker->name, worker->idNum);
            free(worker);
            getchar();
            newSelection();
            return;
        } else if(worker->idNum == id && worker->next == NULL) {
            current->next = NULL;
            system("color A");
            printf("[%s] ID Number: [%d] was removed!\n", worker->name, worker->idNum);
            free(worker);
            getchar();
            newSelection();
            return;
        }
        current = current->next;
    }
    system("color 4");
    printf("There is no employee in the list with that ID number!\n");
    getchar();
    newSelection();
}


int main()
{
    system("title Workers Management System");
    system("MODE con:cols=201 lines=50");
    employee *head = NULL;
    int selection = 0;
    char buffer[20];
    do {
        selection = 0;

        printf("         _     _  _______  ______    ___   _  _______  ______    _______    __   __  _______  __    _  _______  _______  _______  __   __  _______  __    _  _______ \n");
        printf("        | | _ | ||       ||    _ |  |   | | ||       ||    _ |  |       |  |  |_|  ||   _   ||  |  | ||   _   ||       ||       ||  |_|  ||       ||  |  | ||       |\n");
        printf("        | || || ||   _   ||   | ||  |   |_| ||    ___||   | ||  |  _____|  |       ||  |_|  ||   |_| ||  |_|  ||    ___||    ___||       ||    ___||   |_| ||_     _|\n");
        printf("        |       ||  | |  ||   |_||_ |      _||   |___ |   |_||_ | |_____   |       ||       ||       ||       ||   | __ |   |___ |       ||   |___ |       |  |   |  \n");
        printf("        |       ||  |_|  ||    __  ||     |_ |    ___||    __  ||_____  |  |       ||       ||  _    ||       ||   ||  ||    ___||       ||    ___||  _    |  |   |  \n");
        printf("        |   _   ||       ||   |  | ||    _  ||   |___ |   |  | | _____| |  | ||_|| ||   _   || | |   ||   _   ||   |_| ||   |___ | ||_|| ||   |___ | | |   |  |   |  \n");
        printf("        |__| |__||_______||___|  |_||___| |_||_______||___|  |_||_______|  |_|   |_||__| |__||_|  |__||__| |__||_______||_______||_|   |_||_______||_|  |__|  |___|  \n");
        printf("                                                           _______  __   __  _______  _______  _______  __   __                                                      \n");
        printf("                                                          |       ||  | |  ||       ||       ||       ||  |_|  |\n");
        printf("                                                          |  _____||  |_|  ||  _____||_     _||    ___||       |\n");
        printf("                                                          | |_____ |       || |_____   |   |  |   |___ |       |\n");
        printf("                                                          |_____  ||_     _||_____  |  |   |  |    ___||       |\n");
        printf("                                                           _____| |  |   |   _____| |  |   |  |   |___ | ||_|| |\n");
        printf("                                                          |_______|  |___|  |_______|  |___|  |_______||_|   |_|\n");


        printf("Enter a Option:\n"
               "1- Add an Employee\n"
               "2- Remove an Employee\n"
               "3- Show All Employees\n"
               "9- Exit\n"
               "Select your Option: ");
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                gets(buffer);
                addEmployee(&head);
                break;
            case 2:
                gets(buffer);
                removeEmployee(&head);
                break;
            case 3:
                gets(buffer);
                showEmployees(head);
                break;
            case 9:
                printf("Bye bye :)\n");
                break;
            default:
                system("cls");
                printf("Wrong input!\n");;
        }
    }while(selection != 9);
    return 0;
}