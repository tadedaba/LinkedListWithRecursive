/*
	**** This is the "List.h" header file. ****
	It contain the following three main parts.
		1. The class LinkedList
			=> This class hosts:
				--> The private data type struct
				--> The private function get_node()  
					to declare and initialize
					the struct object. 
				--> The declaration of nine private functions 
				--> The public constructors 
					- LinkedList() declaration and implimentation
					- LinkedList(const LinkedList& source) declaration.
				--> The declaration of eight public functions & one friend function.
		2. The implementation of the friend function outside the class.
	Precondition:
		=> The program works for integer data only. 
	Postcondition:
		=> It can handle any number of items.
		=> It lists the items from smallest to the largest.
		=> It performs the following functions:
			-> retaining the copy of the original data
			-> inserting new item
			-> deleting an item
			-> re-initializing the list to empty
			-> searching and returning the kth value of the list
			-> looking up for an item in the list
			-> checking if the list content for emptiness
			-> print the list on the screen
			-> counting the number of items in the list.
*/
#include <iostream>
#ifndef _LIST
#define _LIST
#include <ostream>		//for the implementation of the friend function.
using namespace std;
class LinkedList{
	typedef int Item;	//type defination decoration. 
	private:
		struct Node{	// for the linked lists
			Item item;
			Node * next;
		};
		Node * first;
		Node * getNode(Item entry, Node * list);
		
		void copyNew(const LinkedList& mynew);	//to copy the nodes
		void copy(Node*& source, Node * ptr);
		void rec_Insert(Item entry, Node*&p);	//to insert a new node.
		void rec_Remove(Item target, Node*&p);	//to remove a node from a list
		int length(Node * p);		// to count the number of nodes
		bool Present(Node*ptr, Item found);	//to check the existance of an item in the node.
		void write(ostream& out_s,  Node* p)const;	// to write reccursively
		
	public:
		LinkedList(){		//default constructor
			first = NULL;
		}
		void copynew(const LinkedList& mynew);	// copy constructor
		~LinkedList();	// destructor 
		// to re-initialize the list to empty. The make_empty() function 
		// is absent becouse it will have the same function as re_initialize()
		void re_Initialize(); 
		void insert(Item item);			//to insert items to the list
		void remove(Item item); 		//to remove items from the list
		void operator = (LinkedList s); //"="Operator overloading 
		bool isEmpty(); 			//to check if the list is empty or not
		int listLength(); 		//to get the number of nodes in the list
		bool isPresent(Item target); //to check if an item is in the list
		Item kthValue(int item);	//to access the kth item of the list
		//the friend function is used for the purpose of 
		//"<<" operator overloading. 
		friend ostream& operator << (ostream& out_s, const LinkedList& l);
};
// Implimentation of the friend function.
ostream& operator << (ostream& out_s, const LinkedList& l){
	l.write(out_s, l.first);
	return out_s;
}
//This function implements recursive printing
void LinkedList::write(ostream& out_s, Node*p) const{
	if(p != NULL){
		out_s << p->item << ' ';
		write(out_s, p->next);
	}
}
#endif	//end of header file definition.
/* =======================================================================*/
