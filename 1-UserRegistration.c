#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 100

typedef struct {
    int userID;
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char mobile[MAX_LENGTH];
    char address[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    User newUser;
    newUser.userID = userCount + 1;

    printf("Enter name: ");
    fgets(newUser.name, MAX_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';

    printf("Enter email: ");
    fgets(newUser.email, MAX_LENGTH, stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0';

    printf("Enter mobile number: ");
    fgets(newUser.mobile, MAX_LENGTH, stdin);
    newUser.mobile[strcspn(newUser.mobile, "\n")] = '\0';

    printf("Enter address: ");
    fgets(newUser.address, MAX_LENGTH, stdin);
    newUser.address[strcspn(newUser.address, "\n")] = '\0';

    printf("Enter password: ");
    fgets(newUser.password, MAX_LENGTH, stdin);
    newUser.password[strcspn(newUser.password, "\n")] = '\0';

    users[userCount] = newUser;
    userCount++;
    printf("User registered successfully. UserID: %d\n", newUser.userID);
}

void loginUser() {
    char email[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter email: ");
    fgets(email, MAX_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].email, email) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome %s!\n", users[i].name);
            return;
        }
    }
    printf("Invalid email or password.\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
