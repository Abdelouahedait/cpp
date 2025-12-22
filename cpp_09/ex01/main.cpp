#include "RPN.hpp"

int main(int argc, char** argv) {
    std::stack<int> stack;
    if (argc == 1) {
        std::cout << "error: no arguments provided" << std::endl;
    }
    else 
        rpn(argv, stack);
    return 0;
}