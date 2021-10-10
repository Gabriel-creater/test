#ifndef __LIST_H__
#define __LIST_H__

typedef struct
{
 int num;
 char end[20];
 float km;
}DATA;

typedef struct node
{
  DATA data;
  struct node *next;  
}NODE,POSITION;


NODE* list_create(DATA);
NODE* list_addhead(NODE*, DATA);
NODE* list_addtail(NODE*, DATA);
NODE* list_insert(NODE*,POSITION*, DATA);
POSITION* list_find(NODE*, DATA);
POSITION* list_findbynum(NODE*, int);
NODE* list_delete(NODE*, DATA);
int list_modify(NODE**, DATA, DATA);
void list_showAll(NODE*);
void list_freeAll(NODE*);

#endif
