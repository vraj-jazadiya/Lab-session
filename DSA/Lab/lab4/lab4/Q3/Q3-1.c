// Alg 1: create node in c

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Memory allocation faild\n");
        return NULL;
    }
    newNode->data = val;
    newNode-> next = NULL;

    return newNode;

};

int main(){
    struct node* n = createNode(10);
    if (n != NULL){
        printf("Node created with data = %d\n",n->data);
    }
    return 0;

}

