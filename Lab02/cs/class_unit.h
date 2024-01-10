#ifndef CS_CLASS_UNIT_H
#define CS_CLASS_UNIT_H

#include "../class_unit.h"

// языковая конструкция класса языка C#
// так как уже было дано описание одной из реализаций данной языковой конструкции, здесь будут рассмотрены только отличия от неё
class CsClassUnit : public ClassUnit
{
public:
	static const std::vector<std::string> ACCESS_MODIFIERS;

public:
	explicit CsClassUnit(const std::string &name)
		: ClassUnit(name, ACCESS_MODIFIERS.size())
	{

	}

	void Add(const std::shared_ptr<Unit> &unit, Flags flags = 0)
	{
		if (unit == nullptr)
		{
			throw std::runtime_error("The unit is nullptr.");
		}

		size_t access_modifier = PRIVATE;

		if (flags < fields_.size())
		{
			access_modifier = flags;
		}

		fields_[access_modifier].push_back(unit);
	}

	std::string Compile(unsigned int level = 0) const
	{
		std::string result = "class " + name_ + " {\n"; // класс также может быть подклассом с модификатором доступа, по этому за отступ первой строки отвечает вышестоящий обьект

		for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)
		{
			// так как в данном языке тело класса не делится на поля с модификаторами доступа, они являются частью определения метода
			// по этой причине за отступ первой строки элемента класса отвечает сам класс, и в начало объявления метода дописывается модификатор доступа
			for (const auto &f : fields_[i])
			{
				result += GenerateIndent(level + 1) + ACCESS_MODIFIERS[i] + " " + f->Compile(level + 1);
			}
		}

		result += GenerateIndent(level) + "};\n";

		return result;
	}
};

// в данном языке конструкций больше
const std::vector<std::string> CsClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };

#endif // CS_CLASS_UNIT_H
