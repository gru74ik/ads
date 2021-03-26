#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Person.h"		// abstract base class
#include "Worker.h"		// Worker : public Person
#include "Singer.h"		// Singer : public Worker
#include "Programmer.h" // Programmer : public Worker

int main()
{
	std::vector<std::unique_ptr<Worker>> workers;

	workers.push_back(std::make_unique<Singer>("Paul", "Grant", 32, 11, "tenor"));
	workers.push_back(std::make_unique<Programmer>("Andy", "White", 31, 10, "senior"));

	Worker w("Dick", "Wright", 33, 13);
	workers.push_back(std::make_unique<Singer>(w, "baritone"));
	workers.push_back(std::make_unique<Programmer>(w, "middle"));
	workers.back()->SetExperienceInYears(5);

	for (const auto & elem : workers) {
        elem->Show();
    }

	Person::StaticFunctionSaysHello();

	//===================================

	std::unordered_map<std::string, std::unique_ptr<Worker>> workers2;
	workers2.emplace("Bonzo", std::make_unique<Singer>("John", "Bonham", 32, 11, "bass"));
	workers2.emplace("Greenhorn", std::make_unique<Programmer>("Rick", "Ford", 31, 10, "team-lead"));
	workers2.emplace("GrandMaster", std::make_unique<Programmer>("John", "Lord", 31, 10, "principal software architect"));

	for (const auto& [nickname, object] : workers2) {
		std::cout << "\n" << nickname << "'s info:";
		object->Show();
	}
}
