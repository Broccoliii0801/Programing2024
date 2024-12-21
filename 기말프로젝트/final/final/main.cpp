#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COINS 3

typedef struct {
    char name[20];
    double price;
    double amount_owned;
} Coin;

void display_coins(Coin coins[], int size) {
    printf("\nCurrent Prices:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f (You own: %.4f)\n", i + 1, coins[i].name, coins[i].price, coins[i].amount_owned);
    }
}

void update_prices(Coin coins[], int size) {
    for (int i = 0; i < size; i++) {
        double change = ((rand() % 21) - 10) / 100.0; // -10% to +10%
        coins[i].price += coins[i].price * change;
        if (coins[i].price < 1.0) coins[i].price = 1.0; // Minimum price
    }
    printf("\nPrices updated!\n");
}

void buy_coin(Coin coins[], int size, double* cash) {
    int choice;
    double amount;

    display_coins(coins, size);
    printf("\nEnter the coin number to buy: ");
    if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > size) {
        printf("Invalid input. Please enter a valid coin number.\n");
        return;
    }
    choice--;

    printf("Enter the amount to spend: $");
    if (scanf_s("%lf", &amount) != 1 || amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    if (amount > *cash) {
        printf("Not enough cash!\n");
        return;
    }

    coins[choice].amount_owned += amount / coins[choice].price;
    *cash -= amount;
    printf("You bought %.4f %s.\n", amount / coins[choice].price, coins[choice].name);
}

void sell_coin(Coin coins[], int size, double* cash) {
    int choice;
    double amount;

    display_coins(coins, size);
    printf("\nEnter the coin number to sell: ");
    if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > size) {
        printf("Invalid input. Please enter a valid coin number.\n");
        return;
    }
    choice--;

    printf("Enter the amount to sell: ");
    if (scanf_s("%lf", &amount) != 1 || amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    double coin_amount = amount / coins[choice].price;
    if (coin_amount > coins[choice].amount_owned) {
        printf("Not enough coins to sell!\n");
        return;
    }

    coins[choice].amount_owned -= coin_amount;
    *cash += amount;
    printf("You sold %.4f %s.\n", coin_amount, coins[choice].name);
}

void calculate_assets(Coin coins[], int size, double cash) {
    double total_assets = cash;
    for (int i = 0; i < size; i++) {
        total_assets += coins[i].amount_owned * coins[i].price;
    }
    printf("\nTotal assets: $%.2f (Cash: $%.2f)\n", total_assets, cash);
}

void save_data(Coin coins[], int size, double cash) {
    FILE* file;
    if (fopen_s(&file, "data.txt", "w") != 0) {
        printf("Failed to open file for saving.\n");
        return;
    }

    fprintf(file, "%.2f\n", cash);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %.2f %.4f\n", coins[i].name, coins[i].price, coins[i].amount_owned);
    }

    fclose(file);
    printf("Data saved successfully.\n");
}

void load_data(Coin coins[], int size, double* cash) {
    FILE* file;
    if (fopen_s(&file, "data.txt", "r") != 0) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    if (fscanf_s(file, "%lf", cash) != 1) {
        printf("Error reading cash value from file.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf_s(file, "%s %lf %lf", coins[i].name, (unsigned)_countof(coins[i].name), &coins[i].price, &coins[i].amount_owned) != 3) {
            printf("Error reading coin data from file.\n");
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Data loaded successfully.\n");
}

int main() {
    srand((unsigned int)time(NULL));

    Coin coins[MAX_COINS] = {
        {"Bitcoin", 50000.0, 0.0},
        {"Ethereum", 4000.0, 0.0},
        {"Ripple", 1.0, 0.0}
    };
    double cash = 10000.0;

    load_data(coins, MAX_COINS, &cash);

    int choice;
    do {
        printf("\n--- Crypto Trading Simulator ---\n");
        printf("1. View Coins\n");
        printf("2. Update Prices\n");
        printf("3. Buy Coins\n");
        printf("4. Sell Coins\n");
        printf("5. View Total Assets\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        if (scanf_s("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
        case 1:
            display_coins(coins, MAX_COINS);
            break;
        case 2:
            update_prices(coins, MAX_COINS);
            break;
        case 3:
            buy_coin(coins, MAX_COINS, &cash);
            break;
        case 4:
            sell_coin(coins, MAX_COINS, &cash);
            break;
        case 5:
            calculate_assets(coins, MAX_COINS, cash);
            break;
        case 6:
            save_data(coins, MAX_COINS, cash);
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}    // 불러올 때 최초 소지금에 대한 수익률 추가, 리플을 도지코인으로 변경 후 해당 코인만 금액 상승/하강 폭 늘리기
