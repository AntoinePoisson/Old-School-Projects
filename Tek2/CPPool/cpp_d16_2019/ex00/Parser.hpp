/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser
*/

#ifndef Parser_hpp
#define Parser_hpp

#include <iostream>
#include <stack>
#include <cmath>

class Parser {
	public:
		Parser();
		~Parser();

        void feed(const std::string &);
        int result() const;
        void reset();

	protected:
	private:
        std::stack<char> _operators;
        std::stack<int> _operands;
        int _result;
};

#endif /* !Parser_hpp */
