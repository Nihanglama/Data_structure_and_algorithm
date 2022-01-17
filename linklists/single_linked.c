#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node	*link;
};

struct node* create(struct node *head,int value){
    head=malloc(sizeof(struct node));
    head->data=value;
    head->link=NULL;
}

struct node* insert_begin(struct node *head,int value){
	if(head==NULL){
        printf("list is empty");
	}
	else{
		struct node *temp=NULL;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=value;
		temp->link=head;
		head=temp;

		return head;
	}
}
void insert_end(struct node *head, int value){
	struct node *temp=NULL;
	struct node *ptr=NULL;
	ptr=head;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->link=NULL;
	if(head==NULL){
        printf("Emptylist");
	}
	else{
		while (ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}

}


void insert_position(struct node *head, int value,int position){
	struct node *temp=NULL;
	struct node *ptr=NULL;
    int i;
	
	ptr=head;
	if(ptr==NULL){
		printf("Link list is empty ");
	}
	else{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=value;
        temp->link=NULL;

        
        if(position==1){
            printf("position should be greater than 1\n");
        }
        else
        position--;
        while (position!=1)
        {
            ptr=ptr->link;
            position--;
        }
		temp->link=ptr->link;
		ptr->link=temp;

	}

}

struct node * del_first(struct node *head){
    if(head==NULL){
        printf("empty list");
    }
    else{
        struct node *temp=head;
        head=head->link;
        free(temp);
    }
    return head;
}
void del_end(struct node *head){
    if(head==NULL){
        printf("empty list");
    }
    else{
        struct node *temp=head;
        while (temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
        
    }
}
void del_pos(struct node *head,int position){
	struct node *tem=NULL;
	tem=head;
	position--;
	while(position!=1){
		tem=tem->link;
		position--;
	}
	free(tem->link);
	tem->link=tem->link->link;

}

int main(){
	struct node	*head =NULL;
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
                    ptr=ptr->link;
                }
	        }
		}
		else{
			printf("Wrong choice");
			exit(0);
		}
		
	}
	
	


}

