/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    _result = 0;
}

Parser::~Parser()
{
}


bool is_operator(char charac)
{
    if (charac == '+' || charac == '-' || charac == '*'
        || charac == '/' || charac == '%') {
            return (true);
    }
    return (false);
}

bool is_number(char charac)
{
    if (charac >= '0' && charac <= '9') {
            return (true);
    }
    return (false);
}


int find_number(const std::string & str, int *i)
{
    int result = 0;
    int size = 0;

    for (int i_two = *i; is_number(str[i_two]); i_two++, size++) {
    }
    if (size)
        size--;
    for (; is_number(str[*i]); size--, *i += 1) {
        result += (str[*i] - '0') * pow(10, size);
    }
    return (result);
}

void push_number(int number, std::stack<int> *_operands)
{
    // // printf("Push Number: %d\n", number);
    _operands->push(number);
}

void push_operator(char op, std::stack<char> *_operators)
{
    // // printf("Push Operator: %c\n", op);
    _operators->push(op);
}


int pop_number(std::stack<int> *_operands)
{
    int result = _operands->top();
    // // printf("Pop operator: %d\n", result);
    _operands->pop();
    return (result);
}

char pop_operator(std::stack<char> *_operators)
{
    char result = _operators->top();

    _operators->pop();
    return (result);
}

int calcul(std::stack<char> *_operators, std::stack<int> *_operands)
{
    int b = pop_number(_operands);
    char op = pop_operator(_operators);
    int a = pop_number(_operands);


    // if (charac == '+' || charac == '-' || charac == '*'
    //     || charac == '/' || charac == '%') {
    switch (op) {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            return (a / b);
        case '%':
            return (a % b);
        default:
            return (0);
    }
    return (0);
}

void Parser::feed(const std::string & str)
{
    // std::cout << str << std::endl;
    for (int i = 0; str[i]; i++) {
        // // printf("+++%c+++ %d\n", str[i], i);
        if (is_number(str[i])) {
            push_number(find_number(str, &i), &_operands);
            // if (!str[i]) {
            //     // // printf("||||||||||||||||||||||||||||||||||--\n");
            //     push_number(calcul(&_operators, &_operands), &_operands);
            // }
            i--;
        } else if (is_operator(str[i])) {
            push_operator(str[i], &_operators);
        } else if (str[i] == ')') {
            // // printf("=========================%d\n", !str[i + 1]);
            push_number(calcul(&_operators, &_operands), &_operands);
            // i--;
        }
    }
    while (_operators.size()) {
        push_number(calcul(&_operators, &_operands), &_operands);
    }
        // // printf("---------------------\n");
    _result = 0;    
    while (_operands.size())
        _result += pop_number(&_operands);
    push_number(_result, &_operands);
}

int Parser::result() const {
    return (_result);
}

void Parser::reset() {
    while (_operands.size()) {
        _operands.pop();
    }
    while (_operators.size()) {
        _operators.pop();
    }
    _result = 0;
}

// int Parser::result() const
// {
//     return (_result);
// }

// void Parser::reset()
// {

// }
