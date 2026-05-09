#include "parser/Parser.h"

int Parser::precedence(const std::string& op) {
    if (op == "OR") return 1;
    if (op == "AND") return 2;
    if (op == "==" || op == "!=" || op == ">" || op == "<") return 3;
    if (op == "*" || op == "/" || op == "%") return 4;
    return 0;
}

CustomVector<std::string> Parser::infixToPostfix(const std::string& infix) {
    CustomVector<std::string> postfix;
    CustomStack<std::string> stack;
    std::stringstream ss(infix);
    std::string token;

    while (ss >> token) {
        if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (!stack.isEmpty() && stack.top() != "(") {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.pop(); // Remove "("
        } else if (precedence(token) > 0) {
            while (!stack.isEmpty() && precedence(stack.top()) >= precedence(token)) {
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(token);
        } else {
            postfix.push_back(token);
        }
    }

    while (!stack.isEmpty()) {
        postfix.push_back(stack.top());
        stack.pop();
    }

    std::string postfixStr = "";
    for (size_t i = 0; i < postfix.getSize(); ++i)
        postfixStr += postfix[i] + " ";
    globalLogger.log("Infix \"" + infix + "\" converted to Postfix \"" + postfixStr + "\"");

    return postfix;
}
