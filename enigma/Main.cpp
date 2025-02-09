#include "BaseRotor.h"
#include <iostream>
#include <string>
#include "Reflektor.h"
#include <conio.h>
#include "Decrypter.h"
#include "PlugBoard.h"
std::string DAlgorithm(std::string aString, BaseRotor Rotor1, BaseRotor Rotor2, BaseRotor Rotor3, PlugBoard pb, Reflektor Ref1, Decrypter d1);
int main()
{
	BaseRotor Rotor1 = BaseRotor(1);//siffran är vilken rotor går på plats 1 
	BaseRotor Rotor2 = BaseRotor(2);
	BaseRotor Rotor3 = BaseRotor(3);
	Reflektor Ref1 = Reflektor();
	Decrypter d1 = Decrypter();
	PlugBoard pb = PlugBoard();
	std::string minMening;
	//std::cin >> minMening;
	std::getline(std::cin, minMening);
	std::string minOutputString = "";

	minOutputString = minMening;
	Rotor1.SetShiftPosition(24);//säger hur många steg åt höger en rotor ska gå
	Rotor2.SetShiftPosition(24);
	Rotor3.SetShiftPosition(24);
	//enigma maskin start
	for (int i = 0; i < minMening.size(); i++)
	{
		if (minOutputString[i] == ' ')
		{
			continue;
		}
		if (minOutputString[i] > 90)
		{
			minMening[i] -= 32;
		}
		//turnover r1 = q, r2 = e
		minOutputString[i] = pb.PB(Rotor1.RotorInvers(Rotor2.RotorInvers(Rotor3.RotorInvers(Ref1.UKW(Rotor3.Rotor(Rotor2.Rotor(Rotor1.Rotor(pb.PB(minMening.c_str()[i])))))))));//olika lager i enigman 
		Rotor1.minPosition++;
		Rotor1.rShift();//samma som setshifpos men går bara ett steg 
		if (Rotor1.minPosition == 26)
		{
			Rotor1.minPosition = 0;
			Rotor2.minPosition++;
			Rotor2.rShift();
			if (Rotor2.minPosition == 26)
			{
				Rotor2.minPosition = 0;
				Rotor3.minPosition++;
				Rotor3.rShift();
				if (Rotor3.minPosition == 26)
				{
					Rotor3.minPosition = 0;
				}
			}			
		}
	}
	std::cout << minOutputString;
	std::string tempOut;
	tempOut = DAlgorithm(minOutputString,Rotor1,Rotor2,Rotor3,pb,Ref1,d1);

	while (true)
	{
		std::string input1;
		std::cin >> input1;
		if (input1 == "n")
		{
			break;
		}
		else
		{
			tempOut = DAlgorithm(tempOut, Rotor1, Rotor2, Rotor3, pb, Ref1, d1);
		}
	}
	//enigma maskin slut
	float tempIC = 0;
	std::string temps = "";
	int tempr2pos = 0;
	int tempr3pos = 0;
	int tempr1pos = 0;
	int tempout1 = 0;
	int tempout2 = 0;
	int tempout3 = 0;
	std::string output = "";
	////decrypt start
	//for (int i = 0; i < 17576; i++)
	//{
	//	tempr1pos++;
	//	if (tempr1pos == 26)
	//	{
	//		tempr2pos++;
	//		tempr1pos = 0;
	//		if (tempr2pos == 26)
	//		{
	//			tempr3pos++;
	//			tempr2pos = 0;
	//		}
	//	}
	//	std::string tempOutputString = minOutputString;

	//	Rotor2 = BaseRotor(2);
	//	Rotor1 = BaseRotor(1);
	//	Rotor3 = BaseRotor(3);
	//	Rotor1.SetShiftPosition(tempr1pos);
	//	Rotor2.SetShiftPosition(tempr2pos);
	//	Rotor3.SetShiftPosition(tempr3pos);
	//	for (int i = 0; i < minMening.size(); i++)
	//	{
	//		if (minOutputString[i] == ' ')
	//		{
	//			continue;
	//		}
	//		if (minOutputString[i] > 90)
	//		{
	//			minMening[i] -= 32;
	//		}
	//		//turnover r1 = q, r2 = e
	//		tempOutputString[i] = pb.PB(Rotor1.RotorInvers(Rotor2.RotorInvers(Rotor3.RotorInvers(Ref1.UKW(Rotor3.Rotor(Rotor2.Rotor(Rotor1.Rotor(pb.PB(minOutputString.c_str()[i])))))))));
	//		Rotor1.minPosition++;
	//		Rotor1.rShift();
	//		if (Rotor1.minPosition == 26)
	//		{
	//			Rotor1.minPosition = 0;
	//			Rotor2.minPosition++;
	//			Rotor2.rShift();
	//			if (Rotor2.minPosition == 26)
	//			{
	//				Rotor2.minPosition = 0;
	//				Rotor3.minPosition++;
	//				Rotor3.rShift();
	//				if (Rotor3.minPosition == 26)
	//				{
	//					Rotor3.minPosition = 0;
	//				}
	//			}
	//		}
	//	}
	//	std::cout << d1.Decrypt(tempOutputString) << " " << tempOutputString << tempr1pos << tempr2pos << tempr3pos << std::endl;
	//	if (tempIC < d1.Decrypt(tempOutputString))
	//	{
	//		output = tempOutputString;
	//		tempIC = d1.Decrypt(tempOutputString);
	//		tempout1 = tempr1pos;
	//		tempout2 = tempr2pos;
	//		tempout3 = tempr3pos;
	//		//måste fixas så den tar det närmaste värdet inte det högsta (det högsta brukar funka men inte alltid)
	//	}
	//}
	//std::cout << tempIC << " " << tempout1 << " " << tempout1 << " " << tempout1 << " "  <<output<<std::endl;
	//decrypt slut
	_getch();
	return 0;
}

std::string DAlgorithm(std::string aString, BaseRotor Rotor1, BaseRotor Rotor2, BaseRotor Rotor3, PlugBoard pb, Reflektor Ref1, Decrypter d1)
{
	float tempIC = 0;
	std::string temps = "";
	int tempr2pos = 0;
	int tempr3pos = 0;
	int tempr1pos = 0;
	int tempout1 = 0;
	int tempout2 = 0;
	int tempout3 = 0;
	std::string output = "";
	//decrypt start
	for (int i = 0; i < 17576; i++)
	{
		tempr1pos++;
		if (tempr1pos == 26)
		{
			tempr2pos++;
			tempr1pos = 0;
			if (tempr2pos == 26)
			{
				tempr3pos++;
				tempr2pos = 0;
			}
		}
		std::string tempOutputString = aString;

		Rotor2 = BaseRotor(2);
		Rotor1 = BaseRotor(1);
		Rotor3 = BaseRotor(3);
		Rotor1.SetShiftPosition(tempr1pos);
		Rotor2.SetShiftPosition(tempr2pos);
		Rotor3.SetShiftPosition(tempr3pos);
		for (int i = 0; i < aString.size(); i++)
		{
			if (aString[i] == ' ')
			{
				continue;
			}
			if (aString[i] > 90)
			{
				aString[i] -= 32;
			}
			//turnover r1 = q, r2 = e
			tempOutputString[i] = pb.PB(Rotor1.RotorInvers(Rotor2.RotorInvers(Rotor3.RotorInvers(Ref1.UKW(Rotor3.Rotor(Rotor2.Rotor(Rotor1.Rotor(pb.PB(aString.c_str()[i])))))))));
			Rotor1.minPosition++;
			Rotor1.rShift();
			if (Rotor1.minPosition == 26)
			{
				Rotor1.minPosition = 0;
				Rotor2.minPosition++;
				Rotor2.rShift();
				if (Rotor2.minPosition == 26)
				{
					Rotor2.minPosition = 0;
					Rotor3.minPosition++;
					Rotor3.rShift();
					if (Rotor3.minPosition == 26)
					{
						Rotor3.minPosition = 0;
					}
				}
			}
		}
		std::cout << d1.Decrypt(tempOutputString) << " " << tempOutputString << tempr1pos << tempr2pos << tempr3pos << std::endl;
		if (tempIC < d1.Decrypt(tempOutputString))
		{
			output = tempOutputString;
			tempIC = d1.Decrypt(tempOutputString);
			tempout1 = tempr1pos;
			tempout2 = tempr2pos;
			tempout3 = tempr3pos;
			//måste fixas så den tar det närmaste värdet inte det högsta (det högsta brukar funka men inte alltid)
		}
	}
	std::cout << tempIC << " " << tempout1 << " " << tempout1 << " " << tempout1 << " " << output << std::endl;
	return output;
}