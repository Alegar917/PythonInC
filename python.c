#include<stdio.h>
#include<stdlib.h>

enum datatype{INT=1,FLOAT,STR};


// union sub{
//         int n;
//         float f;
//         char s[100];
//         enum datatype type;
// };

union element{
        int n;
        float f;
        char s[100];
        union sub *a;
};

struct node{
        enum datatype type;
        union element data;
        struct node *next;
};

// void buildsub(){
//     int n, type, i=0;
//     printf("how big is your array?\n");
//     scanf("%d", &n);
//     union sub A[n];
//     printf("Enter the type: ");
//     scanf("%d",&type);
//     if(type==1){
//             printf("Enter a Number: ");
//             scanf("%d",&A[i]);
//             A[i]->type=type;
//     }
//     if(type==2){
//         printf("Enter a decimal: ");
//         scanf("%f",&A[i]);
//         A[i]->type=type;
//     }
//     if(type==3){
//         printf("Enter a string: ");
//         scanf("%s",A[i]);
//         A[i]->type=type;
//     }
//     i++;


// }
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
        // if(type==4){
        //     //printf("would you like to create a sub-array within your linked list: ");
        //     temp->data.a=buildsub();
        //     temp->type=type;
        // }
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

// struct node* Reverse(struct node *head) {
//     struct node *temp = head;
//     struct node *reversing = NULL;
//     struct node *tail= NULL;

//     for(int i=0;i<Len(head);i++){
//          if(reversing==NULL){
//                     reversing=temp->value;
//             }
//           else{
//             temp->next=reversing;
//             reversing=temp;
//         }
//     }
//     return reversing;
// }

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


struct node* Concat (struct node *head1, struct node *head2)
{ 
    struct node *temp1= head1;
    while (temp1->next != NULL){
        temp1 = temp1 -> next;
    } 
    //append the start of the head2 to the end of temp1
    temp1->next = head2;
}

int Len( struct node *head)
{
    int size = 0;
    while(head != NULL){
        size++;
        head= head-> next;
    }
    return size;
}

// union element Min (struct node *head)
// {
//     int size = 0;
//     node temp= head;
//     if (head==NULL)
//         return;
//     while(temp != NULL){
//         if(temp->type=3 && temp->next->type !=3 || temp->type!=3 && temp->next->type ==3)
//         {
//             //
//         }
//         else if (temp->type=3 && temp->next->type =3)
//         {
//             if(asci(temp)<asci(temp->next)){
//                 if(asci(temp< size))
//                     size= asci(temp);
//             }
//         }
//         else if(temp->data < temp->next->data)
//             size= temp->data;
//         else if(temp->data > temp->next->data)
//             size= temp->data;

//     }



// }
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
int asci(char *s){
    int count=0;
    for(int i=0; s[i]!='\0'; i++){
        count+= s[i];
        }
    return count;
}
int main(){
        int type;
        struct node *head=NULL;
        struct node *head1=NULL;
        struct node *temp=NULL;

        printf("Choose your data type (1-Integer 2-FLoat, 3-String 4-list):");
        scanf("%d",&type);
        fflush(stdin);
        switch(type){
                case 1:
                        head=Insert(head);
                        //head=Insert(head);
                        //head=Insert(head);
                        head1=Insert(head1);
                        //head1=Insert(head1);
                        //head1=Insert(head1);
                        Concat(head,head1);
                        //Show(head);
                        printf("len:%d\n",Len(head));
                        //head=Reverse(head);
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
