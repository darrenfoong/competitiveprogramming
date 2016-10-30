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

#define LIMIT 1000000
#define NIL -1

using namespace std;

int parents[LIMIT+1];
int values[LIMIT+1];
int ranks[LIMIT+1];

string query(int arg1, int arg2);
void join(int arg1, int arg2);
int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int q = 0;
    char op;
    int arg1 = 0;
    int arg2 = 0;

    cin >> n >> q;

    forv(i,LIMIT+1) {
        parents[i] = NIL;
        values[i] = i;
        ranks[i] = 1;
    }

    forv(i,q) {
        cin.get();
        cin.get(op);

        cin >> arg1 >> arg2;

        if ( op == '?' ) {
            cout << query(arg1, arg2) << nl;
        }

        if ( op == '=' ) {
            join(arg1, arg2);
        }
    }

    return 0;
}

int handle(int currentNode) {
    while ( parents[currentNode] != NIL ) {
        currentNode = parents[currentNode];
    }

    return currentNode;
}

void flatten(int leaf, int root) {
    int prevcurrentNode = 0;
    int currentNode = leaf;

    while ( currentNode != root ) {
        prevcurrentNode = currentNode;
        currentNode = parents[currentNode];
        parents[prevcurrentNode] = root;
    }
}

string query(int arg1, int arg2) {
    if ( arg1 == arg2 ) {
        return "yes";
    }

    int handle1 = handle(arg1);
    int handle2 = handle(arg2);

    flatten(arg1, handle1);
    flatten(arg2, handle2);

    return (handle1 == handle2) ? "yes" : "no";
}

void join(int arg1, int arg2) {
    if ( arg1 == arg2 ) {
        return;
    }

    int handle1 = handle(arg1);
    int handle2 = handle(arg2);

    if ( handle1 == handle2 ) {
        return;
    }

    int rank1 = ranks[handle1];
    int rank2 = ranks[handle2];

    int handle_base;
    int handle_tomerge;

    if ( rank1 < rank2 ) {
        handle_base = handle2;
        handle_tomerge = handle1;
    } else {
        handle_base = handle1;
        handle_tomerge = handle2;
    }

    parents[handle_tomerge] = handle_base;
    ranks[handle_base] += ranks[handle_tomerge];
}
