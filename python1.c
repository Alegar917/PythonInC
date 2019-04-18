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
int ascii(struct node *s );

/* measure the length of the linked list */
int Len( struct node *head)
{
    int size = 0;
    while(head != NULL){
        size++;
        head= head-> next;
    }
    return size;
}

/* insert a node */
struct node* Insert(struct node *head){
    struct node *temp;
    struct node *prev=head;
    int type;
    temp=malloc(sizeof(struct node));
    printf("Choose your data type (1-Integer 2-FLoat, 3-String):");
    scanf("%d",&type);
    if(type==1){
            printf("Enter a Number: ");
            scanf("%d",&temp->data.n);
            temp->type=type;
    }
    if(type==2){
        printf("Enter a decimal: ");
        scanf("%f",&temp->data.f);
        temp->type=type;
    }
    if(type==3){
        printf("Enter a string: ");
        scanf("%s",temp->data.s);
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
    return head;
}

/* Insert at position */
struct node* InsertPos(struct node *head, int pos){
    if(pos>Len(head) || pos<0){
        printf("Invalid postion");
        return head;
    }
    struct node *temp;
    int type;
    struct node *prev=head;
    temp=malloc(sizeof(struct node));
    printf("Choose your data type (1-Integer 2-FLoat, 3-String):");
    scanf("%d",&type);
    if(type==1){
        printf("Enter a Number: ");
        scanf("%d",&temp->data.n);
        temp->type=type;
    }
    if(type==2){
        printf("Enter a decimal: ");
        scanf("%f",&temp->data.f);
        temp->type=type;
    }
    if(type==3){
        printf("Enter a string: ");
        scanf("%s",temp->data.s);
        temp->type=type;
    }
    temp->next=NULL;
   
    if (pos==0){
        temp->next=prev;
        head=temp;
    } 
    else{
        for(int i=0;i<pos-1;i++)
        {
             prev=prev->next;
        }
        temp->next=prev->next;
        prev->next=temp;
        return head;
    }
}

/* Remove at position */
struct node* removePos(struct node *head, int pos){
    if(pos>=Len(head) || pos<0){
        printf("Invalid postion\n");
        return head;
    }
    struct node *prev=head;
    struct node *temp;

    if (pos==0){
        head=head->next;
    } 
    else{
        for(int i=0;i<pos-1;i++)
        {
            prev=prev->next;
        }
        temp=prev->next;
        prev->next=temp->next;
        return head;
    }
}

/* delete a node */
struct node* Deleting(struct node *head){
        if(head==NULL){
                return head;
        }
        head = NULL;
        //head = head->next;
        return head;
}

/* reverse the list */
struct node* Reverse(struct node* head) 
{ 
    struct node* prev   = NULL; 
    struct node* temp = head; 
    struct node* next = NULL; 

    while (temp != NULL) 
    { 
        next  = temp->next;   
        temp->next = prev;    
        prev = temp; 
        temp = next; 
    } 
    head = prev; 
} 

/* concatenate two lists */
void Concat (struct node *head1, struct node *head2)
{ 
    struct node *temp1= head1;
    while (temp1->next != NULL){
        temp1 = temp1 -> next;
    } 
    //append the start of the head2 to the end of temp1
    temp1->next = head2;
}

/* find the MIN */
struct node* Min(struct node *head)
{
    struct node *temp = head;
    struct node *min = NULL;
    float minVal = 0; //comparator value of min node
    while (temp != NULL){
        if(min == NULL){
            min = temp;
            if(temp->type == 3){
                minVal = ascii(temp);
                min->type=temp->type;
            }
            else if(temp->type == 2){
                minVal = temp->data.f;
                min->type=temp->type;
            }
            else if (temp->type == 1){
                minVal = temp->data.n;
                min->type=temp->type;
            }

        }
        else if (temp->type == 3){
            if (ascii(temp)< minVal) {
                min = temp;
                minVal = ascii(temp);
                min->type=temp->type;
            }
        }
        else if (temp->type == 2){
            if(temp->data.f < minVal) {
                min = temp;
                minVal = temp->data.f;
                min->type=temp->type;
            }
        } else {
            if (temp->data.n < minVal) {
                min = temp;
                minVal = min->data.n;
                min->type=temp->type;
            }
        }
        temp = temp -> next;
    }
    return min;
}

/* find the MAX */
struct node* Max (struct node *head)
{
 struct node *temp = head;
    struct node *max = NULL;
    float maxVal = 0; //comparator value of max node
    while (temp != NULL){
        if(max == NULL){
            max = temp;
            if(temp->type == 3){
                maxVal = ascii(temp);
                max->type=temp->type;
            }
            else if(temp->type == 2){
                maxVal = temp->data.f;
                max->type=temp->type;
            }
            else if (temp->type == 1){
                maxVal = temp->data.n;
                max->type=temp->type;
            }

        }
        /* If temp is equal to a string convert it to ascii val*/
        else if (temp->type == 3){
            if (ascii(temp)> maxVal) {
                max = temp;
                maxVal = ascii(temp);
                max->type=temp->type;
            }
        }
        /* If temp is equal to a float or int compare it to current max*/
        else if (temp->type == 2){
            if(temp->data.f > maxVal) {
                max = temp;
                maxVal = temp->data.f;
                max->type=temp->type;
            }
        } else {
            if (temp->data.n > maxVal) {
                max = temp;
                maxVal = max->data.n;
                max->type=temp->type;
            }
        }
        temp = temp -> next;
    }
    return max;
}

/* display */
void Show(struct node *head){
        if(head==NULL){
                printf("The Queue is empty\n");
        }
        else{
                struct node *temp=head;
                printf("The Queue is: \n");
                while(temp!=NULL){
                        if(temp->type==1){
                                printf("%d, ",temp->data.n);
                        }
                        if(temp->type==2){
                                printf("%.2f, ",temp->data.f);
                        }
                        if(temp->type==3){
                                printf("%s, ",temp->data.s);
                        }
                        temp=temp->next;
                }
                printf("\n");
        }
}

/* specific show */
void Specfic_show(struct node *head, int pos){
    if(pos>Len(head) || pos<0){
        printf("Invalid postion\n");
        return;
    }
    if(head==NULL){
        printf("The Queue is empty\n");
    }
    if(pos==0){
        printf("The element is: ");
        struct node *temp=head;
        if(temp->type==1){
            printf("%d\n",temp->data.n);
        }
        if(temp->type==2){
                printf("%.2f\n",temp->data.f);
        }
        if(temp->type==3){
                printf("%s\n",temp->data.s);
        }
        printf("\n");
    }
    else{
        struct node *temp=head;

        for(int i=0;i<pos;i++){
                temp=temp->next;
        }
        printf("The element is: ");
        if(temp->type==1){
            printf("%d\n",temp->data.n);
        }
        if(temp->type==2){
                printf("%.2f\n",temp->data.f);
        }
        if(temp->type==3){
                printf("%s\n",temp->data.s);
        }
        printf("\n");
    }
}

int ascii(struct node *s){
    int count=0;
    for(int i = 0; s->data.s[i] != '\0'; i++){
        count+= s->data.s[i];
    }
    return count;
}
struct node *sort(struct node *head)
{
    //int minVal, minval1;
    //int n = Len(head);
    struct node *hold=NULL;
    struct node *temp=head; 
    struct node *prev=head;
    struct node *test;
    int size=0;

    while(temp != NULL){
        struct node* adding = Min(temp);
        while(prev!= NULL){ //finds the index of the item in the linked list 
            if(temp->data.n == adding->data.n){
                temp=removePos(temp, size);
                break;
            }
            size++;
            prev= prev->next;
        }
        if(hold == NULL){
            hold= adding;
            hold->type = adding->type;
            test=hold;
        }
        else{
            while(hold->next!= NULL){
                hold=hold->next;
            }
            hold->next=adding;
            hold->type = adding->type;
            hold=test;
        }
       prev= temp;
       size=0;
    }   
    return hold;
}

int main(){
    struct node *head=NULL;
    struct node *head1=NULL;
    struct node *temp=NULL;
    struct node* thingy= NULL;
  int choice,pos;
  printf("\t \t **Welcome to Python in C** \t \t \n");
  printf("what would you like to do first\n (1) Insert\n (2) Insert at position\n (3) Remove at position\n (4) Delete\n (5) Reverse the list\n (6) Concatenate\n (7) Find the minimum\n (8) Find the maximum\n (9) Display list\n (10) Display item\n (11) Sort\n (12) Length of the List \n (13) Exit \n ");
  for(;;){
    printf("command:");
    scanf("%d",&choice);
  switch(choice){
    case 1: head=Insert(head);break;
    case 2: printf("Enter the postiton you want to place:");
            scanf("%d",&pos);
            fflush(stdin);
            head=InsertPos(head,pos);
            break;
    case 3: printf("Enter the postiton you want to remove:");
            scanf("%d",&pos);
            fflush(stdin);
            head=removePos(head,pos);
            break;
    case 4: head=Deleting(head);break;
    case 5: head=Reverse(head);break;

    case 6: temp=malloc(sizeof(struct node));
            temp->data.n=21;
            temp->type=1;
            temp->next =NULL;
            head1=temp;
            temp=malloc(sizeof(struct node));
            temp->data.f=6.7;
            head1->next=temp;
            head1->next->type=2;
            // temp=malloc(sizeof(struct node));
            // temp->data.s="bob";
            // head1->next->next=temp;
            // head1->next->->nexttype=3;
            Concat(head,head1);
            break;
    case 7: thingy =Min(head);
            if(thingy->type==1){
                    printf("%d\n",thingy->data.n);
            }
            if(thingy->type==2){
                    printf("%.2f\n",thingy->data.f);
            }
            if(thingy->type==3){
                    printf("%s\n",thingy->data.s);
            }
            break;
    case 8: thingy =Max(head);
            if(thingy->type==1){
                    printf("%d\n",thingy->data.n);
            }
            if(thingy->type==2){
                    printf("%.2f\n",thingy->data.f);
            }
            if(thingy->type==3){
                    printf("%s\n",thingy->data.s);
            }
            break;
    case 9:  Show(head);break;
    case 10:printf("Enter the postiton you want to see:");
            scanf("%d",&pos);
            fflush(stdin);
            Specfic_show(head,pos);
            break;//
    case 11: head=sort(head);break;
    case 12: printf("%d\n",Len(head));break;
    case 13:
        printf("Goodbye");
        while(head!=NULL){
            temp=head;
            head=head->next;
            free(temp);
        }
            return 0;
            break;

    }
    }
}
