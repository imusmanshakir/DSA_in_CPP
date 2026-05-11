#include <iostream>
using namespace std;

int squareRoot(int n)
{
    int start = 0;
    int end = n;
    int ans = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        long long square = (long long)mid * mid;

        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 20;

    cout << "Square root: " << squareRoot(n) << endl;

    return 0;
}

// Here is practical visulization of this code

// else
//     end = mid - 1; // try smaller values
// ```
// `mid` is too big, so search the left half.

// ---

// ### Step 6 — Visual Walkthrough for n = 20
// ```
// start=0, end=20 → mid=10 → 10²=100 > 20 → end=9
// start=0, end=9  → mid=4  → 4²=16  < 20 → ans=4, start=5
// start=5, end=9  → mid=7  → 7²=49  > 20 → end=6
// start=5, end=6  → mid=5  → 5²=25  > 20 → end=4
// start=5 > end=4 → LOOP ENDS
// --------------------------------------------------------------------------------
// | Step | `start` | `end` | `mid` | `mid²` | Action                     | `ans` |
// | ---- | ------- | ----- | ----- | ------ | -------------------------- | ----- |
// | 1    | 0       | 20    | 10    | 100    | Too big, go left           | 0     |
// | 2    | 0       | 9     | 4     | 16     | Too small, save & go right | 4     |
// | 3    | 5       | 9     | 7     | 49     | Too big, go left           | 4     |
// | 4    | 5       | 6     | 5     | 25     | Too big, go left           | 4     |
// | 5    | 5       | 4     | -     | -      | Loop ends (`start > end`)  | **4** |
// --------------------------------------------------------------------------------