#include <iostream>
using namespace std;

const int SIZE_LIMIT = 1024;

void readArray(char[], int&);
void deleteRepeats(char[], int&);
void printArray(char[], int);

int main() {
    char array[SIZE_LIMIT];
    char answer;
    int size;

    do {
        size = 0;
        readArray(array, size);
        deleteRepeats(array, size);
        cout << "\n\nThe array after deleting repeats:";
        printArray(array, size);
        
        cout << "\n\nRepeat? (y/n): ";
        cin >> answer;
    } while (answer != 'n' && answer != 'N');
    return 0;
}

void readArray(char array[], int &size) {
    cout << "\nWhat is the size: ";
    cin >> size;
    while (size > SIZE_LIMIT || size < 0) {
        cerr << "\nInvalid size. Please enter a size between 0 and " << SIZE_LIMIT << ": ";
        cin >> size;
    }
    cout << "Enter the array (one character at a time):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void deleteRepeats(char array[], int &size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                // Shift elements left to delete the duplicate
                for (int k = j + 1; k < size; k++) {
                    array[k - 1] = array[k];
                }
                size--; // Reduce the size of the array
                j--;    // Adjust the index to check the new element at this position
            }
        }
    }
}

void printArray(char array[], int size) {
    cout << "\nUpdated array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}
