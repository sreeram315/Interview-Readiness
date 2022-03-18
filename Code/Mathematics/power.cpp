#include <iostream>
#include <limits.h>
using namespace std;

int power(int x, int n) {
	if(n == 0)
		return 1;
	int temp = power(x, n/2);
	temp = temp * temp;
	return (n%2==0) ? temp : (x*temp);
}

int power(int x, unsigned int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x*x; 
    }
    return res;
}

int main() {
    int x = 3, n = 5;
	cout << power(x, n) << endl;
}