#include "RPN.hpp"

int rpn(char **argv, std::stack<int> stack)
{
    std::stringstream ss;
    ss << argv[1];
    std::string arg;
    while (ss >> arg) {
        if ((arg.size() > 1 || !isdigit(arg[0])) && arg[0] != '+' && arg[0] != '-' && arg[0] != '*' && arg[0] != '/' ) {
            std::cout << "error: invalid character '" << arg << "'" << std::endl;
            return 1;
        } 
        if (isdigit(arg[0])) {
            stack.push(arg[0] - '0');
        } 
        else {
            if (stack.size() < 2) {
                std::cout << "error: not enough operands for operator '" << arg << "'" << std::endl;
                return 1;
            }
            int right = stack.top(); stack.pop();
            int left = stack.top(); stack.pop();
            int result;
            switch (arg[0]) {
                case '+': result = left + right; break;
                case '-': result = left - right; break;
                case '*': result = left * right; break;
                case '/': 
                    if (right == 0) {
                        std::cout << "error: division by zero" << std::endl;
                        return 1;
                    }
                    result = left / right;
                    break;
            }
            stack.push(result);
        }
    }
    if (stack.size() != 1) {
        std::cout << "error: invalid expression" << std::endl;
        return 1;
    }
    std::cout << stack.top() << std::endl;
    return 1;
}