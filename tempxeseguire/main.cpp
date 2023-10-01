#include <iostream>
using namespace std;

int n = 0;
int x = 0; // il numero equivalente alla lettera
string s = "MCMXCIV";


int check(int n1)
{
    if (s.at(n1) == 'M') { x = 1000; }
    else if (s.at(n1) == 'D') { x = 500; }
    else if (s.at(n1) == 'C') { x = 100; }
    else if (s.at(n1) == 'L') { x = 50; }
    else if (s.at(n1) == 'X') { x = 10; }
    else if (s.at(n1) == 'V') { x = 5; }
    else if (s.at(n1) == 'I') { x = 1; }
    else { cout << "error, insert only Roman Numbers (Capitalized)" << endl; }
    return x;
}

int main()
{
    int tot = 0;
    int prec = 0; // il numero della lettera precedente
    for (n = 0; n < s.length(); n++)
    {
        x = check(n);
        if (prec >= x)
        {
            tot = tot + x;
        }
        else {tot = tot + x - 2 * prec;}
        prec = x;
    }
    cout << tot << endl;
}