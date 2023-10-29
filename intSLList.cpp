//************************  intSLList.cpp  **************************

#include <iostream.h>
#include "intSLList.h"

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

void IntSLList::addToHead(int el) {
    IntSLLNode *tmp = new IntSLLNode(el);
    tmp->next = head;
    head = tmp;
    if (tail == 0)
       tail = head;
}

void IntSLList::addToTail(int el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {

}

int IntSLList::deleteFromTail() {

}

void IntSLList::deleteNode(int el) {

}

bool IntSLList::isInList(int el) const {

}

void IntSLList::printAll() const {

}

