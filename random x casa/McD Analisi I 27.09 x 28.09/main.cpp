#include <iostream>
using namespace std;

int main() {

    int n1;
    int n2;
    int q;
    int r;
    int mcd;

    start: // this is a label

    number1:
    cout << "Insert first number" <<endl;
    cin >> n1;
    if (n1<=0) {
        cout<<"number must be positive"<< endl;
        goto number1;}

    number2:
    cout<< "insert second number (must be smaller than first)" << endl;
    cin >> n2;
    if (n2<=0) {
        cout<<"number must be positive"<< endl;
        goto number2;}
    else if (n2>n1) {
     cout<< "Second number must be smaller than first! "<< endl;
     goto start;
    }

    mcd:

    q = n1/n2;
    r = n1%n2;
    if (r==0) {
        mcd = n2;
        cout << "the McD is " << mcd << " !" << endl;
        return 0;
    }
    else {
        n1 = n2;
        n2 = r;
        goto mcd;
    }

}
