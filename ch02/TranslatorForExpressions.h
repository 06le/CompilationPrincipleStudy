#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Parser
{
public:
	int lookahead;

	Parser() = default;
	Parser(istream&);

	void match(int t);
	void term();
	void rest();
	void expr();

};

