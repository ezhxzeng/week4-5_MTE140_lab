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
	if (index > size_ || size_ == capacity_) return false;
	else {
		for (int i = size_; i > index ; i--)  { // move values after index of insertion to their subsequent index
			data_[i] = data_[i-1];
		}
		data_[index] = val; // insert value at index in list
		size_++; // increment size of list due to addition on another value
		return true;
	}
	return false;
}

bool SequentialList::insert_front(DataType val)
{
	if (size_ == 0) {
		data_[0] = val;
		size_++;
		return true;
	}
	else if (size_ == capacity_) {
		return false;
	}
	else {
		for (int i = size_; i > 0 ; i--)  {
			data_[i] = data_[i-1]; // move values after index of insertion to their subsequent index
		}
		data_[0] = val; // insert value at the beginning of the list
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ < capacity_) {
		data_[size_] = val;
		size_++;
		return true;
	}
	return false;
		
}

bool SequentialList::remove(unsigned int index)
{
	if (index > size_ || size_ == 0)	return false;
	else {
		for (int i = index; i < size_; i++) {
			data_[i] = data_[i + 1];
		}
		size_--;
		//data_[size_] = NULL;
		return true;
	}
	return false;
}

bool SequentialList::remove_front()
{
	if (size_ == 0)	return false;
	else if (size_ == 1) {
		//data_[0] = NULL;
		size_ = 0;
		return true;
	}
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
	if (size_ == 0)	return false;
	else{
		//data_[size_] = NULL;
		size_--;
		return true;	
	}
	return false;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(index > size_) return false;
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
	if(size_ == 0){
		this->insert_front(val);
		return true;
	}
	else if (this->is_sorted_asc() && size_ != capacity_){
		for(int i = 0; i < size_; i++){
			if(val < data_[i]){
				this->insert(val, i);
				return true;
			}
		}
		return this->insert_back(val);
	}
	return false;
}

bool SequentialList::insert_sorted_desc(DataType val) {
	if(size_ == 0){
		this->insert_front(val);
		return true;
	}
	else if (this->is_sorted_desc() && size_ != capacity_){
		for(int i = 0; i < size_; i++){
			if(val > data_[i]){
				return this->insert(val, i);
			}
		}
		return this->insert_back(val);
	}
	return false;
}

void SequentialList::sort_asc() {
	while (!this->is_sorted_asc()){
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
	while (!this->is_sorted_desc()){
		for (int i = 0; i < size_-1; i++){
			if(data_[i] < data_[i+1]){
				DataType temp = data_[i];
				data_[i] = data_[i+1];
				data_[i+1] = temp;
			}
		}
	}
}
