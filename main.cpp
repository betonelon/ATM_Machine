#include <iostream>

using namespace std;

int main() {

    // MEMBER VARIABLES: for PIN #
    int pin_number,
            user_tries = 0;

    // MEMBER VARIABLES: for ATM Machine
    float deposit = 0,
            balance = 5000,
            withdraw = 0;

    int option = 0;

    cout << "\n\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t*                                                         *" << endl;
    cout << "\t*              Welcome to Hesham + Niema bank:            *" << endl;
    cout << "\t*                                                         *" << endl;
    cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

    //GOTO statement that will iterate every time user enters an incorrect pin #
    check_pin_number:

    cout << "\n\tPlease enter your 4 digit pin number:";
    cin >> pin_number;

    // the length of 0 is 1
    int len = 0;

    // finds the length of the pin number:
    // and for numbers greater than 0
    if (pin_number > 9999) {
        len = 5;
    } else if (pin_number > 999) {
        len = 4;
    } else if (pin_number > 99) {
        len = 3;
    } else if (pin_number > 9) {
        len = 2;
    } else
        len = 1; // any integer larger than 9999 and smaller than 9 will default to 1

    // will determine what happens if user inputs an invalid pin number:
    if (len != 4) {

        user_tries++; // increment the wrong pin as a try
        cout << "\tIncorrect amount of pin number!!" << endl;

        // allow the user to renter a value for the pin number:
        cin.clear();
        cin.ignore(1000, '\n');

        if (user_tries == 3) {
            cout << "\n\tYou've exceeded the number of attempts." << endl;
            exit(0);
        }
        // cin >> pin_number;
        goto check_pin_number;
    } else
        goto start_transaction;

    start_transaction:
    cout << "\tYour pin has been accepted!!" << endl;

    cout << "\n\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t*              Welcome to Hesham + Niema bank:            *" << endl;
    cout << "\t*                          MENU                           *" << endl;
    cout << "\t*                     1. Check Balance                    *" << endl;
    cout << "\t*                     2. Withdraw                         *" << endl;
    cout << "\t*                     3. Deposit                          *" << endl;
    cout << "\t*                     4. Exit                             *" << endl;
    cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

    while (option < 4) {

        cout << "\n\tPlease enter the option that you would like:";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\n\tYour current balance is: " << balance << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            case 2:
                cout << "\n\tEnter the amount you want to withdraw: ";

                cin.clear();
                cin.ignore(10000, '\n');

                cin >> withdraw;

                if (withdraw > balance) {
                    cout << "\n\tERROR: You have an insufficient balance." << "\n";
                } else {

                    balance -= withdraw;
                    cout << "\n\tCongratulations! Your transaction has been successfully completed.";
                    cout << "\n\tYour current balance is: " << balance << "\n";
                }
                break;
            case 3:
                cout << "\n\tEnter the amount you want to deposit: ";

                cin.clear();
                cin.ignore(10000, '\n');

                cin >> deposit;

                balance += deposit;

                cout << "\n\tCongratulations!! Your transaction has been successfully completed. \n";
                cout << "\tYour current balance is: " << balance << "\n";
                break;
            case 4:
                cout << "\n\tThanks for using our service!" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            default:

                cin.clear();
                cin.ignore(10000, '\n');

                cout << "\n\tPlease enter a valid choice and try again: ";
                break;
        }

    }

    return (0);
}


