#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

string wybierzSlowo(const vector<string>& slowa);
void rysujWisielca(int proby);
void aktualizujPunkty(int& punkty, int proby, time_t czasStart);
void zapiszWynik(const string& gracz, int punkty);
void pokazNajlepszeWyniki();

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

void aktualizujPunkty(int& punkty, int proby, time_t czasStart) {
    time_t czasKoniec = time(0);
    int czasGry = static_cast<int>(difftime(czasKoniec, czasStart));
    punkty += max(0, 100 - proby * 10 - czasGry);
}

void zapiszWynik(const string& gracz, int punkty) {
    ofstream plik("highscores.txt", ios::app);
    plik << gracz << " " << punkty << endl;
    plik.close();
}

void pokazNajlepszeWyniki() {
    ifstream plik("highscores.txt");
    string linia;

    cout << "\nNajlepsze wyniki:" << endl;
    while (getline(plik, linia)) {
        cout << linia << endl;
    }
    plik.close();
}
