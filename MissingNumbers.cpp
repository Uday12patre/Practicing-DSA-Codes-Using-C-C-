#include<iostream>
using namespace std;

int main()
{
    int A[] = {2,3,4,6,50,51};
    
    int diff = A[0] - 0;

    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        if(A[i] - i != diff)
        {
            while(diff < A[i] - i)
            {
                cout << "Missing Number is: " << i + diff << endl;
                diff++;
            }
        }
    }

    return 0;
}
