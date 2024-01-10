#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H

#include "unit.h"

// конкретная языковая конструкция оператора вывода некоторого языка
class PrintOperatorUnit : public Unit
{
public:
	explicit PrintOperatorUnit(const std::string &text)
		: text_(text)
	{

	}

	virtual ~PrintOperatorUnit() = default; // обьявляем деструктор по умолчанию как виртуальный, для корректного вызова деструкторов конкретных языков

protected:
	std::string text_; // текст, который должен вывести данный оператор
};

#endif // PRINT_OPERATOR_UNIT_H
