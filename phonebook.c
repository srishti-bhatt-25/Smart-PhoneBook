#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CONTACTS 50

struct Contact{
    char fname[31];
    char lname[31];
    char telep[15];
    char cellp[15];
}contacts[MAX_CONTACTS];

int last = 0;
void insert();
void delet();
void edit();
void search();
void list();
void sort();
void displayContact(struct Contact);

int main(){
    char choice;
    while(1){
        printf("\n--- Phone Book Menu ---\n");
        printf("[1] Insert Contact\n");
        printf("[2] Delete Contact\n");
        printf("[3] Edit Contact\n");
        printf("[4] Search Contact\n");
        printf("[5] List All Contacts\n");
        printf("[6] Sort Contacts\n");
        printf("[7] Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice){
            case '1': insert(); break;
            case '2': delet(); break;
            case '3': edit(); break;
            case '4': search(); break;
            case '5': list(); break;
            case '6': sort(); break;
            case '7': exit(0); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insert(){
    if (last >= MAX_CONTACTS){
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter first name: ");
    scanf("%s", contacts[last].fname);
    printf("Enter last name: ");
    scanf("%s", contacts[last].lname);
    printf("Enter telephone number: ");
    scanf("%s", contacts[last].telep);
    printf("Enter cellphone number: ");
    scanf("%s", contacts[last].cellp);

    last++;
    printf("Contact added successfully!\n");
}

void delet(){
    char fname[31], lname[31];
    printf("Enter first name of the contact to delete: ");
    scanf("%s", fname);
    printf("Enter last name of the contact to delete: ");
    scanf("%s", lname);

    for (int i = 0; i < last; i++){
        if (strcmp(contacts[i].fname, fname) == 0 && strcmp(contacts[i].lname, lname) == 0){
            for (int j = i; j < last - 1; j++){
                contacts[j] = contacts[j + 1];
            }
            last--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void edit(){
    char fname[31], lname[31];
    printf("Enter first name of the contact to edit: ");
    scanf("%s", fname);
    printf("Enter last name of the contact to edit: ");
    scanf("%s", lname);

    for (int i = 0; i < last; i++){
        if (strcmp(contacts[i].fname, fname) == 0 && strcmp(contacts[i].lname, lname) == 0){
            printf("Enter new first name: ");
            scanf("%s", contacts[i].fname);
            printf("Enter new last name: ");
            scanf("%s", contacts[i].lname);
            printf("Enter new telephone number: ");
            scanf("%s", contacts[i].telep);
            printf("Enter new cellphone number: ");
            scanf("%s", contacts[i].cellp);
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void search(){
    char fname[31];
    printf("Enter first name to search: ");
    scanf("%s", fname);

    for (int i = 0; i < last; i++){
        if (strcmp(contacts[i].fname, fname) == 0){
            displayContact(contacts[i]);
            return;
        }
    }
    printf("Contact not found!\n");
}


void list(){
    if (last == 0){
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < last; i++){
        printf("\nContact %d:\n", i + 1);
        displayContact(contacts[i]);
    }
}

void displayContact(struct Contact contact){
    printf("First Name: %s\n", contact.fname);
    printf("Last Name: %s\n", contact.lname);
    printf("Telephone: %s\n", contact.telep);
    printf("Cellphone: %s\n", contact.cellp);
}


void sort(){
    struct Contact temp;
    for (int i = 0; i < last - 1; i++){
        for (int j = i + 1; j < last; j++){
            if (strcmp(contacts[i].fname, contacts[j].fname) > 0){
                temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
    printf("Contacts sorted by first name.\n");
}