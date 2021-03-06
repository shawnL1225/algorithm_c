/* probID: W6-DoublyLinkedList */

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct nd node;
// struct nd
// {
//     int value;
//     node *NEXT, *PREV;
// };

// node *list_iterate(node *POS, int k);
// node *list_search(node *POS, int val);
// node *list_insert_before(node *HEAD, node *POS, int val);
// node *list_insert_after(node *HEAD, node *POS, int val);
// node *list_delete(node *HEAD, node *POS);

// void print_list(node *current)
// {
//     node *fin;
//     while(current != NULL)
//     {
//         printf("%d ", current->value);
//         if(current->NEXT == NULL)
//             fin = current;
//         current = current->NEXT;
//     }
//     printf("\n");
//     while(fin != NULL)
//     {
//         printf("%d ", fin->value);
//         fin = fin->PREV;
//     }
//     printf("\n");
// }

// int main()
// {
//     int n, m;
//     scanf("%d", &n);
//     node *first, *current, *previous, *pos;
//     int num, num_pos;
//     first = NULL;

//     // create linked list
//     for(int i = 0; i < n; i++)
//     {
//         current = (node*)malloc(sizeof(node));
//         scanf("%d", &(current->value));
//         if(i == 0)
//         {
//             first = current;
//             current->PREV = NULL;
//         }
//         else
//         {
//             previous->NEXT = current;
//             current->PREV = previous;
//         }
//         current->NEXT = NULL;
//         previous = current;
//     }

//     scanf("%d", &m);
//     char com[10];

//     for(int i = 0; i < m; i++)
//     {
//         scanf("%s", com);

//         if(com[0] == 'i')
//         {
//             scanf("%d %s %d", &num, com, &num_pos);
//             if(com[0] == 'b')
//             {
//                 pos = list_iterate(first, num_pos);
//                 first = list_insert_before(first, pos, num);
//             }
//             if(com[0] == 'a')
//             {
//                 pos = list_iterate(first, num_pos);
//                 first = list_insert_after(first, pos, num);
//             }
//             if(com[0] == 'f')
//             {
//                 pos = list_iterate(first, num_pos);
//                 current = list_iterate(pos, num);
//                 if(current != NULL)
//                     printf("iterate : %d\n", current->value);
//                 else
//                     printf("iterate : NO\n");
//             }
//         }
//         if(com[0] == 's')
//         {
//             scanf("%d %s %d", &num, com, &num_pos);
//             pos = list_iterate(first, num_pos);
//             current = list_search(pos, num);
//             if(current != NULL && current->value == num)
//                 printf("search : YES\n");
//             else
//                 printf("search : NO\n");
//         }
//         if(com[0] == 'd')
//         {
//             scanf("%d", &num_pos);
//             pos = list_iterate(first, num_pos);
//             first = list_delete(first, pos);
//         }
//         if(com[0] == 'p')
//             print_list(first);
//     }

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

typedef struct nd node;
struct nd
{
    int value;
    node *NEXT, *PREV;
};

node *list_iterate(node *POS, int k){
    if(POS == NULL)
        return NULL;
    if(k==0)
        return POS;
    
    if(k>0){
        return list_iterate(POS->NEXT,k-1);
    }else {
        return list_iterate(POS->PREV,k+1);
    }
        
}
node *list_search(node *POS, int val){
    if(POS == NULL) return NULL;
    if(POS->value == val) return POS;
    if(POS->NEXT != NULL) 
        return list_search(POS->NEXT,val);
    
}
node *list_insert_before(node *HEAD, node *POS, int val){
    node *ins;
    ins = (node*) malloc(sizeof(node));
    
    if(POS == NULL){  //記得放前面
        ins->NEXT == NULL;
        ins->PREV == NULL;
        ins->value = val;
        return ins;
    }

    if(POS->PREV == NULL){
        ins->PREV = NULL;
        ins->NEXT = POS;
        POS->PREV = ins;
        ins->value = val;
        return ins;
    }
    
    node *p = POS->PREV;
    p->NEXT = ins;
    POS->PREV = ins;  
    ins->NEXT = POS;
    ins->PREV = p;
    ins->value = val;
    return HEAD;
   
}
node *list_insert_after(node *HEAD, node *POS, int val){
    node *ins;
    ins = (node*) malloc(sizeof(node));
    
    if(POS == NULL){
        ins->NEXT == NULL;
        ins->PREV == NULL;
        ins->value = val;
        return ins;
    }

    if(POS->NEXT == NULL){
        ins->NEXT = NULL;
        ins->PREV = POS;
        POS->NEXT = ins;
        ins->value = val;
        return HEAD;
    }
    
    node *n = POS->NEXT;
    n->PREV = ins;
    POS->NEXT = ins;
    ins->PREV = POS;
    ins->NEXT = n;
    ins->value = val;
    return HEAD;
}
node *list_delete(node *HEAD, node *POS){
    if(POS == NULL) return HEAD;

    node *n = POS->NEXT;
    node *p = POS->PREV;
    if(p == NULL){
        n->PREV = NULL;
        return n;
    }
    if(n == NULL){
        p->NEXT = NULL;
        return HEAD;
    }
    p->NEXT = n;
    n->PREV = p;
    return HEAD;
}