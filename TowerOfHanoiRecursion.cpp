// Tower Of Hanoi Recursion
#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout << "From " << A << " to " << C << endl;
        TOH(n-1,B,A,C);
    }
}

int main()
{
    cout << "Solution for Tower Of Hanoi: " << endl;
    TOH(3,1,2,3);
    return 0;
}
