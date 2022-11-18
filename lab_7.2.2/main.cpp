#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void createArray(int** arr, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    arr[i][j] = Low + rand() % (High-Low+1);

    if(j < colCount-1)
    {
        createArray(arr, rowCount, colCount, Low,High, i, j+1);
    }
        if(i<rowCount-1)
        {
            createArray(arr, rowCount, colCount, Low, High, i+1, 0);
        }

}


void printArray(int** arr, const int rowCount, const int colCount, int i, int j)
{
    cout<< setw(4) << arr[i][j];
    if(j < colCount-1)
    {
        printArray(arr, rowCount, colCount, i, j+1);
    }
    else
    if(i < rowCount-1)
    {
        cout<<endl;
        printArray(arr, rowCount, colCount, i+1, 0);
    }
    else
        cout << endl << endl;

}





void Max(int** arr, const int rowCount, const int colCount)
{
    int max = 0;

    int result[rowCount];
    int i = 0;
    while (i < rowCount)
    {
        for(int j = 0; j < colCount; j++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
            }
            if(i==j)
            {
                arr[i][j] = max;
                
            }
        }
        result[i] = max;
        max = 0;
        i++;
    
    }
    for(int i = 0; i <colCount; i++)
    {
        cout <<result[i]<<endl;
        
    }
    
}




int main()
{
    srand((unsigned)time(NULL));
    int Low = 0;
    int High = 5;
    int rowCount = 3;
    int colCount = 3;
    int **arr = new int*[rowCount];
    for (int i=0; i<rowCount; i++)
    {
        arr[i] = new int[colCount];
    }
    createArray(arr, rowCount, colCount, Low, High,0,0);
    cout << endl;
    printArray(arr, rowCount, colCount, 0, 0);
    Max(arr, rowCount, colCount);
    cout << endl;
    printArray(arr, rowCount, colCount, 0, 0);
    for(int i = 0; i < rowCount; i++)
        delete [] arr[i];
        delete [] arr;

return 0;

}





