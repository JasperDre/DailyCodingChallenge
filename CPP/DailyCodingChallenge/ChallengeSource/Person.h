#pragma once

#include <string>

class Person
{
public:
	Person();
	Person(std::string a_Name);
	~Person();

	std::string GetName();

private:
	std::string name;
};
