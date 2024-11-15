#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_seed()    //시간 변화에 따른 난수 생성
{
    srand((unsigned int)time(NULL));
}

int generate_random_number(int min, int max)   //생성한 무작위 정수 반환 함수
{
    return rand() % (max - min + 1) + min;
}

int user_guess()   //사용자가 숫자를 맞추는 함수
{
    int guess;
    printf("숫자를 입력하세요: ");
    scanf_s("%d", &guess);
    return guess;
}

int main() {
    rand_seed();

    int number = generate_random_number(1, 100);  //1~100 사이에서 무작위로 정수 생성
    int guess;
    int attempts = 10;    //10번의 시도 횟수

    printf("10번의 기회가 있습니다. 1에서 100 사이의 숫자를 맞춰보세요!\n");

    for (int i = 1; i <= attempts; i++)    //숫자 입력에 따라 업, 다운 출력
    {
        printf("\n%d번째 시도: ", i);
        guess = user_guess();

        if (guess == number)
        {
            printf("정답! %d번 만에 맞췄습니다.\n", i);
            return 0;
        }
        else if (guess < number)
        {
            printf("UP\n");
        }
        else
        {
            printf("DOWN\n");
        }
    }

    printf("\n기회를 모두 사용했습니다. 정답은 %d입니다.\n", number);    //10번 동안 맞추지 못할 경우
    
    return 0;
}