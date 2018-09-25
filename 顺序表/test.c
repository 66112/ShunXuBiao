#include "SeqList.h"
#if 0
void Test1()
{
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 1);
	PushBack(&seq, 1);
	PushFront(&seq, 9);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}
#endif
int main()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PrintSeqList(&seq);
	SelectSortOP(&seq);
	int a=BinarySearch_R(&seq, 0,seq.sz-1,6);
	if (a == -1)
	{
		printf("没找到！\n");
		return 0;
	}
	else
		printf("找到了！下标为:%d \n", a);
	//PrintSeqList(&seq);

	//BubbleSort(&seq);    
	//PrintSeqList(&seq);
	//SelectSortOP(&seq);
	//PrintSeqList(&seq);
	//BubbleSort(&seq);    
	//Insert(&seq, 1, 5);
	//Remove(&seq,4);
	//RemoveAll(&seq, 3);
	//int a = Size(&seq);
	//Test1();
#if 0
	int a=Find(&seq,2);
	if (a == -1)
	{
		printf("没找到！\n");
		return 0;
	}
	else
		printf("找到了！下标为:%d \n", a);
#endif
	return 0;
}