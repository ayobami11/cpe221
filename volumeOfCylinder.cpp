#include <iostream>
#include <cmath>   // for pow function
#include <iomanip> // for setprecision function
#include <cctype>  // for tolower function

#define PI 3.14159265

using namespace std;

void GetCylinderDimensions(double *radius_ptr, double *height_ptr);

void CalcCylinderVolume(double *radius_ptr, double *height_ptr, double *volume_ptr);

int main()
{

    char runProgramAgain = 'y';

    do
    {

        double radius, height, volume;

        double *radius_ptr = &radius;
        double *height_ptr = &height;
        double *volume_ptr = &volume;

        GetCylinderDimensions(radius_ptr, height_ptr);

        CalcCylinderVolume(radius_ptr, height_ptr, volume_ptr);

        // converts all values to 3 decimal places
        cout << fixed;
        cout << setprecision(3);

        cout << "\nThe volume of the cylinder with radius " << radius << " and height " << height << " is " << volume;

        cout << "\nDo you want to run this program again? (Press y for yes, any other key for no) ";
        cin >> runProgramAgain;
        cin.ignore(10, '\n');

        // converts the integer returned from tolower function back to a char
        runProgramAgain = (char)tolower(runProgramAgain);

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

void GetCylinderDimensions(double *radius_ptr, double *height_ptr)
{
    cout << "Please input the following cylinder dimesions:\n";

    double radius, height;

    // temporary variable for storing the user input before it is converted to a double
    char temp[10];

    cout << "Radius: ";
    cin.getline(temp, 10);
    radius = atof(temp);
    *radius_ptr = radius;

    cout << "Height: ";
    cin.getline(temp, 10);
    height = atof(temp);
    *height_ptr = height;
}

void CalcCylinderVolume(double *radius_ptr, double *height_ptr, double *volume_ptr)
{
    double Vol_Cylinder = PI * pow(*radius_ptr, 2) * (*height_ptr);

    *volume_ptr = Vol_Cylinder;
};