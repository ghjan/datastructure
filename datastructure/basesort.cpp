#include "basesort.h"

//��������Ԫ��
void Swap(ElementType A[], int i, int j)
{
	ElementType tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;

}

//ð������ ��С�����ݷŵ����� �ô����ǳ��� ���ܲ��ã��� O(N*N)
//�������Ԫ�����������棬ð������Ƚ��ʺ��������ݽṹ
void Bubble_Sort(ElementType A[], int N)
{
	for (int P = N - 1; P >= 0; P--) { //���N��
		int flag = 0;  //0��ʾû��ִ�н���
		for (int i = 0; i < P; i++) { /* һ��ð�� ȷ�����ĳ��������� */
			if (A[i] > A[i + 1]) { //�������ݱȽϴ�С��С��������ð
				Swap(A, i, i + 1);
				flag = 1; /* ��ʶ�����˽���*/
			}
		}
		if (flag == 0) break; /* ȫ���޽���*/
	}
}

//�������� һ��ֽ�� 
void InsertionSort(ElementType A[], int N)
{ /* �������� */
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		Tmp = A[P]; /* ȡ��δ���������еĵ�һ��Ԫ�� ����һ����*/
		for (i = P; i > 0 && A[i - 1] > Tmp; i--)
			A[i] = A[i - 1]; /*������������������Ԫ�رȽϲ�����  �Ƴ���λ*/
		A[i] = Tmp; /* �Ž����ʵ�λ��  ������λ*/
	}
}