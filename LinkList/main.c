#include <stdio.h>
#include <string.h>
#include "linklist.h"
#

typedef struct _Node
{
	struct _Node *next;
}Node;

typedef struct _food{
	Node node;
	int price;
	char name[32];
}Food;


int main(void)
{
	int ret = 0,i=0;
	LinkList *list = NULL;
	
	Food f1,f2,f3;

	f1.price = 20;
	f2.price = 22;
	f3.price = 30;

	list = LinkList_Create();

	ret = LinkList_Insert(list,(LinkListNode*)&f1,0);
	ret = LinkList_Insert(list,(LinkListNode*)&f2,0);
	ret = LinkList_Insert(list,(LinkListNode*)&f3,0);
	
	for(i=0; i < LinkList_Length(list); i++)
	{
		Food *tmp = (Food*)LinkList_Get(list,i);
		if(tmp == NULL)
		{
			printf("func LinkList_Get() err:%d\n",ret);
		}
		printf("age:%d\n",tmp->price);
	}

	LinkList_Destroy(list);
	return 0;
}
