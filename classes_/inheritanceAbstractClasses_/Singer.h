#ifndef SINGER_H
#define SINGER_H

#include "Person.h"
#include "Worker.h"

class Singer : public Worker
{
public:
	Singer(
		const std::string & givenName = "Not specified given name",
		const std::string & surname = "Not specified surname",
		const unsigned age = 0,
		const unsigned experienceInYears = 0,
		const std::string & vocalRange = "Not specified vocal range")
			:
		Worker(givenName, surname, age, experienceInYears),
		m_vocalRange(vocalRange)
	{}

	Singer(
		const Worker & worker,
		const std::string & vocalRange = "Not specified vocal range")
			:
		Worker(worker),
		m_vocalRange(vocalRange)
	{}

	virtual ~Singer()
	{}

	void Show() const override final
	{
		Worker::Show();
		std::cout
			<< "Job name: " << m_jobName
			<< "\nVocal range: " << m_vocalRange << "\n";
	}

	void SetExperienceInYears(const unsigned exp) override
	{
		Worker::SetExperienceInYears(exp);
	}

private:
	std::string m_vocalRange{};
	inline static std::string m_jobName = "singer";
};

#endif //SINGER_H
