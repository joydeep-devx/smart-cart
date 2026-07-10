#include<stdio.h>

// Structure of the Product
typedef struct {
    char name[30];
    int price;
    int utility;
} Product;

// Takes input of the product details
void inputProducts(Product products[], int productNo) {
    printf("\n========== Enter Product Details ==========\n");

    for (int i = 0; i < productNo; i++) {
        printf("\nProduct %d\n", i + 1);

        printf("Name    : ");
        scanf("%s", products[i].name);

        printf("Price   : ");
        scanf("%d", &products[i].price);

        printf("Utility : ");
        scanf("%d", &products[i].utility);
    }
}

int main() {
    int productNo;
    int budget;

    printf("========== Smart Cart ==========\n");

    printf("Enter the number of products: ");
    scanf("%d",&productNo);

    Product products[productNo];

    printf("Enter your budget: ");
    scanf("%d",&budget);

    inputProducts(products, productNo);

    return 0;
}