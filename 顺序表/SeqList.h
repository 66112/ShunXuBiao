#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
typedef int DateType;

typedef struct SeqList
{
	DateType date[MAX];			    //数组
	int sz;                        //元素个数
}SeqList,*pSeqList;

void InitSeqList(pSeqList pSeq);   // 初始化
void PushBack(pSeqList pSeq, DateType d); //尾插
void PopBack(pSeqList pSeq);       //尾删
void PushFront(pSeqList pSeq,DateType d);  //头插
void PopFront(pSeqList pSeq);      //头删
int Find(pSeqList pSeq, DateType d);    //查找指定元素,找到了，返回下标，找不到，返回-1
void Insert(pSeqList pSeq, int pos, DateType d);  //插在下标为pos的位置处
void Erase(pSeqList pSeq,int pos);    //删除下标为pos的元素
void Remove(pSeqList pSeq, DateType d); //删除指定元素
void RemoveAll(pSeqList pSeq, DateType d); //删除所有的指定元素

int Size(pSeqList pSeq);        //返回顺序表的大小
void Empty(pSeqList pSeq);     //判断顺序表是否为空

void BubbleSort(pSeqList pSeq);    //冒泡排序
void SelectSort(pSeqList pSeq);    //选择排序
void SelectSortOP(pSeqList pSeq);    //选择排序优化

int BinarySearch(pSeqList pSeq, DateType d);  //二分查找
int BinarySearch_R(pSeqList pSeq, int left, int right, DateType d);  //二分查找递归写法

void PrintSeqList(pSeqList pSeq);   //打印
#endif __SEQLIST_H__
