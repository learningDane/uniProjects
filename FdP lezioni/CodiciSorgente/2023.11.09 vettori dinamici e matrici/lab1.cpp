//crea un vettore dinamico con gli elementi negativi di un altro vettore
#include <iostream>
using namespace std;

void componentiNegative(const int vec[]) {
    int sizeVec = 6;
    int sizeResult = 0;
    for (int i = 0; i < sizeVec ; i++) {
        if (vec[i] < 0) {
            sizeResult++;
        }
    }

    int *result = new int[sizeResult];
    int temp = 0;
    for (int i = 0; i < sizeVec ; i++) {
        if (vec[i] < 0) {
            result[temp] = vec[i];
            temp++;
        }
    }

    for (int i = 0; i < sizeResult; i++) {
        cout << result[i] << '\t';
    }
    delete[] result;
}

int main() {
    int vec[]={11,-22,4,-3,18,-1};
    componentiNegative(vec);
}