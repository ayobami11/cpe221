#include <iostream>

using namespace std;

double determinant_2x2(double matrix[2][2]);

void simultaneous_2var(double matrix[2][3], double result_arr[1][2]);

int main() {

	double matrix[2][3] = {{2, 4, 7}, {5, 3, 9}};
	
	double result[1][2];
	simultaneous_2var(matrix, result);
	
	system("pause");

	return 0;
}

double determinant_2x2(double matrix[2][2]) {
	double determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

	return determinant;
}

// the result is outputted to the screen, and at the same time, assigned to an existing array
void simultaneous_2var(double matrix[2][3], double result[1][2]) {
    // this calculation is performed using Cramer's rule
	double mat0[2][2] = {{matrix[0][0], matrix[0][1]}, {matrix[1][0], matrix[1][1]}};
	double mat1[2][2] = {{matrix[0][2], matrix[0][1]}, {matrix[1][2], matrix[1][1]}};
	double mat2[2][2] = {{matrix[0][0], matrix[0][2]}, {matrix[1][0], matrix[1][2]}};

	double det0 = determinant_2x2(mat0);
	double det1 = determinant_2x2(mat1);
	double det2 = determinant_2x2(mat2);

	double x = det1 / det0;
	double y = det2 / det0;

	result[0][0] = x;
	result[0][1] = y;

	cout << "x = " << x << "\ny = " << y << endl;
}