#include <iostream>
#include <cmath>
#include <cctype> // contains tolower function

using namespace std;

void Get_Coefficients(double *a_ptr, double *b_ptr, double *c_ptr);

char Calc_Discriminant(double a, double b, double c, double *discriminant_ptr);

void Calc_Root(double discriminant, char discriminant_type, double a, double b);

int main()
{

    char runProgramAgain = 'y';

    do
    {

        cout << "Quadratic equation calculator." << endl;
        cout << "Syntax: ax2 +bx + c = 0" << endl;

        double a, b, c;

        double *a_ptr = &a;
        double *b_ptr = &b;
        double *c_ptr = &c;

        Get_Coefficients(a_ptr, b_ptr, c_ptr);

        // stores the calculated discriminant
        double discriminant;
        char discriminant_type = Calc_Discriminant(a, b, c, &discriminant);

        Calc_Root(discriminant, discriminant_type, a, b);

        cout << "Do you want to run this program again? (Press y for yes, any other key for no) " << endl;

        cin >> runProgramAgain;

        cin.ignore(10, '\n');

        // converts int returned from function back to char
        runProgramAgain = (char)tolower(runProgramAgain);

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

void Get_Coefficients(double *a_ptr, double *b_ptr, double *c_ptr)
{

    cout << "Please input the values of a, b and c" << endl;

    char temp[10];
    double a, b, c;

    cout << "a: ";
    cin.getline(temp, 10);
    a = atoi(temp);
    *a_ptr = a;

    cout << "b: ";
    cin.getline(temp, 10);
    b = atoi(temp);
    *b_ptr = b;

    cout << "c: ";
    cin.getline(temp, 10);
    c = atoi(temp);
    *c_ptr = c;
}

// checks if the roots are real, imaginary or same
char Calc_Discriminant(double a, double b, double c, double *discriminant_ptr)
{
    double discriminant = (b * b) - (4 * a * c);

    *discriminant_ptr = discriminant;

    if (discriminant > 0.0)
    {
        // real
        return 'r';
    }
    else if (discriminant < 0.0)
    {
        // imaginary
        return 'i';
    }
    else
    {
        // same
        return 's';
    }
}

void Calc_Root(double discriminant, char discriminant_type, double a, double b)
{

    cout << "The roots of the quadratic equation are:\n";

    if (discriminant_type == 'r')
    {

        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "root1 = " << root1 << "\n";
        cout << "root2 = " << root2 << "\n";
    }
    else if (discriminant_type == 'i')
    {
        double realPart = -b / (2 * a);

        // absolute value of discriminant is used to avoid negative values (and consequently prevent a nan value)
        double imagPart = sqrt(abs(discriminant)) / (2 * a);

        cout << "root1 = " << realPart << " + " << imagPart << "i\n";
        cout << "root2 = " << realPart << " - " << imagPart << "i\n";
    }
    else if (discriminant_type == 's')
    {

        double root = (-b + sqrt(discriminant)) / (2 * a);

        cout << "root1 = " << root << "\n";
        cout << "root2 = " << root << "\n";
    }
    else
    {
        cout << "Invalid discriminant." << endl;
    }
};