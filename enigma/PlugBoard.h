#pragma once
#include <map>
class PlugBoard
{
public:
	PlugBoard();
	~PlugBoard();
	char PB(char enBokstav);

private:
	std::map<char, char> enKollaUppTabell;
};