#include <iostream>
using namespace std;

void findAndInvertMinimum(int [], int );
void negateElements(int [], int );
void mergeAndDoubleSecondArrayElements(int [], int , const int [], int , int);

int main()
{
    int Array_1[] = {10,20,30,40,50,5,25,125,625,1};
    int Array_2[] = {1024,2048,4096,8192,512,256,128,64,2,4,8,16};
    const int size_1 = sizeof(Array_1) / sizeof(Array_1[0]);
    const int size_2 = sizeof(Array_2) / sizeof(Array_2[0]);

    cout << "Array_1:\n";
    for(int i = 0 ; i < size_1 ; i++)
    {
        cout << *(Array_1 + i) << " ";
    }
    cout << "\nArray_2:\n";
    for (int i = 0 ; i < size_2 ; i++)
    {
        cout << *(Array_2 + i) << " ";
    }
    
    findAndInvertMinimum(Array_1, size_1);
    cout << "\n\nArray_1 after invert minimum:\n";
    for(int i = 0 ; i < size_1 ; i++)
    {
        cout << *(Array_1 + i) << " ";
    }

    negateElements(Array_2, size_2);
    cout << "\n\nArray_2 after negate:\n";
    for(int i = 0 ; i < size_2 ; i++)
    {
        cout << *(Array_2 + i) << " ";
    }

    mergeAndDoubleSecondArrayElements(Array_1, size_1, Array_2, size_2, size_1 + size_2);
    cout << "\n\nArray_1 after merge:\n";
    for(int i = 0 ; i < size_1 + size_2 ; i++)
    {
        cout << *(Array_1 + i) << " ";
    }
}

void findAndInvertMinimum(int arr[], int size)
{
    int i_min = 0;
    for(int i = 1 ; i < size ; i++)
    {
        if(arr[i] < arr[i_min])
        {
            i_min = i;
        }
    }
    arr[i_min] *= -1;
}

void negateElements(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] *= -1;
    }
}

void mergeAndDoubleSecondArrayElements(int arr1[], int arr1Size, const int arr2[], int arr2Size, int combinedCapacity)
{
    for(int i = arr1Size ; i < combinedCapacity ; i++)
    {
        arr1[i] = arr2[i - arr1Size] * 2;
    }
}
