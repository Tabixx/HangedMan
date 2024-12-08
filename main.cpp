#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string wybierzSlowo(const vector<string>& slowa);

int main() {
    vector<string> slowa;
ifstream plik("words.txt");
string slowo;

while (getline(plik, slowo)) {
    slowa.push_back(slowo);
}
plik.close();
if (slowa.empty()) {
    cout << "Brak dostepnych slow do gry." << endl;
    return 1;
}

string haslo = wybierzSlowo(slowa);
string ukryte(haslo.length(), '_');
int punkty = 0, proby = 0;
bool wygrana = false;
time_t czasStart = time(0);

    cout << "Witaj w grze Wisielec!" << endl;
    return 0;
}
 while (proby < 7 && !wygrana) {
    cout << "\nHaslo: " << ukryte << endl;
    rysujWisielca(proby);

    char litera;
    cout << "Podaj litere: ";
    cin >> litera;

    if (haslo.find(litera) != string::npos) {
        for (size_t i = 0; i < haslo.length(); ++i) {
            if (haslo[i] == litera) {
                ukryte[i] = litera;
            }
        }
        if (ukryte == haslo) {
            wygrana = true;
        }
    }
    else {
        proby++;
    }
}

if (wygrana) {
    cout << "\nWoo! Gratulacje! Zgadles haslo!! " << haslo << endl;
    aktualizujPunkty(punkty, proby, czasStart);
}
else {
    cout << "\nHaha! Przegrales! Haslo to: " << haslo << endl;
}