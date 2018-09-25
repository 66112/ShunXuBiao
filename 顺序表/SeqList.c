#include "SeqList.h"
void InitSeqList(pSeqList pSeq)           
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
}

void PushBack(pSeqList pSeq, DateType d)         //尾插
{
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满!\n");
		return;
	}
	pSeq->date[pSeq->sz] = d;
	pSeq->sz++;
}

void PopBack(pSeqList pSeq)         //尾删
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	pSeq->sz--;
}

void PushFront(pSeqList pSeq, DateType d)		  //头插
{
	assert(pSeq != NULL);
	int i = 0;
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满!\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->date[i + 1] = pSeq->date[i];
	}
	pSeq->date[0] = d;
	pSeq->sz++;
}

void PopFront(pSeqList pSeq)       //头删
{
	assert(pSeq != NULL);
	int i = 0;
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (i = 0; i < pSeq->sz-1; i++)
	{
		pSeq->date[i] = pSeq->date[i + 1];
	}
	pSeq->sz--;
}

int Find(pSeqList pSeq, DateType d)      //查找指定元素,找到了，返回下标，找不到，返回-1
{
	assert(pSeq != NULL);
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->date[i] == d)
		{
			return i;
		}
	}
	return -1;
}

void Insert(pSeqList pSeq, int pos, DateType d)   //插在下标为pos的位置处
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	int i = 0;
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满!\n");
		return;
	}
	for (i = pSeq->sz-1; i >= pos ; i--)
	{
		pSeq->date[i + 1] = pSeq->date[i];
	}
	pSeq->date[pos] = d;
	pSeq->sz++;
}

void Erase(pSeqList pSeq, int pos)    //删除下标为pos的元素
{
	assert(pSeq != NULL);
	assert(pos >= 0 && pos < pSeq->sz);
	int i = 0;
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (i = pos; i < pSeq->sz-1; i++)
	{
		pSeq->date[i] = pSeq->date[i + 1];
	}
	pSeq->sz--;
}

void Remove(pSeqList pSeq, DateType d)   //删除指定元素
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->date[i] == d)
		{
			for (j = i; j < pSeq->sz; j++)
			{
				pSeq->date[j] = pSeq->date[j + 1];
			}
			break;
		}
	}
	if (i == pSeq->sz)
	{
		printf("该指定元素不存在!\n");
		return;
	}
	pSeq->sz--;
}

void RemoveAll(pSeqList pSeq, DateType d)  //删除所有的指定元素
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->date[i] != d)
		{
			pSeq->date[j] = pSeq->date[i];
			j++;
		}
	}
	pSeq->sz = j;
}

void BubbleSort(pSeqList pSeq)     //冒泡排序
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	int tmp = 0;
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (i = 0; i < pSeq->sz-1; i++)
	{
		int flag = 0;
		for (j = 0; j < pSeq->sz - 1 - i; j++)
		{
			if (pSeq->date[j]>pSeq->date[j + 1])
			{
				tmp = pSeq->date[j];
				pSeq->date[j] = pSeq->date[j + 1];
				pSeq->date[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}

void SelectSort(pSeqList pSeq)     //选择排序
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	int tmp = 0;
	int min = 0;       //元素下标
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		min = i;
		for (j = i + 1; j < pSeq->sz; j++)
		{
			if (pSeq->date[min] > pSeq->date[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			tmp = pSeq->date[i];
			pSeq->date[i] = pSeq->date[min];
			pSeq->date[min] = tmp;
		}
	}
}

void SelectSortOP(pSeqList pSeq)     //选择排序优化
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	int tmp = 0;
	int start = 0;            //开始元素的下标
	int end = pSeq->sz - 1;   //最后一个元素的下标
	int max = 0;
	int min = 0;
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	while (start < end)
	{
		min = start;
		max = end;
		for (i = start; i <= end; i++)
		{
			if (pSeq->date[min]>pSeq->date[i])
				min = i;
			if (pSeq->date[max] < pSeq->date[i])
				max = i;
		}
		if (end != max)
		{
			tmp = pSeq->date[end];
			pSeq->date[end] = pSeq->date[max];
			pSeq->date[max] = tmp;
		}
		if (min == end)                  //重要:交换后，max为最小值的下标了，min为最大值的下标了
		{
			min = max;
		}
		if (start != min)
		{
			tmp = pSeq->date[start];
			pSeq->date[start] = pSeq->date[min];
			pSeq->date[min] = tmp;
		}
		start++;
		end--;
	}
}

int BinarySearch(pSeqList pSeq, DateType d)   //二分查找
{
	assert(pSeq != NULL);
	int i = 0;
	int left = 0;
	int mid = 0;
	int right = pSeq->sz - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (pSeq->date[mid] == d)
			return mid;
		if (pSeq->date[mid]>d)
			right = mid-1;
		if (pSeq->date[mid] < d)
			left = mid+1;
	}
	return -1;
}

int BinarySearch_R(pSeqList pSeq, int left,int right,DateType d)  //二分查找递归写法
{
	if (left>right)
		return -1;
	int mid = left + (right-left) / 2;
	if (pSeq->date[mid] == d)
		return mid;
	else if (pSeq->date[mid] > d)
		return BinarySearch_R(pSeq, left, mid - 1, d);
	else 
		return BinarySearch_R(pSeq, mid+1, right, d);
	
}

int Size(pSeqList pSeq)       //返回顺序表的大小
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

void Empty(pSeqList pSeq)    //判断顺序表是否为空
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	printf("不为空!\n");
}

void PrintSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->date[i]);
	}
	printf("\n");
}