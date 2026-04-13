#include <iostream>
#include <iomanip> // for setw()
using namespace std;

// ========== CONSTANTS ==========
const int ROWS = 3;
const int COLS = 4;

// ========== FUNCTION PROTOTYPES ==========

// 1. Static 2D array (size known at compile time)
void printStaticArray(int arr[][COLS], int rows);
void fillStaticArray(int arr[][COLS], int rows);

// 2. Dynamic 2D array (size determined at runtime)
int **createDynamicArray(int rows, int cols);
void fillDynamicArray(int **arr, int rows, int cols);
void printDynamicArray(int **arr, int rows, int cols);
void deleteDynamicArray(int **arr, int rows);

// 3. Using vector of vectors (modern C++ way)
#include <vector>
void printVector2D(const vector<vector<int>> &vec);

// 4. Matrix addition example
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B);

// ========== MAIN ==========
int main()
{
    cout << "========== 1. STATIC 2D ARRAY ==========\n";
    // Declare and initialize a static 2D array
    int staticArr[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Initial static array:\n";
    printStaticArray(staticArr, ROWS);

    // Fill with user input (commented out for demo, use if needed)
    // fillStaticArray(staticArr, ROWS);

    // Access individual elements
    cout << "\nElement at [1][2]: " << staticArr[1][2] << endl;

    // Modify an element
    staticArr[0][0] = 100;
    cout << "After modifying [0][0] to 100:\n";
    printStaticArray(staticArr, ROWS);

    cout << "\n========== 2. DYNAMIC 2D ARRAY ==========\n";
    int dynRows, dynCols;
    cout << "Enter rows and columns for dynamic array: ";
    cin >> dynRows >> dynCols;

    // Create dynamic 2D array
    int **dynamicArr = createDynamicArray(dynRows, dynCols);

    // Fill with values (e.g., row*10 + col)
    for (int i = 0; i < dynRows; i++)
    {
        for (int j = 0; j < dynCols; j++)
        {
            dynamicArr[i][j] = i * 10 + j;
        }
    }

    cout << "Dynamic array contents:\n";
    printDynamicArray(dynamicArr, dynRows, dynCols);

    // Clean up dynamic memory
    deleteDynamicArray(dynamicArr, dynRows);

    cout << "\n========== 3. VECTOR OF VECTORS (Modern C++) ==========\n";
    // Create a 2D vector
    vector<vector<int>> vec2D = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Vector 2D contents:\n";
    printVector2D(vec2D);

    // Add a new row
    vec2D.push_back({10, 11, 12});
    cout << "\nAfter adding a row:\n";
    printVector2D(vec2D);

    cout << "\n========== 4. MATRIX ADDITION ==========\n";
    vector<vector<int>> matA = {{1, 2}, {3, 4}};
    vector<vector<int>> matB = {{5, 6}, {7, 8}};
    vector<vector<int>> sum = addMatrices(matA, matB);

    cout << "Matrix A:\n";
    printVector2D(matA);
    cout << "Matrix B:\n";
    printVector2D(matB);
    cout << "A + B:\n";
    printVector2D(sum);

    return 0;
}

// ========== STATIC ARRAY FUNCTIONS ==========
// Note: Second dimension size MUST be specified in parameter
void printStaticArray(int arr[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void fillStaticArray(int arr[][COLS], int rows)
{
    cout << "Enter " << rows * COLS << " elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cin >> arr[i][j];
        }
    }
}

// ========== DYNAMIC ARRAY FUNCTIONS ==========
int **createDynamicArray(int rows, int cols)
{
    // Allocate array of row pointers
    int **arr = new int *[rows];
    // Allocate each row
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    return arr;
}

void fillDynamicArray(int **arr, int rows, int cols)
{
    cout << "Enter " << rows * cols << " elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void printDynamicArray(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteDynamicArray(int **arr, int rows)
{
    // Delete each row first
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    // Delete the array of row pointers
    delete[] arr;
}

// ========== VECTOR 2D FUNCTIONS ==========
void printVector2D(const vector<vector<int>> &vec)
{
    for (const auto &row : vec)
    {
        for (int val : row)
        {
            cout << setw(4) << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}