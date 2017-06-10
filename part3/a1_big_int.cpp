#include "a1_big_int.hpp"
#include <iostream>
#include <cmath>

unsigned int ascii2int(std::string str) { //assuming only values 0-9
	if (str.empty())
		return 0;
	else if (str.at(0) > '9' || str.at(0) < '0')
		return ascii2int(str.substr(1));
	else{
		return ascii2int(str.substr(1))
				//substr makes a new substring from the second character on
				+ (str.at(0) - '0') * pow(10, str.length() -1);
				//when adding or subtracting char; +- deals with ascii values
	}
}

std::string int2ascii(unsigned int num){
	std::string converter[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	if(num < 10){
		return (converter[num]);
	}
	else{
		return(int2ascii(num/10) + converter[num%10]);
	}
}

unsigned int bin2dec(std::string str){
    if (!str.length())
        return 0;
    else 
        return bin2dec(str.substr(1)) + (str.at(0) - '0') * pow(2, str.length() - 1);
}

std::string dec2bin(unsigned int dec){
	if (dec == 0){
		return ("0");
	}
	else if (dec == 1){
		return ("1");
	}
	else{
		return (dec2bin(dec/2) + (dec%2 ? "1":"0"));
	}
}

BigInt::BigInt(){
	bin_size_ = 0;
}

BigInt::~BigInt(){
	delete number;
	number = NULL;
}

BigInt::BigInt(bool B[], int size) {
	std::string str = "";
    for (int i = 0; i < size / 32; i++) {
        for (int j = i * 32; j < 32 * i + 32; j++) {
            str += (B[j] ? "1" : "0");
        }
        number->insert_front(bin2dec(str));
        str = "";
    }
    
    str = "";
    for (int k = size - 1; k > (size / 32) * 32 - 1; k--) {
        str = (B[k] ? "1" : "0") + str;
    }
    number->insert_front(bin2dec(str));
    bin_size_ = size;
    std::cout << "constructor:";
	number->print();
}

int BigInt::get_bin_size() const{
	return bin_size_;
}

int BigInt::amount_nodes(DoublyLinkedList::Node* initial) const {
    if (initial == NULL)
        return 0;
    return 1 + amount_nodes(initial->next);
}

BigInt* BigInt::add(BigInt* rhs) const {
    
    long long sum = 0;
    long long carry = 0;
    
    DoublyLinkedList::Node* end_this = number->head_;
    DoublyLinkedList::Node* end_rhs = rhs->number->head_;
    
    BigInt ans;
    BigInt* answer = &ans;
    
    int count = amount_nodes(number->head_);
    int long_count = amount_nodes(rhs->number->head_);
    DoublyLinkedList::Node* end_longer = number->head_;
    
    if (amount_nodes(number->head_) > amount_nodes(rhs->number->head_)){
    	end_longer = rhs->number->head_;
    	long_count = count;
		count = amount_nodes(rhs->number->head_);
	}
    
    long_count -= count;
    
    for (int i = 0; i < count; i++) {
        sum = end_this->value + end_rhs->value + carry;
        answer->number->insert_back(sum % int(pow(2, 32)));
        carry = sum / int(pow(2, 32));
        end_this = end_this->next;
        end_rhs = end_rhs->next;
        end_longer = end_longer->next;
    }
    
    std::cout << "finished addition of related nodes" << std::endl;
//    for (int i = 0; i < carry / int(pow(2, 32)); i++) {
//        answer->number->insert_back(pow(2, 32));
//    }

    while (carry / int(pow(2, 32)) > 0){
    	sum = end_longer->value + carry;
    	answer->number->insert_back(sum % int(pow(2, 32)));
    	carry = sum / int(pow(2, 32));
    	end_longer = end_longer->next;
	}
	
	std::cout << "finished addition of carry" << std::endl;
	
	for(int i = 0; i < long_count; i++){
		answer->number->insert_back(end_longer->value);
		end_longer = end_longer->next;
	}
	
    std::cout << "finished addition of leftover nodes" << std::endl;
    
    std::cout << "addition of:" << std::endl;
    this->number->print();
    rhs->number->print();
    std::cout << "results:" << std::endl;
    answer->number->print();
	return answer;
}

BigInt* BigInt::and_(BigInt* rhs) {
    
    DoublyLinkedList::Node* end_this = number->head_;
    DoublyLinkedList::Node* end_rhs = rhs->number->head_;
    
    BigInt ans;
    BigInt* answer = &ans;
    
    int count = (amount_nodes(number->head_) < amount_nodes(rhs->number->head_) ? amount_nodes(number->head_) : amount_nodes(rhs->number->head_));
    
    for (int i = 0; i < count; i++) {
        answer->number->insert_back(end_this->value & end_rhs->value);
        end_rhs = end_rhs->next;
        end_this = end_this->next;
    }
    
    for (int i = 0; i < count - (amount_nodes(number->head_) > amount_nodes(rhs->number->head_) ? amount_nodes(number->head_) : amount_nodes(rhs->number->head_)); i++) {
        answer->number->insert_back(0);
    }
        
        return answer;
}
