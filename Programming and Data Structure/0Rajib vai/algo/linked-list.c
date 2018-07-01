#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *head, *tail;

void tail_insert(int v){
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->val = v;
        head->next = NULL;
        tail = head;
    }else{
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->val = v;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
    }
}

void head_insert(int v){
    if(head == NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->val = v;
        head->next = NULL;
        tail = head;
    }else{
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->val = v;
        tmp->next = head;
        head = tmp;
    }
}

void insert_before(int v,int n){
    struct node *curr, *tmp;
    if(head != NULL){
        if(head->val == n){
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->val = v;
            tmp->next = head;
            head = tmp;
            curr = head->next;
        }
        else curr = head;
        while(curr->next != NULL){
            if(curr->next->val == n){
                tmp = (struct node *)malloc(sizeof(struct node));
                tmp->val = v;
                tmp->next = curr->next;
                curr->next = tmp;
                curr = curr->next;
            }
            curr = curr->next;
        }
    }
}

void insert_after(int v,int n){
    struct node *curr, *tmp;
    if(head != NULL){
        curr = head;
        while(curr != NULL){
            if(curr->val == n){
                tmp = (struct node *)malloc(sizeof(struct node));
                tmp->val = v;
                tmp->next = curr->next;
                if(curr->next == NULL) tail = tmp;
                curr->next = tmp;
                curr = curr->next;
            }
            curr = curr->next;
        }
    }
}

void print_linked_list(){
    struct node *curr = head;
    if(curr == NULL) puts("It's Empty...");
    while(curr != NULL){
        printf("%d ",curr->val);
        curr = curr->next;
    }
    printf("\n");
}

void delete_all(int v){
    struct node *tmp, *curr;
    curr = head;
    while(head != NULL && head->val == v){
        tmp = head;
        head = head->next;
        free(tmp);
        curr = head;
    }
    if(curr == NULL) return ;
    while(curr->next != NULL){
        if(curr->next->val == v){
            tmp = curr->next;
            curr->next = curr->next->next;
            free(tmp);
            if(curr->next == NULL) tail = curr;
        }else{
            curr = curr->next;
        }
    }
}

void delete_linked_list(){
    struct node *curr = head,*tmp;
    while(curr != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
        curr = head;
    }
    tail = head = NULL;
}

int main(){
    int i, n, v;

    for(i=1;i<=5;i++){
        tail_insert(i);
    }
    print_linked_list();

    for(i=1;i<=6;i++){
        head_insert(i);
    }
    print_linked_list();

    delete_all(4);

    print_linked_list();

    insert_after(7,5);

    print_linked_list();

    insert_after(8,3);

    print_linked_list();

    insert_before(18,8);

    print_linked_list();

    insert_before(17,7);

    print_linked_list();

    insert_before(17,17);

    print_linked_list();

    delete_linked_list();

    print_linked_list();

    tail_insert(121);

    print_linked_list();
    return 0;
}
