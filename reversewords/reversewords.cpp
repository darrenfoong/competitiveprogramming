// https://code.google.com/codejam/contest/dashboard?c=351101

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string solve(string line);

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

string solve(string line) {
	vector<string> words;

	stringstream ss(line);
	string item;

	while ( getline(ss, item, ' ') ) {
		words.push_back(item);
	}

	ostringstream os;

	for ( vector<string>::reverse_iterator rit = words.rbegin(); rit != words.rend(); rit++ ) {
		if ( rit == words.rend() ) {
			os << *rit;
		} else {
			os << *rit << " ";
		}
	}

	return os.str();
}
