#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define gen_num 10  //������ ������ ���� 10�� ����

void gen_rand_seed()  //�ð��� ���� ��������
{
    srand((unsigned int)(time(NULL)));
}

int generate_random_number(int min, int max)  //Ư�� ���� ������ �������� ������ �����ϴ� �Լ�
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    gen_rand_seed();               //����, �л�, ǥ�������� ���ϱ� ���� ������ �������� ������ �� ��� �ʿ�
    int min_range, max_range;
    int sum = 0;
    int sum_squares = 0;

    printf("������ �ּҰ� �Է�: ");
    scanf_s("%d", &min_range);
    printf("������ �ִ밪 �Է�: ");
    scanf_s("%d", &max_range);

    if (min_range > max_range)     //������ �ּҰ��� �ִ밪���� ũ�� �� ��
    {
        printf("������ �߸��Ǿ����ϴ�.\n");
        return 1;
    }
    else
    {
        printf("���� ����\n");
    }

    for (int i = 0; i < gen_num; i++)         //10���� ���� ������ �Բ� �հ� ������ �� ���
    {
        int num = generate_random_number(min_range, max_range);
        printf("������ ���� %d: %d\n", i + 1, num);   //������ ���ڵ� ���ʴ�� ���
        sum += num;
        sum_squares += num * num;
    }

    double mean = (double)sum / gen_num;                                  //���
    double variance = ((double)sum_squares / gen_num) - (mean * mean);    //�л�
    double std_dev = sqrt(variance);                                      //ǥ������

    printf("�հ�: %d, ���: %.2lf, �л�: %2lf, ǥ������: %.2lf\n", sum, mean, variance, std_dev);

    return 0;
}