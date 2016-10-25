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

#define DEBUG

#ifdef DEBUG
 #define db(x) x
#else
 #define db(x)
#endif

#define LIMIT 100000
#define umapp unordered_map<int,li::iterator>

using namespace std;

void solve(li &xs, umapp &ptrs);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int x = 0;

    cin >> n;

    li xs;
    umapp ptrs;

    forv(i,n) {
        cin >> x;
        xs.pb(x-1);
        ptrs.emplace(x-1,prev(xs.end()));
    }

    solve(xs, ptrs);

    return 0;
}

void solve(li &xs, umapp &ptrs) {
    int n = xs.size();
    int src = 0;
    int dest = 0;

    int cmin = 0;
    int cmax = n-1;

    li::iterator srcptr;

    forv(i,n) {
        if ( i % 2 == 0 ) {
            // i is even: find smallest element
            srcptr = ptrs[cmin++];
            dest = 0;
        } else {
            // i is odd: find largest element
            srcptr = ptrs[cmax--];
            dest = xs.size()-1;
        }

        src = distance(xs.begin(), srcptr);

        cout << abs(dest-src) << nl;

        xs.erase(srcptr);
    }
}
