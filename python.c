#include<stdio.h>
#include<stdlib.h>

enum datatype{INT=1,FLOAT,STR};

union element{
        int n;
        float f;
        char s[100];
};

struct node{
        enum datatype type;
        union element data;
        struct node *next;
};

/* insert a node */
struct node* Insert(struct node *head){
        struct node *temp;
        struct node *prev=head;
        int type;
        temp=malloc(sizeof(struct node));
        printf("Enter the type: ");
        scanf("%d",&type);
        if(type==1){
                printf("Enter a Number: ");
                scanf("%d",&temp->data.n);
                temp->type=type;
        }

        temp->next=NULL;
        if (head==NULL){
                head=temp;
        }
        else{
                while(head->next!=NULL){
                        head=head->next;
                }
                head->next=temp;
                head=prev;
        }
}
struct node* Deleting(struct node *head){
        if(head==NULL){
                return head;
        }
        head = NULL;
        //head = head->next;
}

struct node* Reverse(struct node *head) {
    struct node *temp = head;
    struct node *reversing = NULL;
    struct node *next= temp->next;

    while(next != null) {
        if(reversing == NULL) {
            reversing = temp;
            temp->next = null;
        }
        else{
            temp->next = reversing;
            reversing = temp;
            //reversing = temp;
        }
        temp = next;
        next = next->next;
    }
    return reversing;
}

struct node* Concat (struct node *head1, struct node *head2)
{ 
    struct node *temp1= head1;
    while (temp1->next != null){
        temp1 = temp -> next;
    } 
    //append the start of the head2 to the end of temp1
    temp1.next = head2;
}

struct int Len( struct node *head)
{
    int size = 0;
    while(head != null){
        size++;
        head= head-> next;
    }
    return size;
}

void Show(struct node *head){
        if(head==NULL){
                printf("The Queue is empty\n");
        }
        else{
                struct node *temp=head;
                printf("The Queue is: \n");
                while(temp!=NULL){
                        if(temp->type==1){
                                printf("%d",temp->data.n);
                        }
                        temp=temp->next;
                }
                printf("\n");
        }
}
int main(){
        int type;
        struct node *head=NULL;
        struct node *temp=NULL;
        printf("Choose your data type (1-Integer 2-FLoat, 3-String 4-list):");
        scanf("%d",&type);
        fflush(stdin);
        switch(type){
                case 1:
                        head=Insert(head);
                        Show(head);
                        break;
                //case FLOAt: printf("Enter a real number");
                                //scanf("%d",&element.f);
                                //break;
               //case STR: printf("Enter a string: ");
                                //scanf("%s",element.s);
                                //break;
                default: printf("Invalid choice");
                               while(head!=NULL){
                                        temp=head;
                                        head=head->next;
                                        free(temp);
                                }
                        return 0;

        }
}
