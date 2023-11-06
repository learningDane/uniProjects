#include <iostream>
/* Scrivere una funzione restituisciPrimoValorePari(…) che restituisce (se esiste) il primo
valore pari tra tre interi passati come argomento.
Scrivere un programma che legga da tastiera una sequenza di tre interi, chiami la funzione su di
essi, e mostri a video il primo valore pari fra quelli inseriti. Nel caso non ve ne sia neanche uno,
deve stampare a video "Nessun numero pari presente nella sequenza inserita".*/
using namespace std;

int fun(int nums[]) {
    for (int i = 0; i < 3; i++) {
        if (nums[i] % 2 == 0) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    int nums[3];
    for (int &num: nums) {
        cout << "inserire un numero" << endl;
        cin >> num;
    }
    int result = fun(nums);
    if (result >= 0) {
        cout << "il primo numero pari è:" << result;
    } else {
        cout << "nessun numero pari";
    }
}
