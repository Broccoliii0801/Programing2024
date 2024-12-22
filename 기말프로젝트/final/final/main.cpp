#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COINS 3

// Coin 구조체 정의
typedef struct {
    char name[20];
    double price;          // 현재 가격
    double previous_price; // 이전 가격
    double amount_owned;   // 보유량
    double last_buy_price; // 마지막 구매 가격
} Coin;

void display_coins(Coin* coins, int size) {         // 코인 정보를 출력
    printf("\n--- Current Prices ---\n");
    for (int i = 0; i < size; i++) {
        double change_percent = 0.0;

        if (coins[i].last_buy_price > 0) {          // 코인의 현재가와 마지막 구매 가격 사이의 변화율 계산 위한 과정, 구매가가 0으로 없으면 계산 생략
            change_percent = ((coins[i].price - coins[i].last_buy_price) / coins[i].last_buy_price) * 100.0;
        }
        printf("%d. %s - $%.2f (You own: %.4f) [%+.2f%% change from last buy price]\n",
            i + 1, coins[i].name, coins[i].price, coins[i].amount_owned, change_percent);
    }
}

void update_prices(Coin* coins, int size) {          // 코인 가격을 난수를 사용해 업데이트
    for (int i = 0; i < size; i++) {
        double change;

        if (strcmp(coins[i].name, "Ripple") == 0) {  // 리플 코인은 특수한 변동폭 적용, strcmp를 이용해 문자열 비교
            change = ((rand() % 401) - 200) / 100.0; // -200%에서 +200%
        }
        else {
            change = ((rand() % 21) - 10) / 100.0;   // 다른 코인들은 -10%에서 +10%
        }

        coins[i].price += coins[i].price * change;

        if (coins[i].price < 1.0) {
            coins[i].price = 1.0;                    // 최소 가격 제한
        }
    }

    printf("\nPrices updated!\n");
}

void buy_coin(Coin* coins, int size, double* cash) {                  // 코인 구매 함수
    int choice;     // 구매할 코인의 번호 저장하는 변수
    double amount;  // 지불할 금액을 저장하는 변수

    display_coins(coins, size);

    printf("\nYou currently have $%.2f in cash.\n", *cash);           // 보유중인 현금 출력

    printf("Enter the coin number to buy: ");
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

    double coins_bought = amount / coins[choice].price;                // 구매 가능한 코인의 개수 계산
    coins[choice].amount_owned += coins_bought;                        // 구매한 코인의 개수를 해당 코인의 보유량에 추가
    *cash -= amount;                                                   // 보유 현금에서 지불 금액 차감

    coins[choice].last_buy_price = coins[choice].price;                // 가격 변동 확인을 위해 마지막 구매 가격 업데이트

    printf("You bought %.4f %s for $%.2f at $%.2f per coin.\n",
        coins_bought, coins[choice].name, amount, coins[choice].price);
    printf("Remaining cash: $%.2f\n", *cash);
}

void sell_coin(Coin* coins, int size, double* cash) {                  // 코인 판매 함수
    int choice;    // 판매하려는 코인의 번호 저장
    double amount; // 판매하려는 금액 저장

    display_coins(coins, size);

    printf("\nEnter the coin number to sell: ");
    if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > size) {
        printf("Invalid input. Please enter a valid coin number.\n");
        return;
    }
    choice--;

    if (coins[choice].amount_owned <= 0.0) {
        printf("You don't own any %s to sell.\n", coins[choice].name);
        return;
    }

    double total_value = coins[choice].amount_owned * coins[choice].price;                  // 선택한 코인의 총 가치 계산
    printf("You own %.4f %s, each priced at $%.2f (Total value: $%.2f).\n",
        coins[choice].amount_owned, coins[choice].name, coins[choice].price, total_value);

    printf("Do you want to sell all your %s? (1 for Yes, 0 for No): ", coins[choice].name); // 코인 전량 매도 결정
    int sell_all;
    if (scanf_s("%d", &sell_all) != 1 || (sell_all != 0 && sell_all != 1)) {
        printf("Invalid input. Please enter 1 (Yes) or 0 (No).\n");
        return;
    }

    if (sell_all == 1) {        // 전량 매도할 경우
        *cash += total_value;
        printf("You sold all %.4f %s for $%.2f.\n",
            coins[choice].amount_owned, coins[choice].name, total_value);
        coins[choice].amount_owned = 0.0;
    }
    else {                      // 그렇지 않을 경우 판매 금액 입력 후 판매 개수 계산
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

        coins[choice].amount_owned -= coin_amount;   // 판매량만큼 보유량 감소
        *cash += amount;                             // 판매 금액을 보유 현금에 추가

        printf("You sold %.4f %s for $%.2f.\n", coin_amount, coins[choice].name, amount);
    }

    printf("Remaining cash: $%.2f\n", *cash);
}

void calculate_assets(Coin* coins, int size, double cash) {         // 사용자의 총 자산 출력
    double total_assets = cash;                                     // 총 자산 변수 선언, 초기값은 현금으로 설정

    printf("\n--- Asset Breakdown ---\n");
    printf("Cash: $%.2f\n", cash);
     
    for (int i = 0; i < size; i++) {                                // 각 코인의 정보 처리
        double coin_value = coins[i].amount_owned * coins[i].price; // 코인의 총 가치 계산
        total_assets += coin_value;

        printf("%s: %.4f coins worth $%.2f\n",
            coins[i].name, coins[i].amount_owned, coin_value);
    }

    printf("\nTotal assets: $%.2f\n", total_assets);
}

void save_data(Coin* coins, int size, double cash) {           // 코인 데이터와 현금을 파일에 저장하는 함수
    FILE* file;  // 파일 포인터 선언
    if (fopen_s(&file, "data.txt", "w") != 0) {                // 파일을 쓰기 모드로 열어 현금, 각 코인의 데이터를 저장
        printf("Failed to open file for saving.\n");
        return;
    }

    fprintf(file, "%.2f\n", cash);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %.2f %.4f %.2f\n",
            coins[i].name, coins[i].price, coins[i].amount_owned, coins[i].last_buy_price);
    }

    fclose(file);                                              // 파일 종료
    printf("Data saved successfully.\n");
}

void load_data(Coin* coins, int size, double* cash) {            // 코인의 데이터를 기존에 저장한 파일에서 읽어와 배열과 현금 포인터에 저장
    FILE* file;                                                  // 파일 포인터 선언
    if (fopen_s(&file, "data.txt", "r") != 0) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    if (fscanf_s(file, "%lf", cash) != 1) {                      // 파일의 첫 번째 값을 cash 변수에 저장
        printf("Error reading cash value from file.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < size; i++) {                             // coins 배열의 크기만큼 반복하여 각 코인의 데이터를 파일에서 읽음
        if (fscanf_s(file, "%s %lf %lf %lf",
            coins[i].name, (unsigned)_countof(coins[i].name),
            &coins[i].price, &coins[i].amount_owned, &coins[i].last_buy_price) != 4) {
            printf("Error reading coin data from file.\n");
            fclose(file);
            return;
        }
    }

    fclose(file);                            // 파일 닫기
    printf("Data loaded successfully.\n");
}

void reset_data(Coin* coins, int size, double* cash) {         // 데이터 초기화 후 파일 삭제
    *cash = 10000.0;                                           // 현금을 초기값으로 설정
    for (int i = 0; i < size; i++) {                           // 모든 코인의 데이터 초기화
        coins[i].amount_owned = 0.0;
        coins[i].last_buy_price = 0.0;
    }

    if (remove("data.txt") == 0) {                             // 파일 data.txt 삭제
        printf("\nData reset successfully. All records have been cleared.\n");
    }
    else {
        printf("\nData reset successfully, but no existing save file was found.\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));                                     // 난수 생성을 위한 시드 설정, 매번 다른 난수 생성하도록 초기화

    Coin* coins = (Coin*)malloc(MAX_COINS * sizeof(Coin));               // MAX_COINS 크기의 Coin 구조체 배열을 동적 할당
    if (coins == NULL) {
        printf("Failed to allocate memory for coins.\n");
        return 1;
    }

    strcpy_s(coins[0].name, sizeof(coins[0].name), "Bitcoin");           // coins[0]에 Bitcoin 데이터를 초기화, 이후 각 코인마다 반복
    coins[0].price = 50000.0;
    coins[0].previous_price = 0.0;
    coins[0].amount_owned = 0.0;
    coins[0].last_buy_price = 0.0;

    strcpy_s(coins[1].name, sizeof(coins[1].name), "Ethereum");          
    coins[1].price = 4000.0;
    coins[1].previous_price = 0.0;
    coins[1].amount_owned = 0.0;
    coins[1].last_buy_price = 0.0;

    strcpy_s(coins[2].name, sizeof(coins[2].name), "Ripple");
    coins[2].price = 1.0;
    coins[2].previous_price = 0.0;
    coins[2].amount_owned = 0.0;
    coins[2].last_buy_price = 0.0;

    double cash = 10000.0;                                               // 사용자의 초기 현금 설정

    load_data(coins, MAX_COINS, &cash);                                  // 파일에서 저장된 데이터를 로드해 coin과 cash 업데이트
    int choice;
    do {                                                                 // 프로그램 종료시까지 프로그램의 거래 메뉴 선택을 반복하기 위해 do - while 문 사용
        printf("\n--- Crypto Trading Simulator ---\n");
        printf("1. View Coins\n");
        printf("2. Update Prices\n");
        printf("3. Buy Coins\n");
        printf("4. Sell Coins\n");
        printf("5. View Total Assets\n");
        printf("6. Save and Exit\n");
        printf("7. Reset Data\n");
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
        case 7:
            reset_data(coins, MAX_COINS, &cash);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);                                               // 루프의 종료 조건인 6번, 데이터 저장 후 종료

    free(coins);                                                         // 동적 메모리로 할당된 coins 해제

    return 0;
}
