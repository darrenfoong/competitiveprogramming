#include<bits/stdc++.h>

#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int> >
#define vvpii vector<vector<pair<int, int> > >
#define umapsi unordered_map<string, int>
#define setpii set<pair<int, int> >
#define pqpii priority_queue<pair<int, int> >
#define pqpiir priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pii> >
#define forv(i,n) for ( int i = 0; i < n; i++ )
#define all(x) x.begin(), x.end()
#define nl "\n"

using namespace std;

typedef vvpii adjl;

const int INF = 0x3f3f3f3f;

int dijkstra(adjl &graph, int source, int dest);
vi solve(adjl &graph, vpii &paths);

int main() {
	ios_base::sync_with_stdio(false);

	int s = 0, n = 0;

	cin >> s;

	forv(i,s) {
		cin >> n;

		umapsi names;
		adjl graph;
		vpii paths;

		vpii znrs;
		graph.push_back(znrs);

		forv(j,n) {
			string name = "";
			cin >> name;

			names[name] = j+1;

			int p = 0;
			cin >> p;

			vpii nrs;

			forv(k,p) {
				int nr = 0, cost = 0;
				cin >> nr >> cost;
				nrs.push_back({nr, cost});
			}

			graph.push_back(nrs);
		}

		int r = 0;
		cin >> r;

		forv(j,r) {
			string source = "";
			string dest = "";
			cin >> source >> dest;

			paths.push_back({names[source], names[dest]});
		}

		cin.ignore();
		cin.ignore();

		vi costs = solve(graph, paths);

		forv(j, costs.size()) {
			cout << costs[j]  << nl;
		}
	}

	return 0;
}

int dijkstra(adjl &graph, int source, int dest) {
	vi dists(graph.size(), INF);
	vi visited(graph.size(), 0);
	dists[source] = 0;

	pqpiir q;
	q.push({dists[source], source});

	while ( !q.empty() ) {
		pii top = q.top();
		q.pop();

		int currentNode = top.second;

		if ( visited[currentNode] == 1 ) {
			continue;
		}

		if ( currentNode == dest ) {
			return dists[dest];
		}

		vpii nrs = graph[currentNode];

		for ( auto it = nrs.begin(); it != nrs.end(); it++ ) {
			int nr = it->first;
			int edgeWeight = it->second;
			int newDistance = dists[currentNode] + edgeWeight;

			if ( newDistance < dists[nr] ) {
				dists[nr] = newDistance;
				q.push({dists[nr], nr});
			}
		}

		visited[currentNode] = 1;
	}

	return INF;
}

vi solve(adjl &graph, vpii &paths) {
	vi costs;

	forv(i,paths.size()) {
		costs.push_back(dijkstra(graph, paths[i].first, paths[i].second));
	}

	return costs;
}
