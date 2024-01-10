#ifndef JAVA_METHOD_UNIT_H
#define JAVA_METHOD_UNIT_H

#include "../method_unit.h"

// языковая конструкция метода языка Java
class JavaMethodUnit : public MethodUnit
{
public:
	JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
		: MethodUnit(name, returnType, flags) // проверка допустимых флагов осуществляется в функции Compile
	{

	}

	std::string Compile(unsigned int level = 0) const
	{
		std::string result = "";

		if (flags_ & STATIC)
		{
			result += "static ";
		}
		// virtual в данном языке отсутствует

		if (flags_ & FINAL) // но зато добавляется новый файл - final
		{
			result += "final ";
		}

		result += return_type_ + " ";
		result += name_ + "() {\n"; // const так же не поддерживается

		for (const auto &b : body_)
		{
			result += b->Compile(level + 1);
		}

		result += GenerateIndent(level) + "}\n";

		return result;
	}
};

#endif // JAVA_METHOD_UNIT_H
