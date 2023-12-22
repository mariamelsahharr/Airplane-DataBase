#include "Person.h"

#include <utility>

Person::Person() {

    fName = "__UNDEFINED__";
    lName = "__UNDEFINED__";
    address = "__UNDEFINED__";
    phoneNum = "__UNDEFINED__";

}

Person::Person(string fN, string lN, string add, string num) {

    fName = std::move(fN);
    lName = std::move(lN);
    address = std::move(add);
    phoneNum = std::move(num);

}

void Person::printInfo() {

    cout << fName << ", " << lName<< " : " << address << " : " << phoneNum;

}