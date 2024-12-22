#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COINS 3

typedef struct {
    char name[20];
    double price;          // 현재 가격
    double previous_price; // 이전 가격
    double amount_owned;   // 보유량
    double last_buy_price; // 마지막 구매 가격
} Coin;


void display_coins(Coin coins[], int size) {
    printf("\n--- Current Prices ---\n");
    for (int i = 0; i < size; i++)
    {
        double change_percent = 0.0;

        // 구매 가격과 현재 가격 비교하여 변동률 계산
        if (coins[i].last_buy_price > 0)
        {
            change_percent = ((coins[i].price - coins[i].last_buy_price) / coins[i].last_buy_price) * 100.0;
        }

        // 코인 정보 출력
        printf("%d. %s - $%.2f (You own: %.4f) [%+.2f%% change]\n",
            i + 1, coins[i].name, coins[i].price, coins[i].amount_owned, change_percent);
    }
}



void update_prices(Coin coins[], int size) {
    for (int i = 0; i < size; i++)
    {
        double change;

        coins[i].previous_price = coins[i].price;          // 이전 가격 저장

        if (strcmp(coins[i].name, "Ripple") == 0)          // 리플 코인은 -100%에서 +100% 변동
        {
            change = ((rand() % 201) - 100) / 100.0;       // -100%에서 +100%
        }
        else {
            change = ((rand() % 21) - 10) / 100.0;         // 다른 코인들은 -10%에서 +10%
        }

        coins[i].price += coins[i].price * change;         // 가격 업데이트

        if (coins[i].price < 1.0)                          // 최소 가격 제한
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

    printf("\nYou currently have $%.2f in cash.\n", *cash);             // 현재 보유 현금 출력

    printf("Enter the coin number to buy: ");
    if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > size)
    {
        printf("Invalid input. Please enter a valid coin number.\n");
        return;
    }
    choice--;                                                           // 배열 인덱스에 맞추기 위해 1 감소

    printf("Enter the amount to spend: $");
    if (scanf_s("%lf", &amount) != 1 || amount <= 0)
    {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    if (amount > *cash)                                                 // 보유 현금 확인
    {
        printf("Not enough cash!\n");
        return;
    }

    double coins_bought = amount / coins[choice].price;                 // 코인 구매
    coins[choice].amount_owned += coins_bought;                         // 구매한 코인의 보유량 증가
    *cash -= amount;                                                    // 보유 현금 감소

    coins[choice].last_buy_price = coins[choice].price;                 // 마지막 구매 가격 업데이트

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
    choice--;                                                          // 배열 인덱스에 맞추기 위해 1 감소

    if (coins[choice].amount_owned <= 0.0)                             // 보유량 확인
    {
        printf("You don't own any %s to sell.\n", coins[choice].name);
        return;
    }

    printf("Do you want to sell all your %s? (1 for Yes, 0 for No): ", coins[choice].name);      // 판매 금액 또는 전량 매도 선택
    int sell_all;
    if (scanf_s("%d", &sell_all) != 1 || (sell_all != 0 && sell_all != 1))
    {
        printf("Invalid input. Please enter 1 (Yes) or 0 (No).\n");
        return;
    }

    if (sell_all == 1)                                                             // 전량 매도
    {
        double total_value = coins[choice].amount_owned * coins[choice].price;
        *cash += total_value;
        printf("You sold all %.4f %s for $%.2f.\n",
            coins[choice].amount_owned, coins[choice].name, total_value);
        coins[choice].amount_owned = 0.0;                                          // 보유량 초기화
    }
    else                                                                           // 원하는 금액만 판매
    {
        printf("Enter the amount to sell: ");
        if (scanf_s("%lf", &amount) != 1 || amount <= 0)
        {
            printf("Invalid amount. Please enter a positive value.\n");
            return;
        }

        double coin_amount = amount / coins[choice].price;                         // 판매할 개수 계산
        if (coin_amount > coins[choice].amount_owned)
        {
            printf("Not enough coins to sell!\n");
            return;
        }

        coins[choice].amount_owned -= coin_amount;                                 // 보유 개수 업데이트 및 현금 증가
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
        double coin_value = coins[i].amount_owned * coins[i].price; // 코인의 총 가치 계산
        total_assets += coin_value;

        printf("%s: %.4f coins worth $%.2f\n",                      // 코인별 보유량과 가치를 출력
            coins[i].name, coins[i].amount_owned, coin_value);
    }

    printf("\nTotal assets: $%.2f\n", total_assets);                // 총 자산 출력
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
    double initial_cash = 10000.0;                                 // 최초 소지금

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

    double total_assets = *cash;                                                 // 수익률 계산
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

void reset_data(Coin coins[], int size, double* cash) {                            // 초기 상태 설정
    *cash = 10000.0;                                                               // 초기 보유 현금
    for (int i = 0; i < size; i++) {
        coins[i].amount_owned = 0.0;                                               // 보유량 초기화
        coins[i].last_buy_price = 0.0;                                             // 마지막 구매 가격 초기화
    }

    if (remove("data.txt") == 0)                                                   // 기존 파일 삭제
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

    int choice;                                                         //코인 현재가, 시세 변경, 판매, 구매 등의 메뉴 제공
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

        switch (choice) {                                               // 각 메뉴별로 번호 할당해서 선택 후 작동
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
