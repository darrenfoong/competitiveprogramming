#include <bits/stdc++.h>

#define uint unsigned int
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
#define mapii map<int, int>
#define seti set<int>
#define setpii set<pair<int, int> >
#define mseti multiset<int>
#define msetl multiset<long>
#define msetlr multiset<long, greater<int> >
#define pqi priority_queue<int>
#define pqir priority_queue<int, vector<int>, greater<int> >
#define pqpii priority_queue<pair<int, int> >
#define pqpiir priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >
#define li list<int>
#define forv(i,n) for ( int i = 0; i < n; i++ )
#define forv1(i,n) for ( int i = 1; i <= n; i++ )
#define all(x) x.begin(), x.end()
#define pf printf
#define sf scanf
#define pb push_back
#define nl "\n"

#define NODEBUG

#ifdef DEBUG
 #define db(x) x
 #define io_opts
#else
 #define db(x)
 #define io_opts ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

#define LIMIT 100000

using namespace std;

class FenwickTree {
    public:
    void add(uint index, int v) {
        for ( uint i = index; i < n; i += (-i) & i ) {
            nodes[i] += v;
        }
    }

    int get(uint index) {
        /*
         * In a normal Fenwick tree, this should return the sum up to
         * index inclusive. However, since the previous version's
         * get_offset() method returns the sum up to index exclusive,
         * this method follows the same specifications.
         */
        index--;

        int res = 0;

        for ( uint i = index; i > 0; i -= (-i) & i ) {
            res += nodes[i];
        }

        return res;
    }

    void dump() {
        for ( uint i = 1; i < n; i++ ) {
            cout << "(" << i << " : " << get(i) << ")" << nl;
        }
    }

    FenwickTree(uint size) {
        n = size + 1;

        for ( uint i = 1; i < n; i++ ) {
            nodes[i] = 0;
        }
    }

    private:
    uint n;
    int nodes[LIMIT+1];
};

uint indices[LIMIT+1];

void solve(uint n, FenwickTree &offsets);

int main() {
    io_opts

    uint n = 0;
    int x = 0;

    cin >> n;

    FenwickTree offsets(n);

    for ( uint i = 1; i <= n; i++ ) {
        cin >> x;

        indices[x] = i;
        offsets.add(i, 0);
    }

    solve(n, offsets);

    return 0;
}

void solve(uint n, FenwickTree &offsets) {
    int src = 0;
    int dest = 0;

    uint cmin = 1;
    uint cmax = n;
    db(uint cnum = 0;)

    for ( uint i = 0; i < n; i++ ) {
        db(cout << "i is " << i << nl;)

        if ( i % 2 == 0 ) {
            // i is even: find smallest element
            db(cnum = i/2 + 1;)
            dest = 1;
            src = indices[cmin++];
            offsets.add(src, -1);
            src += offsets.get(src);

            cout << src - dest << nl;
        } else {
            // i is odd: find largest element
            db(cnum = n-((i-1)/2);)
            dest = n - i;
            src = indices[cmax--];
            offsets.add(src, -1);
            src += offsets.get(src);

            cout << dest - src << nl;
        }

        db(
            cout << " cnum is " << cnum << nl;
            cout << " src is " << src << nl;
            cout << " dest is " << dest << nl;
        )
    }
}
