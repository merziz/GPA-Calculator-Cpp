#include <iostream>
#include <string>
#include <numeric>  // for std::gcd
#include <iomanip>
using namespace std;

const int N = 7;
// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    // Use Euclid's algorithm to find the gcd
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the GPA
double calculateGPA(int scores[], int n) {
    // Initialize the total score
    int total = 0;
    // Loop through the scores array and add them to the total
    for (int i = 0; i < n; i++) {
        total += scores[i];
    }
    // Return the average score
    return static_cast<double>(total) / n;
}

// Function to determine the grade
string determineGrade(double gpa) {
    // Define the grade scheme
    string grades[] = { "1st class", "2nd class upper", "2nd class lower", "passed", "fail" };
    // Define the GPA thresholds
    double thresholds[] = { 90, 75, 50, 40, 0 };
    // Loop through the thresholds and compare with the GPA
    for (int i = 0; i < 5; i++) {
        if (gpa >= thresholds[i]) {
            // Return the corresponding grade
            return grades[i];
        }
    }
    // Return an empty string if none of the thresholds match
    return "";
}

// Function to convert a decimal number to a fraction
string decimalToFraction(double decimal) {
    // Multiply both the numerator and the denominator by a power of 10
    double numerator = decimal;
    double denominator = 1;

    while (numerator - static_cast<int>(numerator) != 0) {
        numerator *= 10;
        denominator *= 10;
    }

    // Simplify the fraction by dividing both the numerator and the denominator by their GCD
    int divisor = gcd(static_cast<int>(numerator), static_cast<int>(denominator));
    numerator /= divisor;
    denominator /= divisor;

    // Convert the numerator and the denominator to strings
    string numStr = to_string(static_cast<int>(numerator));
    string denStr = to_string(static_cast<int>(denominator));

    // Return the fraction as a string
    return numStr + "/" + denStr;
}

// Function to convert a decimal number to a fraction with a given denominator
string decimalToFractionWithDenominator(double decimal, int denominator) {
    // Multiply the decimal number by the denominator
    double numerator = decimal * denominator;
    // Round the numerator to the nearest integer
    numerator = round(numerator);
    // Simplify the fraction by dividing both the numerator and the denominator by their GCD
    int divisor = gcd(static_cast<int>(numerator), denominator);
    numerator /= divisor;
    denominator /= divisor;
    // Convert the numerator and the denominator to strings
    string numStr = to_string(static_cast<int>(numerator));
    string denStr = to_string(denominator);
    // Return the fraction as a string
    return numStr + "/" + denStr;
}


int main() {
    // Declare an array to store the subject codes
    string codes[N];

    // Declare an array to store the scores
    int scores[N];

    // Declare a variable to store the student name
    string name;

    //Declare a variable to store the denominator
    int  denominator = 7;

    // Declare a variable to store the decimal number
    double decimal = 0.0;

    // Prompt the user to enter the student name
    cout << "Student name: ";
    cin >> name;

    // Loop through the subjects and prompt the user to enter the code and the score
    for (int i = 0; i < N; i++) {
        cout << "Subject Code : ";
        cin >> codes[i];
        cout << "Mark for " << codes[i] << ": ";
        cin >> scores[i];
    }


    // Call the function to calculate the GPA
    double gpa = calculateGPA(scores, N);

    // Call the function to determine the grade
    string grade = determineGrade(gpa);

    // Call the function to convert the GPA to a fraction with a denominator of 7
    string fraction = decimalToFractionWithDenominator(gpa, 7);

    // Display the total score, the average score, the status, and the result
    cout << "Total Score: " << gpa * N << endl;
    cout << "Average Score: " << fraction << endl;

    // Use fixed and setprecision to limit the decimal places of the GPA to two
    cout << "Status: " << fixed << setprecision(2) << gpa << endl;
    cout << "Result: " << grade << endl;

    return 0;
}