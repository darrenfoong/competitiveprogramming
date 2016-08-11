// C2A - Darren Foong

#include <bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long>
#define vs vector<string>
#define vpii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define vvl vector<vector<long> >
#define vvll vector<vector<long long> >
#define vvpii vector<vector<pair<int, int> > >
#define umapsi unordered_map<string, int>
#define umapii unordered_map<int, int>
#define umapllll unordered_map<long long, long long>
#define setpii set<pair<int, int> >
#define mseti multiset<int>
#define msetl multiset<long>
#define msetlr multiset<long, greater<int> >
#define pqi priority_queue<int>
#define pqir priority_queue<int, vector<int>, greater<int> >
#define pqpii priority_queue<pair<int, int> >
#define pqpiir priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >
#define forv(i,n) for ( int i = 0; i < n; i++ )
#define forv1(i,n) for ( int i = 1; i <= n; i++ )
#define all(x) x.begin(), x.end()
#define pf printf
#define sf scanf
#define pb push_back
#define nl "\n"

#define DEBUG

#ifdef DEBUG
 #define db(x) x
#else
 #define db(x)
#endif

using namespace std;

typedef unordered_map<char, vector<int> > charindex;
typedef unordered_map<string, charindex> charindexes;

string stolower(string input);
bool checkMatch(string input, string ref, charindex &lookup);
string solve(string input, vs &dict, charindexes &lookups);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	string s = "";

	cin >> n >> m;

	vs dict;
	charindexes lookups;

	forv(i,n) {
		cin >> s;
		dict.pb(s);

		charindex lookup;

		forv(j, s.length()) {
			char currentChar = s[j];

			if ( lookup.count(currentChar) == 0 ) {
				vi indices;
				lookup[currentChar] = indices;
			}

			lookup[currentChar].pb(j);
			sort(all(lookup[currentChar]));
		}

		lookups[s] = lookup;
	}

	forv(i,m) {
		cin >> s;
		cout << solve(stolower(s), dict, lookups) << nl;
	}

	return 0;
}

string stolower(string input) {
	string res = "";

	forv(i, input.length()) {
		res += tolower(input[i]);
	}

	return res;
}

bool checkMatch(string input, string ref, charindex &lookup) {
	int tracker = input.length();
	int lastPos = -1;

	forv(i, input.length()) {
		bool found = false;
		char currentChar = input[i];

		if ( lookup.count(currentChar) == 0 ) {
			return false;
		} else {
			vi indices = lookup[currentChar];

			forv(j, indices.size()) {
				if ( indices[j] > lastPos ) {
					lastPos = indices[j];
					found = true;
					break;
				}
			}

			if ( !found ) {
				return false;
			}
		}
	}

	return true;
}

string solve(string input, vs &dict, charindexes &lookups) {
	for ( auto dit = dict.begin(); dit != dict.end(); dit++ ) {
		if ( checkMatch(input, *dit, lookups[*dit]) ) {
			return *dit;
		}
	}

	return "No valid word";
}
