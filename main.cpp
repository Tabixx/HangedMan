#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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

    cout << "Witaj w grze Wisielec!" << endl;
    return 0;
}
