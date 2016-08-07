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

int dp[MAX_LENGTH+1][MAX_LENGTH+1];

int main() {
	ios_base::sync_with_stdio(false);

	int t = 0;
	cin >> t;

	forv(i, MAX_LENGTH+1) {
		dp[0][i] = 0;
		dp[i][0] = 0;
	}

	forv(i,t) {
		string u = "";
		cin >> u;
		cout << solve(u) << nl;
	}

	return 0;
}

int lcs(string u) {
	int up = 0, left = 0, diag = 0;
	for ( int i = 1; i <= u.length(); i++ ) {
		for ( int j = 1; j <= u.length(); j++ ) {
			up = dp[i-1][j];
			left = dp[i][j-1];
			diag = dp[i-1][j-1];

			if ( u[i-1] == u[u.length()-j] ) {
				diag++;
			}

			dp[i][j] = max(up, max(left, diag));
		}
	}

	return dp[u.length()][u.length()];
}

int solve(string u) {
	return u.length() - lcs(u);
}
