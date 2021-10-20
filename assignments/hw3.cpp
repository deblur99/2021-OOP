#include <iostream>
#define ROW 3
#define COL 3
using namespace std;

/*
				HW 3 (7pts, Due: 10/13 23:59PM)
Complete a class Matrix2 by inheriting the class Matrix that you made in HW2. 
Your Matrix2 class should support the following functionalities:

1. zeros()
This function is newly added in Matrix2, which makes the given matrix a zero matrix. 
That is, all elements of the given matrix should be zeros.

2. eyes()
Another new function eyes() makes the given matrix the identity matrix.

3. show()
The show() function of the class Matrix is redefined in class Matrix2.
Now, this function only displays the biggest element of the matrix. 

4. You are free to modify the previous class Matrix if necessary, but you need to use inheritance to create class Matrix2.
Make sure all functions (including those of HW2) are working as intended.
Also, any errors in the previous HW2 code should be corrected. Only then can you get a full score. 


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
uniform_int_distribution<int> dis(1, 10);

class Matrix {
protected:
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
            // Do not use "ESP" in multiplication matrices
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


class Matrix2: public Matrix {
public:
    void zeros();
    void eyes();
    void show();
};

void Matrix2::zeros() {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            this->matrix[i][j] = 0;
        }
    }
}

void Matrix2::eyes() {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == j)
                this->matrix[i][j] = 1;
            else
                this->matrix[i][j] = 0;
        }
    }
}

void Matrix2::show() {
    int largest = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (largest < this->matrix[i][j])
                largest = this->matrix[i][j];
        }
    }

    cout << largest << endl;
}

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

    Matrix A, B, C;		// 3 by 3 matrix created. All values are intialized as non-zero integers.

    Matrix D = A + B;	// Matrix Addition
    Matrix E = A * C;	// Matrix Multiplication

    cout << "A" << endl;
    A.show();		// display the values
    cout << "B" << endl;
    B.show();
    cout << "C" << endl;
    C.show();


    cout << "A + B" << endl;
    D.show();

    cout << "A * C" << endl;
    E.show();


    //added for HW3
    Matrix2 F;
    cout << "Zero Matrix" << endl;
    F.zeros();			// zero all elements.
    F.Matrix::show();	// call the show() of the base.
    F.show();			// diplay the biggest element.

    cout << "Identity Matrix" << endl;
    F.eyes();			// make F the identity matrix.
    F.Matrix::show();
    F.show();

    return 0;
}