#pragma once
#include <map>
class Reflektor
{
public:
	Reflektor();
	~Reflektor();
	char UKW(char enBokstav);

private:
	std::map<char, char> enKollaUppTabell;
};