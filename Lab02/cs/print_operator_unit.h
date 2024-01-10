#ifndef CS_PRINT_OPERATOR_UNIT_H
#define CS_PRINT_OPERATOR_UNIT_H

#include "../print_operator_unit.h"

// языковая конструкция оператора вывода языка C#
class CsPrintOperatorUnit : public PrintOperatorUnit
{
public:
	explicit CsPrintOperatorUnit(const std::string &text)
		: PrintOperatorUnit(text)
	{

	}

	std::string Compile(unsigned int level = 0) const
	{
		return GenerateIndent(level) + "Console.WriteLine(\"" + text_ + "\");\n";
	}
};

#endif // CS_PRINT_OPERATOR_UNIT_H
