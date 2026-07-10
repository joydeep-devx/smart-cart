#include<stdio.h>

// Structure of the Product
typedef struct {
    char name[30];
    int price;
    int utility;
} Product;

int main() {
    int productNo;
    int budget;

    printf("========== Smart Cart ==========\n");

    printf("Enter the number of products: ");
    scanf("%d",&productNo);

    Product products[productNo];

    printf("Enter your budget: ");
    scanf("%d",&budget);

    printf("\nProgram setup completed successfully.\n");

    return 0;
}