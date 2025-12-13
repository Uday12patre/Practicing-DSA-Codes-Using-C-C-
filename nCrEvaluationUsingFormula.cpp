// nCr Evaluation Using Formula
#include<iostream>
using namespace std;

int fact(int n)
{
    if(n<=1)
        return 1;
    else
        return n*fact(n-1);
}

int c(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/(t2*t3);
}

int main()
{
    cout << c(4,2);
    return 0;
}
