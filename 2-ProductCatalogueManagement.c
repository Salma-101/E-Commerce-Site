#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for rand() function
#include <string.h>
#include <time.h> // Include time.h for seeding the rand() function

#define MAX_PRODUCTS 100
#define ID_LENGTH 6

// Structure to store product information
struct Product {
    char id[ID_LENGTH + 1]; // Product ID
    char name[50];          // Product Name
    float price;            // Product Price
    int quantity;           // Product Quantity
};

struct Product products[MAX_PRODUCTS]; // Array to store product records
int numProducts = 0;                   // Variable to keep track of the number of products

// Function to generate a unique product ID
void generateProductID(char *id) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int len = strlen(chars);
    for (int i = 0; i < ID_LENGTH; ++i) {
        id[i] = chars[rand() % len];
    }
    id[ID_LENGTH] = '\0'; // Null-terminate the string
}

// Function to add a new product to the catalogue
void addProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    struct Product newProduct;

    printf("Enter product name: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove trailing newline if present

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    getchar(); // Consume newline left in input buffer

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    getchar(); // Consume newline left in input buffer

    generateProductID(newProduct.id);

    products[numProducts++] = newProduct;

    printf("Product added successfully. Product ID: %s\n", newProduct.id);
}

// Function to display product details
void displayProducts() {
    if (numProducts == 0) {
        printf("No products available in the catalogue.\n");
        return;
    }

    printf("Product Catalogue:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < numProducts; ++i) {
        printf("%-10s %-30s $%-9.2f %-10d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

// Function to delete a product from the catalogue
void deleteProduct() {
    char id[ID_LENGTH + 1];
    printf("Enter the product ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0; // Remove trailing newline if present

    for (int i = 0; i < numProducts; ++i) {
        if (strcmp(products[i].id, id) == 0) {
            for (int j = i; j < numProducts - 1; ++j) {
                products[j] = products[j + 1];
            }
            numProducts--;
            printf("Product with ID %s deleted successfully.\n", id);
            return;
        }
    }
    printf("Product with ID %s not found.\n", id);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int choice;

    do {
        printf("\nProduct Management Menu:\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left in input buffer

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
