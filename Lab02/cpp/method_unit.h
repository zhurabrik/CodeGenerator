#ifndef CPP_METHOD_UNIT_H
#define CPP_METHOD_UNIT_H

#include "../method_unit.h"

// языковая конструкция метода языка C++
class CppMethodUnit : public MethodUnit
{
public:
	CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
		: MethodUnit(name, returnType, flags)
	{
		// за проверку поддерживаемых флагов отвечает функция Compile, если переданный файл не поддерживается, он просто игнорируется
	}

	std::string Compile(unsigned int level = 0) const
	{
		std::string result = GenerateIndent(level); // отступ первой строки объявления метода

		if (flags_ & STATIC) // если в наличии есть статический флаг, используем его
		{
			result += "static ";
		}
		else if (flags_ & VIRTUAL) // так как виртуальная функция не может быть статической, этот флаг проверяется только при отсутствии флага static
		{
			result += "virtual ";
		}

		result += return_type_ + " "; // тип возвращаемого значения
		result += name_ + "()"; // название функции

		if (flags_ & CONST) // константный метод
		{
			result += " const";
		}

		result += " {\n"; // начало тела метода

		for (const auto &b : body_) // перебор всех конструкций, находящихся в данном методе
		{
			result += b->Compile(level + 1); // добавление конструкции с учетом отступа
		}

		result += GenerateIndent(level) + "}\n"; // конец тела

		return result;
	}
};

#endif // CPP_METHOD_UNIT_H
