#ifndef JAVA_PRINT_OPERATOR_UNIT_H
#define JAVA_PRINT_OPERATOR_UNIT_H

#include "../print_operator_unit.h"

// языковая конструкция оператора вывода языка Java
class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
	explicit JavaPrintOperatorUnit(const std::string &text)
		: PrintOperatorUnit(text)
	{

	}

	std::string Compile(unsigned int level = 0) const
	{
		return GenerateIndent(level) + "System.out.println(\"" + text_ + "\");\n";
	}
};

#endif // JAVA_PRINT_OPERATOR_UNIT_H
