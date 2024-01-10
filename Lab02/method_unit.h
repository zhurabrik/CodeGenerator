#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H

#include "unit.h"

// конкретная языковая конструкция метода некоторого языка
class MethodUnit : public Unit
{
public:
	// перечисление всех поддерживаемых модификаторов методов всех поддерживаемых языков
	enum Modifier
	{
		STATIC = 1,
		CONST = 1 << 1, // используются битовые флаги, то есть они могут быть установлены независимо, например STATIC | CONST
		VIRTUAL = 1 << 2,
		FINAL = 1 << 3
	};

public:
	MethodUnit(const std::string &name, const std::string &returnType, Flags flags)
		: name_(name)
		, return_type_(returnType)
		, flags_(flags)
	{

	}

	virtual ~MethodUnit() = default; // обьявляем деструктор по умолчанию как виртуальный, для корректного вызова деструкторов конкретных языков

	void Add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0 )
	{
		if (unit == nullptr)
		{
			throw std::runtime_error("The unit is nullptr.");
		}

		body_.push_back(unit); // данная языковая конструкция не классифицирует создаваемые в ней конструкции, по этому флаги не используются
	}

protected:
	std::string name_; // имя метода
	std::string return_type_; // тип возвращаемого методом значения

	Flags flags_; // выбранные модификаторы метода

	std::vector<std::shared_ptr<Unit>> body_; // тело метода в котором хранятся принадлежащие ему языковые конструкции
};

#endif // METHOD_UNIT_H
