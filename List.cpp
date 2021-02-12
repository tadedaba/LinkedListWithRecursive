/*
	**** This is the "List.cpp" implementation file  ****
	This file implements all the functions defined in the 
	"List.h" header file. Hence it is the file for class
	implimentation. 
*/
#include <iostream>
#include "List.h"
#include <cstddef>
using namespace std;

// reccursion is not needed.
LinkedList::Node * LinkedList::getNode(Item entry, Node * list){
	Node * temp;
	temp = new Node;
	temp->item = entry;
	temp->next = list;
	return temp;
}
//reccursion: Copy constructor
void LinkedList::copy(Node*& source, Node * ptr){
	if(ptr == NULL)
		source = NULL;
	else{
		source = getNode(ptr->item, NULL);
		copy(source->next, ptr->next);
	}
}
//Copy constructor
void LinkedList:: copyNew(const LinkedList& mynew){
	copy(first, mynew.first);
}
//reccursive call is needed
LinkedList::~LinkedList(){
	Node * temp;
	while(first != NULL){
		temp = first;
		first = first->next;
		delete temp;
	}
} 
//Recursive call to copy(_, _)
void LinkedList::operator =(const LinkedList s){
	LinkedList empty;
	if(&s != this){
		empty.~LinkedList();
		copy(first, s.first);
	}
} 
//Recursive call of the length function                                                                                                                                                                                                                                                                                                                                                                                                              
int LinkedList::length(Node*p){
	if(p==NULL)
		return 0;
	else
		return 1+length(p->next);
}
//calls the recursive length(_) func. 
int LinkedList::listLength(){
	int num = length(first);
	return num;
}
// no change
bool LinkedList::isEmpty(){
	Node * ptr;
	ptr = first;
	if(ptr == NULL)
		return true;
	else return false;
}
//reccursive implementation
bool LinkedList::Present(Node*ptr, Item found){
	if(ptr==NULL)
		return false;
	else if (ptr->item == found)
		return true;
	else {
		ptr = ptr->next;
		return Present(ptr, found);
	}
}
//reccursive call
bool LinkedList::isPresent(Item found){
	return Present(first, found);
}
// Recursive implementation
void LinkedList::rec_Insert(Item entry, Node*& p){
	if(p==NULL || entry < p->item)
		p = getNode(entry, p);
	else{
		rec_Insert(entry, p->next);
	}
}
//Recursive call
void LinkedList::insert(Item newItem){
	rec_Insert(newItem, first);
}
// Recursive implementation
void LinkedList::rec_Remove(Item target, Node*&p){
	Node*temp;
	if(p->item == target){
		temp = p;
		p = p->next;
		delete temp;
	}
	else{
		rec_Remove(target, p->next);
	}
}
//Call to the recursive function. 
void LinkedList::remove(Item oldItem){
	rec_Remove(oldItem, first);
}
LinkedList::Item LinkedList::kthValue(Item k){
	Node * prev;
	prev = first;
	for(int i = 0; i < k; i++)
		prev = prev -> next;
	return prev -> item;
}
//No change
void LinkedList::re_Initialize(){
	Node * prev;
	prev = first;
	if(prev == NULL){}
	else{
		LinkedList empty;
		empty.~LinkedList();
	}
}
/* =======================================================================*/
