#include <iostream>
#include <string>
#include <cstdlib> // for srand and rand functions
#include <cctype>  // for tolower function

using namespace std;

char Get_A_Letter();

int main()
{

    char runProgramAgain = 'y';

    do
    {
        cout << "Encoded message generator." << endl;

        cout << "Please provide a seed value: ";

        unsigned int seed;

        // temporary variable to store the user input before it is converted to an int
        char temp[10];

        cin.getline(temp, 10);
        seed = atoi(temp);

        srand(seed);

        string message;

        for (int i = 0; i < 15; i++)
        {
            char randomLetter = Get_A_Letter();

            message += randomLetter;

            cout << message << endl;
        }

        cout << "\nDo you want to run this program again? (Press y for yes, any other key for no) ";
        cin >> runProgramAgain;
        cin.ignore(10, '\n');

        // converts the integer returned from tolower function back to a char
        runProgramAgain = (char)tolower(runProgramAgain);

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

char Get_A_Letter()
{
    // results in a random number within the range of 65 to (65 + 26 = 91) {the 91st value is excluded}
    // in ASCII representation, A=65, Z=90
    int randomNumber = 65 + (rand() % 26);

    // converts an int into a char data type
    char randomLetter = char(randomNumber);
    return randomLetter;
}