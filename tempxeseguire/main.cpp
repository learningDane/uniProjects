#include <iostream>
#include <random>
using namespace std;

void sort(int *first, int maxNums){
    int min = 0;
    int temp;
    for (int i = 0; i <= maxNums ;i++) {
        for (int j = 1; j <= maxNums-i; j++) {
            if (*(first + i + j) < *(first + min)) {
                min = i +j;
            }
        }
        temp = *(first + i);
        *(first + i) = *(first + min);
        *(first + min) = temp;
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    int min_value = 0;
    int max_value = 99;
    uniform_int_distribution<int> distribution(min_value, max_value);
    int maxNums = distribution(gen);

    int nums[maxNums];

    for (int i = 0; i < maxNums ; i++) {
        nums[i] = distribution(gen);
    }

    for (int i = 0; i <= maxNums ; i++) {
        cout << nums[i] << '\t';
    }
    cout << endl << endl;

    sort(&nums[0],maxNums);

    for (int i = 0; i <= maxNums ; i++) {
        cout << nums[i] << '\t';
    }
}