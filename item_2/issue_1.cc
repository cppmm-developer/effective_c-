// Q. const, #define, enum 변수의 주소를 취할 때를 확인

#include <iostream>

using namespace std;

int main()
{
    const int const_val = 1;
    #define define_val 2
    enum { enum_val = 3 };
    
    std::cout << "&const_val: " << const_val << std::endl; 
    //std::cout << "&define_val: " << &define_val << std::endl;   // error: lvalue required as unary ‘&’ operand
    //std::cout << "&enum_val: " << &enum_val << std::endl;   // error: lvalue required as unary ‘&’ operand

    return 0;
}
