#include <iostream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include"scena.hh"

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  char c;

  Lacze.DodajNazwePliku("bryly/graniastoslup-osX.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-4, 10);
  Lacze.UstawZakresY(-9, 9);
  Lacze.UstawZakresZ(-2, 9);


  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
  cout << "Nacisnij ENTER, aby zobaczyc prostopadloscian nr 2 ... " << flush;
  cin >> noskipws >> c;

  Lacze.UsunWszystkieNazwyPlikow();
  Lacze.DodajNazwePliku("bryly/prostopadloscian2.dat");
  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian2.dat"

  cout << "Nacisnij ENTER, aby zobaczyc prostopadloscian nr 3 ... " << flush;
  cin >> noskipws >> c;

  Lacze.UsunWszystkieNazwyPlikow();
  Lacze.DodajNazwePliku("bryly/prostopadloscian3.dat");
  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian3.dat"

  cout << "Nacisnij ENTER, aby zakonczyc ... " << flush;
  cin >> noskipws >> c;

}
