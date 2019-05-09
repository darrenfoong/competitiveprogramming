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

int dp(int n, int c, double maxValue, vi &values, vi &costs);

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

     int res = dp(n, c, pow(2, ((75-n)/(double) 2)), values, costs);

     cout << res << nl;
  }

  return 0;
}

int dp(int n, int c, double maxValue, vi &values, vi &costs) {
  unordered_map<int, umapii> dp;

  forv(i,n) {
    dp[i] = umapii();
  }

  forv1(j,c) {
    if (values[0] <= maxValue && j >= costs[0] && costs[0] <= c) {
      dp[0][j] = values[0];
    }
  }

  for (int i = 1; i < n; i++) {
    forv1(j,c) {
      int picked = j >= costs[i] ?
                   (dp[i-1].count(j - costs[i]) ? dp[i-1][j - costs[i]] : 0) :
                   INT_MIN;

      int pickedValue = picked + values[i];
      int unpickedValue = dp[i-1].count(j) ? dp[i-1][j] : 0;

      int value = max(pickedValue, unpickedValue);
      if (value <= maxValue) {
        if (value > 0) {
          dp[i][j] = value;
        }
      } else {
        break;
      }
    }
  }

  return dp[n-1][c];
}
