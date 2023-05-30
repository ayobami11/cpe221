#include <iostream>

using namespace std;

double determinant_3x3(double matrix[3][3]);

void simultaneous_3var(double matrix[3][4], double result[1][3]);

int main()
{

    double matrix[3][4] = {{5, 2, 1, 4}, {6, 8, 1, -2}, {9, 7, 2, 0}};

    double result[1][3];
    simultaneous_3var(matrix, result);

    system("pause");

    return 0;
}

double determinant_3x3(double matrix[3][3])
{
    double determinant =
        (matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))) -
        (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) +
        (matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])));

    return determinant;
}

// the result is outputted to the screen, and at the same time, assigned to an existing array
void simultaneous_3var(double matrix[3][4], double result[1][3])
{
    // this calculation is performed using Cramer's rule
    double mat0[3][3] = {{matrix[0][0], matrix[0][1], matrix[0][2]}, {matrix[1][0], matrix[1][1], matrix[1][2]}, {matrix[2][0], matrix[2][1], matrix[2][2]}};
    double mat1[3][3] = {{matrix[0][3], matrix[0][1], matrix[0][2]}, {matrix[1][3], matrix[1][1], matrix[1][2]}, {matrix[2][3], matrix[2][1], matrix[2][2]}};
    double mat2[3][3] = {{matrix[0][0], matrix[0][3], matrix[0][2]}, {matrix[1][0], matrix[1][3], matrix[1][2]}, {matrix[2][0], matrix[2][3], matrix[2][2]}};
    double mat3[3][3] = {{matrix[0][0], matrix[0][1], matrix[0][3]}, {matrix[1][0], matrix[1][1], matrix[1][3]}, {matrix[2][0], matrix[2][1], matrix[2][3]}};

    double det0 = determinant_3x3(mat0);
    double det1 = determinant_3x3(mat1);
    double det2 = determinant_3x3(mat2);
    double det3 = determinant_3x3(mat3);

    double x = det1 / det0;
    double y = det2 / det0;
    double z = det3 / det0;

    result[0][0] = x;
    result[0][0] = y;
    result[0][0] = z;

    cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
}