#include "CovertSeqList.h"
void InitSeqList(pSeqList pSeq)     //��ʼ��
{
	assert(pSeq != NULL);
	DataType* tmp = (DataType*)malloc(sizeof(DataType) * INI_NUM);
	if (tmp==NULL)
	{
		perror("ʧ��");
		exit(EXIT_FAILURE);
	}
	pSeq->data = tmp;
	memset(pSeq->data, 0, sizeof(DataType)*INI_NUM);
	pSeq->sz = 0;
	pSeq->capacity = 0;
}

void Increase(pSeqList pSeq)         //����
{
	assert(pSeq != NULL);
	int a = KAIPI_NUM + pSeq->capacity;
	DataType* tmp = (DataType*)realloc(pSeq->data, sizeof(DataType)*a);
	if (tmp == NULL)
	{
		printf("����ʧ��\n");
		exit(EXIT_FAILURE);
	}
	pSeq->capacity += KAIPI_NUM;
	pSeq->data = tmp;
}

void PushBack(pSeqList pSeq, DataType d)         //β��
{
	assert(pSeq != NULL);
	if (pSeq->capacity == pSeq->sz)
	{
		Increase(pSeq);
	}
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;
}

void PopBack(pSeqList pSeq)         //βɾ
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��!\n");
		return;
	}
	pSeq->sz--;
}

void PushFront(pSeqList pSeq, DataType d)         //ͷ��
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->capacity == pSeq->sz)
	{
		Increase(pSeq);
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->sz++;
}

void PopFront(pSeqList pSeq)         //ͷɾ
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��!\n");
		return;
	}
	for (i = 0; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int Find(pSeqList pSeq, DataType d)      //����ָ��Ԫ��,�ҵ��ˣ������±꣬�Ҳ���������-1
{
	assert(pSeq != NULL);
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

void Insert(pSeqList pSeq, int pos, DataType d)   //�����±�Ϊpos��λ�ô�
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	int i = 0;
	if (pSeq->capacity == pSeq->sz)
	{
		Increase(pSeq);
	}
	for (i = pSeq->sz-1; i >= pos ; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}

void Destroy(pSeqList pSeq)          //����˳���
{
	assert(pSeq != NULL);
	free(pSeq);
	pSeq = NULL;
	pSeq->capacity = 0;
	pSeq->sz = 0;
	printf("����˳���!\n");
}

void PrintSeqList(pSeqList pSeq)       //��ӡ
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��!\n");
		return;
	}
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}