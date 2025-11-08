#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <exception>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int evaluate(const std::string &expr) const;

		class InvalidExpressionException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error";
				}
		};

	private:
		bool isOperator(char c) const;
		int performOperation(int a, int b, char op) const;
	};

#endif
