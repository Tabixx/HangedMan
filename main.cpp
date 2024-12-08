#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

string wybierzSlowo(const vector<string>& slowa);
void rysujWisielca(int proby);

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

    string gracz;
    cout << "Podaj swoje imie: ";
    cin >> gracz;

    string haslo = wybierzSlowo(slowa);
    string ukryte(haslo.length(), '_');
    int punkty = 0, proby = 0;
    bool wygrana = false;
    time_t czasStart = time(0);

    cout << "Witaj w grze Wisielec!" << endl;

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

    zapiszWynik(gracz, punkty);
    pokazNajlepszeWyniki();
    return 0;
}

string wybierzSlowo(const vector<string>& slowa) {
    srand(time(0));
    return slowa[rand() % slowa.size()];
}

void rysujWisielca(int proby) {
    const vector<string> rysunki = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };
    cout << rysunki[proby] << endl;
}

