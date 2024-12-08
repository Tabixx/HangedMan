#include <iostream>
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



    cout << "Witaj w grze Wisielec!" << endl;
    return 0;
}
