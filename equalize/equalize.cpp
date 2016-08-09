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
#define msetlr multiset<long, greater<int> >
#define pqi priority_queue<int>
#define pqir priority_queue<int, vector<int>, greater<int> >
#define pqpii priority_queue<pair<int, int> >
#define pqpiir priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >
#define forv(i,n) for ( int i = 0; i < n; i++ )
#define all(x) x.begin(), x.end()
#define nl "\n"

using namespace std;

class MedianHeap {
	int halfsize;
	msetl lowerValues;
	msetl upperValues;

	public:
	void init(msetl &values) {
		lowerValues.clear();
		upperValues.clear();

		auto it = values.begin();
		halfsize = (values.size()-1)/2;
		// assume odd number of values

		forv(i,halfsize + 1) {
			lowerValues.insert(*it);
			it++;
		}

		forv(i,halfsize) {
			upperValues.insert(*it);
			it++;
		}
	}

	long getMedian() {
		auto rit = lowerValues.rbegin();
		return *rit;
	}

	void inout(long inValue, long outValue) {
		if ( inValue == outValue ) {
			return;
		}

		long median = getMedian();

		if ( outValue <= median ) {
			lowerValues.erase(lowerValues.find(outValue));
		} else {
			upperValues.erase(upperValues.find(outValue));
		}

		if ( inValue <= median ) {
			lowerValues.insert(inValue);
		} else {
			upperValues.insert(inValue);
			auto upperFirst = upperValues.begin();
			lowerValues.insert(*upperFirst);
			upperValues.erase(upperFirst);
		}

		if ( upperValues.size() < halfsize ) {
			auto lowerLast = lowerValues.end();
			lowerLast--;
			upperValues.insert(*lowerLast);
			lowerValues.erase(lowerLast);
		}
	}
};

long initMedian(vvl &grid, int k, int l, int row, MedianHeap &kernel);
long nextMedian(vvl &grid, int k, int l, int row, int col, MedianHeap &kernel);
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

long initMedian(vvl &grid, int k, int l, int row, MedianHeap &kernel) {
	msetl values;
	forv(i,k) {
		forv(j,l) {
			values.insert(grid[i+row][j]);
		}
	}

	kernel.init(values);
	return kernel.getMedian();
}

long nextMedian(vvl &grid, int k, int l, int row, int col, MedianHeap &kernel) {
	long todel = 0, toadd = 0;

	forv(i,k) {
		todel = grid[i+row][col-1];
		toadd = grid[i+row][col+l-1];
		kernel.inout(toadd, todel);
	}

	return kernel.getMedian();
}

long solve(vvl &grid, int k, int l) {
	int n = grid.size();
	int m = grid[0].size();

	long maxMedian = 0, newMedian = 0;
	MedianHeap kernel;

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
