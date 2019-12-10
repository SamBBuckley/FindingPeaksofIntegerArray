#include <iostream>

using namespace std;


void printoutArray(int* array, int size) {
    for(int i = 0; i < size; ++i) {
        if(i < size -1) {
            cout << array[i] << ", ";
        } else {
            cout << array[i] << endl;
        }
    }
}


//SHOULD BE AN INT AND RETURN THE NUMBER OF PEAKS
// This function is just so that you can see the output of the different peaks
void findPeakTemperatures(int* temperatures, int size) {
    cout << "Finding the peak temperatures of: " << endl;
    printoutArray(temperatures, size);
    cout << "Peaks:" << endl;
    int peakCounter = 0;
    for(int i = 0; i < size; ++i) {
        //Edge Case which is the ends
        if(i == 0) {
            int compareRight = temperatures[- + 1];
            int current = temperatures[i];
            if(current > compareRight) {
                cout << temperatures[i] << ", ";
                peakCounter++;
            }
        } else if(i == (size - 1)) {
            if(temperatures[i - 1] < temperatures[i]) {
                cout << temperatures[i] << endl;
                peakCounter++;
            } else {
                cout << endl;
            }
        } else { // The rest of the positions that are not edge cases
            int compareLeft = temperatures[i - 1];
            int current = temperatures[i];
            int compareRight = temperatures[i + 1];

            if(current > compareLeft && current > compareRight) {
                cout << temperatures[i] << ", ";
                peakCounter++;
            }
        }
    }
    cout << "There are " << peakCounter << " peaks in this temperature set." << endl;
}

//This just count's all of the peaks after finding them
int countPeaks(int* temperatures, int size) {
    int peakCounter = 0;
    for(int i = 0; i < size; ++i) {
        //Edge Case which is the ends
        if(i == 0) {
            if(temperatures[i] > temperatures[i + 1]) {
                peakCounter++;
            }
        } else if(i == (size - 1)) {
            if(temperatures[i - 1] < temperatures[i]) {
                peakCounter++;
            }
        } else { // The rest of the positions that are not edge cases
            if(temperatures[i] > temperatures[i - 1] && temperatures[i] > temperatures[i + 1]) {
                peakCounter++;
            }
        }
    }
    return peakCounter;
}

int main() {

    int temperatures [5] = {9, 1, 5, 3, 8};


    findPeakTemperatures(temperatures, 5);

    cout << "There were exactly " << countPeaks(temperatures, 5) << " peaks in the set with the other function." << endl;
    cout << endl << "Main program execution finished." << endl;


    return 0;
}