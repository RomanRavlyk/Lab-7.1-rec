#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    if (rowCount == 0)
        return;

    a[rowCount - 1] = new int[colCount];
    for (int j = 0; j < colCount; j++)
        a[rowCount - 1][j] = Low + rand() % (High - Low + 1);

    Create(a, rowCount - 1, colCount, Low, High);
}

void Print(int** a, const int rowCount, const int colCount, const int i = 0, const int j = 0)
{
    if (i == rowCount)
        return;

    if (j == colCount)
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
        return;
    }

    cout << setw(4) << a[i][j];
    Print(a, rowCount, colCount, i, j + 1);
 
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    if (colCount == 0)
        return;

    int tmp = a[row1][colCount - 1];
    a[row1][colCount - 1] = a[row2][colCount - 1];
    a[row2][colCount - 1] = tmp;

    Change(a, row1, row2, colCount - 1);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, const int i = 0, const int j = 0)
{
    if (i == rowCount)
        return;

    if (j == colCount)
    {
        Calc(a, rowCount, colCount, S, k, i + 1, 0);
        return;
    }

    if (a[i][j] % 2 == 0 && !(a[i][j] % 8 == 0))
    {
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    Calc(a, rowCount, colCount, S, k, i, j + 1);
}

void Sort(int** a, const int rowCount, const int colCount, const int i0 = 0, const int i1 = 0)
{
    if (i0 == rowCount - 1)
        return;

    if (i1 == rowCount - i0 - 1)
        Sort(a, rowCount, colCount, i0 + 1, 0);
    else
    {
        if ((a[i1][0] > a[i1 + 1][0])
            ||
            (a[i1][0] == a[i1 + 1][0] &&
                a[i1][1] > a[i1 + 1][1])
            ||
            (a[i1][0] == a[i1 + 1][0] &&
                a[i1][1] == a[i1 + 1][1] &&
                a[i1][3] < a[i1 + 1][3]))
            Change(a, i1, i1 + 1, colCount);

        Sort(a, rowCount, colCount, i0, i1 + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Low = 8;
    int High = 73;
    int rowCount = 7;
    int colCount = 6;
    int** a = new int* [rowCount];
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount); 
    cout << endl;
    Sort(a, rowCount, colCount);
    
    Print(a, rowCount, colCount);
    cout << endl;
    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(a, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}