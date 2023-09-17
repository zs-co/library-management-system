#include <iostream> 
#include "include/User.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    User::create_user(); 
    return 0; 
}