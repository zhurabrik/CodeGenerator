#ifndef CPP_PRINT_OPERATOR_UNIT_H
#define CPP_PRINT_OPERATOR_UNIT_H

#include "../print_operator_unit.h"

// языковая конструкция оператора вывода языка C++
class CppPrintOperatorUnit : public PrintOperatorUnit
{
public:
	explicit CppPrintOperatorUnit(const std::string &text)
		: PrintOperatorUnit(text)
	{

	}

	std::string Compile(unsigned int level = 0) const
	{
		// добавление отступов и необходимых конструкций для потокового вывода текста
		return GenerateIndent(level) + "std::cout << \"" + text_ + "\" << std::endl;\n";
	}
};

#endif // CPP_PRINT_OPERATOR_UNIT_H
