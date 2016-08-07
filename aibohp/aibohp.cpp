#include<bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int> >
#define vvpii vector<vector<pair<int, int> > >
#define umapsi unordered_map<string, int>
#define setpii set<pair<int, int> >
#define pqpii priority_queue<pair<int, int> >
#define pqpiir priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pii> >
#define forv(i,n) for ( int i = 0; i < n; i++ )
#define all(x) x.begin(), x.end()
#define nl "\n"

#define MAX_LENGTH 6100

using namespace std;

int lcs(string u, string v);
int solve(string u);

int prevrow[MAX_LENGTH+1];
int currrow[MAX_LENGTH+1];

int main() {
	ios_base::sync_with_stdio(false);

	int t = 0;
	cin >> t;

	forv(i,t) {
		string u = "";
		cin >> u;
		cout << solve(u) << nl;
	}

	return 0;
}

int lcs(string u) {
	forv(i, MAX_LENGTH+1) {
		prevrow[i] = 0;
	}

	int up = 0, left = 0, diag = 0;
	for ( int i = 1; i <= u.length(); i++ ) {
		for ( int j = 1; j <= u.length(); j++ ) {
			up = prevrow[j];
			left = currrow[j-1];
			diag = prevrow[j-1];

			if ( u[i-1] == u[u.length()-j] ) {
				diag++;
			}

			currrow[j] = max(up, max(left, diag));
		}

		copy(begin(currrow), end(currrow), begin(prevrow));
	}

	return currrow[u.length()];
}

int solve(string u) {
	return u.length() - lcs(u);
}
