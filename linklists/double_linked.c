#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;

};

struct node* create(struct node *head,int value){
    head=(struct node *)malloc(sizeof(struct node));
    head->data=value;
    head->next=NULL;
    head->prev=NULL;
}

struct node * insert_begin(struct node *head,int value){
    if(head==NULL){
        printf("NO list is created empty list");
        head=malloc(sizeof(struct node));
        head->data=value;
        head->next=NULL;
        head->prev=NULL;

        return head;
    }
    else{
        struct node *temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        temp->prev=NULL;
        head->prev=temp;
        temp->next=head;
        head=temp;

        return head;  
    }
}
void insert_end(struct node *head,int value){
    struct node *ptr =NULL;
    struct node *temp=NULL;
    temp=malloc(sizeof(struct node));
    ptr=head;
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
}

void insert_position(struct node *head,int value,int position){
    struct node *temp =NULL;
    struct node *ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;

    position--;
    while (position!=1)
    {
        ptr=ptr->next;
        position--;
    }
    if(ptr->next==NULL){
        temp->next=NULL;
        temp->prev=ptr;
        ptr->next=temp;
    }
    else{

    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next=temp;
    ptr->next->prev=temp;
    
    }

}

struct node * del_first(struct node *head){
    struct node *ptr=head;
    if(head->next==NULL){
        printf("Only one element in the list");
        head=NULL;
        free(head);
        return head;
    }
    else{
        head=ptr->next;
        ptr->next->prev=NULL;
        free(ptr);
        ptr=NULL;
        return head;

    }
    
}
void del_end(struct node *head){
    struct node *ptr=head;
    if(head->next==NULL){
        printf("Only one element in the list");
    }
    else{
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        ptr->prev->next=NULL;
        free(ptr);
        ptr=NULL;

    }
    
}

void del_pos(struct node *head,int position){
    struct node  *ptr=head;
    struct node *temp;
    if(position==1){
        printf("use del_first function to delete first node\n");
    }
    else{
        while(position!=1){
            ptr=ptr->next;
            position--;

        }
        if(ptr->next==NULL){
            printf("use del_end function to delete last item\n");
        }
        else{
            temp=ptr->prev;
            temp->next=ptr->next;
            ptr->next->prev=temp;
            free(ptr);
            ptr=NULL;
        }
        

    }
    
}

int main(){
    struct node *head;
    int position;
	int value;
	int choice;
	while(choice!=9)
	{
		printf("Enter the choice");
		scanf("%d",&choice);
        if(choice==1){
            printf("Enter the value:");
            scanf("%d",&value);
            head=create(head,value);
        }
		else if(choice==2){
			printf("Enter the value:");
			scanf("%d",&value);
			head=insert_begin(head,value);
		}
		else if(choice==3){
			printf("Enter the value:");
			scanf("%d",&value);
			insert_end(head,value);
		}
		else if(choice==4){
			printf("Enter the value:");
			scanf("%d",&value);
			printf("Enter the position:");
			scanf("%d",&position);
			insert_position(head,value,position);
		}
        else if(choice==5){
            head=del_first(head);
        }
        else if(choice==6){
            del_end(head);
        }
		else if(choice==7){
			printf("Enter the position:");
			scanf("%d",&position);
            del_pos(head,position);
            
        }
		else if(choice==8){
			struct node	*ptr=NULL;
            ptr=head;
            if(ptr==NULL){
                printf("List is empty");
            }
            else{
                while (ptr!=NULL)
                {
                    printf("%d ",ptr->data);
                    ptr=ptr->next;
                }
	        }
		}
		else{
			printf("Wrong choice");
			exit(0);
		}
		
	}

}