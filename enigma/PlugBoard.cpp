#include "PlugBoard.h"

PlugBoard::PlugBoard()
{
	enKollaUppTabell.insert({ 'A','A' });
	enKollaUppTabell.insert({ 'B','B' });
	enKollaUppTabell.insert({ 'C','C' });
	enKollaUppTabell.insert({ 'D','D' });
	enKollaUppTabell.insert({ 'E','E' });
	enKollaUppTabell.insert({ 'F','F' });
	enKollaUppTabell.insert({ 'G','G' });
	enKollaUppTabell.insert({ 'H','H' });
	enKollaUppTabell.insert({ 'I','I' });
	enKollaUppTabell.insert({ 'J','J' });
	enKollaUppTabell.insert({ 'K','K' });
	enKollaUppTabell.insert({ 'L','L' });
	enKollaUppTabell.insert({ 'M','M' });
	enKollaUppTabell.insert({ 'N','N' });
	enKollaUppTabell.insert({ 'O','O' });
	enKollaUppTabell.insert({ 'P','P' });
	enKollaUppTabell.insert({ 'Q','Q' });
	enKollaUppTabell.insert({ 'R','R' });
	enKollaUppTabell.insert({ 'S','S' });
	enKollaUppTabell.insert({ 'T','T' });
	enKollaUppTabell.insert({ 'U','U' });
	enKollaUppTabell.insert({ 'V','V' });
	enKollaUppTabell.insert({ 'W','W' });
	enKollaUppTabell.insert({ 'X','X' });
	enKollaUppTabell.insert({ 'Y','Y' });
	enKollaUppTabell.insert({ 'Z','Z' });
}

PlugBoard::~PlugBoard()
{
}

char PlugBoard::PB(char enBokstav)
{
	return enKollaUppTabell[enBokstav];
}
