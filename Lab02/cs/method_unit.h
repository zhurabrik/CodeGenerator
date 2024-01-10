#ifndef CS_METHOD_UNIT_H
#define CS_METHOD_UNIT_H

#include "../method_unit.h"

// языковая конструкция метода языка C#
class CsMethodUnit : public MethodUnit
{
public:
	CsMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
		: MethodUnit(name, returnType, flags) // проверка допустимых флагов осуществляется в функции Compile
	{

	}

	std::string Compile(unsigned int level = 0) const
	{
		std::string result = ""; // отступ отсутствует по той же причине что и у класса

		if (flags_ & STATIC)
		{
			result += "static ";
		}
		else if (flags_ & VIRTUAL)
		{
			result += "virtual ";
		}

		result += return_type_ + " ";
		result += name_ + "() {\n"; // в отличии от C++, в C# нет методов с типом const, по этому даже если такой флаг был выставлен, он будет проигнорирован

		for (const auto &b : body_)
		{
			result += b->Compile(level + 1);
		}

		result += GenerateIndent(level) + "}\n";

		return result;
	}
};

#endif // CS_METHOD_UNIT_H
