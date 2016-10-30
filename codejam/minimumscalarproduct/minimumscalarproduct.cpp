// https://code.google.com/codejam/contest/32016/dashboard

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<long long> u, vector<long long> v);

int main() {
	int N = 0;
	cin >> N;
	cin.ignore();

	for ( int i = 0; i < N; i++ ) {
		int n = 0;
		cin >> n;

		vector<long long> u;
		vector<long long> v;

		long long input = 0;
		for ( int j = 0; j < n; j++ ) {
			cin >> input;
			u.push_back(input);
		}
		for ( int j = 0; j < n; j++ ) {
			cin >> input;
			v.push_back(input);
		}

		cout << "Case #" << (i+1) << ": " << solve(u, v) << endl;
	}

	return 0;
}

long long solve(vector<long long> u, vector<long long> v) {
	sort(u.begin(), u.end());
	sort(v.begin(), v.end(), greater<long long>());

	long long msp = 0;

	for ( unsigned int i = 0; i < u.size(); i++ ) {
		msp += u[i] * v[i];
	}

	return msp;
}
