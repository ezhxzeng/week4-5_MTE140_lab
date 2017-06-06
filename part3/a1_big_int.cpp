#include "a1_big_int.hpp"
#include <iostream>
#include <cmath>

int ascii2int(std::string str) { //assuming only values 0-9
	if (str.empty())
		return 0;
	else if (str.at(0) == '-')
		return -1 * ascii2int(str.substr(1));
	else if (str.at(0) > '9' || str.at(0) < '0')
		return ascii2int(str.substr(1));
	else{
		return ascii2int(str.substr(1))
				//substr makes a new substring from the second character on
				+ (str.at(0) - '0') * pow(10, str.length() -1);
				//when adding or subtracting char; +- deals with ascii values
	}
}

std::string int2ascii(int num){
	std::string converter[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	if(num < 10){
		return (converter[num]);
	}
	else{
		return(int2ascii(num/10) + converter[num%10]);
	}
}

int bin2dec(std::string str){
	if (str.empty())
		return 0;
	else{
		return bin2dec(str.substr(1))
				//substr makes a new substring from the second character on
				+ (str.at(0) - '0') * pow(2, str.length() -1);
				//when adding or subtracting char; +- deals with ascii values
	}
}

std::string dec2bin(int dec){
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
