#include <stdio.h>
#include <stdlib.h>  //���� �Լ� ������ ���� �ʿ��� �������
#include <time.h>    //�ð��� ���� �Լ� ������ ���� �ʿ��� �������
#include <math.h>    //����� ���õ� �Լ� ����� ���� �ʿ��� �������

#define num_flip 10000  //�������� ������ ������ ������ Ƚ�� 10000ȸ ����
#define coin_fwd_status 0  //�ո��� ������ ��� 0���� ǥ��
#define coin_bwd_status 1  //�޸��� ������ ��� 1�� ǥ��

void gen_rand_seed()   //���� ������ ���� ���� �Լ�
{
    srand((unsigned int)(time(NULL)));  //�� ������ �ð� ��ȭ�� ���� ���� ����
}

unsigned int gen_rand_flipcoin()  //��, �޸鿡 ���� �տ��� �����ѵ��� 0�� 1�� ��ȯ�ϴ� �Լ�
{
    return rand() % 2;  //0�̳� 1 ��ȯ
}

int main(void)
{
    gen_rand_seed();

    int sum_fwdflip = 0;
    int sum_bwdflip = 0;     //��, �޸��� Ƚ���� �� �ʱ�ȭ

    for (unsigned int i = 0; i < num_flip; i++)  //������ 10000�� ���� �� ���� �ݺ��� ���
    {
        unsigned int nstatusflipcoin = gen_rand_flipcoin();  //���� ���� ���

        if (nstatusflipcoin == coin_fwd_status)  //if-else������ ��� ���
        {
            sum_fwdflip++;
        }
        else if (nstatusflipcoin == coin_bwd_status)
        {
            sum_bwdflip++;
        }
        else
        {
            printf("error\n");
        }
    }

    printf("���: �ո�=%d (%.2lf%%), �޸�=%d (%.2lf%%)\n", sum_fwdflip, (double)sum_fwdflip / num_flip *100, sum_bwdflip, (double)sum_bwdflip / num_flip * 100);  //��� ���
    
    return 0;
}
 