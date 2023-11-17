#include <iostream>
using namespace std;

int fib_numR(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib_numR(n - 1) + fib_numR(n - 2);
}

int fib_numI(int n) {
    int a = 0, b = 1;
    int c = a + b;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
   cout<<"Enter number";
   int n;
   cin>>n;
   cout<<fib_numI(n);
   cout<<fib_numR(n);
    return 0;
}
