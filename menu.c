#include <stdio.h>

int main(void) {
  int choice;
  printf("\t \t **Welcome to Python in C** \t \t \n");
  printf("what would you like to do first\n (1) Insert\n (2) Insert at position\n (3) Remove at position\n (4) Delete\n (5) Reverse the list\n (6) Concatenate\n (7) Find the minimum\n (8) Find the maximum\n (9) Display list\n (10) Display item\n (11) Sort\n (12) Length of the List \n (13) Exit \n ");

  switch(choice){
    case 1: Insert(head);
    case 2: InsertPos(head);
    case 3: Remove(head);
    case 4: Reverse(head);
    case 5: concat(head);
    case 6: Min(head);
    case 7: Max(head);
    case 8: show(head);
    case 10: Specific_show(head); //
    case 11: Sort(head);
    case 12: Len(head);
    case 13: break;

  }
  return 0;
}
