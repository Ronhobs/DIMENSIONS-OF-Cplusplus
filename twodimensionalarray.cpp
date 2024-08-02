#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int NUM_TESTS = 8;

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds);
void displayTestScores(const int scores[][NUM_TESTS], int numStds);
int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int topStudent(const int scores[][NUM_TESTS], int numStds);

int main() {
    const int NUM_STDS = 10;
    int scores[NUM_STDS][NUM_TESTS];
    ifstream f("Assignment1Data.txt");

    if (!f.is_open()) {
        cerr << "Error: unable to open file\n";
        return 1;
    }

    readTestScores(f, scores, NUM_STDS);
    f.close();
    displayTestScores(scores, NUM_STDS);

    cout << setprecision(2) << fixed;

    cout << "\nTotal for test #1 is: " << totalOneTest(scores, NUM_STDS, 0); // index 0 is test 1
    cout << "\nTotal for test #5 is: " << totalOneTest(scores, NUM_STDS, 4); 
    cout << "\nTotal for Student #3 is: " << totalOneStudent(scores, NUM_STDS, 2); 
    cout << "\nTotal for Student #8 is: " << totalOneStudent(scores, NUM_STDS, 7); 
    cout << "\nAverage for test #5: " << averageOneTest(scores, NUM_STDS, 4); 
    cout << "\nAverage for test #8: " << averageOneTest(scores, NUM_STDS, 7); 
    cout << "\nAverage for Student #5: " << averageOneStudent(scores, NUM_STDS, 4); 
    cout << "\nAverage for Student #9: " << averageOneStudent(scores, NUM_STDS, 8); 
    cout << "\nHighest test score for Student #2: " << highestOneStudent(scores, NUM_STDS, 1); 
    cout << "\nThe top student: " << topStudent(scores, NUM_STDS) << endl; 
    
    return 0;
}

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds) {
    if (f.is_open()) {
        for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
            for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber) {
                f >> scores[studentNumber][testNumber];
            }
        }
    } else {
        cerr << "Error: unable to open file\n";
    }
}

//*****************************************************************************************************

void displayTestScores(const int scores[][NUM_TESTS], int numStds) {
    cout << "    All Test scores" << endl;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
            cout << scores[studentNumber][testNumber] << " ";
        cout << endl;
    }
}

//*****************************************************************************************************

int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber) {
    int sum = 0;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber)
        sum += scores[studentNumber][testNumber];

    return sum;
}

//*****************************************************************************************************

int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber) {
    int sum = 0;

    for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
        sum += scores[studentNumber][testNumber];

    return sum;
}

//*****************************************************************************************************

double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber) {
    int total = 0;
    double average;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber)
        total += scores[studentNumber][testNumber];

    average = static_cast<double>(total) / numStds;

    return average;
}

//*****************************************************************************************************

double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber) {
    int total = 0;
    double average;

    for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
        total += scores[studentNumber][testNumber];

    average = static_cast<double>(total) / NUM_TESTS;

    return average;
}

//*****************************************************************************************************

int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber) {
    int highest = scores[studentNumber][0];

    for (int testNumber = 1; testNumber < NUM_TESTS; ++testNumber)
        if (scores[studentNumber][testNumber] > highest)
            highest = scores[studentNumber][testNumber];

    return highest;
}

//*****************************************************************************************************

int topStudent(const int scores[][NUM_TESTS], int numStds) {
    int topPercent = 0,
        topStudent = 0,
        current;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        current = averageOneStudent(scores, numStds, studentNumber);

        if (current > topPercent) {
            topPercent = current;
            topStudent = studentNumber;
        }
    }

    return (topStudent + 1); // +1 for display purposes
}
