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
int ascii(struct node *s );

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
    if(type==4){
        //printf("would you like to create a sub-array within your linked list: ");
        // temp->data.a=buildsub();
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

/* delete a node */
struct node* Deleting(struct node *head){
        if(head==NULL){
                return head;
        }
        head = NULL;
        //head = head->next;
        return head;
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

/* reverse the list */
void Reverse(struct node* head) 
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

int ascii(struct node *s){
    int count=0;
    for(int i = 0; s->data.s[i] != '\0'; i++){
        count+= s->data.s[i];
    }
    return count;
    //     for(int i = 0; i < sizeof(s); i++){
    //     count+= s[i];
    // }
    // return count;

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
                        struct node* thingy = Max(head); 
                        if(thingy->type==1){
                                printf("%d\n",thingy->data.n);
                        }
                        if(thingy->type==2){
                                printf("%.2f\n",thingy->data.f);
                        }
                        if(thingy->type==3){
                                printf("%s\n",thingy->data.s);
                        }


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
