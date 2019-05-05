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

using namespace std;

int main() {
  io_opts

  int n = 0;

  cin >> n;

  int scores[n];
  int **dp = new int*[n]; // dp[i] is the ith state of the candy distribution

  forv(i,n) {
    cin >> scores[i];
    dp[i] = new int[n];
  }

  long dpsum[n] = {};

  dp[0][0] = 1;
  dpsum[0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] = dp[i-1][j];
    }

    if (scores[i] > scores[i-1]) {
      dp[i][i] = dp[i][i-1] + 1;
      dpsum[i] = dpsum[i-1] + dp[i][i];
    }

    if (scores[i] == scores[i-1]) {
      dp[i][i] = 1;
      dpsum[i] = dpsum[i-1] + dp[i][i];
    }

    if (scores[i] < scores[i-1]) {
      if (dp[i-1][i-1] > 1) {
        dp[i][i] = 1;
        dpsum[i] = dpsum[i-1] + dp[i][i];
      } else {
        // need to "backtrack"
        dpsum[i] = dpsum[i-1];
        for (int j = i; scores[j] < scores[j-1]; j--) {
          dp[i][j] += 1;
          dpsum[i]++;
        }
      }
    }
  }

  cout << dpsum[n-1];

  return 0;
}
