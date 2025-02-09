#include "BaseRotor.h"
BaseRotor::BaseRotor(int rotorInställning)
{
	auto automatiseradFunktion = [&](char x, char y) -> void {
		enKollaUppTabell.insert({ x,y });
	};

	switch (rotorInställning)
	{
	case 1:
		enKollaUppTabell.insert({ 'A','E' });
		enKollaUppTabell.insert({ 'B','K' });
		automatiseradFunktion('C','M');
		automatiseradFunktion('D', 'F');
		automatiseradFunktion('E', 'L');
		automatiseradFunktion('F', 'G');
		automatiseradFunktion('G', 'D');
		automatiseradFunktion('H', 'Q');
		automatiseradFunktion('I', 'V');
		automatiseradFunktion('J', 'Z');
		automatiseradFunktion('K', 'N');
		automatiseradFunktion('L', 'T');
		automatiseradFunktion('M', 'O');
		automatiseradFunktion('N', 'W');
		automatiseradFunktion('O', 'Y');
		automatiseradFunktion('P', 'H');
		automatiseradFunktion('Q', 'X');
		automatiseradFunktion('R', 'U');
		automatiseradFunktion('S', 'S');
		automatiseradFunktion('T', 'P');
		automatiseradFunktion('U', 'A');	
		automatiseradFunktion('V', 'I');
		automatiseradFunktion('W', 'B');
		automatiseradFunktion('X', 'R');
		automatiseradFunktion('Y', 'C');
		automatiseradFunktion('Z', 'J');
		turnOver = 18; //Q->R  // används inte än
		break;
	case 2:
		enKollaUppTabell.insert({ 'A','A' });
		enKollaUppTabell.insert({ 'B','J' });
		automatiseradFunktion('C', 'D');
		automatiseradFunktion('D', 'K');
		automatiseradFunktion('E', 'S');
		automatiseradFunktion('F', 'I');
		automatiseradFunktion('G', 'R');
		automatiseradFunktion('H', 'U');
		automatiseradFunktion('I', 'X');
		automatiseradFunktion('J', 'B');
		automatiseradFunktion('K', 'L');
		automatiseradFunktion('L', 'H');
		automatiseradFunktion('M', 'W');
		automatiseradFunktion('N', 'T');
		automatiseradFunktion('O', 'M');
		automatiseradFunktion('P', 'C');
		automatiseradFunktion('Q', 'Q');
		automatiseradFunktion('R', 'G');
		automatiseradFunktion('S', 'Z');
		automatiseradFunktion('T', 'N');
		automatiseradFunktion('U', 'P');
		automatiseradFunktion('V', 'Y');
		automatiseradFunktion('W', 'F');
		automatiseradFunktion('X', 'V');
		automatiseradFunktion('Y', 'O');
		automatiseradFunktion('Z', 'E');
		turnOver = 6; //E->F
		break;
	case 3:
		enKollaUppTabell.insert({ 'A','B' });
		enKollaUppTabell.insert({ 'B','D' });
		automatiseradFunktion('C', 'F');
		automatiseradFunktion('D', 'H');
		automatiseradFunktion('E', 'J');
		automatiseradFunktion('F', 'L');
		automatiseradFunktion('G', 'C');
		automatiseradFunktion('H', 'P');
		automatiseradFunktion('I', 'R');
		automatiseradFunktion('J', 'T');
		automatiseradFunktion('K', 'X');
		automatiseradFunktion('L', 'V');
		automatiseradFunktion('M', 'Z');
		automatiseradFunktion('N', 'N');
		automatiseradFunktion('O', 'Y');
		automatiseradFunktion('P', 'E');
		automatiseradFunktion('Q', 'I');
		automatiseradFunktion('R', 'W');
		automatiseradFunktion('S', 'G');
		automatiseradFunktion('T', 'A');
		automatiseradFunktion('U', 'K');
		automatiseradFunktion('V', 'M');
		automatiseradFunktion('W', 'U');
		automatiseradFunktion('X', 'S');
		automatiseradFunktion('Y', 'Q');
		automatiseradFunktion('Z', 'O');
		turnOver = 23; //V->W
		break;
	default:
		break;
	}
	minPosition = 0;
}

BaseRotor::~BaseRotor()
{
}

void BaseRotor::rShift()
{
	char tempStorage[27];
	char tmp = 0;
	for (int i = 0; i < 26; i++)
	{
		tempStorage[i] = enKollaUppTabell['A' + i];
	}
	tmp = tempStorage[25];
	
	memmove(tempStorage + 1, tempStorage, 26);
	tempStorage[0] = tempStorage[26];

	for (int i = 0; i < 26; i++)
	{
		enKollaUppTabell['A' + i] = tempStorage[i];
	}
}

char BaseRotor::Rotor(char enBokstav)
{
	return enKollaUppTabell[enBokstav];
}

char BaseRotor::RotorInvers(char enBokstav)
{
	for (auto i = enKollaUppTabell.begin(); i != enKollaUppTabell.end(); i++)
	{
		if (i->second == enBokstav)
		{
			return i->first;
		}
	}
	return 0;
}

void BaseRotor::SetShiftPosition(int enPosition)
{
	char tempStorage[53];
	for (int i = 0; i < 26; i++)
	{
		tempStorage[i] = enKollaUppTabell['A' + i];
	}
	memmove(tempStorage + enPosition, tempStorage, 26);
	memmove(tempStorage, tempStorage + 26, enPosition);
	for (int i = 0; i < 26; i++)
	{
		enKollaUppTabell['A' + i] = tempStorage[i];
	}
}

