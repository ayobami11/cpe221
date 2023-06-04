#include <iostream>
// for atof functions
#include <cstdlib>
// for pow function
#include <cmath>

using namespace std;

void FillArray(float values[5], int size);

void ComputeMeanandStddev(float values[5], int size, float *mean_ptr, float *sd_ptr);

void PrintResult(float values[5], int size, float *mean_ptr, float *sd_ptr);

int main()
{

    float values[5];
    float mean, standard_deviation;

    float *mean_ptr = &mean;
    float *sd_ptr = &standard_deviation;
    // computes the size of the array by dividing the total size of the array by the size of one element in the array
    int values_size = sizeof(values) / sizeof(values[0]);

    FillArray(values, values_size);

    ComputeMeanandStddev(values, values_size, mean_ptr, sd_ptr);

    PrintResult(values, values_size, mean_ptr, sd_ptr);

    system("pause");

    return 0;
}

void FillArray(float values[5], int size)
{

    char temp[15];

    cout << "Please provide values for the following five array elements: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";

        cin.getline(temp, 15);
        // converts the user input to a float
        values[i] = atof(temp);
    }
}

void ComputeMeanandStddev(float values[5], int size, float *mean_ptr, float *sd_ptr)
{
    float sum = 0.0, sum_of_values_squared = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum += values[i];
        // i.e. summation(x^2)
        sum_of_values_squared += pow(values[i], 2);
    }

    float mean = sum / size;
    // variance formula: (summation(fx^2) / n) - mean^2
    float variance = (sum_of_values_squared / size) - pow(mean, 2);
    // sd formula: square root of variance
    float standard_deviation = sqrt(variance);

    *mean_ptr = mean;
    *sd_ptr = standard_deviation;
}

void PrintResult(float values[5], int size, float *mean_ptr, float *sd_ptr)
{

    cout << "\nArray values: ";
    for (int i = 0; i < size; i++)
    {
        // the if-else condition evaluated using the ternary operator (?) just appends a comma after a value if it is not
        // the last value in the array
        cout << values[i] << (i == size - 1 ? "" : ", ");
    }

    cout << "\nMean: " << *mean_ptr;

    cout << "\nStandard deviation: " << *sd_ptr << endl;
}
