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

#define LIMIT 100001
#define NEG -100000000000
#define EMP -1

using namespace std;

long long solve(long long n);

long long prices[LIMIT];
long long a1[LIMIT];
long long a2[LIMIT];
long long a3[LIMIT];
long long b1[LIMIT];
long long b2[LIMIT];
long long b3[LIMIT];

int main() {
	int t = 0;
	long long n = 0;

	scanf("%d", &t);

	forv(i,t) {
		scanf("%lld", &n);

		forv1(j,n) {
			scanf("%lld", &prices[j]);
		}

		printf("%lld\n", solve(n));
	}

	return 0;
}

long long solve(long long n) {
	if ( n == 1 ) {
		return prices[1];
	} else if ( n == 2 ) {
		return prices[1] + prices[2];
	} else if ( n == 3 ) {
		return prices[1] + prices[2] + prices[3];
	}

	a1[0] = 0;
	a2[0] = 0;
	a3[0] = 0;
	b1[0] = 0;
	b2[0] = 0;
	b3[0] = 0;

	forv(i, LIMIT) {
		a1[i] = EMP;
		a2[i] = EMP;
		a3[i] = EMP;
		b1[i] = EMP;
		b2[i] = EMP;
		b3[i] = EMP;
	}

	a1[1] = prices[1]; a1[2] = NEG;
	a2[1] = NEG; a2[2] = prices[1] + prices[2]; a2[3] = NEG;
	a3[1] = NEG; a3[2] = NEG; a3[3] = prices[1] + prices[2] + prices[3]; a3[4] = NEG;
	b1[1] = NEG; b1[2] = prices[1];
	b2[1] = NEG; b2[2] = NEG; b2[3] = NEG; b2[4] = prices[1] + prices[2];
	b3[1] = NEG; b3[2] = NEG; b3[3] = NEG; b3[4] = NEG; b3[5] = NEG; b3[6] = prices[1] + prices[2] + prices[3];

	for ( int i = 3; i <= n; i++ ) {
		if ( a1[i] == EMP ) {
			a1[i] = prices[i] + max({ b1[i-1], b2[i-1], b3[i-1] });
			//printf("a1[%d] is %lld\n", i, a1[i]);
		}

		if ( a2[i] == EMP ) {
			a2[i] = prices[i] + prices[i-1] + max({ b1[i-2], b2[i-2], b3[i-2] });
			//printf("a2[%d] is %lld\n", i, a2[i]);
		}

		if ( a3[i] == EMP ) {
			a3[i] = prices[i] + prices[i-1] + prices[i-2] + max({ b1[i-3], b2[i-3], b3[i-3] });
			//printf("a3[%d] is %lld\n", i, a3[i]);
		}

		if ( i == n ) {
			if ( b1[i] == EMP ) {
				b1[i] = max({ a1[i-1], a2[i-1], a3[i-1] });
				//printf("b1[%d] is %lld\n", i, b1[i]);
			}
			if ( b2[i] == EMP ) {
				b2[i] = max({ a1[i-2], a2[i-2], a3[i-2] });
				//printf("b2[%d] is %lld\n", i, b2[i]);
			}
			if ( b3[i] == EMP ) {
				b3[i] = max({ a1[i-3], a2[i-3], a3[i-3] });
				//printf("b3[%d] is %lld\n", i, b3[i]);
			}
		} else {
			if ( b1[i] == EMP ) {
				b1[i] = a1[i-1];
				//printf("b1[%d] is %lld\n", i, b1[i]);
			}
			if ( b2[i] == EMP ) {
				b2[i] = a2[i-2];
				//printf("b2[%d] is %lld\n", i, b2[i]);
			}
			if ( b3[i] == EMP ) {
				b3[i] = a3[i-3];
				//printf("b3[%d] is %lld\n", i, b3[i]);
			}
		}
	}

	return max({ a1[n], a2[n], a3[n], b1[n], b2[n], b3[n] });
}
