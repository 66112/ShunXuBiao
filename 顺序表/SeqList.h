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
	DateType date[MAX];			    //����
	int sz;                        //Ԫ�ظ���
}SeqList,*pSeqList;

void InitSeqList(pSeqList pSeq);   // ��ʼ��
void PushBack(pSeqList pSeq, DateType d); //β��
void PopBack(pSeqList pSeq);       //βɾ
void PushFront(pSeqList pSeq,DateType d);  //ͷ��
void PopFront(pSeqList pSeq);      //ͷɾ
int Find(pSeqList pSeq, DateType d);    //����ָ��Ԫ��,�ҵ��ˣ������±꣬�Ҳ���������-1
void Insert(pSeqList pSeq, int pos, DateType d);  //�����±�Ϊpos��λ�ô�
void Erase(pSeqList pSeq,int pos);    //ɾ���±�Ϊpos��Ԫ��
void Remove(pSeqList pSeq, DateType d); //ɾ��ָ��Ԫ��
void RemoveAll(pSeqList pSeq, DateType d); //ɾ�����е�ָ��Ԫ��

int Size(pSeqList pSeq);        //����˳���Ĵ�С
void Empty(pSeqList pSeq);     //�ж�˳����Ƿ�Ϊ��

void BubbleSort(pSeqList pSeq);    //ð������
void SelectSort(pSeqList pSeq);    //ѡ������
void SelectSortOP(pSeqList pSeq);    //ѡ�������Ż�

int BinarySearch(pSeqList pSeq, DateType d);  //���ֲ���
int BinarySearch_R(pSeqList pSeq, int left, int right, DateType d);  //���ֲ��ҵݹ�д��

void PrintSeqList(pSeqList pSeq);   //��ӡ
#endif __SEQLIST_H__
