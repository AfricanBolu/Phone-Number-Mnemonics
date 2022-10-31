#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void CombineVector(vector <string>& threewords, vector <string>& fourwords) {
	string result;
	ofstream fout("output.txt");

	for (unsigned int i = 0; i < threewords.size(); i++) {
		for (unsigned int j = 0; j < fourwords.size(); j++) {
			result = threewords[i] + "-" + fourwords[j];
			fout << result << endl;
		}
		
	}
	fout.close();
}

void ValidNum(string number) {
	if (number.length() > 8 || number.length() < 8) {
		cout << "Invalid phone number\n";
	}
	else {
		for (unsigned int i = 0; i < 8; i++) {
			if (number[i] == '1' || number[i] == '0') {
				cout << "Invalid phone number\n";
				break;
			}
			else if (number[3] == '-') {
				continue;
			}
		}
	}
}

string CheckNum(vector <string>, int pos, string letters, string number) {
	for (unsigned int i = pos; i < number.length(); i++) {
		switch (number[i]) {
		case '2':
			letters = "ABC";
			return letters;
		case '3':
			letters = "DEF";
			return letters;
		case '4':
			letters = "GHI";
			return letters;
		case '5':
			letters = "JKL";
			return letters;
		case '6':
			letters = "MNO";
			return letters;
		case '7':
			letters = "PQRS";
			return letters;
		case '8':
			letters = "TUV";
			return letters;
		case '9':
			letters = "WXYZ";
			return letters;
		case '-':
			letters = "-";
			return letters;
			continue;
		}
	}
}

int main() {
	string words, phoneNumber;
	vector<string> letters;
	vector <string> threewords;
	vector <string> fourwords;
	vector <string> goodthree;
	vector <string> goodthree2;
	vector <string> goodfour;
	vector <string> goodfour2;
	vector <string> goodfour3;
	ifstream fin("yawl.txt");
	ofstream fout("output.txt");

	while (fin >> words) {
		if (words.length() == 3) {
			threewords.push_back(words);
			//fout << words << endl;
		}
		if (words.length() == 4) {
			fourwords.push_back(words);
			//fout << words << endl;
		}
	}
	getline(cin, phoneNumber);
	ValidNum(phoneNumber);
	
	for (unsigned int i = 0; i < words.length(); i++) {
		letters.push_back(CheckNum(threewords, i, words, phoneNumber) + " ");
	}

	
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int l = 0; l < threewords.size(); l++) {
			goodthree.push_back(threewords[l]);
		}
		threewords.clear();
		for (unsigned int j = 0; j < goodthree.size(); j++) {
			if (letters[i].find(goodthree[j].at(i)) != string::npos) {
				goodthree2.push_back(goodthree[j]);
			}
		}
		goodthree.clear();
		for (unsigned int k = 0; k < goodthree2.size(); k++) {
			goodthree.push_back(goodthree2[k]);
		}
		goodthree2.clear();	
	}

	for (unsigned int i = 4; i < 8; i++) {
		for (unsigned int l = 0; l < fourwords.size(); l++) {
			goodfour.push_back(fourwords[l]);
		}
		fourwords.clear();
		for (unsigned int j = 0; j < goodfour.size(); j++) {
			if (letters[i].find(goodfour[j].at(i - 4)) != string::npos) {
				goodfour2.push_back(goodfour[j]);
			}
		}
		goodfour.clear();
		for (unsigned int k = 0; k < goodfour2.size(); k++) {
			goodfour3.push_back(goodfour2[k]);
		}
		goodfour2.clear();
		for (unsigned int m = 0; m < goodfour3.size(); m++) {
			goodfour.push_back(goodfour3[m]);
		}
		goodfour3.clear();
	}

	CombineVector(goodthree, goodfour);

	fin.close();

	return 0;
}