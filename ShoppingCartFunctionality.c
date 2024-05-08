#include <stdio.h>
#include <stdlib.h>

// Define a structure for a product
typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
} Product;

// Define a structure for a shopping cart item
typedef struct {
    Product product;
    int quantity;
} CartItem;

// Function to add a product to the cart
void addToCart(CartItem cart[], Product product, int quantity, int *cartSize) {
    cart[*cartSize].product = product;
    cart[*cartSize].quantity = quantity;
    (*cartSize)++;
    printf("Product added to cart.\n");
}

// Function to display the contents of the cart
void displayCart(CartItem cart[], int cartSize) {
    printf("Shopping Cart Contents:\n");
    printf("-------------------------------------------------\n");
    printf("%-5s | %-20s | %-10s | %-8s\n", "ID", "Product", "Price", "Quantity");
    printf("-------------------------------------------------\n");
    float totalAmount = 0;
    for (int i = 0; i < cartSize; i++) {
        printf("%-5d | %-20s | $%-9.2f | %-8d\n", cart[i].product.id, cart[i].product.name, cart[i].product.price, cart[i].quantity);
        totalAmount += cart[i].product.price * cart[i].quantity;
    }
    printf("-------------------------------------------------\n");
    printf("Total Amount: $%.2f\n", totalAmount);
}

int main() {
    // Example products
    Product products[] = {
        {1, "Product 1", 10.99, 100},
        {2, "Product 2", 20.49, 50},
        {3, "Product 3", 15.79, 200}
    };

    // Initialize empty cart
    CartItem cart[100];
    int cartSize = 0;

    // Add products to cart
    addToCart(cart, products[0], 2, &cartSize);
    addToCart(cart, products[1], 1, &cartSize);
    addToCart(cart, products[2], 3, &cartSize);

    // Display cart contents
    displayCart(cart, cartSize);

    return 0;
}
