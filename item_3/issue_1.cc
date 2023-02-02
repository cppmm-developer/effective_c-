#include <iostream>

using namespace std;

class TextBlock {
    public:
        TextBlock(std::string str) {
            this->text = str;
        };
        ~TextBlock() {};
    public:
        // 비상수 객체에 대한 operator []
        char& operator[](std::size_t position) {
            return text[position];
        }
        
        // 상수 객체에 대한 operator []
        const char& operator[] (std::size_t position) const {
            return const_cast<const char&> (
                        static_cast<TextBlock&>  // error: invalid ‘static_cast’ from type ‘const TextBlock’ to type ‘TextBlock&’
                            (*this)[position]
                    );
        }
    private:
        std::string text;
};

int main()
{
    const TextBlock text_block("World");
    std::cout << "text_block[0]: " << text_block[0] << std::endl;
    return 0;
}
