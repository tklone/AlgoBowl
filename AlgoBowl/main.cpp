#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream inputData;
    inputData.open("AlgoBowlInput");
    int m;
    int n;

    if (inputData.is_open()) {
        inputData >> m;
        inputData >> n;
    }

    cout << "m: " << m << endl;
    cout << "n: " << n << endl;

    int valsArray[n];
    for (int i = 0; i < n; i ++) {
        valsArray[i] = 0;
    }


    vector <int> leftSide;
    vector <int> rightSide;

    int leftVal;
    int rightVal;

    while (!inputData.eof()) {
        inputData >> leftVal;
        leftSide.push_back(leftVal);
        inputData >> rightVal;
        rightSide.push_back(rightVal);
    }

    for (int i = 0; i < leftSide.size(); i++) {
        if (leftSide.at(i) < 0) {
            leftSide.at(i) = leftSide.at(i) * -1;
        }
        if (rightSide.at(i) < 0) {
            rightSide.at(i) = rightSide.at(i) * -1;
        }

        if (leftSide.at(i) == rightSide.at(i)) {
            cout << "INVALID INPUT LIST" << endl;
        }
    }

    int currentVal;
    while (!inputData.eof()) {
        inputData >> currentVal;
        if (currentVal > 0) {
            valsArray[currentVal - 1] = valsArray[currentVal - 1] + 1;
        } else if (currentVal < 0) {
            currentVal = currentVal * -1;
            valsArray[currentVal - 1] = valsArray[currentVal - 1] - 1;
        }
    }

    //find max and min vals
    //This part is wrong
//    int minValue = 0;
//    int maxValue = 0;
//    int minValIndex;
//    int maxValIndex;
//    for (int i = 0; i < n - 1; i++) {
//        if (valsArray[i] >= maxValue) {
//            maxValue = valsArray[i];
//            maxValIndex = i;
//        }
//
//        if (valsArray[i] <= minValue) {
//            minValue = valsArray[i];
//            minValIndex = i;
//        }
//    }
//
//    cout << endl;
//    cout << "MIN VALUE: " << minValue << "     AT INDEX: " << minValIndex << endl;
//    cout << "MAX VALUE: " << maxValue << "      AT INDEX: " << maxValIndex << endl;

}
