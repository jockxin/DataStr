#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

typedef struct _tag_linkList{
	LinkListNode head;
	int length;
}TLinkList;

//创建节点
LinkList *LinkList_Create()
{
	TLinkList *tmp = NULL;
	tmp = (TLinkList*)malloc(sizeof(TLinkList));
	if(tmp==NULL)
	{
		printf("func LinkList_Create() err\n");
		return NULL;
	}

	memset(tmp,0,sizeof(TLinkList));
	tmp->length=0;
	tmp->head.next = NULL;
	return tmp;
}

//销毁节点
void LinkList_Destroy(LinkList *list ) 
{
	if(list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}


//清空节点
void LinkList_Clear(LinkList *list ) 
{
	TLinkList *tList = NULL;
	tList = (TLinkList*)list;
	if(list == NULL)
	{
		return ;
	}
	tList->head.next=NULL;
	tList->length=0;
	return ;
}

//获取节点长度
int LinkList_Length(LinkList *list )
{
	TLinkList *tList = NULL;
	tList = (TLinkList*)list;
	if(list == NULL)
	{
		return ;
	}

	return tList->length;
}


//插入节点
int LinkList_Insert(LinkList *list,LinkListNode *node, int pos) 
{
	TLinkList *tList = NULL;
	tList = (TLinkList*)list;
	int i = 0;
	LinkListNode *current = NULL;

	if(list == NULL || node == NULL ||pos<0)
	{
		return -1;
	}


	current = &(tList->head);
	for(i=0;i<pos;i++)
	{
		current = current->next;
	}

	node->next = current->next;

	current->next = node;

	tList->length++;
	return 0;
}



//获取节点
LinkListNode *LinkList_Get(LinkList *list,int pos) 
{
	TLinkList *tList = NULL;
	tList = (TLinkList*)list;
	int i = 0;
	LinkListNode *current = NULL;

	if(list == NULL ||pos<0)
	{
		return NULL;
	}
	current = &(tList->head);

	for(i=0; i< pos;i++)
	{
		current = current->next;
	}

	return current->next;
}




//删除节点
LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
	TLinkList *tList = NULL;
	LinkListNode *ret = NULL;
	tList = (TLinkList*)list;
	int i = 0;
	LinkListNode *current = NULL;

	if(list == NULL ||pos<0)
	{
		return NULL;
	}
	current = &(tList->head);

	for(i=0;i<pos;i++)
	{
		current = current->next;
	}

	ret = current->next;
	current->next = ret->next;
	tList->length--;

	return ret;
}

