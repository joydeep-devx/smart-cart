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


void displayResult(Product products[], int productNo, int budget , int selected[],int maxUtility){
    int totalCost = 0;

    printf("\n==========================================================\n");
    printf("                    SMART CART RESULT\n");
    printf("==========================================================\n\n");

    printf("Selected Products\n\n");

    printf("%-5s %-20s %-10s %-10s\n",
           "No.", "Product", "Price", "Utility");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < productNo; i++) {
        if (selected[i]) {
            printf("%-5d %-20s %-10d %-10d\n",
                   i+1,
                   products[i].name,
                   products[i].price,
                   products[i].utility);

            totalCost += products[i].price;
        }
    }

    printf("----------------------------------------------------------\n");

    printf("Total Cost               : %d\n", totalCost);
    printf("Maximum Utility          : %d\n", maxUtility);
    printf("Remaining Budget         : %d\n", budget - totalCost);

    printf("==========================================================\n");
}

// Reconstruct the solution using the DP table
void findSelectedProducts(Product products[], int productNo, int budget , int dp[productNo + 1][budget + 1] ,int selected[]){
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
        i--;
    }

}

// Returns the maximum utility products using DP
int knapsack(Product products[], int productNo, int budget , int dp[productNo + 1][budget + 1]) {
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
    // findSelectedProducts(products,productNo,budget,dp);

    return dp[productNo][budget];
}


int main() {
    int productNo;
    int budget;
    

    printf("========== Smart Cart ==========\n");
    printf("Enter the number of products: ");
    scanf("%d",&productNo);

    // An array of products 
    Product products[productNo];

    // Total budget
    printf("Enter your budget: ");
    scanf("%d",&budget);

    int dp[productNo + 1][budget + 1];
    int selected[productNo];

    // Takes input details of the products
    inputProducts(products, productNo);

    // Create a Dp table and return maxUtility
    int maxUtility = knapsack(products, productNo, budget, dp);

    // Construct the final solution array
    findSelectedProducts(products, productNo, budget, dp, selected);

    // display the final solution 
    displayResult(products, productNo, budget, selected, maxUtility);


    return 0;
}