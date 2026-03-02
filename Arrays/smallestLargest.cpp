#include <iostream>

using namespace std;

int main()
{
    int nums[] = {1, 2, 3, 5, -10};
    int size = 5;

    int smallest = INT_MAX;
    int largest = INT_MIN;
   int largestIndex = -1;
    int smallestIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] < smallest)
        {
            smallest = nums[i];
            smallestIndex = i;
        }
    }
    for (int i = 0; i < size; i++)
    {
       if(nums[i] > largest)
        {
            largest = nums[i];
            largestIndex = i;
            
        }
    }
    
    cout<<"Smallest number is: "<<smallest<<endl;
    cout<<"Largest number is: "<<largest<<endl;
    cout<<"The index for smallest value is: "<<smallestIndex<<endl;
    cout<<"The index for largest value is: "<<largestIndex;

    return 0;
}