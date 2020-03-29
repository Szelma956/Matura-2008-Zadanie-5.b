// Matura-2008-Zadanie-5.b.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
using namespace std;

string reverse(string napis) {
    string s = "";
    for (int n = napis.length() - 1; n >= 0; n--) {
        char znak = napis[n];
        s = s + znak;
    }
    return s;

}

string generator(string slowo) {
    int max_dlug = slowo.length();
    for (int dlug = max_dlug; dlug >= 1; dlug--) {
        string w1;
        w1 = slowo.substr(0, dlug);
        if (w1 == reverse(w1)) {
            string w2;
            w2 = slowo.substr(dlug);
            return reverse(w2) + slowo;
        }
    }
    return "";
}
const int ROZMIAR_SLOWA = 1000;
string slowa[ROZMIAR_SLOWA];

int main()
{
    ifstream plik("slowa.txt");
    ofstream hasla("hasla_b.txt"), stat("slowa_b.txt");
    string max_has = "";
    string min_has = "";
    int dlug_w_has = 0;
    stat << "1." << '\n';
    for (int licznik = 0; !plik.eof() && licznik < ROZMIAR_SLOWA; licznik++) {

        plik >> slowa[licznik];
    }
    for (int i = 0; i < ROZMIAR_SLOWA; i++) {
        string haslo = generator(slowa[i]);
        dlug_w_has = dlug_w_has + haslo.length();
        if (haslo.length() == 12)
            stat << haslo << '\n';
        if (max_has.length() < haslo.length()) {
            max_has = haslo;
        }
        if (min_has.length() > haslo.length() || min_has == "") {
            min_has = haslo;
        }
        hasla << haslo << '\n';
    }
    stat << "2.\n";
    stat << max_has << '\n' << min_has << '\n';
    stat << "3.\n";
    stat << dlug_w_has << '\n';
    return 0;
}
