#include "CovertSeqList.h"
int main()
{
	SeqList seq;
	InitSeqList(&seq);     //��ʼ��
	Increase(&seq);        //����
	Destroy(&seq);         //����
	return 0;
}