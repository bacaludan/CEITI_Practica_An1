/*
1. Inregistreaza o noua carte;
2. Pune la evidenta un nou cititor;
3. Inregistreaza o noua comanda de imprumutare;
4. Exclude din fisierul Comenzi.txt liniile, ce corespund cartilor restituite;
5. Afiseaza pe ecran seturile de atribute ale tuturor cartilor, editate dupa anul introdus de la tastatura,
ordonandu-le alfabetic dupa numele autorilor;
6. Creeaza fisierul text NuRest.txt, ce va inregistra numele si prenumele abonatilor barbati, care nu au restituit
carti in termenul prestabilit;
7. Determina pretul mediu al unei carti din fondul bibliotecii;
8. Afiseaza pe ecran seturile de atribute ale cartilor cu cea mai mare vechime.
*/

#include <iostream> // PROGRAM NR. 1
#include <fstream>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

//////////////////////////////////////////////////////////////

ifstream fin1 ("Carti.txt");
ifstream fin2 ("Abonati.txt");
ifstream fin3 ("Comenzi.txt");

ofstream fout1 ("CartiOut.txt");
ofstream fout2 ("AbonatiOut.txt");
ofstream fout3 ("ComenziOut.txt");
ofstream fout4 ("NuRest.txt");

//////////////////////////////////////////////////////////////

int nrcarti, nrabonati, nrcomenzi;
char inregistrare;
char evidenta;
char reg;
int numar;
int number;
char regist;
int cititori;
int comenzile;
int an;
char aux[50];
int auxEd;
int codc;
int pretc1;
char yesno;

//////////////////////////////////////////////////////////////

struct a1{

int CodCarte;
char NumAutor[50];
char PrenAutor[50];
char Titlul[50];
int AnEd;
float PretC;

} a11[100];

//////////////////////////////////////////////////////////////

struct a2{

int CodAb;
char NumeAb[50];
char PrenAb[50];
int ziua;
int luna;
int anul;
char Gen[10]; // (m / f)
char AdresaAb[50];

} a22[100];

//////////////////////////////////////////////////////////////

struct a3{

int CodCom;
int CodCarte;
int CodAb;
int ZiuaI;
int LunaI;
int AnulI;
int TermenI; // zile
int ZiuaR;
int LunaR;
int AnulR;

} a33[100];

//////////////////////////////////////////////////////////////

void citire_date1(int n){

for (int i = 0; i < n; i++){

    fin1 >> a11[i].CodCarte;
    fin1 >> a11[i].NumAutor;
    fin1 >> a11[i].PrenAutor;
    fin1 >> a11[i].Titlul;
    fin1 >> a11[i].AnEd;
    fin1 >> a11[i].PretC;

}


}

//////////////////////////////////////////////////////////////

void citire_date2(int n){

for (int i = 0; i < n; i++){

    fin2 >> a22[i].CodAb;
    fin2 >> a22[i].NumeAb;
    fin2 >> a22[i].PrenAb;
    fin2 >> a22[i].ziua;
    fin2 >> a22[i].luna;
    fin2 >> a22[i].anul;
    fin2 >> a22[i].Gen;
    fin2 >> a22[i].AdresaAb;

}


}

//////////////////////////////////////////////////////////////

void citire_date3(int n){

for (int i = 0; i < n; i++){

    fin3 >> a33[i].CodCom;
    fin3 >> a33[i].CodCarte;
    fin3 >> a33[i].CodAb;
    fin3 >> a33[i].ZiuaI;
    fin3 >> a33[i].LunaI;
    fin3 >> a33[i].AnulI;
    fin3 >> a33[i].TermenI;
    fin3 >> a33[i].ZiuaR;
    fin3 >> a33[i].LunaR;
    fin3 >> a33[i].AnulR;

}


}

//////////////////////////////////////////////////////////////

void inregistrare1(int n, int nr){ // inregistreaza cartile

int ii, nn;

cout << " Numarul de carti actuale inregistrate: " << n << endl;

cout << "\n";

ii = n;

nn = ii + nr;

for (int i = ii; i < nn; i++){

    cout << " Codul cartii: ";
    cin >> a11[i].CodCarte;
    cout << " Numele autorului: ";
    cin >> a11[i].NumAutor;
    cout << " Prenumele autorului: ";
    cin >> a11[i].PrenAutor;
    cout << " Titlul cartii: ";
    cin >> a11[i].Titlul;
    cout << " Anul editarii: ";
    cin >> a11[i].AnEd;
    cout << " Pretul cartii: ";
    cin >> a11[i].PretC;

    cout << "\n";

}



}

//////////////////////////////////////////////////////////////

void c_inregistrate(int n, int nr){ // afisarea cartilor ("CartiOut.txt")

int number;

number = n + nr;

for (int i = 0; i < number; i++){

    fout1 << a11[i].CodCarte << " ";
    fout1 << a11[i].NumAutor << " ";
    fout1 << a11[i].PrenAutor << " ";
    fout1 << a11[i].Titlul << " ";
    fout1 << a11[i].AnEd << " ";
    fout1 << a11[i].PretC << " ";

    fout1 << "\n";

}

}

//////////////////////////////////////////////////////////////

void evidenta_cititor(int n, int nr){ // punerea la evidenta

int ii, nn;

cout << " Numarul de persoane inregistrate actuale: " << n << endl;

ii = n;
nn = ii + nr;

cout << "\n";

for (int i = ii; i < nn; i++){

    cout << " Codul persoanei: ";
    cin >> a22[i].CodAb;
    cout << " Numele abonatului: ";
    cin >> a22[i].NumeAb;
    cout << " Prenumele abonatului: ";
    cin >> a22[i].PrenAb;
    cout << " Ziua nasterii: ";
    cin >> a22[i].ziua;
    cout << " Luna nasterii: ";
    cin >> a22[i].luna;
    cout << " Anul nasterii: ";
    cin >> a22[i].anul;
    cout << " Genul persoanei (m / f): ";
    cin >> a22[i].Gen;
    cout << " Adresa: ";
    cin >> a22[i].AdresaAb;

    cout << "\n";

}


}

//////////////////////////////////////////////////////////////

void p_inregistrate(int n, int nr){ // afisarea abonatilor

int number;

number = nr + n;

for (int i = 0; i < number; i++){

    fout2 << a22[i].CodAb << " " << a22[i].NumeAb << " ";
    fout2 << a22[i].PrenAb << " " << a22[i].ziua << " ";
    fout2 << a22[i].luna << " " << a22[i].anul << " ";
    fout2 << a22[i].Gen << " " << a22[i].AdresaAb << " ";

    fout2 << "\n";



}

}

//////////////////////////////////////////////////////////////

void imprumutare(int n, int nr){

int ii, nn;

ii = n;

nn = ii + nr;

for (int i = ii; i < nn; i++){

    cout << " Codul comenzii: ";
    cin >> a33[i].CodCom;
    cout << " Codul cartii: ";
    cin >> a33[i].CodCarte;
    cout << " Codul abonatului: ";
    cin >> a33[i].CodAb;
    cout << " Ziua imprumutarii: ";
    cin >> a33[i].ZiuaI;
    cout << " Luna imprumutarii: ";
    cin >> a33[i].LunaI;
    cout << " Anul imprumutarii: ";
    cin >> a33[i].AnulI;
    cout << " Termenul: ";
    cin >> a33[i].TermenI;
    cout << " Data restituirii: ";
    cin >> a33[i].ZiuaR;
    cout << " Luna restituirii: ";
    cin >> a33[i].LunaR;
    cout << " Anul restituirii: ";
    cin >> a33[i].AnulR;

    cout << "\n";

}


}

//////////////////////////////////////////////////////////////

void c_imprumutate(int n, int nr){ // afisarea

int number;

number = nr + n;

for (int i = 0; i < number; i++){

    fout3 << a33[i].CodCom << " " << a33[i].CodCarte << " ";
    fout3 << a33[i].CodAb << " " << a33[i].ZiuaI << " ";
    fout3 << a33[i].LunaI << " " << a33[i].AnulI << " ";
    fout3 << a33[i].TermenI << " " << a33[i].ZiuaR << " ";
    fout3 << a33[i].LunaR << " " << a33[i].AnulR << " ";

    fout3 << "\n";


}

}

//////////////////////////////////////////////////////////////

void pret_mediu(int n){ // pret mediu al unei carti

int suma = 0;

int nn;


for (int i = 0; i < n; i++){

    suma += a11[i].PretC;

}

    int media;

    media = suma / n;

    cout << media;

}

//////////////////////////////////////////////////////////////

void vechime_carti(int n){ // cartile cu cea mai mare vechime

int vech;
int numar;

vech = a11[0].AnEd;

for (int i = 1; i < n; i++){

    if (a11[i].AnEd < vech){

        vech = a11[i].AnEd;
        numar = i;

    }


}

cout << " Cartea cu cea mai mare vechime: " << a11[numar].CodCarte << " ";
cout << a11[numar].NumAutor << " " << a11[numar].PrenAutor << " ";
cout << a11[numar].Titlul << " " << a11[numar].AnEd << " ";
cout << a11[numar].PretC << endl;

}

//////////////////////////////////////////////////////////////

void c_disponibile(int n){ // afisarea cartilor disponibile

for (int i = 0; i < n; i++){

    cout << " " << a11[i].CodCarte << " ";
    cout << a11[i].NumAutor << " ";
    cout << a11[i].PrenAutor << " ";
    cout << a11[i].Titlul << " ";
    cout << a11[i].AnEd << " ";
    cout << a11[i].PretC << " ";

    cout << "\n";

}

}

//////////////////////////////////////////////////////////////

void c_restituite(int n){ // excluderea cartilor rest

for (int i = 0; i < n; i++){

    if (a33[i].LunaI < a33[i].LunaR || a33[i].AnulI < a33[i].AnulR){

        a33[i].CodCom = 0;
        a33[i].CodCarte = 0;
        a33[i].CodAb = 0;
        a33[i].ZiuaI = 0;
        a33[i].LunaI = 0;
        a33[i].AnulI = 0;
        a33[i].TermenI = 0;
        a33[i].ZiuaR = 0;
        a33[i].LunaR = 0;
        a33[i].AnulR = 0;

    }

}

}

//////////////////////////////////////////////////////////////

void afisareC_restituite(int n){ // cartile restituite

for (int i = 0; i < n; i++){

    if (a33[i].TermenI != 0){ // orice valoare diferita de 0

        fout3 << a33[i].CodCom << " " << a33[i].CodCarte << " ";
        fout3 << a33[i].CodAb << " " << a33[i].ZiuaI << " ";
        fout3 << a33[i].LunaI << " " << a33[i].AnulI << " ";
        fout3 << a33[i].TermenI << " " << a33[i].ZiuaR << " ";
        fout3 << a33[i].LunaR << " " << a33[i].AnulR << " ";

        fout3 << "\n";

    }

}

}

//////////////////////////////////////////////////////////////

void editare_carti(int n, int nr){

for (int i = 0; i < n - 1; i++)
for (int j = i + 1; j < n; j++){

    if (strcmp(a11[i].NumAutor, a11[j].NumAutor) > 0){

        strcpy (aux, a11[i].NumAutor);
        strcpy (a11[i].NumAutor, a11[j].NumAutor);
        strcpy (a11[j].NumAutor, aux);

        strcpy (aux, a11[i].PrenAutor);
        strcpy (a11[i].PrenAutor, a11[j].PrenAutor);
        strcpy (a11[j].PrenAutor, aux);

        strcpy (aux, a11[i].Titlul);
        strcpy (a11[i].Titlul, a11[j].Titlul);
        strcpy (a11[j].Titlul, aux);

        auxEd = a11[i].AnEd;
        a11[i].AnEd = a11[j].AnEd;
        a11[j].AnEd = auxEd;

        codc = a11[i].CodCarte;
        a11[i].CodCarte = a11[j].CodCarte;
        a11[j].CodCarte = codc;

        pretc1 = a11[i].PretC;
        a11[i].PretC = a11[j].PretC;
        a11[j].PretC = pretc1;

    }

}

}

//////////////////////////////////////////////////////////////

void afisareE_carti(int n, int nr){

for (int i = 0; i < n; i++){

    if (a11[i].AnEd > nr){

        cout << a11[i].CodCarte << " " << a11[i].NumAutor << " ";
        cout << a11[i].PrenAutor << " " << a11[i].Titlul << " ";
        cout << a11[i].AnEd << " " << a11[i].PretC << " ";

        cout << "\n";

    }

}

}

//////////////////////////////////////////////////////////////

void afisareC_restituiteCOUT(int n, int nr){ // cartile restituite

int aux;

for (int i = 0; i < n; i++){

    if (a33[i].TermenI != 0){ // orice valoare diferita de 0

        fout4 << " Cartea nerestituita: ";
        fout4 << a33[i].CodCom << " " << a33[i].CodCarte << " ";
        fout4 << a33[i].CodAb << " " << a33[i].ZiuaI << " ";
        fout4 << a33[i].LunaI << " " << a33[i].AnulI << " ";
        fout4 << a33[i].TermenI << " " << a33[i].ZiuaR << " ";
        fout4 << a33[i].LunaR << " " << a33[i].AnulR << " ";

        fout4 << "\n";

        aux = i;

        fout4 << " Nu a restituit cartea a " << aux << " - a persoana, lista fiind: " << endl;

        fout4 << "\n";

        for (int i = 0; i < nr; i++){

            fout4 << " " << a22[i].NumeAb << " " << a22[i].PrenAb << " ";
            fout4 << "\n";

        }

    }



}

}





//////////////////////////////////////////////////////////////

void afisare(){

fin1 >> nrcarti;
fin2 >> nrabonati;
fin3 >> nrcomenzi;

citire_date1(nrcarti);
citire_date2(nrabonati);
citire_date3(nrcomenzi);

cout << "\n";

cout << " Numarul ales: ";
cin >> numar;

cout << "\n";

switch (numar){

case 1: {

    cout << " Doriti sa inregistrati o noua carte? (+ / -): ";
    cin >> regist;

    if (regist == '+'){

    cout << " Cate carti doriti sa inregistrati?: ";
    cin >> number;

    inregistrare1(nrcarti, number);
    c_inregistrate(nrcarti, number);

    }
break;}

case 2: {

    cout << " Doresti sa inregistrezi un nou cititor? (+ / -): ";
    cin >> evidenta;

if (evidenta == '+'){

    cout << " Cati cititori doresti sa inregistrezi?: ";
    cin >> cititori;

    evidenta_cititor(nrabonati, cititori);
    p_inregistrate(nrabonati, cititori);

}; break;}

case 3: {

    cout << " Doresti sa inregistrezi o noua comanda de imprumutare? (+ / -): ";
    cin >> reg;

if (reg == '+'){

    cout << " Cate comenzi de imprumutari doresti sa faci?: ";
    cin >> comenzile;

    cout << "\n";

    cout << " Cartile disponibile sunt: " << endl;
    c_disponibile(nrcarti);

    cout << "\n";


    imprumutare(nrcomenzi, comenzile);
    c_imprumutate(nrcomenzi, comenzile);

}; break; }

case 4: {vechime_carti(nrcarti); break;}

case 5: {

cout << " Pretul mediu al unei carti: ";
pret_mediu(nrcarti);
cout << " lei.";
break;

}

case 6: {

c_restituite(nrcomenzi);
afisareC_restituite(nrcomenzi);

cout << " Modificarile au fost salvate in fisierul 'ComenziOut.txt" << endl;

break;

}

case 7: {

cout << " Cartile editate dupa anul introdus de la tastatura: ";
cin >> an;

editare_carti(nrcarti, an);
afisareE_carti(nrcarti, an);
break;

}

case 8: {

c_restituite(nrcomenzi);
afisareC_restituiteCOUT(nrcomenzi, nrabonati);

cout << "Modificarile au fost salvate in fisierul 'NuRest.txt'.";

break;

}

default : cout << " Nu ai ales un numar potrivit.";

}

cout << "\n";

cout << " Doresti sa verifici alt rezultat? (Y / N): ";
cin >> yesno;

if ((yesno == 'Y') || (yesno == 'y')){

    afisare();

}

}

//////////////////////////////////////////////////////////////

int main(){

cout << "\n";

cout << " |-------------------------------------------------------------------------|" << endl;
cout << " |                             CEITI B-2012                                |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " |                                                                         |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '1' pentru inregistrarea cartilor.                                |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '2' pentru punerea la evidenta a unui nou cititor.                |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '3' pentru o noua comanda de imprumutare.                         |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '4' pentru afisarea cartii cu cea mai mare vechime.               |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '5' pentru afisarea pretului mediu al cartilor.                   |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '6' pentru excluderea din fisier 'Comenzi.txt' al cartilor rest.  |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '7' pentru afisarea cartilor editate dupa anul introdus.          |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;
cout << " | Tasta '8' pentru afisarea numelui barbatilor ce nu au rest. cartea.     |" << endl;
cout << " |-------------------------------------------------------------------------|" << endl;

afisare();

fin1.close();
fin2.close();
fin3.close();

fout1.close();
fout2.close();
fout3.close();

return 0;

}
