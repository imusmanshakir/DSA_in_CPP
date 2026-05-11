#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int> &arr, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocatedBooK(const vector<int> &arr, int m)
{
    int start = 0;
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    }
    int end = sum;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> pages = {60, 45, 26, 90};
    int student = 2;
    cout << "Allocated Total Pages Book is : " << allocatedBooK(pages, student) << endl;
    return 0;
}

/*
Step 1 — Understand the Problem First
understanding the problem:
Books  = [12, 34, 67, 90]   (pages in each book)
Students (M) = 2

Rules:
✅ Each student must get at least 1 book
✅ Books must be contiguous (in order, no skipping)
✅ Minimize the MAXIMUM pages any single student reads

Visualizing the allocations:
Student 1 → [12, 34, 67]  → 113 pages
Student 2 → [90]          → 90  pages
Maximum = 113 ❌ (not optimal)

Student 1 → [12, 34]      → 46  pages
Student 2 → [67, 90]      → 157 pages
Maximum = 157 ❌ (worse)

Student 1 → [12]          → 12  pages
Student 2 → [34, 67, 90]  → 191 pages
Maximum = 191 ❌ (even worse)

Best answer = 113 ✅

Step 2 — The Key Insight (Where Binary Search Comes In)
Ask yourself:
❓ What are we searching for?
→ The MINIMUM possible value of maximum pages

❓ What is the search range?
→ LEFT  = max(array)  = 90   (minimum possible, 1 student gets 1 book)
→ RIGHT = sum(array)  = 203  (1 student gets ALL books)

So answer lies somewhere between 90 and 203

Why Binary Search?
If I give each student a limit of X pages:
→ X is too small  → too many students needed   → go RIGHT
→ X is too large  → too few students needed    → go LEFT
→ X is just right → save it, try smaller (go LEFT)
Step 3 — The "Can We Do It?" Helper Function
Before the main logic, you need a function:
isFeasible(books, M, maxPages)
→ "Can we allocate books to M students
   if each student reads at most maxPages?"
   Logic:
students_needed = 1
current_pages   = 0

For each book:
    if current_pages + book <= maxPages:
        → add book to current student
    else:
        → give book to NEXT student
        → students_needed++
        → current_pages = book (reset)

At the end:
    if students_needed <= M → YES feasible ✅
    else                    → NO  ❌
    Example — maxPages = 113, M = 2:
Book 12  → current = 12,  students = 1
Book 34  → current = 46,  students = 1
Book 67  → current = 113, students = 1
Book 90  → 113+90 > 113 → new student!
           current = 90,  students = 2

students_needed (2) <= M (2) ✅ Feasible!
Example — maxPages = 100, M = 2:
Book 12  → current = 12,  students = 1
Book 34  → current = 46,  students = 1
Book 67  → current = 113 > 100 → new student!
           current = 67,  students = 2
Book 90  → 67+90 > 100 → new student!
           current = 90,  students = 3

students_needed (3) > M (2) ❌ Not Feasible
Step 4 — Binary Search on the Answer
start = max(books) = 90
end   = sum(books) = 203
ans   = 0

Iteration 1:
mid = (90+203)/2 = 146
isFeasible(146, 2)? → YES → ans=146, end=145

Iteration 2:
mid = (90+145)/2 = 117
isFeasible(117, 2)? → YES → ans=117, end=116

Iteration 3:
mid = (90+116)/2 = 103
isFeasible(103, 2)? → NO  → start=104

Iteration 4:
mid = (104+116)/2 = 110
isFeasible(110, 2)? → NO  → start=111

Iteration 5:
mid = (111+116)/2 = 113
isFeasible(113, 2)? → YES → ans=113, end=112

start(111) > end(112)? NO
mid = (111+112)/2 = 111
isFeasible(111, 2)? → NO  → start=112

start(112) > end(112)? NO
mid = 112
isFeasible(112, 2)? → NO → start=113

start(113) > end(112) → LOOP ENDS ✅

Final Answer = 113


*/
