#include <iostream>
#include "compito.h"

using namespace std;

int main()
{
    cout << "--- PRIMA PARTE ---" << endl;
    cout << "Test del costruttore:" << endl;
    History hist;
    cout << hist << endl;

    cout << "Test della record:" << endl;
    hist.record(503, "aaa");
    hist.record(599, "bbb");
    hist.record(-107, "ccc");
    hist.record(405, "ddd");
    hist.record(711, "eee");
    hist.record(902, "fff");
    cout << hist << endl;

    cout << "Test della forget:" << endl;
    hist.forget("aaa");
    hist.forget("ccc");
    cout << hist << endl;

    cout << "Test del distruttore:" << endl;
    {
        History hist2;
        hist2.record(500, "aaa");
        hist2.record(400, "bbb");
        hist2.record(600, "ccc");
    }
    cout << "(oggetto distrutto)" << endl;

    // SECONDA PARTE
    cout << endl << "--- SECONDA PARTE ---" << endl;
    cout << "Test longest_period:" << endl;
    cout << hist.longest_period() << endl;

    cout << "Test forget overloaded:" << endl;
    hist.forget(500, 750);
    cout << hist << endl;

    cout << "Test create_alternative:" << endl;
    History hist3;
    hist3.record(-75, "ggg");
    hist3.record(507, "hhh");
    hist3.record(753, "iii");
    hist3.record(821, "jjj");
    History *p_hist4 = create_alternative(hist, 450, hist3);
    cout << *p_hist4 << endl;
    delete p_hist4;

    return 0;
}
