#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "Worker.h"

class Programmer : public Worker
{
public:
	Programmer(
		const std::string & givenName = "Not specified given name",
		const std::string & surname = "Not specified surname",
		const unsigned age = 0,
		const unsigned experienceInYears = 0,
		const std::string & rank = "Not specified professional rank")
		:
		Worker(givenName, surname, age, experienceInYears),
		m_rank(rank)
	{}

	Programmer(
		const Worker & worker,
		const std::string & rank = "Not specified professional rank")
		:
		Worker(worker),
		m_rank(rank)
	{}

	virtual ~Programmer()
	{}

	void Show() const override final
	{
		Worker::Show();
		std::cout
			<< "Job name: " << m_jobName
			<< "\nProfessional rank (skill level): " << m_rank << "\n";
	}

	void SetExperienceInYears(const unsigned exp) override
	{
		Worker::SetExperienceInYears(exp);
	}

private:
	std::string m_rank; // junior, middle, senior, team lead etc.
	inline static std::string m_jobName = "software developer";
};

#endif //PROGRAMMER_H
