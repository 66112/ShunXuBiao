#include "CovertSeqList.h"
int main()
{
	SeqList seq;
	InitSeqList(&seq);     //³õÊ¼»¯
	Increase(&seq);        //À©Èİ
	Destroy(&seq);         //Ïú»Ù
	return 0;
}