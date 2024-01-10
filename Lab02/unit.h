#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include <memory>

// базовый класс, определяющий некоторую языковую конструкцию
class Unit
{
public:
	using Flags = unsigned int; // указание типа данных флагов. используется как для битовых флагов, так и для цифровых перечислений

public:
	virtual ~Unit() = default; // обьявляем деструктор по умолчанию как виртуальный, для корректного вызова деструкторов конкретных языковых конструкций

	virtual void Add(const std::shared_ptr<Unit> &, Flags) // чтобы не выводилось предупреждение о неиспользуемых переменных, не задаем неиспользуемым аргументам имена
	{
		throw std::runtime_error("This type of unit doesn't support the Add method."); // так как не все конструкции поддерживают добавление других конструкций, данный метод реализуется по умолчанию и выбрасывает исключение
	}

	virtual std::string Compile(unsigned int level = 0) const = 0; // функция генерации кода программы

protected:
	// функция генерации отступов, на вход принимает количество отступов которые необходимо сделать
	virtual std::string GenerateIndent(unsigned int level) const
	{
		static const auto DEFAULT_INDENT = "    "; // величина одного отступа

		std::string res; // буфер с отступами

		for (size_t i = 0; i < level; i++) // добавление необходимого количества отступов в строку
		{
			res += DEFAULT_INDENT;
		}

		return res; // возвращается полученная строка
	}
};

#endif // UNIT_H
