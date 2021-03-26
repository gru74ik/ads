#include <iostream>
#include <string>
#include <vector>

#include "Car.h"

int main()
{
    Car porsche911(
        "Porsche",
        "911 Carrera",
        "rear engine",
        "2+2 seater coupé",
        "8-speed Porsche Doppelkupplung (PDK) with dual-mass fly wheel",
        2020,
        293,
        4.2,
        {{"Length", 4.519}, {"Width", 1.852}, {"Height", 1.298}, {"Wheelbase", 2.450}});

    Car porsche911GT3(
        "Porsche",
        "911 GT3",
        "rear engine",
        "2+2 seater coupé",
        "8-speed Porsche Doppelkupplung (PDK) with dual-mass fly wheel",
        2020,
        318,
        3.4,
        {{"Length", 4.573}, {"Width", 1.852}, {"Height", 1.279}, {"Wheelbase", 2.457}});

    Car porsche911TurboS(
        "Porsche",
        "911 Turbo S",
        "rear engine",
        "2+2 seater coupé",
        "8-speed Porsche Doppelkupplung (PDK) with dual-mass fly wheel",
        2020,
        330,
        2.7,
        {{"Length", 4.535}, {"Width", 1.900}, {"Height", 1.303}, {"Wheelbase", 2.450}});

    std::cout << porsche911 << "\n" << porsche911GT3 << "\n" << porsche911TurboS << "\n";
}