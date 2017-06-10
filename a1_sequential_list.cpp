#include "a1_sequential_list.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap; 
	size_ = 0 ;
	data_ = new DataType[cap]; // create array of DataType of size cap
}

SequentialList::~SequentialList()
{
	delete [] data_; // free data_ dynamic array
	data_ = NULL;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	if (size_ == 0) return true;
	return false;
}

bool SequentialList::full() const
{
	if (size_ == capacity_) return true;
	return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index < size_){
		return data_[index]; // return value at index
	}
	return data_[size_]; // return value at last index if index is out of range of list size
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++) {
		if (data_[i] == val)
			return i; // return index of value if it is found in list
	}
	return size_; // return size of list if value is not found in list
}

void SequentialList::print() const
{
    std::cout << "START" << std::endl;
	for (int i = 0; i < size_; i++){
		std::cout << data_[i] << std::endl;
	}
	std::cout << "END" << std::endl;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
/**
 * insert value at given index.
 *
 * @param val value to insert.
 * @param index index to insert at
 * @return true if successful.
 */
	if (index > size_ || size_ == capacity_) return false;
	else {
		// move values after index of insertion to their subsequent index
		for (int i = size_; i > index ; i--)  {
			data_[i] = data_[i-1];
		}
		// insert value at index in list
		data_[index] = val;
		
		// increment size of list due to addition on another value
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::insert_front(DataType val)
{
/**
 * insert value at first index.
 *
 * @param val value to insert.
 * @return true if successful.
 */
 
 	// no need to move subsequent values if size==0
	if (size_ == 0) { 
		data_[0] = val;
		size_++;
		return true;
	}
	
	//fail if the list is already at capacity
	else if (size_ == capacity_) {
		return false;
	}
	
	else {
		for (int i = size_; i > 0 ; i--)  {
			// move values after index of insertion to their subsequent index
			data_[i] = data_[i-1];
		}
		// insert value at the beginning of the list
		data_[0] = val;
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::insert_back(DataType val)
{
/**
 * insert value to end.
 *
 * @param val value to insert.
 * @return true if successful.
 */
 	//only insert if list is not yet full
	if (size_ < capacity_) {
		data_[size_] = val;
		size_++;
		return true;
	}
	return false;
		
}

bool SequentialList::remove(unsigned int index)
{
/**
 * remove value from index.
 *
 * @param index index of point to remove.
 * @return true if successful.
 */
 	//check if index is valid
	if (index > size_ || size_ == 0)	return false;
	else {
		//move everything after the index forward
		for (int i = index; i < size_; i++) {
			data_[i] = data_[i + 1];
		}
		//decrement size
		size_--;
		//data_[size_] = NULL;
		return true;
	}
	return false;
}

bool SequentialList::remove_front()
{
/**
 * remove value from front.
 *
 * @return true if successful.
 */
 	// check if there is anything to remove
	if (size_ == 0)	return false;
	// if there's only one, no need to move anything else
	else if (size_ == 1) {
		//data_[0] = NULL;
		size_ = 0;
		return true;
	}
	// move everything forward by one
	else {
		for (int i = 0; i < size_; i++) {
			data_[i] = data_[i + 1];
		}
		size_--;
		//data_[size_] = NULL;
		return true;
	}
	return false;
}

bool SequentialList::remove_back()
{
/**
 * remove value from back.
 *
 * @return true if successful.
 */
 	// check if there is anything to remove
	if (size_ == 0)	return false;
	// if valid, decrement size
	else{
		//data_[size_] = NULL;
		size_--;
		return true;	
	}
	return false;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
/**
 * replace value at index.
 *
 * @param index where to replace value.
 * @param val value to replace with
 * @return true if successful.
 */
 	// check if index is valid
	if(index > size_) return false;
	//set value at index to be val
	else{
		data_[index] = val;
		return true;
	}
	return false;
}

bool SequentialList::is_sorted_asc() const {
	if(size_== 0 || size_ == 1) return true;
	for(int i = 0; i < size_ - 1; i++){
		if(data_[i] > data_[i+1]) return false;
	}
	return true;
}

bool SequentialList::is_sorted_desc() const {
	if(size_==0 || size_ == 1) return true;
	for(int i = 0; i < size_ - 1; i++){
		if(data_[i] < data_[i+1]) return false;
	}
	return true;
}

bool SequentialList::insert_sorted_asc(DataType val) {
/**
 * insert in a way to maintain ascending sort.
 *
 * @param val value to insert.
 * @return true if successful.
 */
 	// if nothing present, insert at front
	if(size_ == 0){
		this->insert_front(val);
		return true;
	}
	// only insert if already sorted, and is not full
	else if (this->is_sorted_asc() && size_ != capacity_){
		// go through the list until the next value is greater than val
		for(int i = 0; i < size_; i++){
			if(val < data_[i]){
				// insert val into index where data_[i] is greater
				// use insert function so data_[i] then goes behind inserted val 
				this->insert(val, i);
				return true;
			}
		}
		//if val is larger than anything already present, insert at back
		return this->insert_back(val);
	}
	return false;
}

bool SequentialList::insert_sorted_desc(DataType val) {
/**
 * insert in a way to maintain descending sort.
 *
 * @param val value to insert.
 * @return true if successful.
 */
 	// if nothing present, insert at front
	if(size_ == 0){
		this->insert_front(val);
		return true;
	}
	// only insert if already sorted, and is not full
	else if (this->is_sorted_desc() && size_ != capacity_){
		// go through the list until the next value is smaller than val
		for(int i = 0; i < size_; i++){
			if(val > data_[i]){
				// insert val into index where data_[i] is smaller
				// use insert function so data_[i] then goes behind inserted val 
				return this->insert(val, i);
			}
		}
		//if val is smaller than anything already present, insert at back
		return this->insert_back(val);
	}
	return false;
}

void SequentialList::sort_asc() {
/**
 * sort the list to be ascending.
 *
 */
 	// finish loop when this is confirmed to be sorted
	while (!this->is_sorted_asc()){
		//if values immediatly next to each other are not ascending, switch the values
		for (int i = 0; i < size_-1; i++){
			if(data_[i] > data_[i+1]){
				DataType temp = data_[i];
				data_[i] = data_[i+1];
				data_[i+1] = temp;
			}
		}
	}
}
    
void SequentialList::sort_desc() {
/**
 * sort the list to be decending.
 *
 */
 	// finish loop when this is confirmed to be sorted
	while (!this->is_sorted_desc()){
		//if values immediatly next to each other are not decending, switch the values
		for (int i = 0; i < size_-1; i++){
			if(data_[i] < data_[i+1]){
				DataType temp = data_[i];
				data_[i] = data_[i+1];
				data_[i+1] = temp;
			}
		}
	}
}
