
#include<iostream>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
 
ll a, i = 5;
ll b, j = 5;
 
void f(ll n){
	if (n == 1)
	{
		a = 5, b = 5;
		return;
	}
	f(n / 2);

	if (n % 2){
        // % == 0 為false
        // (i, i+j) left node
        a += b;
    } else {
        // % 2 有餘數 true
        // (i+j, j) right node
        b += a;
    }
}

// 給layer n, 找出該node的值
// Enumerating Game問的是, 給node的值, 找出對應的層數
int main(){
	ll p, n;
	cin >> p;
	cout << p << endl;
	while (p--)
	{
		cin >> n;
		// cin >> n;
		f(n); // 第n個(layer)
		cout << i << " " << j << " " << a << ' ' << b << endl;
	}
	return 0;
}
