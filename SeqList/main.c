#include <stdio.h>
#include <string.h>
#include "seqlist.h"

typedef struct _food{
	int price;
	char name[32];
}Food;


int main(void)
{
	int ret = 0,i=0;
	SeqList *list = NULL;
	
	Food f1,f2,f3;

	f1.price = 20;
	f2.price = 22;
	f3.price = 30;

	list = SeqList_Create(10);

	ret = SeqList_Insert(list,(SeqListNode*)&f1,0);
	ret = SeqList_Insert(list,(SeqListNode*)&f2,0);
	ret = SeqList_Insert(list,(SeqListNode*)&f3,0);
	
	for(i=0; i < SeqList_Length(list); i++)
	{
		Food *tmp = (Food*)SeqList_Get(list,i);
		if(tmp == NULL)
		{
			printf("func SeqList_Get() err:%d\n",ret);
		}
		printf("age:%d\n",tmp->price);
	}

	SeqList_Destroy(list);
	return 0;
}
