// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int** transpose(int **x);

int** add(int **x);

int** multiply(int **xT);

int main()
{
    //get method to run
    int method;
    cin >> method;

    //get x matrix
    int** x = new int*[10];
    for (int i = 0; i < 10; i++) {
        x[i] = new int[3];
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    }


    //run the method
    switch (method) {
        case 1: {
            int** z1 = transpose(x);
            cout << "Z1 = ";
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 5; j++) {
                    if (z1[i][j] != 0) {
                        cout << i << " " << j << " " << z1[i][j] << " ";
                    }
                }
            }
            break;
        }
        case 2: {
            int** z2 = add(x);
            cout << "Z2 = ";
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 8; j++) {
                    if (z2[i][j] != 0) {

                        cout << i << " " << j << " " << z2[i][j] << " ";
                    }
                }
            }
            break;
        }
        case 3: {
            int** xT = transpose(x);
            int** z3 = multiply(xT);
            cout << "Z3 = ";
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (z3[i][j] != 0) {
                        cout << i << " " << j << " " << z3[i][j] << " ";
                    }
                }
            }
            break;
        }
    }

    return 0;
}

int** transpose(int **x) {
    
    //initialize result matrix to zero
    int** z1 = new int*[8];
    for (int idx = 0; idx < 8; idx++) {
        z1[idx] = new int[5];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            z1[i][j] = 0;
        }
    }

    //loop through given array
    for (int i = 0; i < 10; i++) {
        //place the value into the corresponding location
        z1[x[i][1]][x[i][0]] = x[i][2];
    }

    return z1;
}

int** add(int **x) {

    //initialize y matrix
    int y[10][3] = {
        {0, 0, 1},
        {0, 3, 9},
        {0, 5, 5},
        {1, 4, 2},
        {1, 7, 3},
        {2, 1, 4},
        {2, 6, 8},
        {3, 2, 2},
        {4, 0, 1},
        {4, 4, 7}
    };

    //initialize result matrix
    int** z2  = new int* [5];
    for (int idx = 0; idx < 5; idx++) {
        z2[idx] = new int[8];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            z2[i][j] = 0;
        }
    }

    //insert vals
    for (int idx = 0; idx < 10; idx++) {
        //set from x matrix
        z2[x[idx][0]][x[idx][1]] = x[idx][2];

        //add from y matrix
        z2[y[idx][0]][y[idx][1]] += y[idx][2];
    }

    return z2;

}

int** multiply(int **xT) {

    //initialize y matrix
    int y[5][8] = {
        {1, 0, 0, 9, 0, 5, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 3},
        {0, 4, 0, 0, 0, 0, 8, 0},
        {0, 0, 2, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 7, 0, 0, 0}
    };

    //initialize z3 matrix
    int** z3 = new int*[8];
    for (int idx = 0; idx < 8; idx++) {
        z3[idx] = new int[8];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            z3[i][j] = 0;
        }
    }

    //multiply matrices
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int dotProduct = 0;
            for (int k = 0; k < 5; k++) {
                z3[i][j] += xT[i][k] * y[k][j];
            }
        }
    }

    return z3;
}
