#ifndef WORKER_H
#define WORKER_H

#include "Person.h"

class Worker : public Person
{
public:
	Worker(
		const std::string & givenName = "Not specified given name",
		const std::string & surname = "Not specified surname",
		const unsigned age = 0,
		const unsigned experienceInYears = 0)
			:
		Person(givenName, surname, age),
		m_experienceInYears(experienceInYears)
	{}

	Worker(
		const Person & person,
		const unsigned experienceInYears)
			:
		Person(person),
		m_experienceInYears(experienceInYears)
	{}

	Worker(const unsigned experienceInYears) :
		Person(),
		m_experienceInYears(experienceInYears)
	{}

	virtual ~Worker()
	{}

	void Show() const override
	{
		Person::Show();
		std::cout << "Experience in years: " << m_experienceInYears << "\n";
	}

	unsigned ExperienceInYears() { return m_experienceInYears; }
	virtual void SetExperienceInYears(const unsigned exp) { m_experienceInYears = exp; }

private:
	unsigned m_experienceInYears{};
};

#endif //WORKER_H
