// https://code.google.com/codejam/contest/90101/dashboard

#include <iostream>
#include <vector>

using namespace std;

bool match(string word, vector<string> &fsa);
vector<string> mkfsa(string re);
int solve(vector<string> &dict, string re);

int main() {
	int L = 0;
	int D = 0;
	int N = 0;
	cin >> L;
	cin >> D;
	cin >> N;
	cin.ignore();

	vector<string> dict;

	for ( int i = 0; i < D; i++ ) {
		string word = "";
		cin >> word;
		dict.push_back(word);
	}

	for ( int i = 0; i < N; i++ ) {
		string re = "";
		cin >> re;
		cout << "Case #" << (i+1) << ": " << solve(dict, re) << endl;
	}

	return 0;
}

vector<string> mkfsa(string re) {
	bool inparen = false;
	string tok = "";
	vector<string> fsa;

	for ( unsigned int i = 0; i < re.size(); i++ ) {
		char current = re[i];

		if ( current == '(' ) {
			inparen = true;
		} else if ( current == ')' ) {
			inparen = false;
			fsa.push_back(tok);
			tok = "";
		} else {
			if ( inparen ) {
				tok += current;
			} else {
				fsa.push_back(string(1, current));
			}
		}
	}

	return fsa;
}

bool match(string word, vector<string> &fsa) {
	for ( unsigned int i = 0; i < word.size(); i++ ) {
		char current = word[i];
		string state = fsa[i];

		if ( (state.length() == 1) && (state[0] != current) ) {
			return false;
		}

		if ( state.length() > 1 ) {
			bool hasCurrent = false;

			for ( unsigned int j = 0; j < state.length(); j++ ) {
				if ( state[j] == current ) {
					hasCurrent = true;
					break;
				}
			}

			if ( !hasCurrent ) {
				return false;
			}
		}
	}

	return true;
}

int solve(vector<string> &dict, string re) {
	int count = 0;

	vector<string> fsa = mkfsa(re);

	for ( vector<string>::iterator it = dict.begin(); it != dict.end(); it++ ) {
		if ( match(*it, fsa) ) {
			count++;
		}
	}

	return count;
}
