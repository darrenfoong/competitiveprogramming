// C2A - Darren Foong

#include <bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long>
#define vs vector<string>
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

using namespace std;

string stolower(string input);
bool checkMatch(string input, string ref);
string solve(string input, vs &dict);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m = 0;
    string s = "";

    cin >> n >> m;

    vs dict;

    forv(i,n) {
        cin >> s;
        dict.pb(s);
    }

    forv(i,m) {
        cin >> s;
        cout << solve(stolower(s), dict) << nl;
    }

    return 0;
}

string stolower(string input) {
    string res = "";

    forv(i, input.length()) {
        res += tolower(input[i]);
    }

    return res;
}

bool checkMatch(string input, string ref) {
    int tracker = input.length();
    int lastPos = -1;

    forv(i, input.length()) {
        bool matched = false;
        char currentChar = input[i];

        for ( int j = lastPos+1; j < ref.length(); j++ ) {
            if ( ref[j] == currentChar ) {
                lastPos = j;
                tracker--;
                matched = true;
                break;
            }
        }

        if ( !matched ) {
            return false;
        }
    }

    return tracker == 0;
}

string solve(string input, vs &dict) {
    for ( auto dit = dict.begin(); dit != dict.end(); dit++ ) {
        if ( checkMatch(input, *dit) ) {
            return *dit;
        }
    }

    return "No valid word";
}
