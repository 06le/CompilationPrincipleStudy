#include "TranslatorForExpressions.h"

Parser::Parser(istream& cin)
{
	lookahead = cin.get();
	
}

void Parser::match(int t)
{
	if (lookahead == t)
	{
		lookahead = cin.get();
	}
	else
	{
		cout << "syntax error! \n";
		exit(0);
	}
}

void Parser::term()
{
	if (isdigit(lookahead))
	{
		int t = lookahead;
		match(lookahead);
		cout << (char)t;
	}
	else
	{
		cout << "syntax error! \n";
		exit(0);
	}
}

void Parser::expr()
{
	term();

	while (true)
	{
		if (lookahead == '+')
		{
			match('+');
			term();
			cout << "+";
		}
		else if (lookahead == '-')
		{
			match('-');
			term();
			cout << "-";
		}
		else
		{
			return;
		}
	}

}