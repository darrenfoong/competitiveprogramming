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

  int n;

  cin >> n;

  int *scores = new int[n];

  forv(i,n) {
    cin >> scores[i];
  }

  long *candies = new long[n];
  candies[0] = 1;

  forv1(i,n-1) {
    if (scores[i] > scores[i-1]) {
      candies[i] = candies[i-1]+1;
    } else {
      candies[i] = 1;
    }
  }

  for (int i = n-2; i >= 0; i--) {
    if (scores[i] > scores[i+1]) {
      if (candies[i] <= candies[i+1]) {
        candies[i] = candies[i+1]+1;
      }
    }
  }

  long numCandies = 0;

  forv(i,n) {
    numCandies += candies[i];
  }

  cout << numCandies;

  return 0;
}
