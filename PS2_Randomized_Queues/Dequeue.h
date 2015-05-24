//
//  Dequeue.h
//  class for Dequeue
//
//  Created by Jun Xiong on 5/9/15.
//
//

#ifndef __HW2__Dequeue__
#define __HW2__Dequeue__

#include <stdio.h>
//#include <stdexcept>
#include <typeinfo>
#include <iostream>
using namespace std;

template <class Item>

class Node{
//public:
//    friend class Deque;
public:
    Item item_;
    Node* prev;
    Node* next;
    Node(Node* pre, Node* nxt);
};

template <class Item>
class Deque{
public:
    Deque();
    ~Deque();
    bool isEmpty();
    int size();
    void addFirst(Item it);
    void addLast(Item it);
    Item removeFirst();
    Item removeLast();
    Item remove();
    const Node<Item>* begin();
    const Node<Item>* end();//return the end of the deque (after the last item), NULL usually
    void nextNode(const Node<Item>*);
    Item getItem(const Node<Item>*);  // or need to add const?
//need to find a way to implement iterator
    
private:
    int size_;
    Node<Item> *first, *last;

};

template <class Item>
Node<Item>::Node(Node<Item>* pre, Node<Item>* nxt):prev(pre), next(nxt){
    
}

template <class Item>
Deque<Item>::Deque():first(NULL),last(NULL){
    size_=0;
}

template <class Item>
Deque<Item>::~Deque(){
    //need to delete all the items here
    while(first!=NULL){
        Node<Item> *pt;
        pt=first;
        first=pt->next;
        delete pt;
    }
}

template <class Item>
bool Deque<Item>::isEmpty(){
    if(size_==0)
        return true;
    else return false;
}

template <class Item>
int Deque<Item>::size(){
    return size_;
}

template <class Item>
void Deque<Item>::addFirst(Item it){  // also need to judge whether it's NULL or not? if (typeid(T) == typeid(string), or if (std::is_same<T, int>::value))
    if(typeid(Item) == typeid(char *)){
        if(it == NULL){
            throw "NullPointerException";
        }
    }
    Node<Item> *pt=new Node<Item>(NULL, first);
    pt->item_=it;
    if(size_>0){
        first->prev=pt;
    }
    first=pt;
    size_++;
    if(size_==1){
        last=first;
    }
}

template <class Item>
void Deque<Item>::addLast(Item it){  // here need to think about initialization 
    Node<Item> *pt=new Node<Item>(last, NULL);
    pt->item_=it;
    if(size_>0){
        last->next=pt;
    }
    last=pt;
    size_++;
    if(size_==1){
        first=last;
    }
    //cout<<"Added:\n"<<first->next->item_<<"\t"<<last->prev->item_<<endl;
    
}

template <class Item>
Item Deque<Item>::removeFirst(){
    Node<Item> *pt=first, *nt;
    Item it;
    if(first!=NULL){
        it=first->item_;
        nt=first->next;
        if(nt!=NULL){
            nt->prev=NULL;
        }
        first=nt;
        size_--;
        if(size_==0){
            last=first;
        }
       // cout<<first->item_<<"\t"<<last->item_<<endl;
        delete pt;
        return it;
    }
    else {
        //throw a exception to say that all empty, cannot remove from first
        throw "Remove First error: NoSuchElementExceptionEmptyDeque"; //empty deque
                //there is an error message here
    }
}

template <class Item>
Item Deque<Item>::removeLast(){
    Node<Item> *pt=last,*pr;
    Item it;
    if(last!=NULL){
        it=last->item_;
        pr=last->prev;
        if(pr!=NULL){
            pr->next=NULL;
        }
        last=pr;
        size_--;
        if(size_==0){
            first=last;
        }
        delete pt;
        return it;
    }
    else{
        //throw a exception to say that all empty, cannot remove from first
        throw "Remove Last error: NoSuchElementExceptionEmptyDeque"; //empty deque
    }
}

template <class Item>
Item Deque<Item>::remove(){
    throw "UnsupportedOperationException";
    return 0;
}

template <class Item>
const Node<Item>* Deque<Item>::begin(){
    return first;
}

template <class Item>
const Node<Item>* Deque<Item>::end(){
    if(last==NULL){
        return last;
    }
    else return last->next;
}

template <class Item>
void Deque<Item>::nextNode(const Node<Item>* pt){
    if(pt == NULL){
        throw "Try to get next of NULL";
    }
    else{
        pt=pt->next;
    }
}

template <class Item>
Item Deque<Item>::getItem(const Node<Item>* pt){
    if(pt == NULL){
        throw "Try to get item of NULL";
    }
    else{
        return pt->item_;
    }
}

#endif /* defined(__HW2__Dequeue__) */
