#include "MyLib.h"
#include "Wrds.h"

int main()
{
    std::locale::global(std::locale("lt_LT.UTF-8"));
    map<string, Wrds> mp;
    string file;
    cout << "Enter txt file name" << endl;
    cin >> file;
    read(file, mp);
    findURL(file);
    output("ats.txt", mp);
    
    return 0;
}

