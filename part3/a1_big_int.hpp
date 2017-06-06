#ifndef A1_BIG_INT_HPP
#define A1_BIG_INT_HPP

#include "a1_doubly_linked_list2.hpp"

class BigInt {
private:
	int bin_size_;
	DoublyLinkedList binary;
public:
	//CONSTRUCTORS
	//takes  as  input array  of  booleans and  the  size  of  the  array
	//creates  the  matching  BigInt  instance  andDoublyLinkedList instance
	BigInt(bool B[], int size);
	
	//takes string input, creates cooresponding BigInt
	BigInt(string value);
	
	BigInt* add(BigInt* rhs); // computes “*this + *rhs”
	BigInt* sub(BigInt* rhs); // computes “*this - *rhs”
	BigInt* mul(BigInt* rhs); // computes “*this * *rhs” 
	
	BigInt* and(BigInt* rhs); // computes bitwise AND of “*this & *rhs”
	BigInt* or(BigInt* rhs); // computes bitwise OR of “*this | *rhs”
	BigInt* xor(BigInt* rhs); // computes bitwise XOR of “*this ^ *rhs” 
};
#endif 
