//stampa una matrice quadrata di lato n=3 e ne stampa la moltiplicazione per un vettore inserito
#include <iostream>

using namespace std;

int *moltipMatVec(const int mat[], const int vec[], int n) {
    int *vecResult = new int[n];
    for (int i = 0; i < 3; i++) {
        vecResult[i] = 0;
        for (int j = 0; j < n; j++) {
            vecResult[i] += mat[i * n + j] * vec[j];
        }
    }
    return vecResult;
}

void stampa(int mat[], int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << mat[i * k + j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n = 3;
    int mat[n * n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i * n + j] = i * n + j + 1;
        }
    }
    stampa(mat, n, n);
    int vec[n];
    for (int i = 0; i < n; i++) {
        cout << "inserire elementi del vettore:";
        cin >> vec[i];
        cout << endl;
    }
    moltipMatVec(mat, vec, n);
    int *veccc = new int[n];
    veccc = moltipMatVec(mat, vec, n);
    stampa(veccc, n, 1);
}