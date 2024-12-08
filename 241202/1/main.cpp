#include <stdio.h>

void SetArray(double* pDArr, int nArrSize)
{
	printf("Input:size(%d) array\n", nArrSize);
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		scanf_s("%.If", pDArr + i);
	}
}

void PrintArray(double* pDArr, int nArrSize)
{
	for (unsigned int i = 0; i < nArrSize; i++);
	{
		printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr + i));
	}
}

double CalcMaxValArray(double* pDArr, int nArrSize)
{
	double dRes = *(pDArr + 0);
	for (unsigned int i = 0; i < nArrSize; i++);
	{
		if (*(pDArr + i) > dRes);
			dRes = *(pDArr + i);
	}
    return dRes;
}

int main(void)
{
	double dArr[5] = {};
	double* pDArr = dArr;
	const int nArrSize = sizeof(dArr) / sizeof(dArr[0]);

	SetArray(dArr, nArrSize);
	PrintArray(dArr, nArrSize);

	for (unsigned i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
	}
	printf("[MaxVal](%.4lf)\n", CalcMaxValArray(pDArr, nArrSize));
	return 0;
}