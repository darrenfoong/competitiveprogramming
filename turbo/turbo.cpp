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

#define NODEBUG

#ifdef DEBUG
 #define db(x) x
#else
 #define db(x)
#endif

#define LIMIT 100000

using namespace std;

int indices[LIMIT];
int offsets[LIMIT];

void solve(int n);
int get_offset(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int x = 0;

    cin >> n;

    forv(i,n) {
        cin >> x;

        indices[x-1] = i;
        offsets[i] = 0;
    }

    solve(n);

    return 0;
}

void solve(int n) {
    int src = 0;
    int dest = 0;

    int cmin = 0;
    int cmax = n-1;
    int cnum = 0;

    forv(i,n) {
        db(cout << "i is " << i << nl;)

        if ( i % 2 == 0 ) {
            // i is even: find smallest element
            cnum = i/2;
            dest = get_offset(0);
            src = indices[cmin++];
            offsets[src]--;
            src += get_offset(src);

            cout << src - dest << nl;
        } else {
            // i is odd: find largest element
            cnum = n-((i+1)/2);
            dest = (n-1) + get_offset(n);
            src = indices[cmax--];
            offsets[src]--;
            src += get_offset(src);

            cout << dest - src << nl;
        }

        db(
            cout << " cnum is " << cnum << nl;
            cout << " src is " << src << nl;
            cout << " dest is " << dest << nl;
        )
    }
}

int get_offset(int n) {
    int offset = 0;

    forv(i,n) {
        offset += offsets[i];
    }

    return offset;
}
