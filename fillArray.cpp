#include <iostream>
#include <cstdlib> // for srand and rand functions

using namespace std;

void Fill_It(int arr[], unsigned int seed, int min, int max);

int main()
{

    int arr1[20], arr2[20];

    // temporary variable for storing the user input before it is converted to an int
    char temp[10];

    unsigned int seed1, seed2;

    cout << "Please provide a seed value to be used for the first array: ";
    cin.getline(temp, 10);
    seed1 = atoi(temp);

    cout << "Please provide a seed value to be used for the second array: ";
    cin.getline(temp, 10);
    seed2 = atoi(temp);

    Fill_It(arr1, seed1, 1000, 2000);
    Fill_It(arr2, seed2, 0, 1000);

    // Prints out the elements of arr1
    cout << "\nArray 1:\nSeed value: " << seed1 << endl;

    cout << "[";
    for (int i = 0; i < 20; i++)
    {
        bool isLastElement = (i == 20 - 1);

        cout << arr1[i] << (isLastElement ? "" : ", ");
    }
    cout << "]" << endl;

    // Prints out the elements of arr2
    cout << "Array 2:\nSeed value: " << seed2 << endl;

    cout << "[";
    for (int i = 0; i < 20; i++)
    {
        bool isLastElement = (i == 20 - 1);

        cout << arr2[i] << (isLastElement ? "" : ", ");
    }
    cout << "]" << endl;

    system("pause");

    return 0;
}

void Fill_It(int arr[], unsigned int seed, int min, int max)
{

    srand(seed);

    for (int i = 0; i < 20; i++)
    {
        // by default the number at the end of the range (i.e. max) is not included, so 1 is added to ensure it is part of the range
        int randomNumber = min + (rand() % ((max - min) + 1));

        arr[i] = randomNumber;
    }
}