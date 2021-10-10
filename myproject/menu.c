#include <stdio.h>
#include "menu.h"
#include "func.h"
#include <stdlib.h>

void welcome()
{
	printf("\n\n");

    printf("  \t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("  \t┃ ****************************************************** ┃\n");
	printf("  \t┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
	printf("  \t┃ * ┃************************************************┃ * ┃\n");
	printf("  \t┃ * ┃***                                         ****┃ * ┃\n");
	printf("  \t┃ * ┃***        欢迎使用智能公交调度子系统       ****┃ * ┃\n");
	printf("  \t┃ * ┃***                                         ****┃ * ┃\n");
	printf("  \t┃ * ┃***                                         ****┃ * ┃\n");
	printf("  \t┃ * ┃***               嵌入式2107班              ****┃ * ┃\n");
	printf("  \t┃ * ┃***                                         ****┃ * ┃\n");
	printf("  \t┃ * ┃***                Ver1.00.00               ****┃ * ┃\n");
	printf("  \t┃ * ┃***                                         ****┃ * ┃\n");
	printf("  \t┃ * ┃************************************************┃ * ┃\n");
	printf("  \t┃ * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ * ┃\n");
	printf("  \t┃ ****************************************************** ┃\n");
	printf("  \t┗━━━━━━━━━━━━━━━━━━━━━━按任意键继续━━━━━━━━━━━━━━━━━━━━━━┛\n");
    
	getchar();
}

int MainMenu(NODE** head)
{
        system("clear");
	puts("\n\t\t1、浏览所有已调度信息");
	puts("\t\t2、添加调度信息");
	puts("\t\t3、删除已调度信息");
	puts("\t\t4、修改调度信息");
	puts("\t\t5、查找调度信息");
	
	puts("\t\t0、退出");
        puts("\n\n");
	printf("\t\t请选择：");
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
                system("clear");
		while (SortMenu(*head))
			;
		break;
	case 2:
                system("clear");
		while (AddMenu(head))
			;
		break;
	case 3:
		    	system("clear");
		Delete(head);
		break;
	case 4:
			   system("clear");
		Modify(head);
		break;
        case 5:
			   system("clear");
        query(head);
        break;
	}

	return i;
}

int SortMenu(NODE* head)
{
	puts("\n\n\t\t1、按运行车次排序");
	puts("\t\t2、按终点站名称排序");
	puts("\t\t3、按全程里数排序");
	puts("\t\t4、不排序打印"); 
	puts("\t\t0、返回主菜单");
        puts("\n\n");
	printf("\t\t请选择：");
	int i = 0;
	scanf("%d", &i);
	
	switch (i)
	{
	case 1:
	case 2:
	case 3:
		Sort(head,i);
		break;
	case 4:
		Print(head);
		break;
	}
	
	return i;
}

int AddMenu(NODE** head)
{
	puts("\n\n\t\t1、向头部插入");
	puts("\t\t2、向尾部插入");
	puts("\t\t0、返回主菜单");

        puts("\n\n");
	printf("\t\t请选择：");

	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	case 2:
		*head = Input(*head,i);
		break;
	}
	return i;
}

