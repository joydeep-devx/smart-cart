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

void findSelectedProducts(Product products[], int productNo, int budget , int dp[productNo + 1][budget + 1]){
    // tracks selected items
    int selected[productNo];

    // initialize 
    for(int i=0;i < productNo;i++){
        selected[i] = 0;
    }

    int i = productNo, j = budget;

    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i-1][j]){
            selected[i-1] = 1;
            j -= products[i-1].price;
        }
    }

}

// Returns the maximum utility products using DP
int knapsack(Product products[], int productNo, int budget) {
    int dp[productNo + 1][budget + 1];

    // Initialize first column
    for (int i = 0; i <= productNo; i++) {
        dp[i][0] = 0;
    }
    // Initialize first row 
    for (int j = 0; j <= budget; j++) {
        dp[0][j] = 0;
    }

    // Build DP table
    for (int i = 1; i <= productNo; i++) {
        for (int j = 1; j <= budget; j++) {

            // Product's Price is less than current budget
            if (products[i - 1].price <= j) {

                // utility after including the current product
                int include = products[i - 1].utility + dp[i - 1][j - products[i - 1].price];

                // utility excluding the current product
                int exclude = dp[i - 1][j];

                // take maximum between them 
                dp[i][j] = (include > exclude) ? include : exclude;
            }
            // Product's Price is greater than current budget
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // print the selected products
    findSelectedProducts(products,productNo,budget,dp);

    return dp[productNo][budget];
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

    int maxUtility = knapsack(products, productNo, budget);
    printf("\nMaximum Utility: %d\n", maxUtility);

    return 0;
}