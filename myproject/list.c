#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
函数: list_create
功能: 创建一个链表节点
参数: 存储到节点上的数据
返回值:节点的地址
*/

NODE* list_create(DATA dt)
{
  NODE* p =(NODE*)malloc(sizeof(NODE));
  if(!p)
  {
     puts("创建节点失败!");
     return NULL;
  }
  p-> data = dt;
  p-> next = NULL;
  return p;
}


/*
函数: list_addhead
功能: 插入一个节点到链表的头部，使得该节点为头节点
参数: dt:存储到节点上的数据
      head: 插入的链表头指针
返回值:新的链表头指针
*/

NODE* list_addhead(NODE* head,DATA dt)
{
   if(!head)
    return list_create(dt);

   NODE* p = (NODE*)malloc(sizeof(NODE));
   if(!p)
   {
      puts("插入失败!");
      return head;
   }
   p->data = dt;
   p->next = head;
   head = p;
   return head;
}


/*
函数: list_addtail
功能: 插入一个节点到链表的尾部，使得该节点为最后一个节点
参数: dt:存储到节点上的数据
      head: 插入的链表头指针
返回值:新的链表头指针
*/

NODE* list_addtail(NODE* head,DATA dt)
{
   NODE* pNew = (NODE*)malloc(sizeof(NODE));
   if(!pNew)
   {
      puts("创建新的节点失败!");
      return head;
   }
   pNew->data = dt;
   pNew->next = NULL;

   if(!head)
   {
      head = pNew;
      return head;
   }  
   NODE* p = head;
   NODE* q = NULL;
  // while(p->next)
   while(p)
   {
       q = p;
       p = p->next;
   }
  // p->next = pNew;
   q->next = pNew;
   return head;
}

/*
函数: list_insert 
功能: 插入一个节点到链表的中间指定的位置;
参数: dt:存储到节点上的数据
      head: 插入的链表头指针
      pos:  插入的位置
返回值:新的链表头指针
*/
NODE* list_insert(NODE* head,POSITION* pos,DATA dt)
{
  if(!pos)
  {
     return head;
  }
  NODE* pNew = (NODE*)malloc(sizeof(NODE));
  pNew->data = dt;
  pNew->next = pos;

  if(!head)
  {
    pNew ->next = NULL;
    head = pNew;
    return head;
  }
  
  if(pos == head)
  {
     return list_addhead(head,dt);
  }
  NODE* p,*q = NULL;
  p = head;
  while(p)
  {
    if(p == pos)
      break;
    q = p;
    p = p->next;
  }
  q->next = pNew;

  return head;
}
/*
函数: list_find
功能: 查找节点数据所在的位置
参数: head:链表的头指针
      dt:  待查找的数据
返回值:返回找到的数据所在的位置
*/

POSITION* list_findbynum(NODE* head,int num)
{
  if(!head)
   {
      return NULL;
   }
   NODE* p = head;
   while(p)
   {
      if(p->data.num == num)
         return p;
      p = p->next;
   }
   return NULL;
}

POSITION* list_find(NODE* head,DATA dt)
{
   if(!head)
   {
      return NULL;
   }
   NODE* p = head;
   while(p)
   {
      if(memcmp(&p->data,&dt,sizeof(DATA)) == 0)
         return p;
      p = p->next;
   }
   return NULL;
}
 
/*
函数: list_showAll
功能: 遍历整个链表,并输出节点数据
参数: 链表的头指针
返回值:无
*/

void list_showAll(NODE* head)
{
   NODE* p = head;
  // printf("%8s%12s%12s\n","车次","终点站","里程");
   printf("%-16s\t%-12s\t%-12s\n", "车次", "终点站", "里程");

   while(p)
   {
       printf("%-8d\t%-12s\t%-12.2f\n",p->data.num,p->data.end,p->data.km);
       p = p->next;
   }
   //printf("\n");
}

/*
函数: list_delete
功能: 删除链表中的某个节点
参数: head:链表的头指针
      dt: 删除的节点数据
返回值:新的链表头指针
*/

NODE* list_delete(NODE* head,DATA dt)
{
  if(!head)
    return NULL;
  NODE* p = head;
  if(memcmp(&p->data,&dt,sizeof(DATA)) == 0)
  {
     head = p->next;
     free(p);
     return head;
  }
  NODE* q = NULL;
  while(p)
  {
     if(memcmp(&p->data,&dt,sizeof(DATA)) == 0)
     {
         q->next = p->next;
         free(p);
         return head;
     }
     q = p;
     p = p->next;
  }
  return head;
}
/*
函数：list_modify
功能：修改链表中某个节点的数据
参数：head :链表的头指针
      old:要修改的原始数据
      new:修改之后的新数据
返回值：新的链表头指针
*/
int list_modify(NODE** head,DATA old,DATA new)
{
    POSITION* p = list_find(*head,old);
    if (!p)
    {
        return -1;
    }
    p ->data = new;
    return 0;
}

/*
函数: list_freeAll
功能: 回收整个链表
参数: 链表的头指针
返回值:无
*/

void list_freeAll(NODE* head)
{
   NODE* p = head;
   NODE* q = NULL;
  
   while(p)
   {
      q = p;     
      p = p->next; 
	  free(q);
   } 
}
