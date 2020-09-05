// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int** transpose(int **x);

int** add();

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
    case 1:
        int** result = transpose(x);
        cout << "Z1 = ";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 5; j++) {
                cout << result[i][j] << " ";
            }
        }
        break;
    case 2:
        int** result = add();
        break;
    case 3:
        int** result = multiply();
        break;
    }

    return 0;
}

int** transpose(int **x) {

}

int** add() {

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
