// Papildoma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyLib.h"
#include "Wrds.h"


int main()
{
    //Wrds temp;
    map<string, Wrds> mp;
    string file;
    //cout << "Enter txt file name" << endl;
    //cin >> file;
    try {
        read("tekstas.txt", mp);  // Call read function
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    if (mp.empty()) {
        cout << "No words were found in the file." << endl;
    }
    else {
        // Print the word counts
        /*for (const auto& a : mp) {
            cout << "Word: " << a.first << ", Count: " << a.second.kiekis << endl;
        }*/
        output("ats.txt", mp);
    }

    return 0;
}

