#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person // abstract base class
{
public:
	Person()
	{}

	Person(const std::string & givenName, const std::string & surname, const unsigned age)
		: m_givenName(givenName), m_surname(surname), m_age(age)
	{}

	virtual ~Person()
	{}

	std::string GivenName() const { return m_givenName; }
	std::string Surname() const { return m_surname; }
	unsigned Age() const { return m_age; }

	void SetGivenName(const std::string & givenName) { m_givenName = givenName; }
	void SetSurname(const std::string & surname) { m_surname = surname; }
	void SetAge(const unsigned & age) { m_age = age; }

	virtual void Show() const = 0;

	static void StaticFunctionSaysHello()
	{
		std::cout << "\nI am abstract base class static function member. Hello! :)\n\n";
	}

private:
	std::string m_givenName{};
	std::string m_surname{};
	unsigned m_age{};
};

inline void Person::Show() const
{
	std::cout
		<< "\nGiven name: " << m_givenName
		<< "\nSurname: " << m_surname
		<< "\nAge: " << m_age << "\n";
}

#endif //PERSON_H
