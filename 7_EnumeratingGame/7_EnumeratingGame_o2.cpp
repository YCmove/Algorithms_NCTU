
#include<iostream>
using namespace std;
 
int a, b;
 
void f(int n){
	if (n == 1)
	{
		a = 1, b = 1;
		return;
	}
	f(n / 2);
	if (n % 2)a += b;
	else b += a;
}


int main(){
	int p, n;
	cin >> p;
	while (p--)
	{
		cin >> n;
		cout << n << ' ';
		cin >> n;
		f(n);
		cout << a << '/' << b << endl;
	}
	return 0;
}
