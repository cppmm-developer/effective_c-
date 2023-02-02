// Q. 비상수 객체를 생성했는데 상수 객체에 대한 operator[]만 있고 비상수 객체에 대한 operator[]가 없는 경우

#include <iostream>

using namespace std;

class ConstObj {
    public:
        ConstObj(std::string str) {
            this->text = str;
        };
        ~ConstObj() {};
    public:
        // 상수 객체에 대한 operator []
        const char& operator[] (std::size_t position) const 
        { return text[position]; }
    private:
        std::string text;
};

int main()
{
    cConstObj const_obj("World");           // 1. 비상수 객체 생성
    std::cout << const_obj[0] << std::endl; // 2. operator[] 얻어온 값 출력
    
    const_obj[0] = 'J';                     // 3. operator[]주소에 'J' 대입
                                                 // -> const char& 이기 때문에 에러 발생
    std::cout << const_obj[0] << std::endl;
    return 0;
}
