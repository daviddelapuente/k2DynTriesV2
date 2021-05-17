#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../../treeBlock/linkedList.c"

void test1(){
    linkedList* l=createLinkedList(3);
    assert(l!=NULL);
    assert(l->data==3);
    assert(l->next==NULL);
}

void test2(){
    linkedList* l0=createLinkedList(0);
    linkedList* l1=createLinkedList(1);
    linkedList* l2=createLinkedList(2);

    l1->next=l2;
    l0->next=l1;

    linkedList* head=l0;
    int i=0;
    while(head!=NULL){
        assert(head->data==i);
        i++;
        head=head->next;
    }
    assert(head==NULL);

}

void test3(){
    linkedList* l0=createLinkedList(0);
    linkedList* l1=createLinkedList(1);
    linkedList* l2=createLinkedList(2);

    l1->next=l2;
    l0->next=l1;

    linkedList* l3=createLinkedList(3);
    linkedList* l4=createLinkedList(4);
    linkedList* l5=createLinkedList(5);

    l4->next=l5;
    l3->next=l4;

    linkedList *l=concatenateLinkedList(l0,l3);
    linkedList* head=l0;
    int i=0;
    while(head!=NULL){
        assert(head->data==i);
        i++;
        head=head->next;
    }
    assert(head==NULL);

    printLinkedList(l0);

}

int main(){
    test1();
    test2();
    test3();
    return 0;
}