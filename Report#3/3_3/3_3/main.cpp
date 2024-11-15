#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_seed()    //�ð� ��ȭ�� ���� ���� ����
{
    srand((unsigned int)time(NULL));
}

int generate_random_number(int min, int max)   //������ ������ ���� ��ȯ �Լ�
{
    return rand() % (max - min + 1) + min;
}

int user_guess()   //����ڰ� ���ڸ� ���ߴ� �Լ�
{
    int guess;
    printf("���ڸ� �Է��ϼ���: ");
    scanf_s("%d", &guess);
    return guess;
}

int main() {
    rand_seed();

    int number = generate_random_number(1, 100);  //1~100 ���̿��� �������� ���� ����
    int guess;
    int attempts = 10;    //10���� �õ� Ƚ��

    printf("10���� ��ȸ�� �ֽ��ϴ�. 1���� 100 ������ ���ڸ� ���纸����!\n");

    for (int i = 1; i <= attempts; i++)    //���� �Է¿� ���� ��, �ٿ� ���
    {
        printf("\n%d��° �õ�: ", i);
        guess = user_guess();

        if (guess == number)
        {
            printf("����! %d�� ���� ������ϴ�.\n", i);
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

    printf("\n��ȸ�� ��� ����߽��ϴ�. ������ %d�Դϴ�.\n", number);    //10�� ���� ������ ���� ���
    
    return 0;
}