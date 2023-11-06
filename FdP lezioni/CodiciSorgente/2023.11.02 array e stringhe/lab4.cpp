//scrivere un programma che unisce due vettori
#include <iostream>

using namespace std;

void concatena(const int *v1, const int *v2, int n1, int n2, int *v3) {
    for (int i = 0; i < n1+n2 ; i++) {
        if (i < n1) {*(v3 + i) = *(v1 + i); }
        else { *(v3 + i) = *(v2 + i - n1); }
    }
}

int main() {
    const int v1[2] = {2 , 6};
    const int v2[3] = {3 , 15 , 4};
    int v3[5];

    concatena(&v1[0], &v2[0], 2, 3, &v3[0]);
    for (int i : v3)
    {cout << i << '\t';}
}