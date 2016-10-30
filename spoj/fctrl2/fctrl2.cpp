#include<bits/stdc++.h>

#define vi vector<int>
#define fori(x) for ( int i = 0; i < x; i++ )
#define all(x) x.begin(), x.end()
#define nl "\n"

#define NUM_DIGITS 200
#define NULL_DIGIT 0

using namespace std;

void mult(vi &acc, int n, int place, vi &res);
void addTo(vi &operand, vi &acc);
void innerFactorial(int n, vi &acc);
string factorial(int n);

int main() {
	int t = 0, n = 0;
	cin >> t;

	fori(t) {
		cin >> n;
		cout << factorial(n) << nl;
	}

	return 0;
}

void mult(vi &acc, int n, int place, vi &res) {
	int prod = 0, multResult = 0, carry = 0;

	for ( int i = NUM_DIGITS - 1; i >= place; i-- ) {
		prod = acc[i] * n + carry;
		multResult = prod % 10;
		carry = (prod - multResult)/10;
		res[i-place] = multResult;
	}
}

void addTo(vi &operand, vi &acc) {
	int sum = 0, addResult = 0, carry = 0;

	vi addRes = vi(NUM_DIGITS);

	for ( int i = NUM_DIGITS - 1; i >= 0; i-- ) {
		sum = operand[i] + acc[i] + carry;
		addResult = sum % 10;
		carry = (sum - addResult)/10;
		addRes[i] = addResult;
	}

	acc = addRes;
}

void innerFactorial(int n, vi &acc) {
	if ( n > 1 ) {
		vi multAcc = vi(NUM_DIGITS);
		string nstr = to_string(n);

		for ( int i = nstr.length() - 1; i >= 0; i-- ) {
			vi multRes = vi(NUM_DIGITS);
			mult(acc, nstr[i] - '0', nstr.length() - i - 1, multRes);
			addTo(multRes, multAcc);
		}

		acc = multAcc;

		innerFactorial(n-1, acc);
	}
}

string factorial(int n) {
	if ( n == 0 ) {
		// mathematically wrong, but correct for SPOJ
		return "0";
	}

	vi acc = vi(NUM_DIGITS, NULL_DIGIT);
	acc[NUM_DIGITS-1] = 1;

	ostringstream ss("");

	innerFactorial(n, acc);

	bool z = true;

	fori(NUM_DIGITS) {
		if ( z ) {
			if ( acc[i] != 0 ) {
				z = false;
			}
		}

		if ( !z ) {
			ss << acc[i];
		}
	}

	return ss.str();
}
