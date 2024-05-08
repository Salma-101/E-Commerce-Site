#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define ID_LENGTH 6

// Structure to store user information
struct User {
    char name[50];
    char email[50];
    char mobile[15];
    char address[100];
    char userID[ID_LENGTH + 1]; // Add 1 for null terminator
};

struct User users[MAX_USERS]; // Array to store user records
int numUsers = 0; // Variable to keep track of the number of registered users

// Function to generate a unique user ID
void generateUserID(char *userID) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int len = strlen(chars);
    for (int i = 0; i < ID_LENGTH; ++i) {
        userID[i] = chars[rand() % len];
    }
    userID[ID_LENGTH] = '\0'; // Null-terminate the string
}

// Function to register a new user
void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct User newUser;

    printf("Enter your name: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0; // Remove trailing newline if present

    printf("Enter your email: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = 0; // Remove trailing newline if present

    printf("Enter your mobile number: ");
    fgets(newUser.mobile, sizeof(newUser.mobile), stdin);
    newUser.mobile[strcspn(newUser.mobile, "\n")] = 0; // Remove trailing newline if present

    printf("Enter your address: ");
    fgets(newUser.address, sizeof(newUser.address), stdin);
    newUser.address[strcspn(newUser.address, "\n")] = 0; // Remove trailing newline if present

    generateUserID(newUser.userID);

    users[numUsers++] = newUser;

    printf("User registered successfully. Your User ID is: %s\n", newUser.userID);
}

// Function to allow user login
void loginUser() {
    char userID[ID_LENGTH + 1];
    printf("Enter your User ID to login: ");
    fgets(userID, sizeof(userID), stdin);
    userID[strcspn(userID, "\n")] = 0; // Remove trailing newline if present

    for (int i = 0; i < numUsers; ++i) {
        if (strcmp(users[i].userID, userID) == 0) {
            printf("Welcome back, %s!\n", users[i].name);
            return;
        }
    }

    printf("User ID not found. Please register first.\n");
}

int main() {
    int choice;

    do {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left in input buffer

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
