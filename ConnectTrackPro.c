#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_ENTRIES 100
#define MAX_REMINDERS 50
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define ADDRESS_LENGTH 100
#define ENTRY_LENGTH 200
#define DATE_LENGTH 12
#define TIME_LENGTH 6
#define CATEGORY_LENGTH 10
#define AMPM_LENGTH 3

typedef struct 
{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char address[ADDRESS_LENGTH];
    char category[CATEGORY_LENGTH]; 
} Contact;

typedef struct {
    char entry[ENTRY_LENGTH];
} DiaryEntry;

typedef struct {
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    char am_pm[AMPM_LENGTH];
    char description[ENTRY_LENGTH];
} Reminder;

Contact contacts[MAX_CONTACTS];
DiaryEntry diary[MAX_ENTRIES];
Reminder reminders[MAX_REMINDERS];

int contactCount = 0;
int diaryCount = 0;
int reminderCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[contactCount].name);
    printf("Enter phone: ");
    scanf("%s", contacts[contactCount].phone);
    printf("Enter email: ");
    scanf("%s", contacts[contactCount].email);
    printf("Enter address: ");
    scanf("%s", contacts[contactCount].address);
    
    
    printf("Enter category (Friend, Family, Work, Others): ");
    scanf("%s", contacts[contactCount].category);
    
    contactCount++;
    printf("Contact added successfully!\n");
}

void updateContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to update: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Updating contact: %s\n", contacts[i].name);
            printf("Enter new phone: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new email: ");
            scanf("%s", contacts[i].email);
            printf("Enter new address: ");
            scanf("%s", contacts[i].address);
            printf("Enter new category (Friend, Family, Work, Others): ");
            scanf("%s", contacts[i].category); 
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void viewContacts() {
    printf("Contact:\n");

    for (int i = 0; i < contactCount; i++) {
            printf("Name: %s, Phone: %s, Email: %s, Address: %s, Category: %s\n",
                   contacts[i].name, contacts[i].phone, contacts[i].email,
                   contacts[i].address, contacts[i].category);
            return;
        }
    }


void searchContactByCriterion() {
    int choice;
    char input[ADDRESS_LENGTH]; 
    printf("\nSearch Contact By:\n");
    printf("1. Name\n2. Phone\n3. Email\n4. Address\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value to search: ");
    scanf("%s", input);

    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if ((choice == 1 && strstr(contacts[i].name, input) != NULL) ||
            (choice == 2 && strstr(contacts[i].phone, input) != NULL) ||
            (choice == 3 && strstr(contacts[i].email, input) != NULL) ||
            (choice == 4 && strstr(contacts[i].address, input) != NULL)) {
            printf("Name: %s, Phone: %s, Email: %s, Address: %s, Category: %s\n",
                   contacts[i].name, contacts[i].phone, contacts[i].email,
                   contacts[i].address, contacts[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found matching the given criteria!\n");
    }
}

void sortContactsByCategory() {
    for (int i = 0; i < contactCount - 1; i++) {
        for (int j = i + 1; j < contactCount; j++) {
            if (strcmp(contacts[i].category, contacts[j].category) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
    printf("Contacts sorted by category successfully!\n");
}

void addDiaryEntry() {
    if (diaryCount >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    printf("Enter diary entry: ");
    scanf(" %s", diary[diaryCount].entry); 
    diaryCount++;
    printf("Diary entry added successfully!\n");
}

void deleteDiaryEntry() {
    int entryNumber;
    printf("Enter the diary entry number to delete: ");
    scanf("%d", &entryNumber);
    if (entryNumber <= 0 || entryNumber > diaryCount) {
        printf("Invalid entry number!\n");
        return;
    }
    for (int i = entryNumber - 1; i < diaryCount - 1; i++) {
        strcpy(diary[i].entry, diary[i + 1].entry);
    }
    diaryCount--;
    printf("Diary entry deleted successfully!\n");
}

void viewDiaryEntries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < diaryCount; i++) {
        printf("Entry %d: %s\n", i + 1, diary[i].entry);
    }
}

void addReminder() {
    if (reminderCount >= MAX_REMINDERS) {
        printf("Reminders list is full!\n");
        return;
    }
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", reminders[reminderCount].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", reminders[reminderCount].time);
    printf("Enter AM/PM: ");
    scanf("%s", reminders[reminderCount].am_pm);
    printf("Enter description: ");
    scanf(" %s", reminders[reminderCount].description);
    reminderCount++;
    printf("Reminder added successfully!\n");
}
void updateReminder() {
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    printf("Enter the date of the reminder to update (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter the time of the reminder to update (HH:MM): ");
    scanf("%s", time);

    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].date, date) == 0 && strcmp(reminders[i].time, time) == 0) {
            printf("Updating reminder: %s at %s %s\n", reminders[i].date, reminders[i].time, reminders[i].am_pm);
            printf("Enter new date (DD/MM/YYYY): ");
            scanf("%s", reminders[i].date);
            printf("Enter new time (HH:MM): ");
            scanf("%s", reminders[i].time);
            printf("Enter new AM/PM: ");
            scanf("%s", reminders[i].am_pm);
            printf("Enter new description: ");
            scanf("%s", reminders[i].description);
            printf("Reminder updated successfully!\n");
            return;
        }
    }
    printf("Reminder not found!\n");
}

void deleteReminder() {
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    printf("Enter the date of the reminder to delete (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter the time of the reminder to delete (HH:MM): ");
    scanf("%s", time);

    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].date, date) == 0 && strcmp(reminders[i].time, time) == 0) {
            for (int j = i; j < reminderCount - 1; j++) {
                reminders[j] = reminders[j + 1];
            }
            reminderCount--;
            printf("Reminder deleted successfully!\n");
            return;
        }
    }
    printf("Reminder not found!\n");
}

void viewTodaysReminders() {
    char today[DATE_LENGTH];
    printf("Enter today's date (DD/MM/YYYY): ");
    scanf("%s", today);

    printf("Today's Reminders:\n");
    int found = 0;
    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].date, today) == 0) {
            printf("Time: %s %s, Description: %s\n", reminders[i].time, reminders[i].am_pm, reminders[i].description);
            found = 1;
        }
    }
    if (!found) {
        printf("No reminders for today!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. Update Contact\n");
        printf("3. Delete Contact\n");
        printf("4. View Contacts\n");
        printf("5. Search Contact by criterion\n");
        printf("6. Sort Contacts by Category\n");
        printf("7. Add Diary Entry\n");
        printf("8. Delete Diary Entry\n");
        printf("9. View Diary Entries\n");
        printf("10. Add Reminder/Meeting\n");
        printf("11. Update Reminder\n");
        printf("12. Delete Reminder\n");
        printf("13. View Today's Reminders/Meetings\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); 
            break;
            case 2: updateContact(); 
            break;
            case 3: deleteContact(); 
            break;
            case 4: viewContacts();
            break;
            case 5: searchContactByCriterion(); 
            break;
            case 6: sortContactsByCategory(); 
            break;
            case 7: addDiaryEntry(); 
            break;
            case 8: deleteDiaryEntry(); 
            break;
            case 9: viewDiaryEntries(); 
            break;
            case 10: addReminder(); 
            break;
            case 11: updateReminder(); 
            break;
            case 12: deleteReminder(); 
            break;
            case 13: viewTodaysReminders(); 
            break;
            case 14: printf("Exiting...\n"); 
            break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 14);

    return 0;
}
