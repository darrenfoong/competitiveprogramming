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

using namespace std;

int solve(int n, vi &values);

int main() {
	int n = 0, m = 0;

	scanf("%d %d", &n, &m);

	vi values;

	int value = 0;

	forv1(i,m) {
		scanf("%d", &value);
		values.push_back(value);
	}

	printf("%d\n", solve(n, values));

	return 0;
}

int solve(int n, vi &values) {
	n--;
	sort(all(values));

	vi diffs;

	for ( int i = 1; i < values.size(); i++ ) {
		diffs.push_back(values[i]-values[i-1]);
	}

	int kernelSum = 0;

	for ( int i = 0; i < n; i++ ) {
		kernelSum += diffs[i];
	}

	int minSum = kernelSum;

	for ( int i = 1; i <= diffs.size() - n; i++ ) {
		kernelSum -= diffs[i-1];
		kernelSum += diffs[i+n-1];

		if ( kernelSum < minSum ) {
			minSum = kernelSum;
		}
	}

	return minSum;
}
