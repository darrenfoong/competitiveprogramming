#include<bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long>
#define vpii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define vvl vector<vector<long> >
#define vvpii vector<vector<pair<int, int> > >
#define umapsi unordered_map<string, int>
#define setpii set<pair<int, int> >
#define mseti multiset<int>
#define msetl multiset<long>
#define pqpii priority_queue<pair<int, int> >
#define pqpiir priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pii> >
#define forv(i,n) for ( int i = 0; i < n; i++ )
#define all(x) x.begin(), x.end()
#define nl "\n"

using namespace std;

long initMedian(vvl &grid, int k, int l, int row, msetl &kernel);
long nextMedian(vvl &grid, int k, int l, int row, int col, msetl &kernel);
long solve(vvl &grid, int k, int l);

int main() {
	int n = 0, m = 0, q = 0;
	scanf("%d %d %d", &n, &m, &q);

	vvl grid;

	forv(i,n) {
		vl row(m);
		forv(j,m) {
			scanf("%ld", &row[j]);
		}
		grid.push_back(row);
	}

	int k = 0, l = 0;

	forv(i,q) {
		scanf("%d %d", &k, &l);
		printf("%ld\n", solve(grid, k, l));
	}

	return 0;
}

long initMedian(vvl &grid, int k, int l, int row, msetl &kernel) {
	kernel.clear();

	forv(i,k) {
		forv(j,l) {
			kernel.insert(grid[i+row][j]);
		}
	}

	auto it = kernel.begin();
	advance(it, (kernel.size()-1)/2);

	return *it;
}

long nextMedian(vvl &grid, int k, int l, int row, int col, msetl &kernel) {
	long todel = 0, toadd = 0;

	forv(i,k) {
		todel = grid[i+row][col-1];
		kernel.erase(kernel.find(todel));
		toadd = grid[i+row][col+l-1];
		kernel.insert(toadd);
	}

	auto it = kernel.begin();
	advance(it, (kernel.size()-1)/2);

	return *it;
}

long solve(vvl &grid, int k, int l) {
	int n = grid.size();
	int m = grid[0].size();

	long maxMedian = 0, newMedian = 0;
	msetl kernel;

	forv(i, n-k+1) {
		newMedian = initMedian(grid, k, l, i, kernel);

		if ( newMedian > maxMedian ) {
			maxMedian = newMedian;
		}

		forv(j, m-l) {
			newMedian = nextMedian(grid, k, l, i, j+1, kernel);
			if ( newMedian > maxMedian ) {
				maxMedian = newMedian;
			}
		}
	}

	return maxMedian;
}
