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

int indices[LIMIT];
umapp ptrs;
li xs;
seti sorted;

void solve(int n);
int num_lte(int x);
int num_gte(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int x = 0;

    cin >> n;

    forv(i,n) {
        cin >> x;

        indices[x-1] = i;
        xs.push_back(x-1);
        ptrs.emplace(x-1,prev(xs.end()));
    }

    solve(n);

    return 0;
}

void solve(int n) {
    int src = 0;
    int dest = 0;
    int nsorted_src = 0;
    int nsorted_dest = 0;

    int cmin = 0;
    int cmax = n-1;
    int cnum = 0;

    forv(i,n) {
        cout << "i is " << i << nl;
        if ( i % 2 == 0 ) {
            cnum = i/2;
            // i is even: find smallest element
            src = indices[cmin];
            dest = indices[*(xs.begin())];

            cmin++;

            nsorted_src = num_lte(src);
            nsorted_dest = num_lte(dest);
        } else {
            cnum = n-((i+1)/2);
            // i is odd: find largest element
            src = indices[cmax];
            dest = indices[*(prev(xs.end()))];

            cmax--;

            nsorted_src = num_gte(src);
            nsorted_dest = num_gte(dest);
        }

        cout << " cnum is " << cnum << nl;
        cout << " src is " << src << nl;
        cout << " dest is " << dest << nl;
        cout << " nsorted_src is " << nsorted_src << nl;
        cout << " nsorted_dest is " << nsorted_dest << nl;
        cout << " emplace " << src << nl;

        cout << abs(dest-src) - (nsorted_src-nsorted_dest) << nl;

        sorted.emplace(src);

        xs.erase(ptrs[cnum]);
    }
}

int num_lte(int x) {
    auto lb = upper_bound(all(sorted), x);
    return distance(sorted.begin(), lb);
}

int num_gte(int x) {
    auto lb = lower_bound(all(sorted), x);
    return distance(lb, sorted.end());
}
