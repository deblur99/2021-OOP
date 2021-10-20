//
// Created by 한현민 on 2021-10-20.
//

#include <iostream>

using namespace std;

int main() {
    int *f = new int[20];
    int *p = new int[20];
    int **arr = new int*[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = new int[10];
    }

    for (int i = 0; i < 20; i++) {
        f[i] = 10 + i;
        p[i] = 20 + i;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = 50 + i - j;
        }
    }

    for (int i = 0; i < 20; i++) { // for each 문은 고정 배열에서 사용할 수 있고, 동적 포인터에서는 사용 불가.
        cout << f[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 20; i++) {
        cout << p[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    for (int i = 0; i < 10; i++) {
        delete[] arr[i];
    }

    delete[] arr;

    delete[] p;
    delete[] f;

    return 0;
}