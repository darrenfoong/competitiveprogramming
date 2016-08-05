// https://code.google.com/codejam/contest/619102/dashboard

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<pair<int, int> > &wires);

int main() {
	int T = 0;
	int N = 0;
	cin >> T;

	for ( int i = 0; i < T; i++ ) {
		cin >> N;
		vector<pair<int, int> > wires;

		for ( int j = 0; j < N; j++ ) {
			int a = 0;
			int b = 0;
			cin >> a;
			cin >> b;
			wires.push_back(make_pair(a, b));
		}

		cout << "Case #" << (i+1) << ": " << solve(wires) << endl;
	}

	return 0;
}

int solve(vector<pair<int, int> > &wires) {
	sort(wires.begin(), wires.end());

	int count = 0;

	for ( unsigned int i = 0; i < wires.size(); i++ ) {
		int currentB = wires[i].second;

		for ( unsigned int j = i; j < wires.size(); j++ ) {
			int nextB = wires[j].second;

			if ( nextB < currentB ) {
				count++;
			}
		}
	}

	return count;
}
