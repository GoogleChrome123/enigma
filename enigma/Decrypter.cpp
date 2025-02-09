#include "Decrypter.h"

Decrypter::Decrypter()
{
}

Decrypter::~Decrypter()
{
}

float Decrypter::Decrypt(const std::string& aString)
{
	float IC = 0;
	//std::string myString = aString;
	int myIOC[26]{};
	for (int i = 0; i < aString.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (j == aString[i] - 65)
			{
				myIOC[j] = myIOC[j] + 1;
				break;
			}
		}

	}
	for (int i = 0; i < 26; i++)
	{
		IC = IC + static_cast<float>(((myIOC[i] * (myIOC[i] - 1))) / static_cast<float>((aString.size() * (aString.size() - 1))));//ioc ekvation
	}
	//IC=IC + static_cast<float>((static_cast<float>(myIOC[i]) /static_cast<float>((myString.size()) 
//	* static_cast<float>((myIOC[i] - 1)) / static_cast<float>(myString.size() - 1))));
	//IC = IC * 26;
	//std::cout << IC;
	//for (int i = 0; i < 26; i++)
	//{
	//	std::cout << myIOC[i];
	//}
	//ONEDAYTHEHARELAUGHEDATTHESHORTFEETANDSLOWSPEEDOFTHETORTOISETHETORTOISEREPLIEDYOUMAYBEASFASTASTHEWINDBUTIWILLBEATYOUINARACETHEHARETHOUGHTTHISIDEAWASIMPOSSIBLEANDHEAGREEDTOTHEPROPOSALITWASAGREEDTHATTHEFOXSHOULDCHOOSETHECOURSEANDDECIDETHEENDTHEDAYFORTHERACECAMEANDTHETORTOISEANDHARESTARTEDTOGETHERTHETORTOISENEVERSTOPPEDFORAMOMENTWALKINGSLOWLYBUTSTEADILYRIGHTTOTHEENDOFTHECOURSETHEHARERANFASTANDSTOPPEDTOLIEDOWNFORARESTBUTHEFELLFASTASLEEPEVENTUALLYHEWOKEUPANDRANASFASTASHECOULDBUTWHENHEREACHEDTHEENDHESAWTHETORTOISETHEREALREADYSLEEPINGCOMFORTABLYAFTERHEREFFORT
	return IC;
}
