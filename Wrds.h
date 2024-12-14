#ifndef WRDS_H_INCLUDED
#define WRDS_H_INCLUDED

#include "MyLib.h"

class Wrds {
public:
	string zodis;
	int kiekis;
	set<int> eilutes;
	Wrds() : zodis(""), kiekis(0), eilutes() {}
	Wrds(string z, int k, set<int> e) : zodis(z), kiekis(k), eilutes(e) {}

	friend ostream& operator<<(ostream& out, const Wrds& student);
	
};
void read(const string& fileName, map<string, Wrds>& mp);
void output(const string& fileName, const map<string, Wrds>& mp);
string removePunctuation(const string& word);


#endif // MYCLASS_H_INCLUDED
