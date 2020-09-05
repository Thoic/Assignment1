// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int** transpose(int **x);

int** add(int **x);

int** multiply();

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
            int** result = multiply();
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

int** multiply() {

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

    int** z3 = new int* [5];
    return z3;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
