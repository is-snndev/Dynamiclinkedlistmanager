//dynamic linked list manager
//The Node before the semicolon is an alias (a shorthand name) created by typedef.
//typedef is a keyword in C that lets you create a new name (alias) for an existing type.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int id;
    char name[100];
    struct node *next;
} Node;

Node* creatememory(int id, const char* name){
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(!newnode){
        printf("Memory allocation failed.");
        return NULL;
    }
    newnode->id=id;
    strcpy(newnode->name, name);
    newnode->next=NULL;
    return newnode;
}

void insertatbeginning(Node**head, int id, const char* name){
    Node* newnode=creatememory(id,name);
    newnode->next=*head;
    *head=newnode;
}

void insertatend(Node**head, int id, const char* name){
    Node* newnode=creatememory(id,name);
    //check if stack is empty
    if(*head==NULL){
        *head=newnode;
        return;
    }
    //traverse the whole list
    Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void deletenode(Node** head, int id){//by id
    Node* temp=*head;
    Node* prev=NULL;
    while(temp!=NULL&&temp->id != id){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Id not found.\n");
        return;
    }

    if(prev==NULL){
        *head=temp->next;
    }else{
        prev->next=temp->next;
    }
    free(temp);
    printf("Node with Id %d deleted\n",id);

}

Node* searchnode(Node* head, int id){//byid
    Node* temp=head;
    while(temp!=NULL){
        if(temp->id==id){
            return temp;
        }
        else{
          temp=temp->next;
        }
    }
          return NULL;
}

void display(Node* head){
    if(head==NULL){
        printf("List is empty.");
        return;
    }
   Node* temp=head;
   while(temp!=NULL){
    printf("Id=%d, Name=%s\n",temp->id,temp->name);
    temp=temp->next;
   }
}

void freeentirelist(Node** head){
    Node* temp=*head;
    while(temp!=NULL){
        Node*next= temp->next;
        free(temp);
        temp=next;
    }
    *head=NULL;
}

int main(){
    Node* head=NULL;
    int choice;
    int id;
    char name[100];
    while(1){
    printf("--Linked List Menu--\n");
    printf("1.Insert at beginning.\n");
    printf("2.Insert at end.\n");
    printf("3.Delete by id.\n");
    printf("4.Search by id.\n");
    printf("5.Display list.\n");
    printf("6.Exit.\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
        printf("Enter id and name:");
        scanf("%d %s",&id,name);
        insertatbeginning(&head,id,name);
        printf("\n");
        break;

        case 2:
        printf("Enter id and name:");
        scanf("%d %s",&id,name);
        insertatend(&head,id,name);
        printf("\n");
        break;

        case 3:
        printf("Enter id:");
        scanf("%d",&id);
        deletenode(&head,id);
        printf("\n");
        break;

        case 4:
        printf("Enter id:");
        scanf("%d",&id);
        Node* found = searchnode(head, id); 
        if (found) 
        { printf("Found: ID=%d, Name=%s\n", found->id, found->name); } 
        else { printf("ID %d not found.\n", id);}
        printf("\n");
        break;

        case 5:
        display(head);
        printf("\n");
        break;

        case 6:
        freeentirelist(&head);
        printf("Exiting\n");
        printf("\n");
        return 0;

        default:
        printf("Invalid choice.\n");
        printf("\n");
    }
   
  }


}

    
