# User Guide #
Mariam's Airplane Database is a terminal program that lets you create, manage, and delete multiple flights and associated information.  These flights are stored as object-based classes and can be interacted with via numerous pre-programmed commands.

## Help ##
The help command will give the user a basic overview of all the commands in the terminal environment.

#Modes
There are multiple modes in this program. This explains them.

- Detail mode will determine how much information is provided on the selected object (Flight, passengers, etc..). The higher the number, the more detail is provided. 


- Sort mode determines how passengers are sorted, if the detail mode is sufficient.

## Creating flights ##
Creating a Flight can be accomplished using the `create flight` command.  This command will then prompt you to provide:
1. departure : string
2. destination : string
3. departure date : string
4. number of seats : int

Once a flight is created it can be selected with the command `select flight.`  Information on all flights can also be viewed using the command `info all`

## Deleting flights ##
Selected flights can be deleted by using the command `delete flight.` After prompting the user for confirmation the Flight will be deleted and the user will be prompted to reassign passengers to new flights.  To do this the user will be provided with an alphabetised list of the passengers along with their contact info.  Once removed there is no way to undo this action.

## Adding passengers ##
Passengers can be added to selected flights by using the `add passenger` command.  This command will prompt the user for information relating to the Person:
1. First name : string
2. Last name : string
3. Address : string
4. Phone number : string

This command will then assign the passenger to the provided Seat.  This function will not work if a Person is already in the selected Seat.

## Removing passengers ##
Passengers can be removed from selected flights using the `remove passenger` command.  This command will prompt the user for the index of the Seat the passenger is on.  Once removed there is no way to undo this action.

## Viewing all flights info ##
Information relating to all flights can be viewed using the `info all` command.  This command will prompt the user for two values:
1. Detail mode : int (0,1,2)
   1. Prints flight only info
   2. Prints flight info + seat availability
   3. Prints flight info + list of passengers in each flight that are sorted according to the sort mode
2. Sort mode : int (0,1)
   1. Mode 1 sorts them by seat number
   2. Mode 2 sorts them alphabetically

Detail mode will determine how much information is provided on each flight.
Sort mode will determine how passengers are sorted, if the detail mode is sufficient.

## Viewing flight info ##
Information relating to the selected flight can be viewed using the `info flight` command.  This command will prompt the user for two values:
1. Detail mode : int (0,1,2)
   1. Prints flight only info
   2. Prints flight info + seat availability
   3. Prints flight info + list of passengers that are sorted according to the sort mode
2. Sort mode : int (0,1)
   1. Mode 1 sorts them by seat number 
   2. Mode 2 sorts them alphabetically

## Viewing passenger info ##
Information relating to the selected seat can be viewed using either the `info seat` or `info passenger` commands.  These commands both prompt the user for a single value:
1. Detail mode : int (0,1)


## Setting flight information ##
Selected flight information can be adjusted through the following commands:
1. `set departure`
2. `set destination`

Both commands will prompt the user for a single string.