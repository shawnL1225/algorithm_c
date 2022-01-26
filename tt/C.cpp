//
//  main.c
//  16
//
//  Created by 彭薏璇 on 2021/12/16.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
}node;

node* head = NULL;//起始的節點(數值)
node* current = NULL;//目前的節點
node* temp;//暫時的節點
node* end;//
int k = 0;

void addfunction() {
    end = (node*)malloc(sizeof(node));  //配置一個記憶體空間
    int input;
    scanf("%d", &input);
    current = head;  //重頭開始印
    while (current->next != NULL) {
        current = current->next; //印完後前往下一個節點
    }
    current->next = end;
    end->data = input;
    end->next = NULL;

    printf("ADD_SUCC\n");
    k++;
}

void printfunction() {
    current = head;  //重頭開始印
    while (1) {
        if (current->next == NULL) {  //current 的next為NULL的時候停
            break;
        }
        //印目前的節點

        current = current->next; //印完後前往下一個節點
       printf("%d ", current->data);
//        printf("%p\n",current);
    }
    printf("\n");
}

void insertfunction() {
    if (k == 0) {
        printf("INSERT_FAIL\n");
        return;
    }
    int num, d;
    scanf("%d", &num);
    current = head;
    if (current->data == num) {
        scanf("%d", &d);
        temp->data = d;
        temp->next = current;
        head = temp;
        printf("INSERT_SUCC\n");
        k++;
    }
    else {
        while (current->next->data != num) {
            if (current->next->next == NULL) {
                printf("INSERT_FAIL\n");
                return;
            }
            current = current->next;
        }
        temp = (node*)malloc(sizeof(node));
        scanf("%d", &d);
        temp->data = d;
        temp->next = current->next;
        current->next = temp;
        printf("INSERT_SUCC\n");
    }
}

void searchfunction(){
    int n;
    scanf("%d",&n);
    current=head;
    while(current!=NULL){
        if(current->data==n){
            printf("FOUND\n");
            return;
        }
        current=current->next;
    }
    printf("NOT FOUND\n");
}

void updatefunction(){
    int n,c;
    scanf("%d %d",&n,&c);
    current=head;
    while(current!=NULL){
        if(current->data==n){
            current->data=c;
            printf("UPDATE_SUCC\n");
            return;
        }
        current=current->next;
    }
    printf("UPDATE_FAIL\n");
}

void deletefunction(){
    int number;
    scanf("%d",&number);
    current=head;
    while(current->next!=NULL){
//        if(k==0){
//            printf("DELETE_FAIL\n");
//            return;
//        }
        if(current->next->data==number){
            temp=current->next;
            current->next=current->next->next;
            current=temp;
            free(current);
//            printf("%d %p\n",current->data,current);
            printf("DELETE_SUCC\n");
//            k--;
            return;
        }
//        printf("%p\n",current);
        current=current->next;
    }
    printf("DELETE_FAIL\n");
}
    


int main() {
    head = (node*)malloc(sizeof(node));  //配置一個記憶體空間
    current = head; //先讓目前的節點等於起始的節點
    current->next = NULL;//配置記憶體空間給下一個節點

    char comment[10];

    while (scanf("%s", comment) != EOF) {
        if (strcmp(comment, "add") == 0) {
            addfunction();
        }
        else if ((strcmp(comment, "print") == 0)) {
            printfunction();
        }
        else if (strcmp(comment, "insert") == 0) {
            insertfunction();
        }
        else if(strcmp(comment,"search")==0){
            searchfunction();
        }
        else if(strcmp(comment,"update")==0){
            updatefunction();
        }
        else if(strcmp(comment,"delete")==0){
            deletefunction();
        }
    }

    return 0;
}