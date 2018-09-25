#ifndef __COVERT_SEQ_LIST_H__
#define __COVERT_SEQ_LIST_H__
#define INI_NUM 3
#define KAIPI_NUM 2

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;
typedef struct SeqList
{
	DataType* data;
	int capacity;    //容量
	int sz;          //元素个数
}SeqList,*pSeqList;

void InitSeqList(pSeqList pSeq);     //初始化
void PrintSeqList(pSeqList pSeq);       //打印
void Increase(pSeqList pSeq);         //扩容
void Destroy(pSeqList pSeq);          //销毁顺序表

void PushBack(pSeqList pSeq, DataType d);         //尾插
void PopBack(pSeqList pSeq);         //尾删
void PushFront(pSeqList pSeq, DataType d);         //头插
void PopFront(pSeqList pSeq);         //头删
void Insert(pSeqList pSeq, int pos, DataType d);   //插在下标为pos的位置处

int Find(pSeqList pSeq, DataType d);     //查找指定元素,找到了，返回下标，找不到，返回-1

#endif __COVERT_SEQ_LIST_H__