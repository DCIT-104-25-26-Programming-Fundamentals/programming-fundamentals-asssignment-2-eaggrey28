// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

double calculateSum(const double numbers[], int count) {
    double total = 0;

    for (int i = 0; i < count; i++) {
        total += numbers[i];
    }

    return total;
}

double calculateAverage(const double numbers[], int count) {
    return calculateSum(numbers, count) / count;
}

double calculateMaximum(const double numbers[], int count) {
    double maximum = numbers[0];

    for (int i = 1; i < count; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    return maximum;
}

double calculateMinimum(const double numbers[], int count) {
    double minimum = numbers[0];

    for (int i = 1; i < count; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }

    return minimum;
}

int main() {
    int count;

    cout << "How many numbers? ";
    cin >> count;

    if (count <= 0) {
        cout << "Error: Number of values must be positive." << endl;
        return 0;
    }

    double* numbers = new double[count];

    for (int i = 0; i < count; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << endl << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers, count) << endl;
    cout << "Average: " << calculateAverage(numbers, count) << endl;
    cout << "Maximum: " << calculateMaximum(numbers, count) << endl;
    cout << "Minimum: " << calculateMinimum(numbers, count) << endl;

    delete[] numbers;
    return 0;
}
