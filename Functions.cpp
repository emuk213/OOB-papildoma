#include "MyLib.h"
#include "Wrds.h"

string removePunctuation(const string& word) {
	string result = word;
	// Remove punctuation from the beginning and end of the word
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
		else {
			cout << "File opened successfully." << endl;  // Debug message
		}
		string line;
		int cl = 1;
		while (getline(inFile, line)) {
			cout << "Reading line: " << cl << endl;
			istringstream iss(line);
			string word;
			
			while (iss >> word){
				//mp[word].eilutes.clear();
				word = removePunctuation(word);
				if (mp.find(word) != mp.end()) {
					mp[word].kiekis++;
					mp[word].eilutes.insert(cl);
				}
				else {
					mp[word] = Wrds(word, 1, {cl});
					//mp.insert()
				}
			}
			cl++;
		}
		if (mp.empty()) {
			throw runtime_error("No words found in the file!" );
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
	Wrds Lok;
	out << setw(15) << left << "Zodis" << setw(5) << right << "Kiekis" << setw(20) << right << "Eilutes" << endl;
	for (auto a : mp) {
		if (a.second.kiekis > 1) {
			out << a.second << "\n";
		}
	}

}

ostream& operator<<(ostream& out, const Wrds& zod) {

	out << setw(15) << left << zod.zodis << setw(3) << right << zod.kiekis << setw(19) << right;
	for (auto& a : zod.eilutes) {
		out << a << " ";
	}

	return out;
}

