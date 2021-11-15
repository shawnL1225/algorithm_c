#include<stdio.h>
int num_node, num_edge, packSize;
typedef struct Node Node;
typedef struct Node
{
    int id;
    int weight;
    Node *parent;
    Node **children;

};

int main(){
    scanf("%d%d%d", num_node, num_edge, packSize);
}