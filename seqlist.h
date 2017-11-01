#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;


//Create List
SeqList* SeqList_Create(int capacity);

//Clear List
void SeqList_Clear(SeqList* list);


//Get List Length
int SeqList_Length(SeqList* list);

//List Capacity
int SeqList_Capacity(SeqList* list);

//Insert 
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//Get Node
SeqListNode *SeqList_Get(SeqList *list, int pos);

//Delete Pos Node
SeqListNode* SeqList_Delete(SeqList* list, int pos);
#endif

