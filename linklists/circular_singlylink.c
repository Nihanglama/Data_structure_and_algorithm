#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;

};
struct node* create(int value){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->link=temp;
    return temp;
}
struct node* insert_begin(struct node* tail,int value){
    if(tail==NULL){
        printf("Empty list creating the list with given value");
        tail=create(value);
        return tail;
    }else{
        struct node * temp=malloc(sizeof(struct node));
        temp->data=value;
        temp->link=NULL;

        temp->link=tail->link;
        tail->link=temp;
        return tail;

    }
}
struct node* insert_end(struct node *tail,int value){
    struct node *temp=NULL;
    temp=malloc(sizeof(struct node));
    if(tail==NULL){
        printf("Empty list creating the list with given value");
        tail=create(value);
        return tail;
    }else{
        temp->data=value;
        temp->link=NULL;

        temp->link=tail->link;
        tail->link=temp;
        tail=tail->link;

        return tail;
    }
}
struct node* insert_position(struct node *tail,int value,int position){
    if(tail==NULL){
        printf("Empty list creating the list with given value");
        tail=create(value);
        return tail;
    }
    else if(position==1){
        tail=insert_begin(tail,value);
        return tail;
    }
    else{
        struct node *ptr=tail->link;
        position--;
        while (position!=1)
        {
            ptr=ptr->link;
            position--;
        }
        if(ptr->link==tail->link){
            printf("Use insert_end function for inserting in last node\n3");

        }else{
            struct node* temp=malloc(sizeof(struct node));
            temp->data=value;
            temp->link=NULL;

            temp->link=ptr->link;
            ptr->link=temp;
            return tail;
            
        }
        
    }
   

}
struct node * del_first(struct node *tail){
    struct node *ptr=tail->link;
    if(tail->link==tail){
        printf("Single item in the list\n");
        tail=NULL;
    }else if(tail==NULL){
        printf("Empty list cannot delete an item\n");
    }else{
        tail->link=ptr->link;
        free(ptr);
        ptr=NULL;
    }
    return tail;
}
struct node * del_end(struct node *tail){
    if(tail==tail->link){
        printf("Single item in the list\n");
        free(tail);
        tail=NULL;
        return tail;
    }else if(tail==NULL){
        printf("Empty list cannot delete an item\n");
    }
    else{
        struct node *ptr=tail->link;
        while(ptr->link!=tail){
            ptr=ptr->link;
        }
        ptr->link=tail->link;
        free(tail);
        tail=ptr;
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
            ptr=tail->link;
            if(tail==NULL){
                printf("List is empty");
            }
            else{
                do{
                    printf("%d ",ptr->data);
                    ptr=ptr->link;
                    
                    
                }while (ptr!=tail->link);
		        }
		}else{
			printf("Wrong choice");
			exit(0);
		}
		
	}


}