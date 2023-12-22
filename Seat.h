#pragma once

#include <utility>

#include "Person.h"

class Seat
{
private:
    bool avalible;
    Person person;

    /// @brief Index of the seat - used when displaying available seats so that correct index is shown
    int index;

public:
    Seat();
    explicit Seat(Person p, int n);

    /// @brief Get whether the seat is available
    bool getAvalible() const { return avalible; }
    /// Get the person in the seat
    Person getPerson() { return person; }
    /// @brief Get index of the seat
    int getIndex() const     { return index; }

    /// @brief Set the person in the seat
    void setPerson(Person p) { person = std::move(p); avalible = false; }
    /// @brief Remove the person currently in the seat
    void removePerson()      { avalible = true; }
    /// @brief Set the index of the seat
    void setIndex(int i)     { index = i; }

    /// @brief Prints out the seat's information.  Recurse down to Person.printInfo when applicable
    /// @param mode : determines how much information is printed.
    /// \n A mode of 0 prints out the availability of the seat.
    /// \n A mode of 1 prints out the person within the seat, if applicable
    void printInfo(int mode);
};