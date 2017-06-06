	#include <iostream>
#include <string>

#include "a1_test_3.hpp"

using namespace std;

string get_status_str(bool status)
{
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main()
{
    BigIntTest bitest;

	string big_int_test_descriptions[8] = {
      "Test1: Constructor with boolean array and size",
      "Test2: Constructor with string value input",
      "Test3: addition",
	  "Test4: subtraction",
      "Test5: multiplication",
      "Test6: bitwise and",
      "Test7: bitwise or",
      "Test8: bitwise xor"   
	};
	
	bool big_int_test_results[8];
    big_int_test_results[0] = bitest.test1();
    big_int_test_results[1] = bitest.test2();
    big_int_test_results[2] = bitest.test3();
    big_int_test_results[3] = bitest.test4();
    big_int_test_results[4] = bitest.test5();
    big_int_test_results[5] = bitest.test6();
    big_int_test_results[6] = bitest.test7();
    big_int_test_results[7] = bitest.test8();


	cout << "BIGINT TESTING RESULTS \n";
	cout << "********************************** \n";
	for (int i = 0; i < 8; i++) {
    	cout << big_int_test_descriptions[i] << endl << get_status_str(big_int_test_results[i]) << endl;
	}
	cout << endl;
    system("pause");
}
