#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H

#include "unit.h"

// конкретная языковая конструкция класса некоторого языка
class ClassUnit : public Unit
{
public:
	// перечисление всех поддерживаемых модификаторов доступа всех поддерживаемых языков
	enum AccessModifier
	{
		PUBLIC,
		PROTECTED,
		PRIVATE,
		INTERNAL,
		PROTECTED_INTERNAL,
		PRIVATE_PROTECTED
	};

public:
	explicit ClassUnit(const std::string &name, size_t fields_size)
		: name_(name)
		, fields_(fields_size) // количество поддерживаемых модификаторов доступа конкретным языком
	{

	}

	virtual ~ClassUnit() = default; // обьявляем деструктор по умолчанию как виртуальный, для корректного вызова деструкторов конкретных языков

protected:
	std::string name_; // имя создаваемого класса

	using Fields = std::vector<std::shared_ptr<Unit>>; // тип данных для набора полей класса

	std::vector<Fields> fields_; // каждому модификатору доступа соотвествует свой набор полей
};

#endif // CLASS_UNIT_H
