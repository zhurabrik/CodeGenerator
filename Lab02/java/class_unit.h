#ifndef JAVA_CLASS_UNIT_H
#define JAVA_CLASS_UNIT_H

#include "../class_unit.h"

// языковая конструкция класса языка Java
// данная языковая конструкция отличается от C# незначительно
class JavaClassUnit : public ClassUnit
{
public:
	static const std::vector<std::string> ACCESS_MODIFIERS;

public:
	explicit JavaClassUnit(const std::string &name)
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
		std::string result = "class " + name_ + " {\n";

		for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)
		{
			for (const auto &f : fields_[i])
			{
				result += GenerateIndent(level + 1) + ACCESS_MODIFIERS[i] + " " + f->Compile(level + 1);
			}
		}

		result += GenerateIndent(level) + "};\n";

		return result;
	}
};

// данный язык поддерживает только три модификатора доступа
const std::vector<std::string> JavaClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

#endif // JAVA_CLASS_UNIT_H
