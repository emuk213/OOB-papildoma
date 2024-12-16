#include "MyLib.h"
#include "Wrds.h"

string removePunctuation(const string& word) {
	string result = word;
	while (!result.empty() && ispunct(result.back())) {
			result.pop_back();	
	}

	while (!result.empty() && ispunct(result.front())) {
			result.erase(result.begin());
	}

	for (char& r : result) {
		r = tolower(r);
	}
	
	return result;
	
}

void read(const string& fileName, map<string, Wrds>& mp) {
	ifstream inFile(fileName);
	try {
		if (!inFile.is_open()) {
			throw runtime_error("Error: unable to open file: " + fileName);
		}

		string line;
		int cl = 1;
		while (getline(inFile, line)) {
			istringstream iss(line);
			string word;
			
			while (iss >> word) {
				word = removePunctuation(word);
				if (word != "") {
					if (mp.find(word) != mp.end()) {
						mp[word].kiekis++;
						mp[word].eilutes.insert(cl);
					}
					else {
						mp[word] = Wrds(1, { cl });
						//mp.insert({ word, Wrds(1, {cl}) });
					}
				}
			}
			
			cl++;
		}
		if (mp.empty()) {
			throw runtime_error("Error: no words found in the file" );
		}
		inFile.close();
	}
	
	catch (exception& e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void findURL(const string& fileName) {
	ifstream inFile(fileName);
	try {
		if (!inFile.is_open()) {
			throw runtime_error("Error: unable to open file: " + fileName);
		}
		string line;
		while (getline(inFile, line)) {
			istringstream iss(line);
			string word;
			while (iss >> word) {
				word = removePunctuation(word);
				if (word.substr(0, 4) == "www." || word.substr(0, 7) == "http://" || find(word.begin(), word.end(), '.') != word.end()) {
					cout << word << endl;
				}
			}
		}
		
		inFile.close();
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}


void output(const string& fileName, const map<string, Wrds>& mp) {
	ofstream out(fileName);
	out << setw(25) << left << "Zodis" << setw(10) << left << "Kiekis"  <<setw(15) <<right << "Eilutes" << endl;
	for (auto a : mp) {
		if (a.second.kiekis > 1) {
			out << setw(25) << left << a.first << setw(10) << right << a.second << "\n";
		}
	}

}

ostream& operator<<(ostream& out, const Wrds& zod) {
	out  << setw(10) << left << zod.kiekis << setw(10)<<right;
	
	for (auto& a : zod.eilutes) {
		out << a << " ";
	}

	return out;
}

