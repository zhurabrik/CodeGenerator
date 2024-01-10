#include <iostream>

#include "language_factory.h"

// общая функция, генерирующая код программы
// в качестве аргумента принимает языковую фабрику,через которую происходит работа с Unit'ами языка
std::string GenerateProgram(const std::shared_ptr<LanguageFactory> &factory)
{
	auto class_a = factory->CreateClass("ClassA"); // самый верхний класс, в который будет помещаться всё остальное

	auto class_b = factory->CreateClass("ClassB"); // подкласс, для демонстрации работы модификаторов доступа перед именем класса

	class_b->Add(factory->CreateMethod("testFunc1", "void", 0), ClassUnit::PUBLIC); // публичная функция, находящаяся в подклассе ClassB

	class_a->Add(class_b, ClassUnit::PUBLIC); // помещение подкласса в основной класс с публичным модификатором доступа

	class_a->Add(factory->CreateMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE); // добавление приватной статической функции в верхний класс

	auto method = factory->CreateMethod("testFunc4", "void", MethodUnit::STATIC); // создание метода

	method->Add(factory->CreatePrintOperator("Hello, world!")); // добавление в метод операции вывода

	class_a->Add(method, ClassUnit::PROTECTED); // помещение метода в верхний класс

	class_a->Add(factory->CreateMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC); // добавление публичного виртуального константного метода

	return class_a->Compile(); // генерация кода программы, по произведенным выше настройкам
}

int main(int argc, char *argv[])
{
	// C++
	std::cout << "C++:" << std::endl;

	// обработка ошибок сделана для того чтобы ошибка при генерации программы на одном из языков, программы на других языках имели возможность быть сгенерированными, так как они слабо зависят друг от друга
	try
	{
		std::cout << GenerateProgram(std::make_shared<CppFactory>()) << std::endl; // создание фабрики языка C++ и генерация кода программы на этом языке
	}
	catch (const std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}

	// C#
	std::cout << "C#:" << std::endl;

	try
	{
		std::cout << GenerateProgram(std::make_shared<CsFactory>()) << std::endl; // создание фабрики языка C# и генерация кода программы на этом языке
	}
	catch (const std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}

	// Java
	std::cout << "Java:" << std::endl;

	try
	{
		std::cout << GenerateProgram(std::make_shared<JavaFactory>()) << std::endl; // создание фабрики языка Java и генерация кода программы на этом языке
	}
	catch (const std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}

	return 0;
}
