// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;

int** transpose(int **x, int r);

int** add(int **x, int r);

int** multiply(int **xT);

class SparseMatrix {

    //max possible elements
    const static int MAX = 100;

private:
    int** data;
    int row;
    int col;

    //num elems
    int len;

public:
    //convert normal matrix to sparse matrix
    SparseMatrix(int** z, int row, int col) {
        this->row = row;
        this->col = col;
        this->len = 0;

        //initialize matrix
        data = new int*[MAX];
        for (int idx = 0; idx < MAX; idx++) {
            data[idx] = new int[3]{ };
        }

        //add values from regular matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (z[i][j] != 0) {
                    data[len][0] = i;
                    data[len][1] = j;
                    data[len][2] = z[i][j];
                    len++;
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < len-1; i++) {
            cout << data[i][0] << " " << data[i][1] << " " << data[i][2] << " ";
        }
        cout << data[len-1][0] << " " << data[len-1][1] << " " << data[len-1][2];
    }

    int** getData() {
        return data;
    }

    int getLength() {
        return len;
    }
};

int main()
{
    //get method to run n
    int n;
    cin >> n;

    //get num elements r
    int r;
    cin >> r;

    //get x matrix
    int** x = new int*[r];
    for (int i = 0; i < r; i++) {
        x[i] = new int[3];
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    }


    //run the method
    switch (n) {
        case 1: {
            int** z1 = transpose(x, r);

            cout << "Z1 = ";
            SparseMatrix output(z1, 8, 5);
            output.print();
            
            break;
        }
        case 2: {
            int** z2 = add(x, r);
            cout << "Z2 = ";
            SparseMatrix output(z2, 5, 8);
            output.print();

            break;
        }
        case 3: {
            int** xT = transpose(x, r);
            int** z3 = multiply(xT);
            cout << "Z3 = ";
            SparseMatrix output(z3, 8, 8);
            output.print();

            break;
        }
        default: {
            cout << "invalid test case" << endl;
            break;
        }
    }

    return 0;
}

int** transpose(int **x, int r) {
    
    //initialize result matrix to zero
    int** z1 = new int*[8];
    for (int idx = 0; idx < 8; idx++) {
        z1[idx] = new int[5]{ };
    }

    //loop through given array
    for (int i = 0; i < r; i++) {
        //place the value into the corresponding location
        z1[x[i][1]][x[i][0]] = x[i][2];
    }

    return z1;
}

int** add(int **x, int r) {

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
        z2[idx] = new int[8]{ };
    }

    //add from x matrix
    for (int i = 0; i < r; i++) {
        z2[x[i][0]][x[i][1]] += x[i][2];
    }

    //add from y matrix
    for (int i = 0; i < 10; i++) {
        z2[y[i][0]][y[i][1]] += y[i][2];
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
        z3[idx] = new int[8]{ };
    }

    //multiply matrices
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //take dot product
            for (int k = 0; k < 5; k++) {
                z3[i][j] += xT[i][k] * y[k][j];
            }
        }
    }

    return z3;
}

