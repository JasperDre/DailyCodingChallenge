#include "Person.h"

Person::Person()
{
}

Person::Person(std::string a_Name)
{
	name = a_Name;
}

Person::~Person()
{
}

std::string Person::GetName()
{
	return name;
}
