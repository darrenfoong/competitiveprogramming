#include<bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long>
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
#define nl "\n"

#define LIMIT 100

using namespace std;

int solve(int h, int w);

int grid[LIMIT+2][LIMIT+2];
int memo[LIMIT+2][LIMIT+2];

int main() {
	int t = 0, h = 0, w = 0;

	cin >> t;

	forv(i,t) {
		cin >> h >> w;
		forv1(j,h) {
			forv1(k,w) {
				cin >> grid[j][k];
			}
		}

		cout << solve(h, w) << endl;
	}

	return 0;
}

int solve(int h, int w) {
	forv(i, LIMIT+2) {
		forv(j, LIMIT+2) {
			memo[i][j] = 0;
		}
	}

	forv1(i,h) {
		forv1(j,w) {
			memo[i][j] = grid[i][j] + max(memo[i-1][j-1], max(memo[i-1][j+1], memo[i-1][j]));
		}
	}

	int res = 0;

	forv1(j,w) {
		if ( memo[h][j] > res ) {
			res = memo[h][j];
		}
	}

	return res;
}
