#include "Reflektor.h"

Reflektor::Reflektor()
{
	enKollaUppTabell.insert({ 'A','E' });
	enKollaUppTabell.insert({ 'B','J' });
	enKollaUppTabell.insert({ 'C','M' });
	enKollaUppTabell.insert({ 'D','Z' });
	enKollaUppTabell.insert({ 'E','A' });
	enKollaUppTabell.insert({ 'F','L' });
	enKollaUppTabell.insert({ 'G','Y' });
	enKollaUppTabell.insert({ 'H','X' });
	enKollaUppTabell.insert({ 'I','V' });
	enKollaUppTabell.insert({ 'J','B' });
	enKollaUppTabell.insert({ 'K','W' });
	enKollaUppTabell.insert({ 'L','F' });
	enKollaUppTabell.insert({ 'M','C' });
	enKollaUppTabell.insert({ 'N','R' });
	enKollaUppTabell.insert({ 'O','Q' });
	enKollaUppTabell.insert({ 'P','U' });
	enKollaUppTabell.insert({ 'Q','O' });
	enKollaUppTabell.insert({ 'R','N' });
	enKollaUppTabell.insert({ 'S','T' });
	enKollaUppTabell.insert({ 'T','S' });
	enKollaUppTabell.insert({ 'U','P' });
	enKollaUppTabell.insert({ 'V','I' });
	enKollaUppTabell.insert({ 'W','K' });
	enKollaUppTabell.insert({ 'X','H' });
	enKollaUppTabell.insert({ 'Y','G' });
	enKollaUppTabell.insert({ 'Z','D' });
}
Reflektor::~Reflektor()
{
}

char Reflektor::UKW(char enBokstav)
{
	return enKollaUppTabell[enBokstav];
}