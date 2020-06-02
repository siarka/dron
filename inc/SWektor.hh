#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>


/*
 *  Klast ta opisuje macierz a wymiarach 1 na ROZMIAR
 * ma za zadanie opisać wektory  w tym zadaniu 
 * reprezetowan tablica jedno wymiarowa wielkości ROZMIAR
 * 
 */
template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &dod) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
};


/*
 * przeciazenie operatora pozwalajace na odjmowanie dwuch wektorow
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &dod) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + dod[Ind];
  return Wynik;
}


/*
 * przeciąenie operatora mnozenia pozwala na monozenie wektora przez liczba 
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

/*
 * wypisuje wektor na wyjściu
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " "<<W[Ind];
  }  
  return StrmWyj;
}
/*
 * pobiera z wejście wektor
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek)
{
    for (int i = 0; i < SWymiar; i++)
    {
        Strm>>Wek[i];
    }
    return Strm;
}
#endif
