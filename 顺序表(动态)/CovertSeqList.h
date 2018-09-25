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
	int capacity;    //����
	int sz;          //Ԫ�ظ���
}SeqList,*pSeqList;

void InitSeqList(pSeqList pSeq);     //��ʼ��
void PrintSeqList(pSeqList pSeq);       //��ӡ
void Increase(pSeqList pSeq);         //����
void Destroy(pSeqList pSeq);          //����˳���

void PushBack(pSeqList pSeq, DataType d);         //β��
void PopBack(pSeqList pSeq);         //βɾ
void PushFront(pSeqList pSeq, DataType d);         //ͷ��
void PopFront(pSeqList pSeq);         //ͷɾ
void Insert(pSeqList pSeq, int pos, DataType d);   //�����±�Ϊpos��λ�ô�

int Find(pSeqList pSeq, DataType d);     //����ָ��Ԫ��,�ҵ��ˣ������±꣬�Ҳ���������-1

#endif __COVERT_SEQ_LIST_H__