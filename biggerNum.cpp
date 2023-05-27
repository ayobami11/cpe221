#include <iostream>
#include <cctype> // contains the tolower function

using namespace std;

void GetTwoNumbers(int *num1, int *num2);

int FindBigOne(int num1, int num2);

int main()
{

    char runProgramAgain = 'y';

    do
    {

        int num1, num2;

        int *num1_ptr = &num1;
        int *num2_ptr = &num2;

        GetTwoNumbers(num1_ptr, num2_ptr);

        int biggerNum = FindBigOne(num1, num2);

        cout << "The bigger number between " << num1 << " and " << num2 << " is " << biggerNum << endl;

        cout << "Do you want to run this program again? (Press y for yes, any other key for no) " << endl;

        cin >> runProgramAgain;

        cin.ignore(10, '\n');

        // converts int returned from function back to char
        runProgramAgain = (char)tolower(runProgramAgain);

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

void GetTwoNumbers(int *num1, int *num2)
{

    int firstNumber, secondNumber;

    // temporary char array to store the 'string' text before it is converted to an int
    char temp[10];

    cout << "Please input the first number: ";
    cin.getline(temp, 10);
    firstNumber = atoi(temp);
    *num1 = firstNumber;

    cout << "Please input the second number: ";
    cin.getline(temp, 10);
    secondNumber = atoi(temp);
    *num2 = secondNumber;
}

int FindBigOne(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}