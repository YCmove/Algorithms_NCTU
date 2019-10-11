#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		int K;
		int p, q;

		string str;
		cin >> K >> str;

		int ind = str.find('/');
		p = stoi(str.substr(0, ind));
		q = stoi(str.substr(ind + 1));

		int ansp, ansq;

		if (q == 1) // rightmost node
			ansp = 1, ansq = p + 1;
		else if (p < q) // left child
			ansp = q, ansq = q - p;
		else {
			int height = p / q;
			p %= q;

			q -= p;
			p += q;

			ansp = p;
			ansq = q + height * p;
		}

		cout << K << " " << ansp << "/" << ansq << endl;
	}

	return 0;
}
