#include<bits/stdc++.h>

#define vi vector<int>
#define umapsi unordered_map<string, int>
#define fori(n) for ( int i = 0; i < n; i++ )
#define fori2(m,n) for ( int i = m; i < n; i++ )
#define forie(n) for ( int i = 0; i <= n; i++ )
#define forie2(m,n) for ( int i = m; i <= n; i++ )
#define all(x) x.begin(), x.end()
#define nl "\n"

using namespace std;

int solve(string input, umapsi &map);

int main() {
	string input = "";

	umapsi map;

	while ( true ) {
		cin >> input;
		if ( input == "0" ) {
			return 0;
		}

		cout << solve(input, map) << nl;
	}

	return 0;
}

int solve(string input, umapsi &map) {
	if ( input[0] == '0' ) {
		return 0;
	}

	auto lookup = map.find(input);

	if ( lookup != map.end() ) {
		return lookup->second;
	}

	if ( input.length() < 2 ) {
		return input.length();
	}

	int head = stoi(input.substr(0,2));

	if ( head > 26 ) {
		return solve(input.substr(1), map);
	} else if ( head == 10 || head == 20 ) {
		if ( input.length() ==2 ) {
			return 1;
		} else {
			return solve(input.substr(2), map);
		}
	} else {
		if ( input.length() == 2 ) {
			if ( head < 10 ) {
				return 1;
			} else {
				return 2;
			}
		}
	}

	int res = 0;

	res += solve(input.substr(1), map);
	res += solve(input.substr(2), map);

	map[input] = res;
	return res;
}
