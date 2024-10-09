#include <stdio.h>

int main() {
    int Money, Price, Totalchange, change;         // 투입한 금액, 물건 가격, 거스름돈, 지폐(동전) 개수
    int W1000, W500, W100;                         // 1000원의 개수, 500원의 개수, 100원의 개수

    // 입력받기
    printf("투입한 금액과 물건값을 차례대로 입력하세요 (원): ");
    scanf_s("%d %d", &Money, &Price);

    Totalchange = (Money - Price);  // 총 거스름돈 게산

    W1000 = Totalchange / 1000;     // 1000원 지폐 개수, 총 거스름돈에서 계산
    change = Totalchange % 1000;

    W500 = change / 500;       // 500원 동전 개수, 1000원 개수 제외한 나머지로 계산
    change = change % 500;

    W100 = change / 100;       // 100원 동전 개수, 500원 개수 제외한 나머지로 계산
    change = change % 100;

    printf("거스름돈은 다음과 같습니다:\n");       // 1000원 지폐부터 내림차순으로 돌려줄 개수 출력
    printf("거스름돈: %d원\n", Totalchange);       // 총 거르슴돈 액수 출력
    printf("1000원 지폐: %d개\n", W1000);
    printf("500원 동전: %d개\n", W500);
    printf("100원 동전: %d개\n", W100);
    printf("남은 잔돈: %d원\n", change);

    return 0;
}