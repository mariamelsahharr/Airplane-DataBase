#include "Database.h"

// default constructor
Database::Database() {
    selectedFlight = -1;
    selectedSeat = -1;
    idCounter = 0;

}

//might change to switch?
void Database::runCommand (const string& cmd){

    // find out what the command is and run it, executes everything

    if (cmd.empty())
        return;
    else if (cmd == "help")
        printHelp();
    else if (cmd == "info all")
        printFlights();
    else if (cmd == "info flight")
        printFlight();
    else if (cmd == "info seat")
        printSeat();
    else if (cmd == "info passenger")
        printPassenger();
    else if (cmd == "create flight")
        createFlight();
    else if (cmd == "delete flight")
        deleteFlight();
    else if (cmd == "select flight")
        selectFlight();
    else if (cmd == "select seat")
        selectSeat();
    else if (cmd == "set departure")
        setDep();
    else if (cmd == "set destination")
        setDest();
    else if (cmd == "add passenger")
        addPassenger();
    else if (cmd == "remove passenger")
        removePassenger();
    else if(cmd=="set departure time")
        setDepTime();
    //might add set passenger?
    else                                         // unknown command error
        cout << "ERROR - Unknown command" << endl;
}


// commands
// help command
void Database::printHelp() {
    cout << "> help - prints out help info, such as what is being shown right now" << endl;
    cout << "> info all - print info on all flights, has multiple detail parameters " << endl;
    cout << "> info flight - print info on selected flight, has info on passengers, time, etc." << endl;
    cout << "> info seat - print info on selected seat, tells if seat is available + passenger" << endl;
    cout << "> info passenger - prints info on passenger in selected seat" << endl;
    cout << "> create flight - creates new flight" << endl;
    cout << "> delete flight - deletes selected flight" << endl;
    cout << "> select flight - selects a flight to perform other commands on" << endl;
    cout << "> select seat - selects a seat for commands" << endl;

    cout << "> set departure - set a flight's departure place" << endl;

    cout << "> set destination - set a flight's destination" << endl;
    cout << "> set departure_time - set a flight's departure time" << endl;
    cout << "> add passenger - add a passenger to a flight" << endl;
    cout << "> remove passenger - remove a passenger from a flight" << endl;
}


void Database::printFlights() {

    // print out all flight information int a given mode
    cout << "> Enter a detail mode (0, 1, 2)" << endl;

    int dMode;
    cin >> dMode;

    if (dMode != 0 && dMode != 1 && dMode != 2) {
        cout << "> ERROR - Please enter a valid detail mode (0, 1, 2)" << endl;
        return;
    }

    // get the sort type
    int sMode = 0;
    if (dMode != 0) {
        cout << "> Enter a sort mode (0, 1)" << endl;

        cin >> sMode;

        if (sMode != 0 && sMode != 1) {
            cout << "> ERROR - Please enter a valid sort mode (0, 1)" << endl;
            return;
        }
    }

    cout << "> Flights: " << flights.size() << endl;
    if (!flights.empty()) {
        for (int i = 0; i < flights.size(); i++) {
            cout << "> " << i << "." << endl;
            flights[i].printInfo(dMode, sMode);
        }
    }

}

void Database::printFlight() {

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - No flight selected.  Please select a flight using 'select flight'" << endl;
        return;
    }

    // get the mode
    cout << "> Enter a detail mode (0, 1, 2)" << endl;

    int dMode;
    cin >> dMode;

    if (dMode != 0 && dMode != 1 && dMode != 2) {
        cout << "> ERROR - Please enter a valid detail mode (0, 1, 2)" << endl;
        return;
    }

    // get the sort type
    int sMode = 0;
    if (dMode != 0) {
        cout << "> Enter a sort mode (0, 1)" << endl;

        cin >> sMode;

        if (sMode != 0 && sMode != 1) {
            cout << "> ERROR - Please enter a valid sort mode (0, 1)" << endl;
            return;
        }
    }

    // print out the flight info
    flights[selectedFlight].printInfo(dMode, sMode);

}

void Database::printSeat() {

    // make sure a seat is selected
    if (selectedSeat == -1) {
        cout << "> ERROR - No seat selected.  Please select a flight using 'select seat'" << endl;
        return;
    }

    // get the mode
    cout << "> Enter a mode (0, 1)" << endl;

    int mode;
    cin >> mode;

    if (mode != 0 && mode != 1) {
        cout << "> ERROR - Please enter a valid mode (0, 1)" << endl;
        return;
    }

    // print out the seat info
    flights[selectedFlight].getSeat(selectedSeat)->printInfo(mode);
}

void Database::printPassenger() {

    // make sure a seat is selected
    if (selectedSeat == -1) {
        cout << "> ERROR - No seat selected.  Please select a flight using 'select seat'" << endl;
        return;
    }

    // print out info
    flights[selectedFlight].getSeat(selectedSeat)->getPerson().printInfo();

}

// creation & deletion
void Database::createFlight() {

    // get the flight info
    cout << "> Please enter flight departure" << endl;
    string dep;
    getline(cin, dep);

    cout << "> Please enter flight destination" << endl;
    string dest;
    getline(cin, dest);

    cout << "> Please enter number of seats on the flight" << endl;
    string nS_str;
    getline(cin, nS_str);

    // make sure the number is an int
    bool isNum = true;
    for (char const c : nS_str) {
        if (isdigit(c) == 0)
            isNum = false;
    }

    if (!isNum) {
        cout << "> ERROR - Please enter an integer for the number of seats" << endl;
        return;
    }

    int nS = stoi(nS_str);

    cout << "> Please enter flight departure time" << endl;
    string depTime;
    getline(cin, depTime);

    // create the flight
    flights.emplace_back(idCounter, nS, dep, dest, depTime);

    cout << "> Created flight" << endl;

    idCounter ++;
}

void Database::deleteFlight() {

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - Please select a flight using 'select flight' first" << endl;
        return;
    }

    // confirmation
    cout << "> Are you sure you want to delete flight #" << selectedFlight << " (y/n)" << endl;

    string resp;
    cin >> resp;

    // delete the selected flight and deselect all flights
    if (resp == "n") {
        cout << "> Canceled deletion" << endl;
        return;
    }

    // confirmation if passengers
    if (flights[selectedFlight].getNumFullSeats() != 0) {
        cout << "> There are still passengers on this flight - are ou sure you want to delete it (y/n)";

        cin >> resp;

        if (resp == "n") {
            cout << "> Canceled deletion" << endl;
            return;
        }
    }

    // print out info on the flight
    cout << "> Deleting selected flight - please reassign all passengers" << endl;
    flights[selectedFlight].printInfo(2, 0);

    // delete the flight
    flights.erase(flights.begin() + selectedFlight);
    cout << "> Deleted flight " << selectedFlight << endl;

}

// selection commands
void Database::selectFlight() {

    // get the index
    cout << "> Please enter the index of the flight you would like to select" << endl;

    int index;
    cin >> index;

    // make sure it's valid
    if (index >= flights.size()) {
        cout << "> ERROR - Please enter a valid index (0-" << flights.size()-1 << ")" << endl;
        return;
    }

    cout << "> Selected flight " << index << endl;

    selectedFlight = index;
    selectedSeat = -1; // reset the selected seat

}

void Database::selectSeat() {

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - Please select a flight using 'select flight' first" << endl;
        return;
    }

    // get the index
    cout << "> Please enter the index of the seat you would like to select" << endl;

    int index;
    cin >> index;

    // make sure it's valid
    if (index > flights[selectedFlight].getNumSeats()) {
        cout << "> ERROR - Please enter a valid index (0-" << flights[selectedFlight].getNumSeats() << ")" << endl;
        return;
    }

    cout << "> Selected seat " << index << endl;

    selectedSeat = index;

}

// setter commands
void Database::setDep() {

    cout << "> Enter a new departure" << endl;

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - Please select a flight using 'select flight' first" << endl;
        return;
    }

    string dep;
    getline(cin, dep);

    flights[selectedFlight].setDeparture(dep);

    cout << "> updated flight " << selectedFlight << "'s departure" << endl;

}

void Database::setDest() {

    cout << "> Enter a new destination" << endl;

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - Please select a flight using 'select flight' first" << endl;
        return;
    }

    string dest;
    getline(cin, dest);

    flights[selectedFlight].setDestination(dest);

    cout << "> updated flight " << selectedFlight << "'s destination" << endl;

}

void Database::setDepTime() {

    cout << "Enter a new departure time" << endl;

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - Please select a flight using 'select flight' first" << endl;
        return;
    }

    string depTime;
    getline(cin, depTime);

    flights[selectedFlight].setDepartureTime(depTime);

    cout << "> updated flight " << selectedFlight << "'s departure time" << endl;
}

void Database::addPassenger() {

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> ERROR - Please select a flight using 'select flight' first" << endl;
        return;
    }

    // get person info
    string fName;
    string lName;
    string addr;
    string pNum;

    cout << "> Please enter first name" << endl;
    getline(cin, fName);
    cout << "> Please enter last name" << endl;
    getline(cin, lName);
    cout << "> Please enter address" << endl;
    getline(cin, addr);
    cout << "> Please enter phone number" << endl;
    getline(cin, pNum);

    // find out which passenger to delete
    cout << "> Please enter the passenger's seat" << endl;
    string i_str;
    getline(cin, i_str);

    // make sure the number is an int
    bool isNum = true;
    for (char const c : i_str) {
        if (isdigit(c) == 0)
            isNum = false;
    }

    int i = stoi(i_str);

    if (!isNum) {
        cout << "> ERROR - Please enter an integer" << endl;
        return;
    }
    else if (i >= flights[selectedFlight].getNumSeats()) {
        cout << "> ERROR - Index is too high" << endl;
        return;
    }
    else if (!flights[selectedFlight].getSeat(i)->getAvalible()) {
        cout << "> ERROR - Seat already has a passenger" << endl;
        return;
    }

    flights[selectedFlight].addPassenger(i, Person(fName, lName, addr, pNum));

    cout << "Added a passenger" << endl;

}

void Database::removePassenger() {

    // make sure a flight is selected
    if (selectedFlight == -1) {
        cout << "> Please select a flight using 'select flight' first" << endl;
        return;
    }

    // find out which passenger to delete
    cout << "> Please enter the index of the passenger to remove" << endl;
    string i_str;
    getline(cin, i_str);

    // make sure the number is an int
    bool isNum = true;
    for (char const c : i_str) {
        if (isdigit(c) == 0)
            isNum = false;
    }

    int i = stoi(i_str);

    if (!isNum) {
        cout << "> ERROR - Please enter an integer" << endl;
        return;
    }
    else if (i >= flights[selectedFlight].getNumSeats()) {
        cout << "> ERROR - index is too high" << endl;
        return;
    }
    else if (flights[selectedFlight].getSeat(i)->getAvalible()) {
        cout << "> ERROR - no passenger in selected seat" << endl;
        return;
    }

    flights[selectedFlight].removePassenger(i);

    cout << "Passenger removed" << endl;

}

void Database::setPassenger() {

}
