//http://www.spoj.com/problems/ONP/

#include <iostream>
#include <string.h>
#include <set>
#include <stack>

using namespace std;

set<char> operators = { '+', '-', '*', '/', '^' };

class Expression
{
public:
	bool unary = false;
	char op;
	char ch;
	Expression* left;
	Expression* right;

	Expression()
	{
		ch = '-';
	}

	void Print()
	{
		if (this->unary)
		{
			if (ch == '-')
			{
				left->Print();
			}
			else
			{
				printf("%c", this->ch);
			}
		}
		else
		{
			left->Print();
			right->Print();
			printf("%c", op);
		}
	}
};

int Transform_the_expression()
{
	int numTests = 1;
	//scanf("%d", &numTests);

	while (numTests--)
	{
		char expression[400];
		//strcpy_s(expression, "((a+t)*((b+(a+c))^(c+d)))");
		//strcpy_s(expression, "(a+(b+(c+d)))");
		//strcpy_s(expression, "((a+b)+c)");
		//strcpy_s(expression, "(a+b)");
		//strcpy_s(expression, "((a+b)+(c+d))");
		//scanf("%s", expression);

		stack<Expression*> st;

		for (int i = 0; i < strlen(expression); ++i)
		{
			char curChar = expression[i];

			if (curChar == '(')
			{
				Expression* newEx = new Expression();
				newEx->op = '(';
				st.push(newEx);
			}
			else if (curChar == ')')
			{
				Expression* ex1 = st.top();
				st.pop();
				Expression* ex2 = st.top();
				st.pop();
				Expression* ex3 = st.top();
				st.pop();
				st.pop();
				Expression* ex4 = new Expression();
				ex4->unary = false;
				ex4->left = ex3;
				ex4->right = ex1;
				ex4->op = ex2->op;
				st.push(ex4);
			}
			else if (curChar >= 'a' && curChar <= 'z')
			{
				Expression* ex1 = new Expression();
				ex1->unary = true;
				ex1->ch = curChar;
				st.push(ex1);
			}
			else
			{
				Expression* ex1 = new Expression();
				ex1->op = curChar;
				st.push(ex1);
			}
		}

		Expression* ex = st.top();
		ex->Print();
		printf("\n");
	}

	//cin >> numTests;

	return 0;
}