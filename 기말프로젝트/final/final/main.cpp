#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COINS 3

typedef struct {
    char name[20];
    double price;          // ���� ����
    double previous_price; // ���� ����
    double amount_owned;   // ������
    double last_buy_price; // ������ ���� ����
} Coin;


void display_coins(Coin coins[], int size) {
    printf("\n--- Current Prices ---\n");
    for (int i = 0; i < size; i++)
    {
        double change_percent = 0.0;

        // ���� ���ݰ� ���� ���� ���Ͽ� ������ ���
        if (coins[i].last_buy_price > 0)
        {
            change_percent = ((coins[i].price - coins[i].last_buy_price) / coins[i].last_buy_price) * 100.0;
        }

        // ���� ���� ���
        printf("%d. %s - $%.2f (You own: %.4f) [%+.2f%% change]\n",
            i + 1, coins[i].name, coins[i].price, coins[i].amount_owned, change_percent);
    }
}



void update_prices(Coin coins[], int size) {
    for (int i = 0; i < size; i++)
    {
        double change;

        coins[i].previous_price = coins[i].price;          // ���� ���� ����

        if (strcmp(coins[i].name, "Ripple") == 0)          // ���� ������ -100%���� +100% ����
        {
            change = ((rand() % 201) - 100) / 100.0;       // -100%���� +100%
        }
        else {
            change = ((rand() % 21) - 10) / 100.0;         // �ٸ� ���ε��� -10%���� +10%
        }

        coins[i].price += coins[i].price * change;         // ���� ������Ʈ

        if (coins[i].price < 1.0)                          // �ּ� ���� ����
        {
            coins[i].price = 1.0; 
        }
    }

    printf("\nPrices updated!\n");
}




void buy_coin(Coin coins[], int size, double* cash) {
    int choice;
    double amount;

    display_coins(coins, size);

    printf("\nYou currently have $%.2f in cash.\n", *cash);             // ���� ���� ���� ���

    printf("Enter the coin number to buy: ");
    if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > size)
    {
        printf("Invalid input. Please enter a valid coin number.\n");
        return;
    }
    choice--;                                                           // �迭 �ε����� ���߱� ���� 1 ����

    printf("Enter the amount to spend: $");
    if (scanf_s("%lf", &amount) != 1 || amount <= 0)
    {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    if (amount > *cash)                                                 // ���� ���� Ȯ��
    {
        printf("Not enough cash!\n");
        return;
    }

    double coins_bought = amount / coins[choice].price;                 // ���� ����
    coins[choice].amount_owned += coins_bought;                         // ������ ������ ������ ����
    *cash -= amount;                                                    // ���� ���� ����

    coins[choice].last_buy_price = coins[choice].price;                 // ������ ���� ���� ������Ʈ

    printf("You bought %.4f %s for $%.2f at $%.2f per coin.\n",         
        coins_bought, coins[choice].name, amount, coins[choice].price);
    printf("Remaining cash: $%.2f\n", *cash);
}

void sell_coin(Coin coins[], int size, double* cash) {
    int choice;
    double amount;

    display_coins(coins, size);

    printf("\nEnter the coin number to sell: "); 
    if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > size)
    {
        printf("Invalid input. Please enter a valid coin number.\n");
        return;
    }
    choice--;                                                          // �迭 �ε����� ���߱� ���� 1 ����

    if (coins[choice].amount_owned <= 0.0)                             // ������ Ȯ��
    {
        printf("You don't own any %s to sell.\n", coins[choice].name);
        return;
    }

    printf("Do you want to sell all your %s? (1 for Yes, 0 for No): ", coins[choice].name);      // �Ǹ� �ݾ� �Ǵ� ���� �ŵ� ����
    int sell_all;
    if (scanf_s("%d", &sell_all) != 1 || (sell_all != 0 && sell_all != 1))
    {
        printf("Invalid input. Please enter 1 (Yes) or 0 (No).\n");
        return;
    }

    if (sell_all == 1)                                                             // ���� �ŵ�
    {
        double total_value = coins[choice].amount_owned * coins[choice].price;
        *cash += total_value;
        printf("You sold all %.4f %s for $%.2f.\n",
            coins[choice].amount_owned, coins[choice].name, total_value);
        coins[choice].amount_owned = 0.0;                                          // ������ �ʱ�ȭ
    }
    else                                                                           // ���ϴ� �ݾ׸� �Ǹ�
    {
        printf("Enter the amount to sell: ");
        if (scanf_s("%lf", &amount) != 1 || amount <= 0)
        {
            printf("Invalid amount. Please enter a positive value.\n");
            return;
        }

        double coin_amount = amount / coins[choice].price;                         // �Ǹ��� ���� ���
        if (coin_amount > coins[choice].amount_owned)
        {
            printf("Not enough coins to sell!\n");
            return;
        }

        coins[choice].amount_owned -= coin_amount;                                 // ���� ���� ������Ʈ �� ���� ����
        *cash += amount;

        printf("You sold %.4f %s for $%.2f.\n", coin_amount, coins[choice].name, amount);
    }

    printf("Remaining cash: $%.2f\n", *cash);
}





void calculate_assets(Coin coins[], int size, double cash) {
    double total_assets = cash;

    printf("\n--- Asset Breakdown ---\n");
    printf("Cash: $%.2f\n", cash);

    for (int i = 0; i < size; i++)
    {
        double coin_value = coins[i].amount_owned * coins[i].price; // ������ �� ��ġ ���
        total_assets += coin_value;

        printf("%s: %.4f coins worth $%.2f\n",                      // ���κ� �������� ��ġ�� ���
            coins[i].name, coins[i].amount_owned, coin_value);
    }

    printf("\nTotal assets: $%.2f\n", total_assets);                // �� �ڻ� ���
}


void save_data(Coin coins[], int size, double cash) {
    FILE* file;
    if (fopen_s(&file, "data.txt", "w") != 0)
    {
        printf("Failed to open file for saving.\n");
        return;
    }

    fprintf(file, "%.2f\n", cash);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s %.2f %.4f\n", coins[i].name, coins[i].price, coins[i].amount_owned);
    }

    fclose(file);
    printf("Data saved successfully.\n");
}

void load_data(Coin coins[], int size, double* cash) {
    FILE* file;
    double initial_cash = 10000.0;                                 // ���� ������

    if (fopen_s(&file, "data.txt", "r") != 0)
    {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    if (fscanf_s(file, "%lf", cash) != 1)
    {
        printf("Error reading cash value from file.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (fscanf_s(file, "%s %lf %lf", coins[i].name, (unsigned)_countof(coins[i].name), &coins[i].price, &coins[i].amount_owned) != 3) {
            printf("Error reading coin data from file.\n");
            fclose(file);
            return;
        }
    }

    fclose(file);

    double total_assets = *cash;                                                 // ���ͷ� ���
    for (int i = 0; i < size; i++)
    {
        total_assets += coins[i].amount_owned * coins[i].price;
    }

    double profit_rate = ((total_assets - initial_cash) / initial_cash) * 100.0; 

    printf("Data loaded successfully.\n");
    printf("Initial Cash: $%.2f\n", initial_cash);
    printf("Current Total Assets: $%.2f\n", total_assets);
    printf("Profit Rate: %.2f%%\n", profit_rate);
}

void reset_data(Coin coins[], int size, double* cash) {                            // �ʱ� ���� ����
    *cash = 10000.0;                                                               // �ʱ� ���� ����
    for (int i = 0; i < size; i++) {
        coins[i].amount_owned = 0.0;                                               // ������ �ʱ�ȭ
        coins[i].last_buy_price = 0.0;                                             // ������ ���� ���� �ʱ�ȭ
    }

    if (remove("data.txt") == 0)                                                   // ���� ���� ����
    {
        printf("\nData reset successfully. All records have been cleared.\n");
    }
    else
    {
        printf("\nData reset successfully, but no existing save file was found.\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));

    Coin coins[MAX_COINS] =
    {
        {"Bitcoin", 50000.0, 0.0, 0.0},
        {"Ethereum", 4000.0, 0.0, 0.0},
        {"Ripple", 1.0, 0.0, 0.0}
    };
    double cash = 10000.0;

    load_data(coins, MAX_COINS, &cash);

    int choice;                                                         //���� ���簡, �ü� ����, �Ǹ�, ���� ���� �޴� ����
    do {
        printf("\n--- Crypto Trading Simulator ---\n");
        printf("1. View Coins\n");
        printf("2. Update Prices\n");
        printf("3. Buy Coins\n");
        printf("4. Sell Coins\n");
        printf("5. View Total Assets\n");
        printf("6. Save and Exit\n");
        printf("7. Reset Data\n");
        printf("Enter your choice: ");
        if (scanf_s("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {                                               // �� �޴����� ��ȣ �Ҵ��ؼ� ���� �� �۵�
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
        case 7:
            reset_data(coins, MAX_COINS, &cash);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
