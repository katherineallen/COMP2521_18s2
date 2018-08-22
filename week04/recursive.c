#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode *Link;
 
typedef struct ListNode {
    int value;
    Link next;
} ListNode;
 
typedef Link List;
 
#define head(L)  (empty(L) ? -1 : (L)->value)
#define tail(L)  (empty(L) ? NULL : (L)->next)
#define empty(L) ((L) == NULL)
 
// display the value contained in a ListNode
#define show(V) { printf("%d \n",(V)); }

Link newNode(int val);
void drop(List L);
List copy(List L);
int length(List L);
int findLength(List L);
int fold(List L, int (*f)(int,int), int z);
void map(List L, int (*f)(int));

int main (int argc, char * argv[]){
    Link list = newNode(1);
    list -> next = newNode(2);
    list -> next -> next = newNode(3);
    show(list -> value);
    show(list -> next -> value);
    show(list -> next -> next -> value);

    List new = copy(list);
    show(new -> value);
    show(new -> next -> value);
    show(new -> next -> next -> value);

    drop(list);

    printf("after drop\n");

    printf("length: %d \n", length(new));


    return EXIT_SUCCESS;
}
 
// create a new ListNode containing supplied value
// prints error and exit()s if can't create a ListNode
Link newNode(int val) {
    Link new = malloc(sizeof(struct ListNode));
    if (!new) {
        printf("Could not malloc\n");
        exit(EXIT_FAILURE);
    }
    new -> value = val;
    new -> next = NULL;
    return new;
}

void drop(List L) { 
    if (!L) {
        return;
    } else {
        drop(L->next);
        free(L);
        return;
    }

}

List copy(List L) {
    if(!L) {
        return NULL;
    } else {
        List new = newNode(L->value);
        new -> next = copy(L->next);
        return new;
    }
}

int fold(List L, int (*f)(int,int), int z) {
    return 0;
}

int one (int x) {
    return 1;
}

int add(int x, int y) {
    return x + y;
}

int findLength(List L) {
    map(L, one);
    return fold(L, add, 0);
}

void map(List L, int (*f)(int)) {
    if (!empty(L)) {
        head(L) = (*f)(head(L));
        (L->value)
        map(tail(L), f);
    }
}

int length(List L) {
   List L1 = copy(L);
   printf("after copy\n");
   int n = findLength(L);
   drop(L1);
   return n;
}