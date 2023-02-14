/*
MISTAKE_TEST = 1 : 생성이 채 끝나지 않은 BuyTransaction 객체의 미초기화된 데이터 멤버를 자칫 실수로 건드리는 예제 코드
MISTAKE_TEST = 0 : 정적 멤버 함수로 선언하여, 미초기화된 데이터 멤버를 건드리는 실수 방지하는 예제 코드
*/

#define MISTAKE_TEST 1

#include <iostream>
#include <typeinfo>

using namespace std;

#if MISTAKE_TEST
class Transaction {
 public:
    explicit Transaction(const std::string& logInfo) {
        logTransaction(logInfo);
    };
    ~Transaction() {};
    void logTransaction(const std::string& logInfo) const {
        std::cout << "logTransaction: " << logInfo << std::endl;
    };
};

class BuyTransaction : public Transaction {
 public:
    BuyTransaction(int var) 
        : Transaction(createLogString(var))
         ,multiple(10) {
    };
    ~BuyTransaction() {};
 private:
    int multiple;
    std::string createLogString(int var) {
        return std::to_string(var*multiple);
    };
};

int main() {
    std::cout << "=== BuyTransaction creating string through member function  ===" << std::endl;
    BuyTransaction* buy_transaction = new BuyTransaction(3);
    return 0;
}

#else  // MISTAKE_TEST

class Transaction {
 public:
    explicit Transaction(const std::string& logInfo) {
        logTransaction(logInfo);
    };
    ~Transaction() {};
    void logTransaction(const std::string& logInfo) const {
        std::cout << "logTransaction: " << logInfo << std::endl;
    };
};

class BuyTransaction : public Transaction {
 public:
    BuyTransaction(int var) 
        : Transaction(createLogString(var))
         ,multiple(10) {
    };
    ~BuyTransaction() {};
 private:
    int multiple;
    static std::string createLogString(int var) {
        return std::to_string(var*multiple);  // error:  invalid use of member ‘BuyTransaction::multiple’ in static member function
    };
};

int main() {
    std::cout << "=== BuyTransaction creating string through 'static' member function ===" << std::endl;
    BuyTransaction* buy_transaction_static = new BuyTransaction(3.3);  // 빌드 에러 발생
    return 0;
}

#endif
