#include "a1_doubly_linked_list.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(size_ != 0){
		Node* next = NULL;
	    Node* node = head_;
	    while (node->next != NULL) {
	    	next = node->next;
	        delete node;
	        node = NULL;
	        node = next;
	        next = next->next;
	    }
	    head_ = NULL;
	    tail_ = NULL;
	    size_ == 0;
	}
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
	if(size_ == 0) return true;
	return false;
}

bool DoublyLinkedList::full() const
{
	if(size_ == CAPACITY) return true;
	return false;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if(index >= size_){
		return tail_->value;
	}
	else{
		Node* select = head_;
		for(int i = 0; i < index; i++){
			select = select-> next;
		}
		return select->value;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if (size_ == 0) return 0;
	else{
		int i = 0;
		Node* select = head_;
		while(i < size_){
			if (select->value == value){
				return i;
			}
			else{
				select = select->next;
				i++;
			}
		}
		return size_;
	}
}

void DoublyLinkedList::print() const
{
	if(head_ == NULL) return;
	std::cout << "(NULL <-";
	Node* node = head_;
	while(node != NULL){
		std::cout << "[" << node->value << "]" ;
		node = node->next;
		if (node!= NULL) std::cout << "-><-";
	}
	std::cout << "-> NULL)" << std::endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if (index > (size_ - 1)) return NULL;
    else if (index == (size_ - 1)) return tail_;
    else if (index > ((size_ - 1) / 2)) {
        Node* select = tail_;
        for (int i = 0; i < (size_ - 1 - index); i++) {
            select = select->prev;
        }
        return select;
    }
    else {
        Node* select = head_;
        for (int i = 0; i <= index; i++) {
            select = select->next;
        }
        return select;
    }
}

/**
 * Insert node at specified index in the list.
 *
 * @param value to insert at specified index.
 * @param index at which value should be inserted.
 * @return true if insert operation at index is successful.
 * @return false if insert operation at index is unsuccessful.
 */
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if(index > size_ ){
        // do not insert value at index if index is greater than the size of the list
		return false;
	}
	else if(index == 0){
        // insert value at front if index corresponds to the beginnning of list
		return insert_front(value);
	}
	else if(index == size_){
        // insert value at back if index corresponds to the size / end of the list
		return insert_back(value);
	}
	else{
		Node* select = head_;
        // traverse to index of point of insertion
		for(int i = 0; i < index; i++){
			select = select->next;
		}
        // create a new node of value to be inserted
        Node* temp = new Node(value);
        // change associations, next and prev, of nodes before and after point of insertion to include new node at index
		temp->prev = select->prev;
		temp->next = select;
		select->prev = temp;
		select = temp->prev;
		select->next = temp;
		size_++;
		return true;
	}
	return false;
}

/**
 * Insert node at front of the list.
 *
 * @param value to insert at front of list.
 * @return true if insertion of new node with value at front of the list is successful.
 * @return false if insertion of new node with value at front of the list is unsuccessful.
 */
bool DoublyLinkedList::insert_front(DataType value)
{
    // make new node with specified value the head and tail of the list if size of list is zero
	if(size_ == 0){
		head_ = new Node(value);
		tail_ = head_;
		head_->prev = NULL;
		head_->next = NULL;
		size_ ++;
		return true;
	}
    // change next and prev associations of head node of list to include a new node of specified value
	else{
		Node* temp = head_;
		head_ = new Node(value);
		head_-> next = temp;
		head_-> prev = NULL;
		temp-> prev = head_;
		size_++;
		return true;
	}
	return false;
}

/**
 * Insert node at the back of the list.
 *
 * @param value to insert at back of list.
 * @return true if insertion of new node with value at back of the list is successful.
 * @return false if insertion of new node with value at back of the list is unsuccessful.
 */
bool DoublyLinkedList::insert_back(DataType value)
{
    // make new node with specified value the head and tail of the list if size of list is zero
	if(size_ == 0){
		head_ = new Node(value);
		tail_ = head_;
		head_->prev = NULL;
		head_->next = NULL;
		size_ ++;
		return true;
	}
    // change next and prev associations of tail node of the list to include a new node of specified value
	else{
		Node* temp = tail_;
		tail_ = new Node(value);
		temp->next = tail_;
		tail_->next = NULL;
		tail_-> prev = temp;
		size_++;
		return true;
	}
	return false;
}

/**
 * Remove list node at the index specified.
 *
 * @param index of node to be removed from the list.
 * @return true if removal of new node at specified index is successful.
 * @return false if removal of new node at specified index is successful.
 */
bool DoublyLinkedList::remove(unsigned int index)
{
    // removal of node at index is unsuccessful if index is greater than the end index of the list
	if (index > (size_ - 1)) return false;
    else if (index == (size_ - 1)){
    	return remove_back();
	}
	else if (index == 0){
		return remove_front(); 
	}
	else{
		Node* temp = getNode(index);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		temp = NULL;
		return true;
	}
} 

bool DoublyLinkedList::remove_front()
{
	if(size_ == 0) return false;
	else if(size_ == 1){
		delete(head_);
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		return true;
	}
	else{
		Node* temp = head_->next;
		delete(head_);
		head_ = temp;
		head_-> prev = NULL;
		size_--;
		return true;
	}
	return false;
}

bool DoublyLinkedList::remove_back()
{
	if(size_ == 0) return false;
	else if(size_ == 1){
		delete(tail_);
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		return true;
	}
	else{
		Node* temp = tail_->prev;
		delete(tail_);
		tail_ = temp;
		tail_->next = NULL;
		size_--;
		return true;
	}
	return false;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(index >= size_){
		return false;
	}
	else{
		Node* select = head_;
		for(int i = 0; i < index; i++){
			select = select-> next;
		}
		select->value = value;
		return true;
	}
	return false;
}

bool DoublyLinkedList::is_sorted_asc() const {
	if(size_== 0 || size_ == 1) return true;
	else{
		Node* node = head_;
		for(int i = 0; i < size_ - 1; i++){
			if(node->value > node->next->value){
				return false;
			}
			node = node->next;
		}
		return true;
	}
}

bool DoublyLinkedList::is_sorted_desc() const {
	if(size_== 0 || size_ == 1) return true;
	else{
		Node* node = head_;
		for(int i = 0; i < size_ - 1; i++){
			if(node->value < node->next->value){
				return false;
			}
			node = node->next;
		}
		return true;
	}
}

bool DoublyLinkedList::insert_sorted_asc(DataType val) {
	if(size_ == 0) return insert_front(val);
	else if(!full() && is_sorted_asc()){
		Node* node = head_;
		for(int i = 0; i < size_; i++){
			if(node->value > val){
				return this->insert(val, i);
			}
			node = node->next;
		}
		return this->insert_back(val);;
	}
	return false;
}

bool DoublyLinkedList::insert_sorted_desc(DataType val) {
	if(size_ == 0) return insert_front(val);
	else if(!full() && is_sorted_desc()){
		Node* node = head_;
		for(int i = 0; i < size_; i++){
			if(node->value < val){
				return this->insert(val, i);
			}
			node = node->next;
		}
		return this->insert_back(val);;
	}
	return false;
}

void DoublyLinkedList::sort_asc() {
	if (size_ > 1){
		Node* node = head_;
		for (int i = 0; i < size_-1; i++) {
			Node* min = node;
			Node* current = min->next;
			for(int j = i+1; j < size_; j++){
				if (current->value < min->value){
					min = current;
				}
				current = current->next;
			}
			DataType temp = min->value;
			min->value = node->value;
			node->value = temp;
			node = node->next;
		}
	}
}
    
void DoublyLinkedList::sort_desc() {
	if (size_ > 1){
		Node* node = head_;
		for (int i = 0; i < size_-1; i++) {
			Node* max = node;
			Node* current = max->next;
			for(int j = i+1; j < size_; j++){
				if (current->value > max->value){
					max = current;
				}
				current = current->next;
			}
			DataType temp = max->value;
			max->value = node->value;
			node->value = temp;
			node = node->next;
		}
	}
}


