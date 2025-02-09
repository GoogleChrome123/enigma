#pragma once
#include <map>

class BaseRotor
{
public:
	BaseRotor(int rotorInställning);
	~BaseRotor();
	void rShift();
	char Rotor(char enBokstav);
	char RotorInvers(char enBokstav);
	void SetShiftPosition(int enPosition);
	std::map<char, char> enKollaUppTabell;
	int minPosition;
	int turnOver;
private:
};