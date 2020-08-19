/* File: deque.cpp

  Implementation of functions for doubly linked list deque.

*/
#include "Deque.h"// contains the declarations of the variables and functions.
#include <cstddef>
#include <iostream>

using namespace std;

Deque::Deque(){
current_size = 0;
left_p = NULL;
right_p = NULL;
cursor = NULL;
}

Deque::Deque(const Deque& dq){

    if (dq.current_size != 0) {
	node * start = dq.left_p;
	left_p = new node(start->data, NULL, NULL);
	right_p = left_p;
	cursor = left_p;
	current_size = 1;
	    while (start != dq.right_p) {
		start = start->next;
		this->push_right(start->data);
		    if(start == dq.cursor) {
			cursor = right_p;
		    }
	    }
	start = NULL;
	delete start;
    } else {
	current_size = 0;
	left_p = NULL;
	right_p = NULL;
	cursor = NULL;
    }
}

Deque::~Deque(){

     while(left_p != right_p) {
	if (cursor == left_p) {
	    cursor = NULL;
	}
	node * temp = left_p;
	left_p = left_p->next;
	delete temp;
	current_size--;
    }

    node * temp = left_p;
    left_p = NULL;
    right_p = NULL;

    if (cursor != NULL) {
	cursor = NULL;
    }

    delete temp;
    current_size = 0;
}

void Deque::push_left(int item){
    node * newNode = new node(item, NULL, NULL);

    if (empty()) {
	left_p = newNode;
	right_p = newNode;
	cursor = newNode;
    } else {
	newNode->next = left_p;
	left_p->prev = newNode;
	left_p = newNode;
    }

    current_size++;
}

void Deque::push_right(int item){
    node * newNode = new node(item, NULL, NULL);

    if (empty()) {
	left_p = newNode;
	right_p = newNode;
	cursor = newNode;
    } else {
	newNode->prev = right_p;
	right_p->next = newNode;
	right_p = newNode;
    }

    current_size++;
}

int Deque::pop_left(){
    if(!empty()) {
	if (left_p == right_p) {
	    node * temp = left_p;
	    left_p = NULL;
	    right_p = NULL;
    	    cursor = NULL;
	    delete temp;
	    current_size--;
	} else {
	    if (cursor == left_p) {
		cursor = left_p->next;
	    }
	    node * temp = left_p;
	    left_p = left_p->next;
	    left_p->prev = NULL;
	    delete temp;
	    current_size--;
	}
    }
}

int Deque::pop_right(){
    if(!empty()) {
	if (left_p == right_p) {
	    node * temp = right_p;
	    left_p = NULL;
	    right_p = NULL;
	    cursor = NULL;
	    delete temp;
	    current_size--;
	} else {
	    if (cursor == right_p) {
	        cursor = right_p->prev;
	    }
	    node * temp = right_p;
	    right_p = right_p->prev;
	    right_p->next = NULL;
	    delete temp;
	    current_size--;
	}
    }
}

bool Deque::empty(){
    return current_size == 0;
}

int Deque::size(){
    return current_size;
}

bool Deque::cursor_left(){
    if (!empty()) {
	if (cursor->prev != NULL) {
	    cursor = cursor->prev;
	    return true;
	} else {
	    return false;
	}
    } else {
	return false;
    }
}

bool Deque::cursor_right(){
    if (!empty()) {
	if (cursor->next != NULL) {
	    cursor = cursor->next;
	    return true;
	} else {
	    return false;
	}
    } else {
	return false;
    }
}

int Deque::peek_left(){
    if (!empty()) {
	return left_p->data;
    }
}

int Deque::peek_right(){
    if (!empty()) {
	return right_p->data;
    }
}

int Deque::get_cursor(){
    if (!empty()) {
    	return cursor->data;
    }
}

void Deque::set_cursor(int i){
    if (!empty()) {
	cursor->data = i;
    }
}

void Deque::display(){
    if (!empty()) {
	node * temp = left_p;
	int displayThem[current_size];
	int counter = 0;

	while(counter < current_size) {
	    displayThem[counter] = temp->data;
	    temp = temp->next;
	    counter++;
	}

	delete temp;
	
	cout << "[";
	for(int i = 0; i < current_size; i++) {
	    cout << displayThem[i] << ";";
	}
	cout << "]";
	cout << " size=" << size();
	cout << ", cursor=";
	if (get_cursor() == 0) {
	    cout << "NULL." << endl;
	} else {
	    cout << cursor->data << "." << endl;
	}

    } else {
	cout << "[] size=0, cursor=NULL." << endl;
    }
}

void Deque::verbose_display(){

    display();
	
    if (!empty()) {
    	node * temp = left_p;
	node * displayAddresses[current_size];
	int counter = 0;

	while(counter < current_size) {
	    displayAddresses[counter] = &(*temp);
	    temp = temp->next;
	    counter++;
	}

	delete temp;

	cout << "[";
	for(int i = 0; i < current_size; i++) {
	    cout << displayAddresses[i] << ";";
	}

	cout << "]";
	cout << " left_p=" << left_p->data;
	cout << ", right_p=" << right_p->data << "." << endl;

    } else {
	cout << "[] size=0, cursor=NULL." << endl;
    }
}
