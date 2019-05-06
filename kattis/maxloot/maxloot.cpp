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

#define DEBUG

#ifdef DEBUG
 #define db(x) x
 #define io_opts
#else
 #define db(x)
 #define io_opts ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

using namespace std;

struct pair_hash {
  template <class T1, class T2>
  size_t operator() (const pair<T1, T2> &pair) const {
    return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
  }
};

pii dp(int n, int c, double maxValue, vi &values, vi &costs, unordered_map<pii, pii, pair_hash> &memo);

int main() {
  io_opts

   int t = 0;
   int n = 0;
   int c = 0;
   int value = 0;
   int cost = 0;

   cin >> t;

   forv1(i,t){
     cin >> n;
     cin >> c;

     vi values;
     vi costs;

     forv(j,n) {
       cin >> value;
       values.pb(value);
      }

     forv(j,n) {
       cin >> cost;
       costs.pb(cost);
     }

     unordered_map<pii, pii, pair_hash> memo;

     pii res = dp(n, c, pow(2, ((75-n)/(double) 2)), values, costs, memo);

     cout << res.first << nl;
  }

  return 0;
}

pii dp(int n, int c, double maxValue, vi &values, vi &costs, unordered_map<pii, pii, pair_hash> &memo) {
  pii nc = pii(n,c);

  if (memo.find(nc) != memo.end()) {
    return memo[nc];
  }

  pii res;

  if (c <= 0) {
    res = pii(INT_MIN, 0);
    memo[nc] = res;
    return res;
  }

  if (n == 0) {
    if (values[0] <= maxValue && costs[0] <= c) {
      res = pii(values[0], costs[0]);
    } else {
      res = pii(0, 0);
    }
    memo[nc] = res;
    return res;
  }

  pii pickedResult = dp(n-1, c-costs[n], maxValue, values, costs, memo);
  pii unpickedResult = dp(n-1, c, maxValue, values, costs, memo);

  pickedResult = pii(pickedResult.first + values[n], pickedResult.second + costs[n]);

  if (pickedResult.first > maxValue) {
    res = unpickedResult;
  } else {
    if (pickedResult.first > unpickedResult.first) {
      res = pickedResult;
    } else {
      res = unpickedResult;
    }
  }

  memo[nc] = res;
  return res;
}
