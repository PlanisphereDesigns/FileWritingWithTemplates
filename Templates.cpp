// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<fstream>
#include<algorithm>

/*Include exceptions*/
#include<stdexcept>

#include "Templates.h"

using namespace std;

/*Exception class--throw exceptions later.  Not in a seperate file.*/
class BadInputException : public std::runtime_error {
public:
    /*This is the constructor for the exception.*/
    BadInputException() : std::runtime_error{ "You entered a character that was not allowed.  Please try again." } {
        /*This is the body of the exception.*/
    }
};

string checkInput(string myString) {
    int badLetterCount = 0;
    for (int i = 0; i < int(myString.size()); i++) {
        if (!(isalpha(myString.at(i))) || myString.at(i) == ' ') {
            badLetterCount++;
        }
    }
    if (badLetterCount > 0) {
        /*Throw an exception*/
        /*Keeping this out of the for loop ensures the exception is only thrown once.*/
        throw BadInputException{};
    }
    else {
        return myString;
    }
    return "badstring";
}

/*Get name function*/
string getFileName() {
    
    bool isValid = false;
    string fileName;
    while (!isValid) {
        cout << "Please enter a file name for your file: ";
        cin >> fileName;
        fileName.erase(remove_if(fileName.begin(), fileName.end(), isspace), fileName.end());
        try {
            checkInput(fileName);
            isValid = true;
            
        }
        catch (BadInputException) {
            cout << "Bad, invalid input was entered!";
            isValid = false;
            continue;
        }
        if (isValid == true) {
            //return the string
            cout << "The file name was accepted!" << endl;
            return fileName;
            break;
        }
        else {
            continue;
        }
    }
}





string checkIntInput(string myIntString) {
    int badLetterCount = 0;
    for (int i = 0; i < int(myIntString.size()); i++) {
        if (!(isdigit(myIntString.at(i))) || myIntString.at(i) == ' ') {
            badLetterCount++;
        }
    }
    if (badLetterCount > 0) {
        /*Throw an exception*/
        /*Keeping this out of the for loop ensures the exception is only thrown once.*/
        throw BadInputException{};
    }
    else {
        return myIntString;
    }
    return "badstring";
}

int main()
{
    cout << "Welcome to the generic template file writing program!\n";
    cout << endl;

    cout << "Please enter a the name you want your file of strings called.  Then, keep entering strings to represent the file contents.  When you're done, type done: " << endl;



    /*Made a new class template object.*/
    /*Templates do not have class constructor parentheses, like a class's constructor.*/


    Writer<string> stringFileWriter;

    string savedFN1 = getFileName();

    stringFileWriter.setFileName(savedFN1);
    string myInput;
    bool keepGoing = true;
    while (keepGoing) {
        cout << "Please enter a value! (type done for done): ";
        cin >> myInput;
        myInput.erase(remove_if(myInput.begin(), myInput.end(), isspace), myInput.end());
        if (myInput != "done") {
            try {
                checkInput(myInput);
                /*The vector is inside the class, so just want to pass the good input to the class.*/
                stringFileWriter.addItem(myInput);
                continue;
            }
            catch (BadInputException) {
                cout << "Your guess was not valid. Your answer cannot have spaces in it or have numbers.  Please try again: ";
                continue;
            }
        }
        else {
            if (int(stringFileWriter.getVectorSize()) <= 1) {
                cout << "Sorry, you can't be done until you enter at least two strings." << endl;
                continue;
            }

            stringFileWriter.writeItemToFile();
            cout << "These are the expected contents:" << endl;
            stringFileWriter.printVectorItems();
            keepGoing = false;
        }

        //ENTERING AND CHECKING INTS
        cout << "Please enter a the name you want your file of ints called.  Then, keep entering strings to represent the file contents.  When you're done, type done: " << endl;
        string myIntInput;
        string savedFN2 = getFileName();

        /*Made a new class template object.*/
        /*Templates do not have class constructor parentheses, like a class's constructor.*/
        Writer<int>intFileWriter;
        intFileWriter.setFileName(savedFN2);

        bool keepGoing2 = true;
        while (keepGoing2) {
            cout << "Please enter a value! (type done for done): ";
            /*Remove white spaces.*/
            cin >> myIntInput;
            myIntInput.erase(remove_if(myIntInput.begin(), myIntInput.end(), isspace), myIntInput.end());
            if (myIntInput != "done") {
                try {
                    checkIntInput(myIntInput);
                    /*The vector is inside the class, so just want to pass the good input to the class.*/
                    intFileWriter.addItem(stoi(myIntInput));
                    continue;
                }
                catch (BadInputException) {
                    cout << "Your guess was not valid. Your answer cannot have spaces in it or have numbers.  Please try again: ";
                    continue;
                }
            }
            else {
                if (int(intFileWriter.getVectorSize()) <= 1) {
                    cout << "Sorry, you can't be done until you enter at least two strings." << endl;
                    continue;
                }

                intFileWriter.writeItemToFile();
                cout << "These are the expected contents:" << endl;
                intFileWriter.printVectorItems();
                keepGoing2 = false;
            }

        } //End the second while loop



        //string to double is STOD
    } //End WHILE LOOP BRACKET
    /*The third while loop works with doubles.  This could also be done with vectors, arrays, class objects, and more but this is the
    last test that will be demonstrated.*/
}//End MAIN bracket.