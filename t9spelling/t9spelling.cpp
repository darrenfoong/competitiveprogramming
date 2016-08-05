// https://code.google.com/codejam/contest/351101/dashboard

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string solve(string line);
string ctokp(char c);
string dup(string input, int n);

int main() {
	int N = 0;
	cin >> N;
	cin.ignore();

	for ( int i = 0; i < N; i++ ) {
		string line = "";
		getline(cin, line);

		cout << "Case #" << (i+1) << ": " << solve(line) << endl;
	}

	return 0;
}

string dup(char c, int n) {
	string res = "";

	for ( int i = 0; i < n; i++ ) {
		res += string(1, c);
	}

	return res;
}

string ctokp(char c) {
	if ( c == ' ' ) {
		return "0";
	} else if ( c <= 'c' ) {
		return dup('2', 3 - ('c' - c));
	} else if ( c <= 'f' ) {
		return dup('3', 3 - ('f' - c));
	} else if ( c <= 'i' ) {
		return dup('4', 3 - ('i' - c));
	} else if ( c <= 'l' ) {
		return dup('5', 3 - ('l' - c));
	} else if ( c <= 'o' ) {
		return dup('6', 3 - ('o' - c));
	} else if ( c <= 's' ) {
		return dup('7', 4 - ('s' - c));
	} else if ( c <= 'v' ) {
		return dup('8', 3 - ('v' - c));
	} else if ( c <= 'z' ) {
		return dup('9', 4 - ('z' - c));
	}

	return "";
}

string solve(string line) {
	vector<string> keypresses;

	for ( unsigned int i = 0; i < line.size(); i++ ) {
		keypresses.push_back(ctokp(line[i]));
	}

	ostringstream os;

	char prev = 'X';

	for ( vector<string>::iterator it = keypresses.begin(); it != keypresses.end(); it++ ) {
		string current = *it;

		if ( current[0] == prev ) {
			os << " " << current;
		} else {
			os << current;
		}

		prev = current[0];
	}

	return os.str();
}
