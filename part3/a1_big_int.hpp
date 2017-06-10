#ifndef A1_BIG_INT_HPP
#define A1_BIG_INT_HPP

#include "a1_doubly_linked_list2.hpp"
#include <string>

class BigInt {
private:
	int bin_size_;
	DoublyLinkedList* number = new DoublyLinkedList();
public:
	//CONSTRUCTORS
	//takes  as  input array  of  booleans and  the  size  of  the  array
	//creates  the  matching  BigInt  instance  andDoublyLinkedList instance
	BigInt(bool B[], int size);
	
	//destructor
	~BigInt();
	
	//default constructor
	BigInt();
	
	//takes string input, creates cooresponding BigInt
	BigInt(std::string value);
	
	int get_bin_size() const; //gets the bin_size_
	DoublyLinkedList* get_linked_list() const; //gets pointer to big_int
	
	void print() const; //prints boolean in string format
	
	BigInt* add(BigInt* rhs) const; // computes “*this + *rhs”
	BigInt* sub(BigInt* rhs); // computes “*this - *rhs”
	BigInt* mul(BigInt* rhs); // computes “*this * *rhs” 
	
	BigInt* and_(BigInt* rhs); // computes bitwise AND of “*this & *rhs”
	BigInt* or_(BigInt* rhs); // computes bitwise OR of “*this | *rhs”
	BigInt* xor_(BigInt* rhs); // computes bitwise XOR of “*this ^ *rhs” 
	
	int amount_nodes(DoublyLinkedList::Node* initial) const;
	
};
#endif 
