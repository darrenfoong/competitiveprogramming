#include <bits/stdc++.h>

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

#define LIMIT 100000

using namespace std;

int solve(int n);

long long arr[LIMIT+1];
int memo[LIMIT+1];

int main() {
	int n = 0;

	scanf("%d", &n);

	forv1(i,n) {
		scanf("%lld", &arr[i]);
	}

	printf("%d\n", solve(n));

	return 0;
}

int solve(int n) {
	arr[0] = LLONG_MAX;

	int max = 0;

	forv1(i,n) {
		memo[i] = arr[i] > arr[i-1] ? memo[i-1] + 1 : 1;

		if ( memo[i] > max ) {
			max = memo[i];
		}
	}

	return max;
}
