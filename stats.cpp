#include <iostream>
#include <vector>
#include <algorithm> // for sort function
#include <unordered_map>
#include <cmath> // for floor function

float mean(float numbers[], int size);
float min(float numbers[], int size);
float max(float numbers[], int size);
float median(float numbers[], int size);
float range(float numbers[], int size);
float mode(float numbers[], int size);

using namespace std;

int main()
{

    float grades[] = {82.83, 18.43, 97.73, 76.10, 71.92, 49.81, 52.49, 20.87};
    const int size = sizeof(grades) / sizeof(grades[0]);

    cout << "Lowest grade: " << min(grades, size) << endl;
    cout << "Highest grade: " << max(grades, size) << endl;
    cout << "Mean grade: " << mean(grades, size) << endl;
    cout << "Median grade: " << median(grades, size) << endl;
    cout << "Range of grades: " << range(grades, size) << endl;
    cout << "Modal grade: " << mode(grades, size) << endl;

    system("pause");

    return 0;
}

float mean(float numbers[], int size)
{
    float sum = 0.0, average;

    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }

    average = sum / size;

    return average;
}

float min(float numbers[], int size)
{
    float minValue = numbers[0];

    // started from index 1 because there is no need to check the element at index 0 since it is already the default min value
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < minValue)
        {
            minValue = numbers[i];
        }
    }

    return minValue;
}

float max(float numbers[], int size)
{
    float maxValue = numbers[0];

    // started from index 1 because there is no need to check the element at index 0 since it is already the default max value
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > maxValue)
        {
            maxValue = numbers[i];
        }
    }

    return maxValue;
}

float median(float numbers[], int size)
{

    vector<float> numbersCopy;

    // created a copy of the array to avoid mutating the original array (arrays are passed by reference)
    // in a vector data type because the size of the array's copy couldn't be set dynamically
    for (int i = 0; i < size; i++)
    {
        numbersCopy.push_back(numbers[i]);
    }

    // makes use of the built-in sort function (quicksort implementation) to sort the array in ascending order
    sort(numbersCopy.begin(), numbersCopy.end());

    if (size % 2 == 1)
    {
        int midvalue = floor(size / 2.0);
        return numbersCopy[midvalue];
    }
    else
    {
        int midvalue = floor(size / 2.0);
        return (numbersCopy[midvalue - 1] + numbersCopy[midvalue]) / 2;
    }
}

float range(float numbers[], int size)
{
    return max(numbers, size) - min(numbers, size);
}

float mode(float numbers[], int size)
{
    // used unordered maps because they have an average time complexity of O(1) - very fast
    unordered_map<float, int> dataMap;

    float modalGrade = numbers[0];

    for (int i = 0; i < size; i++)
    {
        float currentValue = numbers[i];

        // if key does not exist on the map, create one, else increment
        if (dataMap.find(currentValue) == dataMap.end())
        {
            dataMap[currentValue] = 1;
        }
        else
        {
            dataMap[currentValue]++;
        }

        // if the frequency of the currentValue is greater than that of the modalGrade, set the modalGrade
        if (dataMap[currentValue] > dataMap[modalGrade])
        {
            modalGrade = currentValue;
        }
    }

    return modalGrade;
}