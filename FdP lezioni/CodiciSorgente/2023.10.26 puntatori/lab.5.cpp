#include <iostream>
/*Scrivere la fuzione calcolaStatistiche(…) che, dati tre interi in ingresso, restituisca tre
valori: il minimo, il massimo, ed il valor medio (quest'ultimo deve essere un valore reale, non
intero).*/

using namespace std;

void calcola(int nums[], int *min, int *max, float *med) {
    for (int i = 1; i < 3; i++) {
        if (nums[i] < *min) {
            *min = nums[i];
        }
    }
    for (int i = 1; i < 3; i++) {
        if (nums[i] > *max) {
            *max = nums[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        *med += nums[i];
    }
    *med /= 3;
}

int main() {
    int min, max;
    float med = 0;
    int nums[3];
    for (int i = 0; i < 3; i++) {
        cout << "inserire un numero" << endl;
        cin >> nums[i];
    }
    min = nums[0], max = nums[0];
    calcola(nums, &min, &max, &med);
    cout << min << '\t' << max << '\t' << med;
}
