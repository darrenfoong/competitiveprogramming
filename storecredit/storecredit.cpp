// https://code.google.com/codejam/contest/351101/dashboard

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int C, vector<pair<int, int> > prices);

int main() {
	int N = 0;
	cin >> N;

	for ( int i = 0; i < N; i++ ) {
		int C = 0;
		int I = 0;
		vector<pair<int, int> > prices;
		cin >> C;
		cin >> I;

		int price = 0;

		for ( int j = 0; j < I; j++ ) {
			cin >> price;
			prices.push_back(make_pair(price, j));
		}

		cout << "Case #" << (i+1) << ": " << solve(C, prices) << endl;
	}

	return 0;
}

string solve(int C, vector<pair<int, int> > prices) {
	sort(prices.begin(), prices.end());

	int i = 0;
	for ( vector<pair<int, int> >::iterator it = prices.begin(); it != prices.end(); it++, i++ ) {
		int current_price = it->first;
		int price_difference = C - current_price;

		vector<pair<int, int> >::iterator lower = lower_bound(prices.begin(), prices.end(), make_pair(price_difference, 0));
		int matching_index = lower - prices.begin();

		if ( prices[matching_index].first == price_difference ) {
			int first_index = prices[i].second + 1;
			int second_index = prices[matching_index].second + 1;

			if ( first_index > second_index ) {
				swap(first_index, second_index);
			}

			if ( first_index == second_index ) {
				second_index++;
			}

			ostringstream os;
			os << first_index << " " << second_index;
			return os.str();
		}
	}

	return string();
}
