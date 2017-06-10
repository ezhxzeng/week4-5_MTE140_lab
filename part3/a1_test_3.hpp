#ifndef A1_TESTS_HPP
#define A1_TESTS_HPP

#include "a1_doubly_linked_list2.hpp"
#include "a1_big_int.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class BigIntTest
{
public:
	// Constructor with boolean list and size input
    bool test1()
    {
    	bool test_arr[3] = {1,0,1};
    	BigInt test(test_arr, 3);
    	ASSERT_TRUE(test.get_bin_size() == 3)
	    bool test_arr_big[50] = {1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1};
		BigInt test2(test_arr_big, 50);
    	ASSERT_TRUE(test2.get_bin_size() == 50);
    	return true;
    }

	// Constructor with string value input
    bool test2()
    {
	    return true;
    }

	// addition
    bool test3()
    {
	    return true;
    }
    
    // subtraction
    bool test4()
    {
	    return true;
    }
    
    // multipliction
    bool test5()
    {
	    return true;
    }
    
    // bitwise and
    bool test6()
    {
	    return true;
    }
    
    // bitwise or
    bool test7()
    {
	    return true;
    }
    
    // bitwise xor
    bool test8()
    {
	    return true;
    }
};


#endif
