#pragma once
#include "Mark.h"
#include <string>

class Converter
{
public:
	static char MarkToChar(const Mark& mark);

	static int SpaceNameToInt(const std::string& string);

};

