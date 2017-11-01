#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct _tag_SeqList{
	int capacity;
	int length;
	int **node;
}TSeqList;

//Create List
SeqList* SeqList_Create(int capacity)
{
	int ret;
	TSeqList *tmp = NULL;	
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if(tmp == NULL){
		ret = 1;
		printf("func SeqList_Create() err:%d\n",ret);
		return ret;
	}
	memset(tmp,0,sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;
	tmp-> node = (TSeqList**)malloc(sizeof(TSeqList*)*capacity);
	memset(tmp->node,0,sizeof(TSeqList*)*capacity);
	return tmp;
}

//Clear List
void SeqList_Clear(SeqList* list)
{
	TSeqList *tmp = NULL;
	if(list == NULL)
	{
		return;
	}

	tmp = (TSeqList*)list;
	tmp->length = 0;
	memset(tmp->node,0,sizeof(void*)*tmp->capacity);
	return;
}


//Get List Length
int SeqList_Length(SeqList* list)
{
	TSeqList * tmp = NULL;
	if(list == NULL)
	{
		return -1;
	}
	tmp =  (TSeqList*)list;
	 return tmp->length;
}

//List Capacity
int SeqList_Capacity(SeqList* list)
{
	TSeqList * tmp = NULL;
	if(list == NULL)
	{
		return -1;
	}

	tmp =  (TSeqList*)list;
	return tmp->capacity; 
}

//Insert 
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList *tmp = NULL;
	int i = 0;
	if(list == NULL|| node == NULL)
	{
		return -1;
	}

	tmp = (TSeqList*)list;

	if(tmp->length >= tmp->capacity)
	{
		return -2;
	}

	if(pos > tmp->length)
	{
		pos = tmp->length;
	}

	for(i=tmp->length;i > pos;i--)
	{
		tmp->node[i] = tmp->node[i-1];
	}

	tmp->node[i] = (int *)node;
	tmp->length ++;
	return 0;
}

//Get Node
SeqListNode *SeqList_Get(SeqList *list, int pos)
{
	TSeqList *tmp = NULL;
	int i = 0;
	if(list == NULL)
	{
		return -1;
	}

	tmp = (TSeqList*)list;
	return tmp->node[pos];
}

//Delete Pos Node
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *tmp = NULL;
	TSeqList *temp = NULL;
	int i = 0;
	if(list == NULL)
	{
		return -1;
	}

	tmp = (TSeqList*)list;
    temp = tmp->node[pos];	
	for(i=pos;i<tmp->length-pos;i++)
	{
		tmp->node[i] = tmp->node[i+1];	
	}
	return temp;
}

