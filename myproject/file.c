#include "list.h"
#include <stdio.h>

NODE* load()
{
	NODE* head = NULL;
	FILE* fp = fopen("./bus.dat","rb");
        if(!fp)
        {
            puts("加载文件失败！");
            return NULL;
        }
	DATA dt;
	while(fread(&dt,sizeof(DATA),1,fp) == 1)
      head = list_addtail(head,dt) ;
    fclose(fp);
	return head;
};
int Save(NODE* head)
{
    FILE* fp = fopen("./bus.dat", "wb");
    if (!fp)
    {
        puts("加载文件失败！");
        return -1;
    }
    NODE* p = head;
   // DATA dt = 0;
    //dt = p->data;
    while (p)
    {
        //fprintf(fp,"%8d%20s%.2f\n",p -> data.num,p -> data.end,p -> data.km);
        fwrite(&p -> data, sizeof(DATA), 1, fp);
        p = p->next;
    }
    fclose(fp);

    return 0;
}
//void save()
//{
//    FILE* fp;
//    int i;
//    if ((fp = fopen("./bus.dat", "wb")) == NULL)
//    {
//        printf("cannot open file\n");
//        return;
//    }
//    for (i = 0; i < SIZE; i++) /*二进制写*/
//if (fwrite(&DATA[i], sizeof(DATA), 1, fp) != 1)
//            printf(“file write error\n”);/*出错*/
//    fclose(fp);
//}
/*关闭文件*/


