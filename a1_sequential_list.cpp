#include "a1_sequential_list.hpp"
#include <cstdlib>

SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	size_ = 0 ;
	data_ = new DataType[cap];
}

SequentialList::~SequentialList()
{
	delete [] data_;
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
	if (index <= size_){
		return data_[index];
	}
	return data_[size_];
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i < size_; i++) {
		if (data_[i] == val)
			return i;
	}
	return size_;
}

void SequentialList::print() const
{
}

bool SequentialList::insert(DataType val, unsigned int index)
{
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
		for (int i = size_; i >= 0 ; i--)  {
			data_[i + 1] = data_[i];
		}
		data_[0] = val;
		size_++;
		return true;
	}
	
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
}

bool SequentialList::remove_front()
{
	if (size_ == 0)	return true;
	else if (size_ == 1) {
		data_[0] = NULL;
		size_ = 0;
	}
	else {
		for (int i = 0; i < size_--; i++) {
			data_[i] = data_[i + 1];
		}
	}
}

bool SequentialList::remove_back()
{
	if (size_ == 0)	return true;
	data_[size_] = NULL;
	size_--;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
}

bool SequentialList::is_sorted_asc() const {

}

bool SequentialList::is_sorted_desc() const {

}

bool SequentialList::insert_sorted_asc(DataType val) {

}

bool SequentialList::insert_sorted_desc(DataType val) {

}

void SequentialList::sort_asc() {
}
    
void SequentialList::sort_desc() {
}
