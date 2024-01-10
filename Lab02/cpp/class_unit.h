#ifndef CPP_CLASS_UNIT_H
#define CPP_CLASS_UNIT_H

#include "../class_unit.h"

// языковая конструкция класса языка C++
class CppClassUnit : public ClassUnit
{
public:
	static const std::vector<std::string> ACCESS_MODIFIERS; // набор модификаторов доступа, поддерижваемых данным языком

public:
	explicit CppClassUnit(const std::string &name)
		: ClassUnit(name, ACCESS_MODIFIERS.size()) // передача базовому классу количества поддерживаемых модификаторов доступа
	{

	}

	// добавление языковых конструкций в тело класса
	void Add(const std::shared_ptr<Unit> &unit, Flags flags)
	{
		if (unit == nullptr)
		{
			throw std::runtime_error("The unit is nullptr.");
		}

		size_t access_modifier = PRIVATE; // size_t, по тому что это индекс

		if (flags < fields_.size()) // отсеивание модификаторов доступа, не поддерживающихся данным языком
		{
			access_modifier = flags;
		}

		fields_[access_modifier].push_back(unit); // добавление конструкции в поле с соотвествующим модификатором доступа
	}

	// генерация кода класса
	std::string Compile(unsigned int level = 0) const
	{
		std::string result = GenerateIndent(level) + "class " + name_ + " {\n"; // имя класса

		for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++) // перебор набора полей модификаторов доступа
		{
			if (fields_[i].empty()) // если с данным модификатором доступа полей нет, не указываем его
			{
				continue;
			}

			result += GenerateIndent(level) + ACCESS_MODIFIERS[i] + ":\n"; // указание блока модификатора доступа

			for (const auto &f : fields_[i]) // перебор всех полей модификатора доступа
			{
				result += f->Compile(level + 1); // вывод языковых конструкций, с учетом дополнительного уровня вложенности (отступа)
			}

			result += "\n";
		}

		result += GenerateIndent(level) + "};\n"; // завершение генерации кода класса

		return result;
	}
};

const std::vector<std::string> CppClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" }; // перечисление поддерживаемых языком модификаторов доступа определяется вне класса, так как оно статическое

#endif // CPP_CLASS_UNIT_H
