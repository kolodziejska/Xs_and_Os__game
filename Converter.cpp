#include "Converter.h"

char Converter::MarkToChar(const Mark& mark)
{
	if (mark == Mark::X) return 'X';
	else if (mark == Mark::O) return 'O';
	else return 0;
}

int Converter::SpaceNameToInt(const std::string& string)
{
	int spaceNumber;

	if (string.length() == 1) {
		spaceNumber = static_cast<int>(string[0]) - static_cast<int>('0');
	}

	else {
		spaceNumber = (static_cast<int>(string[1]) - static_cast<int>('0')) + ((static_cast<int>(string[0]) - static_cast<int>('0')) * 10);
	}

	return spaceNumber;

}
