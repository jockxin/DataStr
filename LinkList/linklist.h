#ifndef __MYLINKLIST_H__
#define __MYLINKLIST_H__

typedef void LinkList;

typedef struct _tag_LinkListNode{
	struct _tag_LinkListNode* next;	
}LinkListNode;

//创建节点
LinkList *LinkList_Create();

//销毁节点
void LinkList_Destroy(LinkList *list ); 


//清空节点
void LinkList_Clear(LinkList *list ); 

//获取节点长度
int LinkList_Length(LinkList *list );


//插入节点
int LinkList_Insert(LinkList *list,LinkListNode *node, int pos); 

//获取节点
LinkListNode *LinkList_Get(LinkList *list,int pos); 

//删除节点
LinkListNode *LinkList_Delete(LinkList *list, int pos);
#endif
