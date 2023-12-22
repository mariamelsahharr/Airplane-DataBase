#include "Seat.h"

#include <utility>

Seat::Seat() {

    avalible = true;
    index=-1;
}

Seat::Seat(Person p, int n) {

    avalible = false;
    person = std::move(p);
    index=-1;
 //   setIndex(n);
}

void Seat::printInfo(int mode) {

    if (mode == 0 || avalible) {
        cout << (avalible ? "available" : "not available") << endl;
    }
    else {
        person.printInfo();
        cout << endl;
    }

}
