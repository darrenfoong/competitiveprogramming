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
#define all(x) x.begin(), x.end()
#define nl "\n"

using namespace std;

long long solve(long long n, umapllll &memo);

int main() {
	string input = "";
	long long n;
	umapllll memo;

	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;

	while ( scanf("%lld", &n) == 1 ) {
		printf("%lld\n", solve(n, memo));
	}

	return 0;
}

long long solve(long long n, umapllll &memo) {
	if ( memo.count(n) == 1 ) {
		return memo[n];
	}

	long long res = 0;
	long long res2 = solve(n/2, memo);
	long long res3 = solve(n/3, memo);
	long long res4 = solve(n/4, memo);
	res = max(n, res2+res3+res4);
	memo[n] = res;
	return res;
}
