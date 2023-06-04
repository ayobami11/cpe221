#include <iostream>
#include <cstdlib> // for atof function
#include <cctype>  // for tolower function
#include <cmath>   // for abs, pow and sqrt functions
#include <complex> // for complex numbers

using namespace std;

// New version (easier to understand)
void Get_Coefficients(float *a_ptr, float *b_ptr, float *c_ptr);
char Calc_Discriminant(float a, float b, float c);
void Calc_Root(float a, float b, float c);

int main()
{

    char runProgramAgain = 'y';

    do
    {

        float a, b, c;
        float *a_ptr, *b_ptr, *c_ptr;

        a_ptr = &a;
        b_ptr = &b;
        c_ptr = &c;

        Get_Coefficients(a_ptr, b_ptr, c_ptr);

        Calc_Root(a, b, c);

        cout << "\nDo you want to run this program again? (Press y for yes, for no press any other key) ";
        cin >> runProgramAgain;
        cin.ignore(10, '\n');

        // the tolower function returns an int representing the ascii value of the lowercased character so this value is casted back to
        // a char to ensure accurate results
        runProgramAgain = (char)tolower(runProgramAgain);

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

void Get_Coefficients(float *a_ptr, float *b_ptr, float *c_ptr)
{
    cout << "\nQuadratic Equation Calculator.";
    cout << "\nSyntax: ax2 + bx + c = 0";
    cout << "\nPlease provide the values for a, b, and c";

    float a, b, c;

    // temporary variable for storing user input as a string before converting it to a float
    char temp[15];

    cout << "\na: ";
    cin.getline(temp, 15);
    a = atof(temp);
    *a_ptr = a;

    cout << "b: ";
    cin.getline(temp, 15);
    b = atof(temp);
    *b_ptr = b;

    cout << "c: ";
    cin.getline(temp, 15);
    c = atof(temp);
    *c_ptr = c;
}

char Calc_Discriminant(float a, float b, float c)
{
    float discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant > 0.0)
    {
        // real and unequal roots
        return 'r';
    }
    else if (discriminant < 0.0)
    {
        // complex roots
        return 'i';
    }
    else
    {
        // real and equal roots
        return 's';
    }
}

void Calc_Root(float a, float b, float c)
{
    char discriminant_type = Calc_Discriminant(a, b, c);

    float root1, root2;

    if (discriminant_type == 'r')
    {
        root1 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
        root2 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

        cout << "root 1 = " << root1;
        cout << "\nroot 2 = " << root2;
    }
    else if (discriminant_type == 'i')
    {
        float real_part, imaginary_part;

        real_part = -b / (2 * a);
        // the absolute value is taken as shown below so as to prevent errors arising from taken the root of a negative number
        imaginary_part = sqrt(abs(pow(b, 2) - (4 * a * c))) / (2 * a);

        // this
        cout << "root 1 = " << real_part << " + " << imaginary_part << "i";
        cout << "\nroot 2 = " << real_part << " - " << imaginary_part << "i";

        // or that
        // complex<float> root(real_part, imaginary_part);

        // cout << "root 1 = " << root.real() << " + " << root.imag() << "i";
        // cout << "\nroot 2 = " << root.real() << " - " << root.imag() << "i";
    }
    else if (discriminant_type == 's')
    {
        root1 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

        cout << "root 1 = " << root1;
        cout << "\nroot 2 = " << root1;
    }
    else
    {
        cout << "Invalid discriminant." << endl;
    }
}

// Old version
/*

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
*/