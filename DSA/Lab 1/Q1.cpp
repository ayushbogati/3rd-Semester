#include <iostream>
using namespace std;
int choice, aSize;
int **arr, *pSize;

void printArray()
{

  for (int i = 0; i < choice; ++i)
  {
    cout << "Element of array " << i + 1 << endl;

    for (int j = 0; j < pSize[i]; ++j)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void getData()
{
  cout << "Enter how many arrays do you want to create?" << endl;
  cin >> choice;

  arr = new int *[choice];
  pSize = new int[choice];

  for (int i = 0; i < choice; ++i)
  {
    cout << "Enter the size for array " << i + 1 << ": ";
    cin >> aSize;

    arr[i] = new int[aSize];
    pSize[i] = aSize;

    cout << "Enter the elements for array " << i + 1 << ": " << endl;
    for (int j = 0; j < aSize; ++j)
    {
      cin >> arr[i][j];
    }
  }
}

void deleteElement()
{

  int arrIndex, arrValue;

  cout << "The array has the following values: " << endl;
  printArray();

  cout << "Enter which array do you want to do the delete command. " << endl;
  cin >> arrIndex;

  --arrIndex;

  cout << "Enter which value you want to delete of the array." << endl;
  cin >> arrValue;

  cout << "Before deleting: " << endl;

  for (int i = 0; i < pSize[arrIndex]; ++i)
  {
    cout << arr[arrIndex][i] << " ";
  }
  cout << endl;

  for (int i = 0; i < pSize[arrIndex]; ++i)
  {

    if (arr[arrIndex][i] == arrValue)
    {
      for (int j = i; j < pSize[arrIndex] - 1; ++j)
      {
        int temp = arr[arrIndex][j];
        arr[arrIndex][j] = arr[arrIndex][j + 1];
        arr[arrIndex][j + 1] = temp;
      }
    }
  }

  cout << "After deleting the element: " << endl;

  for (int i = 0; i < pSize[arrIndex] - 1; ++i)
  {
    cout << arr[arrIndex][i] << " ";
  }
  cout << endl;
}

void sortArray()
{

  cout << "Sorting in ascending order " << endl;

  for (int i = 0; i < choice; ++i)
  {

    for (int j = 0; j < pSize[i]; ++j)
    {

      for (int k = j + 1; k < pSize[i]; ++k)
      {

        if (arr[i][j] > arr[i][k])
        {
          int temp = arr[i][k];
          arr[i][k] = arr[i][j];
          arr[i][j] = temp;
        }
      }
    }
  }

  printArray();

  cout << "Sorting in descending order " << endl;

  for (int i = 0; i < choice; ++i)
  {

    for (int j = 0; j < pSize[i]; ++j)
    {

      for (int k = j + 1; k < pSize[i]; ++k)
      {

        if (arr[i][j] < arr[i][k])
        {
          int temp = arr[i][k];
          arr[i][k] = arr[i][j];
          arr[i][j] = temp;
        }
      }
    }
  }
  printArray();
}

void mergeArray(){
    
     cout << "Enter any two arrays you want to merge." << endl;
     
     int arrInd[2];
     
     for(int i=0; i<2; ++i){
          cin >> arrInd[i];
     }
    
    int firstArr = arrInd[0]-1;
    int secArr = arrInd[1]-1;
    
    cout << "Result after merging the array:" << endl;
    
    for(int i=0; i<pSize[firstArr]; ++i){
         cout << arr[firstArr][i] << " ";
    }
    
    for(int i=0; i<pSize[secArr]; ++i){
         cout << arr[secArr][i]<< " ";
    }
    cout << endl;
}

int main()
{

  char choice;

  string ch = "A";

  while (ch == "A")
  {

    cout << "Enter your choice:" << endl;
    cout << "A. Enter any element in the array." << endl;
    cout << "B. Delete any element in the array." << endl;
    cout << "C. Sort the array." << endl;
    cout << "D. Display elements of the array." << endl;
    cout << "E. Merge an array." << endl;

    cin >> choice;

    switch (choice)
    {
    case 'A':
      getData();
      break;

    case 'B':
      deleteElement();
      break;

    case 'C':
      sortArray();
      break;

    case 'D':
      printArray();
      break;
    }

    cout << "Do you want to do more?" << endl;
    cout << "A. Yes" << endl;
    cout << "B. No" << endl;
    cin >> ch;
  }

  return 0;
}
