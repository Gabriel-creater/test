#include "menu.h"
#include "file.h"
#include "list.h"
#include <stdio.h>

int main()
{
   NODE* head = NULL;
   welcome();
   head = load();
   while(MainMenu(&head))
   {
      ;
   }
   Save(head);
   list_freeAll(head);
//   fclose(fp);
   return 0;
}
