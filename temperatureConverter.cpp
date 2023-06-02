#include <iostream>
#include <iomanip> // for fixed, setprecision
#include <cctype>  // for tolower, toupper functions
#include <string>
#include <unordered_map>

using namespace std;

bool getTempScale(char *tempScalePtr);

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
float celsiusToRankine(float celsius);

float fahrenheitToCelsius(float fahrenheit);
float fahrenheitToKelvin(float fahrenheit);
float fahrenheitToRankine(float fahrenheit);

float kelvinToCelsius(float kelvin);
float kelvinToFahrenheit(float kelvin);
float kelvinToRankine(float kelvin);

float rankineToCelsius(float rankine);
float rankineToFahrenheit(float rankine);
float rankineToKelvin(float rankine);

float performCalcConversion(float baseTempScale, float targetTempScale, float baseTemp);

int main()
{

    // stores the initial precision for floats so we can reset it to the default value later
    streamsize initialPrecision = cout.precision();

    char runProgramAgain = 'y';

    do
    {
        unordered_map<char, string> tempScales;
        tempScales['C'] = "Celsius";
        tempScales['F'] = "Fahrenheit";
        tempScales['K'] = "Kelvin";
        tempScales['R'] = "Rankine";

        char baseTempScale, targetTempScale;
        float baseTemp, result;

        cout << "\nTemperature Converter Program.\n"
             << endl;

        cout << "\nPlease select the base temperature scale: " << endl;
        // terminates the execution of the current loop if an invalid input is provided i.e.
        // the remaining code below the continue statement is ignored and the loop starts executing from the top of the do block
        if (!getTempScale(&baseTempScale))
        {
            continue;
        }

        cout << "Base temperature scale: " << tempScales[baseTempScale] << endl;

        cout << "\nPlease select the target temperature scale: " << endl;
        // terminates the execution of the current loop if an invalid input is provided
        if (!getTempScale(&targetTempScale))
        {
            continue;
        }
        cout << "Target temperature scale: " << tempScales[targetTempScale] << endl;

        cout << "\nInput the value in " << tempScales[baseTempScale] << ": ";
        char temp[10];

        cin.getline(temp, 10);
        baseTemp = atof(temp);

        result = performCalcConversion(baseTempScale, targetTempScale, baseTemp);

        // converts the obtained results to 2 decimal places (by limiting the precision of the floating point values)
        cout << fixed << setprecision(2) << endl;
        // it seems the round function is not supported by this version of Visual Studio (it wasn't even in the header file)

        // this would convert to 2 significant figures (provided the default precision is unaltered
        // cout << setprecision(2) << endl;

        cout << "Converting " << baseTemp << " from " << tempScales[baseTempScale] << " to " << tempScales[targetTempScale] << " gives " << result << endl;
        // resets the precision back to initial value, after the results are displayed in 2 decimal places
        cout << setprecision(initialPrecision);

        cout << "Do you want to run this program again? (Press y for yes, for no press any other key) ";
        cin >> runProgramAgain;
        cin.ignore(10, '\n');

        runProgramAgain = (char)tolower(runProgramAgain);

        // clears the console window on each iteration of the loop
        system("cls");

    } while (runProgramAgain == 'y');

    system("pause");

    return 0;
}

// returns true if user input is valid, false otherwise
bool getTempScale(char *tempScalePtr)
{
    cout << "\tC - Celsius\n\tF - Fahrenheit\n\tK - Kelvin\n\tR - Rankine" << endl;

    char tempScale;

    cin >> tempScale;
    cin.ignore(10, '\n');

    tempScale = (char)toupper(tempScale);

    switch (tempScale)
    {
    // the inputted value is only stored if a valid value is provided
    case 'C':
    case 'F':
    case 'K':
    case 'R':
        *tempScalePtr = tempScale;
        return true;
        // break keyword isn't accessible in the program due to the return statement
        break;
    default:
        cout << "Invalid temperature scale." << endl;
        return false;
    }
}

float celsiusToFahrenheit(float celsius)
{
    float fahrenheit = ((celsius / 5.0) * 9.0) + 32;
    return fahrenheit;
}

float celsiusToKelvin(float celsius)
{
    float kelvin = celsius + 273.15;
    return kelvin;
}

float celsiusToRankine(float celsius)
{
    float kelvin = celsiusToKelvin(celsius);
    float rankine = kelvinToRankine(kelvin);

    return rankine;
}

float fahrenheitToCelsius(float fahrenheit)
{
    float celsius = ((fahrenheit - 32) / 9.0) * 5.0;
    return celsius;
}

float fahrenheitToKelvin(float fahrenheit)
{
    float celsius = fahrenheitToCelsius(fahrenheit);
    float kelvin = celsius + 273.15;

    return kelvin;
}

float fahrenheitToRankine(float fahrenheit)
{
    float kelvin = fahrenheitToKelvin(fahrenheit);
    float rankine = kelvinToRankine(kelvin);

    return rankine;
}

float kelvinToCelsius(float kelvin)
{
    float celsius = kelvin - 273.15;
    return celsius;
}

float kelvinToFahrenheit(float kelvin)
{
    float celsius = kelvinToCelsius(kelvin);
    float fahrenheit = celsiusToFahrenheit(celsius);

    return fahrenheit;
}

float kelvinToRankine(float kelvin)
{
    float rankine = kelvin * 1.8;
    return rankine;
}

float rankineToKelvin(float rankine)
{
    float kelvin = rankine * (5.0 / 9.0);
    return kelvin;
}

float rankineToFahrenheit(float rankine)
{
    float fahrenheit = rankine - 459.67;
    return fahrenheit;
}

float rankineToCelsius(float rankine)
{
    float fahrenheit = rankineToFahrenheit(rankine);
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsius;
}

float performCalcConversion(float baseTempScale, float targetTempScale, float baseTemp)
{
    float result = 0.0;

    // if the temperature scales match, just return the user input (baseTemp)
    if (baseTempScale == targetTempScale)
    {
        result = baseTemp;
    }
    else if (baseTempScale == 'C' && targetTempScale == 'F')
    {
        result = celsiusToFahrenheit(baseTemp);
    }
    else if (baseTempScale == 'C' && targetTempScale == 'K')
    {
        result = celsiusToKelvin(baseTemp);
    }
    else if (baseTempScale == 'C' && targetTempScale == 'R')
    {
        result = celsiusToRankine(baseTemp);
    }
    else if (baseTempScale == 'F' && targetTempScale == 'C')
    {
        result = fahrenheitToCelsius(baseTemp);
    }
    else if (baseTempScale == 'F' && targetTempScale == 'K')
    {
        result = fahrenheitToKelvin(baseTemp);
    }
    else if (baseTempScale == 'F' && targetTempScale == 'R')
    {
        result = fahrenheitToRankine(baseTemp);
    }
    else if (baseTempScale == 'K' && targetTempScale == 'C')
    {
        result = kelvinToCelsius(baseTemp);
    }
    else if (baseTempScale == 'K' && targetTempScale == 'F')
    {
        result = kelvinToFahrenheit(baseTemp);
    }
    else if (baseTempScale == 'K' && targetTempScale == 'R')
    {
        result = kelvinToRankine(baseTemp);
    }
    else if (baseTempScale == 'R' && targetTempScale == 'C')
    {
        result = rankineToCelsius(baseTemp);
    }
    else if (baseTempScale == 'R' && targetTempScale == 'F')
    {
        result = rankineToFahrenheit(baseTemp);
    }
    else if (baseTempScale == 'R' && targetTempScale == 'K')
    {
        result = rankineToKelvin(baseTemp);
    }
    else
    {
        cout << "Invalid operation." << endl;
    }

    return result;
}