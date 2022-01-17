#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *prev;
    struct node* next;

};

struct node* create(int value){
    struct node *temp=NULL;
    temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->prev=NULL;
    temp->next=NULL;

    temp->prev=temp;
    temp->next=temp;

    return temp;

}

struct node* insert_begin(struct node *tail,int value){
    if(tail==NULL){
        printf("list is empty");
        tail=create(value);
        return tail;
    }
    else{
        struct node *temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->data=value;
        temp->prev=NULL;
        temp->next=NULL;
        temp->next=tail->next;
        temp->prev=tail;
        tail->next->prev=temp;
        tail->next=temp;

        return tail;
    }
}


struct node *insert_end(struct node*tail ,int value){
    if(tail==NULL){
        printf("list is empty");
        tail=create(value);
        return tail;
    }
    else{
        struct node *temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->data=value;
        temp->prev=NULL;
        temp->next=NULL;
        temp->next=tail->next;
        temp->prev=tail;
        tail->next->prev=temp;
        tail->next=temp;
        tail=temp;

        return tail;
    }

}

struct node* insert_position(struct node* tail,int value, int position){
        if(tail==NULL){
            printf("list is empty");
            tail=create(value);
            return tail;
        }
        else if(position==1){
            tail=insert_begin(tail,value);
            return tail;

        }
        else{
            struct node *ptr=tail->next;
            struct node *temp=NULL;
            while (position!=1)
            {
                ptr=ptr->next;
                position--;
                
            }
            if(ptr==tail->next->prev){
                printf("Inserting at the end");
                tail=insert_end(tail,value);
                return tail;
            }
            else{
                temp=malloc(sizeof(struct node));
                temp->data=value;
                temp->prev=NULL;
                temp->next=NULL;
                printf("%d",ptr->data);
                printf("%d",ptr->prev->data);
                temp->next=ptr;
                temp->prev=ptr->prev;
                ptr->prev->next=temp;
                ptr->prev=temp;
                

                return tail;

            }
    
        }   
}

struct node * del_first(struct node *tail){
    struct node *ptr=tail->next;
    if(tail==NULL){
            printf("list is empty");
            return tail;
    }else if(ptr==tail){

        printf("Single element in list");
        free(tail);
        tail=NULL;
        return tail;
    }
    else{
        tail->next=ptr->next;
        ptr->next->prev=tail;
        free(ptr);
        return tail;
    }
    

}

struct node *del_end(struct node *tail){
    struct node *ptr=tail;
    if(tail==NULL){
            printf("list is empty");
            return tail;
    }else if(ptr->next==tail){

        printf("Single element in list");
        free(tail);
        tail=NULL;
        return tail;
    }else{
        tail->prev->next=tail->next;
        tail->next->prev=tail->prev;
        tail=tail->prev;
        free(ptr);
        ptr=NULL;
        return tail;
    }


}

int main(){
    struct node *tail=NULL;
    int position;
	int value;
	int choice;
	while(choice!=9)
	{
		printf("Enter the choice");struct node* temp=malloc(sizeof(struct node));
		scanf("%d",&choice);
        if(choice==1){
            printf("Enter the value:");
            scanf("%d",&value);
            tail=create(value);
        }
		else if(choice==2){
			printf("Enter the value:");
			scanf("%d",&value);
			tail=insert_begin(tail,value);
		}
		else if(choice==3){
			printf("Enter the value:");
			scanf("%d",&value);
			tail=insert_end(tail,value);
		}
		else if(choice==4){
			printf("Enter the value:");
			scanf("%d",&value);
			printf("Enter the position:");
			scanf("%d",&position);
			tail=insert_position(tail,value,position);
		}
        else if(choice==5){
            tail=del_first(tail);
        }
        else if(choice==6){
            tail=del_end(tail);
        }
	
		else if(choice==7){
			struct node	*ptr=NULL;
            ptr=tail->next;
            if(tail==NULL){
                printf("List is empty");	
            }
            else{
                do{
                    printf("%d ",ptr->data);
                    ptr=ptr->next;
                    
                    
                }while (ptr!=tail->next);
		        }
		}else{
			printf("Wrong choice");
			exit(0);
		}
		
	}


}