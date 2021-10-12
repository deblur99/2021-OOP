#include <iostream>

#define ROW 3
#define COL 3
using namespace std;

/*
				HW 2 (5pts, Due: 10/4 23:59PM)
Provide a class Matrix to complete this code.
This class should support the following functionalities:

1. Matrix Creation
A 3 by 3 matrix is created. All values are intialized as non-zero integers.
You may want to use rand for this.

2. Matrix Addtion and Multiplication
You may want to use operator overloading.

3. Display
The values of a matrix dare "well" displayed.

Submit this file to the LMS.
*/

//Your code goes here.
#include <random>
#include <chrono>

// generate random numbers by using current time
auto current = chrono::system_clock::now();
auto duration = current.time_since_epoch();
auto mills = chrono::duration_cast<chrono::milliseconds>(duration).count();

mt19937 gen(mills);
uniform_int_distribution<int> dis(1, 2);

class Matrix {
private:
    int matrix[ROW][COL];
public:
    Matrix() {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                matrix[i][j] = dis(gen);
            }
        }
    }

    friend Matrix operator+(Matrix, Matrix);
    friend Matrix operator*(Matrix, Matrix);

    void show();
};

Matrix operator+(Matrix op1, Matrix op2) {
    Matrix result;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            result.matrix[i][j] = op1.matrix[i][j] + op2.matrix[i][j];
        }
    }

    return result;
}

Matrix operator*(Matrix op1, Matrix op2) {
    Matrix result;
    int resultElement = 0;

    for (int i = 0; i < ROW; i++) {

        for (int j = 0; j < COL; j++) {
            resultElement = 0;
            // 행렬 곱에 ESP 쓰지 말자
            for (int k = 0; k < COL; k++) {
                resultElement += (op1.matrix[i][k] * op2.matrix[k][j]);
            }

            result.matrix[i][j] = resultElement;
        }
    }

    return result;
}

void Matrix::show() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

    Matrix A, B, C;        // 3 by 3 matrix created. All values are intialized as non-zero integers.

    Matrix D = A + B;    // Matrix Addition
    Matrix E = A * C;    // Matrix Multiplication

    cout << "A" << endl;
    A.show();        // display the values
    cout << "B" << endl;
    B.show();
    cout << "C" << endl;
    C.show();


    cout << "A + B" << endl;
    D.show();

    cout << "A * C" << endl;
    E.show();

    return 0;
}