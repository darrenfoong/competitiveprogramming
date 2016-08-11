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

class Node {
	public:
	int value;
	int rank = 1;
	Node* parent = NULL;

	Node(int v, Node* p) {
		value = v;
		parent = p;
	}
};

Node* nodes[LIMIT+1];

Node* handle(int arg);
void flatten(Node* leaf, Node* root);
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
	nodes[i] = new Node(i, NULL);
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

Node* handle(int arg) {
    Node* currentNode = nodes[arg];

    while ( currentNode->parent != NULL ) {
        currentNode = currentNode->parent;
    }

    return currentNode;
}

void flatten(Node* leaf, Node* root) {
    Node* prevcurrentNode;
    Node* currentNode = leaf;

    while ( currentNode != root ) {
        prevcurrentNode = currentNode;
        currentNode = currentNode->parent;
	prevcurrentNode->parent = root;
    }
}

string query(int arg1, int arg2) {
    if ( arg1 == arg2 ) {
        return "yes";
    }

    Node* handle1 = handle(arg1);
    Node* handle2 = handle(arg2);

    flatten(nodes[arg1], handle1);
    flatten(nodes[arg2], handle2);

    return (handle1 == handle2) ? "yes" : "no";
}

void join(int arg1, int arg2) {
    if ( arg1 == arg2 ) {
        return;
    }

    Node* handle1 = handle(arg1);
    Node* handle2 = handle(arg2);

    if ( handle1 == handle2 ) {
        return;
    }

    int rank1 = handle1->rank;
    int rank2 = handle2->rank;

    Node* handle_base;
    Node* handle_tomerge;

    if ( rank1 < rank2 ) {
        handle_base = handle2;
        handle_tomerge = handle1;
    } else {
        handle_base = handle1;
        handle_tomerge = handle2;
    }

    handle_tomerge->parent = handle_base;
    handle_base->rank += handle_tomerge->rank;
}
