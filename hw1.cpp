//
// Created by 한현민 on 2021-09-10.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

class VectorApp {
private:
    vector<float> myVector;
public:
    void createVector() {
        float input = 0.f;
        // debug
        while (true) {
            cin >> input;
            if (!(fabsf(input - (-1)) <= FLT_EPSILON))
                myVector.push_back(input);
            else
                break;
        }
    }

    void modifyVector(int targetIndex, float modifyValue) {
        if (!myVector.empty()) {
            // check whether the target can be assigned by checking the size of myVector
            if (!(targetIndex >= myVector.size() - 1)) {
                myVector[targetIndex] = modifyValue;
            }
        }
    }

    void multiplyFromScalar(float multiplier) {
        if (!myVector.empty()) {
            for (int i = 0; i < myVector.size(); i++) {
                myVector[i] *= multiplier;
            }
        }
    }

    void displayVector() {
        if (!myVector.empty()) {
            for (int i = 0; i < myVector.size(); i++) {
                if (i != myVector.size() - 1)
                    cout << myVector[i] << ", ";
                else
                    cout << myVector[i] << endl;
            }
        }
    }
};

int main() {
    VectorApp instance;
    instance.createVector();
    instance.modifyVector(2, 3.14f);
    instance.multiplyFromScalar(10.f);
    instance.displayVector();
}