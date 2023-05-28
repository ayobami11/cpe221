#include <iostream>
#include <cmath>  // for pow and sqrt functions
#include <cctype> // for tolower function

using namespace std;

int banner();

void input_parameter(int choice, double *var1_ptr, double *var2_ptr, double *var3_ptr);

double analysis(int choice, double var1, double var2, double var3);

void output(double var1, double var2, double var3, double result);

int main()
{

    char runProgramAgain = 'y';

    do
    {
        int choice = banner();

        double var1, var2, var3;

        double *var1_ptr = &var1;
        double *var2_ptr = &var2;
        double *var3_ptr = &var3;

        input_parameter(choice, var1_ptr, var2_ptr, var3_ptr);

        double result = analysis(choice, var1, var2, var3);

        output(var1, var2, var3, result);

        cout << "\nDo you want to perform another computation? (Press y for yes, any other key for no) " << endl;

        cin >> runProgramAgain;

        cin.ignore(10, '\n');

        // converts int returned from function back to char
        runProgramAgain = (char)tolower(runProgramAgain);

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

// displays info the program and retrieves the equation number from the user
int banner()
{
    cout << "\nWelcome to the Equation of Motion Application Programme";

    cout << "\n1. First Equation: s = u*t + (1/2)*a*t^2,";
    cout << "\n2. Second Equation: v = u + a*t,";
    cout << "\n3. Third Equation: v^2 = u^2 + 2*a*s";

    cout << "\n\nChoice the Equation to Solve => ";

    int choice;
    // temporary variable for storing the user input as a char array
    char temp[5];

    cin.getline(temp, 5);
    // atoi - converts a char array to an int
    // atof - converts a char array to float/double
    choice = atoi(temp);

    return choice;
}

// gets the inputs for the variables of the equation of motion used
void input_parameter(int choice, double *var1_ptr, double *var2_ptr, double *var3_ptr)
{

    double var1, var2, var3;
    // temporary variable for storing the user input
    char temp[10];

    if (choice == 1)
    {
        cout << "\nPlease input the values for the following quantities:\n";

        cout << "Initial velocity (u): ";
        cin.getline(temp, 10);
        var1 = atof(temp);
        *var1_ptr = var1;

        cout << "Time (t): ";
        cin.getline(temp, 10);
        var2 = atof(temp);
        *var2_ptr = var2;

        cout << "Acceleration (a): ";
        cin.getline(temp, 10);
        var3 = atof(temp);
        *var3_ptr = var3;
    }
    else if (choice == 2)
    {
        cout << "\nPlease input the values for the following quantities:\n";

        cout << "Initial velocity (u): ";
        cin.getline(temp, 10);
        var1 = atof(temp);
        *var1_ptr = var1;

        cout << "Acceleration (a): ";
        cin.getline(temp, 10);
        var2 = atof(temp);
        *var2_ptr = var2;

        cout << "Time (t): ";
        cin.getline(temp, 10);
        var3 = atof(temp);
        *var3_ptr = var3;
    }
    else if (choice == 3)
    {
        cout << "\nPlease input the values for the following quantities:\n";

        cout << "Initial velocity (u): ";
        cin.getline(temp, 10);
        var1 = atof(temp);
        *var1_ptr = var1;

        cout << "Acceleration (a): ";
        cin.getline(temp, 10);
        var2 = atof(temp);
        *var2_ptr = var2;

        cout << "Distance (s): ";
        cin.getline(temp, 10);
        var3 = atof(temp);
        *var3_ptr = var3;
    }
}

// performs the required calculations based on the equation used
double analysis(int choice, double var1, double var2, double var3)
{
    double result;

    switch (choice)
    {
    case 1:
        result = (var1 * var2) + ((1.0 / 2.0) * var3 * pow(var2, 2));
        break;
    case 2:
        result = var1 + (var2 * var3);
        break;
    case 3:
        result = sqrt(pow(var1, 2) + (2 * var2 * var3));
        break;
    default:
        result = -1;
    }

    return result;
}

// displays the result
void output(double var1, double var2, double var3, double result)
{
    if (result == -1)
    {
        // what if the result of the calculation is actually -1 ???
        cout << "\nThe Choice of Equation is not a Valid One." << endl;
    }
    else
    {
        cout << "\nVariable 1: " << var1;
        cout << "\nVariable 2: " << var2;
        cout << "\nVariable 3: " << var3;
        cout << "\n\nResult: " << result << endl;
    }
}