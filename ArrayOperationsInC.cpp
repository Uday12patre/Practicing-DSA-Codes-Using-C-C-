#include<iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int value)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        
        arr->A[index] = value;
        arr->length++;
    }
}

void display(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        cout << arr->A[i] << "\t";
    }
}

void del(struct Array *arr, int index)
{
    if(index >= 0 && index <= arr->length)
    {
        int x = arr->A[index];
        
        for(int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        
        arr->length--;
    }
}

int search(struct Array arr, int x)
{
    for(int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] == x)
            return i;
    }
    
    return -1;
}

int BinarySearch(struct Array arr, int x)
{
    int l = 0;
    int h = arr.length-1;
    
    while(l <= h)
    {
        int mid = (l+h)/2;
        if(arr.A[mid] == x)
        {
            return mid;
        }
        
        else if(arr.A[mid] > x)
        {
            h = mid - 1;
        }
        
        else
        {
            l = mid + 1;
        }
    }
    
    return -1;
}

int RBins(int a[], int l, int h, int x)
{
    if(l <= h)
    {
        int mid = (l+h)/2;
        
        if(a[mid] == x)
        {
            return mid;
        }
        
        else if(x < a[mid])
        {
            h = mid - 1;
            return RBins(a, l, h, x);
        }
        
        else 
        {
            l = mid + 1;
            return RBins(a, l, h, x);
        }
    }
    
    return -1;
}

void reverseArray(struct Array *arr)
{
    int *B;
    int i, j;
    
    B = (int *)malloc(arr->length*sizeof(int));
    
    for(int i = arr->length-1, j = 0; i > -1; i--, j++)
    {
        B[j] = arr->A[i];
    }
    
    for(int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
    
    free(B);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse2(struct Array *arr)
{
    int i,j;
    
    for(i = 0, j = arr->length-1; i < j; i++, j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

void appendSort(struct Array *arr, int x)
{
    int i = arr->length-1;
    while(arr->A[i] > x)
    {
        if(arr->length <= arr->size)
        {
            arr->A[i+1] = arr->A[i]; 
        }
        
        i--;
    }
    
    arr->A[i+1] = x;
    arr->length++;
}

bool ArrayIsSorted(struct Array arr)
{
    for(int i = 0; i < arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return false;
        }
    }
    
    return true;
}

void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    
    while(i < j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if(i<j)swap(&arr->A[i], &arr->A[j]);
    }
    
    return;
}

void merge(struct Array *arr, struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] > arr2->A[j])
        {
            arr->A[k++] = arr2->A[j++];
        }
        
        else
        {
            arr->A[k++] = arr1->A[i++];
        }
    }
    
    if(i != arr1->length)
    {
        for(; i < arr1->length; i++)
        {
            arr->A[k++] = arr1->A[i]; 
        }
    }
    
    if(j != arr2->length)
    {
        for(; j < arr2->length; j++)
        {
            arr->A[k++] = arr2->A[j]; 
        }
    }
    
    arr->length = arr1->length + arr2->length;

}

int main()
{
    struct Array arr = {{0}, 20, 0};
    
    struct Array arr1 = {{1,3,5,7,9}, 10, 5};
    struct Array arr2 = {{0,2,4,6,8}, 10, 5};
    
    cout << "Array 1: ";
    display(&arr1);
    cout << "\nArray 2: ";
    display(&arr2);
    
    cout << endl;
    merge(&arr, &arr1, &arr2);
    cout << "Merged Array: ";
    display(&arr);
    
    return 0;
}
