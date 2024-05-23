#include <stdio.h>
#include <string.h>

#define MAX_CART_ITEMS 100
#define MAX_PRODUCTS 100
#define MAX_LENGTH 100

typedef struct {
    int productID;
    char name[MAX_LENGTH];
    float price;
    int quantity;
} CartItem;

CartItem cart[MAX_CART_ITEMS];
int cartItemCount = 0;

typedef struct {
    int productID;
    char name[MAX_LENGTH];
    float price;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void viewProducts() {
    printf("Available Products:\n");
    printf("%-5s %-25s %-10s\n", "ID", "Name", "Price");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-25s $%-9.2f\n", products[i].productID, products[i].name, products[i].price);
    }
    printf("\n");
}

void addToCart() {
    int productID, quantity;
    printf("Enter product ID to add to cart: ");
    scanf("%d", &productID);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    getchar(); // Consume the newline character left by scanf

    for (int i = 0; i < productCount; i++) {
        if (products[i].productID == productID) {
            // Check if the product is already in the cart
            for (int j = 0; j < cartItemCount; j++) {
                if (cart[j].productID == productID) {
                    cart[j].quantity += quantity;
                    printf("Updated product quantity in cart.\n\n");
                    return;
                }
            }

            // If the product is not in the cart, add it as a new item
            CartItem newItem;
            newItem.productID = products[i].productID;
            strcpy(newItem.name, products[i].name);
            newItem.price = products[i].price;
            newItem.quantity = quantity;

            cart[cartItemCount] = newItem;
            cartItemCount++;
            printf("Product added to cart.\n\n");
            return;
        }
    }
    printf("Product not found.\n\n");
}

void viewCart() {
    float total = 0.0;
    printf("Shopping Cart:\n");
    printf("%-5s %-25s %-10s %-10s %-10s\n", "ID", "Name", "Price", "Quantity", "Total");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < cartItemCount; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        printf("%-5d %-25s $%-9.2f %-10d $%-9.2f\n",
               cart[i].productID, cart[i].name, cart[i].price, cart[i].quantity, itemTotal);
        total += itemTotal;
    }
    printf("-----------------------------------------------------------------------\n");
    printf("%-5s %-25s %-10s %-10s $%-9.2f\n", "", "", "", "Total:", total);
    printf("\n");
}

void deleteFromCart() {
    int productID;
    printf("Enter product ID to remove from cart: ");
    scanf("%d", &productID);
    getchar(); // Consume the newline character left by scanf

    for (int i = 0; i < cartItemCount; i++) {
        if (cart[i].productID == productID) {
            for (int j = i; j < cartItemCount - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cartItemCount--;
            printf("Product removed from cart.\n\n");
            return;
        }
    }
    printf("Product not found in cart.\n\n");
}

void checkout() {
    float total = 0.0;
    for (int i = 0; i < cartItemCount; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    printf("Total Amount: $%.2f\n", total);
    printf("Checkout successful. Thank you for your purchase!\n");
    cartItemCount = 0;  // Clear the cart after checkout
    printf("\n");
}

int main() {
    // Actual products for demonstration
    products[0] = (Product){1, "Apple iPhone 14", 999.99};
    products[1] = (Product){2, "Samsung Galaxy S21", 799.99};
    products[2] = (Product){3, "Google Pixel 6", 599.99};
    products[3] = (Product){4, "OnePlus 9 Pro", 729.99};
    products[4] = (Product){5, "Sony WH-1000XM4 Headphones", 349.99};
    products[5] = (Product){6, "Apple MacBook Pro", 1299.99};
    products[6] = (Product){7, "Dell XPS 13", 999.99};
    products[7] = (Product){8, "iPad Pro", 799.99};
    products[8] = (Product){9, "Amazon Kindle", 89.99};
    products[9] = (Product){10, "Fitbit Charge 5", 149.99};
    productCount = 10;

    int choice;
    while (1) {
        printf("1. View Products\n2. Add to Cart\n3. View Cart\n4. Delete from Cart\n5. Checkout\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf
        switch (choice) {
            case 1:
                viewProducts();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                deleteFromCart();
                break;
            case 5:
                checkout();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    }
}
