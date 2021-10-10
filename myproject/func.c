#include "func.h"
#include <stdio.h>

NODE* Input(NODE* head,int sel)
{
  DATA dt = {0};
  printf("请输入线路号:");
  scanf("%d",&dt.num);
  printf("请输入终点站:");
  scanf("%s",dt.end);
  printf("请输入公里数:");
  scanf("%f",&dt.km);

  if(sel == 1)
    return list_addhead(head,dt);
  else
    return list_addtail(head,dt);
}

void Print(NODE* head)
{
  list_showAll(head);  
}


void Delete(NODE** head)
{ 
   int lineno = 0;
   char ch = ' ';
  do
  {
	   printf("请输入要删除的线路号:");
	   scanf("%d",&lineno);
	   
	   NODE* p  = *head;
	   while(p)
	   {
		   if(p -> data.num == lineno)
		   {
			   break;
		   }
			p = p -> next;
	   }
	   if(p == NULL)
	   {
		   puts("删除的线路不存在");
	   }
	   else
	   {
	       * head =  list_delete(*head,p -> data);   
	       list_showAll(*head);
	   }
       ch = getchar();

	   printf("是否继续? Y or N\n");
	   ch = getchar();
  }while(ch == 'Y');

}
void query(NODE** head)
{
	int lineno = 0;
	char ch = ' ';
	do
	{
		printf("请输入要查找的线路号:");
		scanf("%d", &lineno);

		NODE* p = *head;
		while (p)
		{
			if (p->data.num == lineno)
			{
				break;
			}
			p = p->next;
		}
		if (p == NULL)
		{
			puts("查找的线路不存在");
		}
		else
		{
			printf("%-16s\t%-12s\t%-12s\n", "车次", "终点站", "里程");
			printf("%-8d\t%-12s\t%-12.2f\n", p->data.num, p->data.end, p->data.km);
			//printf("%-8d\t%-12s\t%-12.2f\n", p[i]->num, p[i]->end, p[i]->km);

		}
		ch = getchar();

		printf("是否继续? Y or N\n");
		ch = getchar();
	} while (ch == 'Y');
}
void Modify(NODE** head)
{
	int lineno = 0;
	char ch = ' ';
	//NODE* p = NULL;
	//DATA dt = p->data;
	//p = list_findbynum(*head,lineno);

	do
	{
		printf("请输入要修改的线路号:");
		scanf("%d", &lineno);
		NODE* q = *head;
		while (q)
		{
			if (q->data.num == lineno)
			{
				break;
			}
			q = q->next;
		}
		if (q == NULL)
		{
			puts("您所要修改的线路不存在");
		}
		else
		{
			DATA dt;
			printf("请输入修改完成之后的线路号：");
			scanf("%d", &dt.num);
			list_modify(head,q -> data,dt);
			printf("请输入要修改的终点站：");
			scanf("%s", &dt.end);
			list_modify(head,q -> data,dt);
			printf("请输入要修改的公里数：");
			scanf("%f", &dt.km);
			list_modify(head,q -> data,dt);
			list_showAll(*head);
		}
		ch = getchar();
		printf("是否继续? Y or N\n");
		ch = getchar();
	} while (ch == 'Y');
}
int GetNodeNum(NODE* head)
{
	int n = 0;
	while (head)
	{
		n++;
		head = head->next;
	}
	return n;
}
static int condition(DATA* p, DATA* q, int n)
{
	switch (n)
	{
	case 1:
		return p->num < q->num;
	//case 2:
	//	return p->timer < q->timer;
	case 2:
		return strcmp(p -> end,q -> end)< 0;
	case 3:
		return p->km < q->km;
	default:
		return 0;
	}
}

int Sort(NODE* head, int idx)
{
	int n = GetNodeNum(head);
	DATA** p = (DATA**)calloc(sizeof(DATA*), n);
	if (!p)
	{
		return -1;
	}
	register int i = 0, j;//i要初始化！！！！
	while (head)
	{
		p[i] = &(head->data);
		i++;
		head = head->next;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (condition(p[j], p[j + 1], idx))
			{
				DATA* t = p[j];
				p[j] = p[j + 1];
				p[j + 1] = t;
			}
		}
	}
	int count = 0;
	printf("%-16s\t%-12s\t%-12s\n", "车次", "终点站", "里程");
	for (i = 0; i < n; i++)
	{
		printf("%-8d\t%-12s\t%-12.2f\n", p[i]->num, p[i]->end, p[i]->km);
		count++;
	}
	printf("共有 %d 条记录", count);
	free(p);

	return 0;
}
