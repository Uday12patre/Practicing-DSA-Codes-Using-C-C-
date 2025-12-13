// Fibonacci Series Using Memoization 
#include<iostream>

using namespace std;
int F[100];
int mfib(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    
    else
        if(F[n-2] == -1)
            F[n-2] = mfib(n-2);
        
        if(F[n-1] == -1)
            F[n-1] = mfib(n-1);
            
        return F[n-2] + F[n-1];
}

int main()
{
    for(int i = 0; i < 100; i++)
    {
        F[i] = -1;
    }
    // index number:0 1 2 3 4 5 6 7  8  9  10 11 12 13 14 15 16 17 18 19 20
    // Fibo  Series: 0 1 1 2 3 5 8 13 21 34 55 89 
    
    cout << mfib(11);
    return 0;
}
