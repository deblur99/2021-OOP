//
// Created by 한현민 on 2021-09-10.
//

#include <iostream>

using namespace std;

class VectorApp {
private:
    int Xshape = 0, Yshape = 0;
    float **myVector;
public:
    void createVector() {
        cout << "Creating myVector" << endl;
        cout << "First, enter X shape and Y shape respectively" << endl;

        // first, get two positive integer inputs from user to assign Xshape and Yshape.
        while (true) {
            cin >> Xshape;
            cin >> Yshape;

            // check Xshape or Yshape is positive
            if (!(Xshape > 0 && Yshape > 0)) {
                cout << "Invalid Input" << endl;
            } else break;
        }

        // allocate myVector 2d-array with Xshape and Yshape
        myVector = new float*[Xshape];

        for (int i = 0; i < Xshape; i++)
            myVector[i] = new float[Yshape];

        // second, get values from user to assign each element in the myVector 2d-array.
        float input = 0.f;
        cout << "Second, enter values to assign in your vector" << endl;

        for (int i = 0; i < Xshape; i++) {
            for (int j = 0; j < Yshape; j++) {
                cin >> input;
                myVector[i][j] = input;
            }
        }

        displayVector();

        return;
    }

    void modifyVector() {
        cout << "Modifying myVector" << endl;

        int Xtarget = 0, Ytarget = 0;
        float modifyValue = 1.f;

        cout << "Enter X index, Y index, and a float value where you want to modify value in myVector" << endl;
        cin >> Xtarget; cin >> Ytarget; cin >> modifyValue;

        // convert input -1 to the last index
        if (Xtarget == -1)
            Xtarget = Xshape - 1;
        if (Ytarget == -1)
            Ytarget = Yshape - 1;

        // check indexes of the target is out of range
        if (!(Xtarget >= Xshape || Ytarget >= Yshape)) {
            myVector[Xtarget][Ytarget] = modifyValue;
        } else {
            cout << "The target index is out of range" << endl;
        }

        displayVector();

        return;
    }

    void multiplyFromScalar() {
        float multiplier = 1.f;

        cout << "Multiplying myVector with a scalar" << endl;
        cout << "Enter a float value to multiply all of values in myVector" << endl;

        cin >> multiplier;

        for (int i = 0; i < Xshape; i++) {
            for (int j = 0; j < Yshape; j++) {
                myVector[i][j] *= multiplier;
            }
        }

        displayVector();

        return;
    }

    void displayVector() {
        cout << "Displaying Result" << endl;

        if (Xshape > 0 && Yshape > 0) {
            cout << "(";
            for (int i = 0; i < Xshape; i++) {
                for (int j = 0; j < Yshape; j++) {
                    cout << myVector[i][j];

                    if (!(i == Xshape - 1 && j == Yshape - 1))
                        cout << ", ";
                }

                if (i == Xshape - 1) {
                    cout << ")" << endl;
                    break;
                }

                cout << "\n ";
            }
        }

        cout << endl;

        return;
    }

    ~VectorApp() {
        // release dynamic memory
        for (int i = 0; i < Xshape; i++) {
            delete[] myVector[i];
        }

        delete[] myVector;
    }
};

int main() {
    VectorApp instance;
    instance.createVector();
    instance.modifyVector();
    instance.modifyVector();
    instance.modifyVector();
    instance.modifyVector();
    instance.modifyVector();
    instance.multiplyFromScalar();
    instance.multiplyFromScalar();
    instance.multiplyFromScalar();
    instance.multiplyFromScalar();
    instance.multiplyFromScalar();
    instance.displayVector();
}