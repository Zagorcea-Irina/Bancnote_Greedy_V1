#include <bits/stdc++.h>
using namespace std;

//Tablou unidimensional cu valoarea bancnotelor
int bills[] = { 1, 5, 10, 20, 50, 100, 200, 500, 1000 };
//Aflam lungimea tabloului  sizeof(deno) - lungimea tabloului in intregime in octeti impartim cu lungimea unui element
int bills_size = sizeof(bills) / sizeof(bills[0]);

//functia care returneaza valoarea optima bancnotei, pentru suma indicata, V este parametru care primeste suma
void countBills(int V)
{
    //Initializam vector pentru pastrarea bancnotelor care satisfac criteriilor de selectie
    //Vector poate schimba dinamic dimensiunea/размер, prin aceasta se deosebeste de tablou
    vector<int> optin_bills;

    //Trecem prin toate elementele tabloului, incepem de la element situat pe ultima pozitie, bancnota cu valoare maximă
    for (int i = bills_size - 1; i >= 0; i--) {

        //Verificam dacă bancnota selectată poate participa in formarea sumei
        //Verificam cu ajutorul unui ciclu, pentru suma mai mare bancnota cu valoarea maxima poate fi dublată
        while (V >= bills[i]) { //conditia verifică daca valoarea bancnotei este mai mai mică decat suma
            V -= bills[i]; //Scadem bancnota din suma sau din restul ce a ramas după scadere
            optin_bills.push_back(bills[i]); //Salvam bancnota in vector
        }
    }

    //Afisam vector cu bancnote selectate
    for (int i = 0; i < optin_bills.size(); i++) {
        cout << optin_bills[i] << "  ";
    }
}

int main()
{
    int sum;
    cout << "Introduceti suma b si Enter: ";
    cin >> sum; //Se citeste numarul de la tastatură
    cout << "Suma introdusa " << sum << " poate fi platita cu bancnotele: ";
    countBills(sum);
    return 0;
}
