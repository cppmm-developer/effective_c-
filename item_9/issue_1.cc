/* 런타임 정보를 사용하는 가상 함수 예제 */

#include <iostream>
#include <typeinfo>

using namespace std;

class Parent {
 public:
    Parent() { 
        PrintTypeId();
    };
    ~Parent() {};
 public:
    // 런타임 정보를 사용하는 가상함수
    virtual void PrintTypeId() {
        cout << "typeid: " << typeid(*this).name() << std::endl; 
    };
};

class Child : public Parent {
 public:
    Child() {
    };
    ~Child() {};
};

int main() {
    std::cout << "=== Create Child Object ==="<< std::endl;
    Child* child = new Child();
    
    std::cout << "=== Call virtual function ===" << std::endl;
    child->PrintTypeId();

    return 0;
}
