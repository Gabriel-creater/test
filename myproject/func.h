#ifndef __FUNC_H__
#define __FUNC_H_

#include "list.h"
#include <string.h>
#include <stdlib.h>

NODE* Input(NODE* head,int sel);
void Print(NODE* head);
void Delete(NODE** head);
void query(NODE** head);
void Modify(NODE** head);
int Sort(NODE*, int);
static int condition(DATA* p, DATA* q, int n);
int GetNodeNum(NODE* head);


#endif
