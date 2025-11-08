#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expr) const;

	private:
		bool isOperator(char c) const;
		int performOperation(int a, int b, char op) const;
	};

#endif
