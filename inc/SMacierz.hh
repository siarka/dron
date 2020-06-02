#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "SWektor.hh"
#include <iostream>


/*
 *  Macierz to klasa ktora przechowuje wspolczynniki w tym zadaniu
 *  jest reprzentowana tablica o wymiarze ROZMIAR na ROZMIAR
 * Odwolywanie do poszczegulnych pol nastepuje przez nawiasy okragle
 */
template <typename STyp, int SWymiar>
class SMacierz {
  SWektor< STyp , SWymiar > M[SWymiar];
  public:
  
  const STyp operator( ) (unsigned int Wi, unsigned int Ko) const {return M[Ko][Wi];} 
  STyp &operator( ) (unsigned int Wi, unsigned int Ko) {return M[Ko][Wi];}

  SWektor<STyp,SWymiar>  operator * (const SWektor<STyp,SWymiar> &we) const;
  STyp W()const;
  STyp T()const;
};

/*
 * funkcja zawaca wyznacznik macierzy
 */
template <typename STyp, int SWymiar>
 STyp SMacierz<STyp,SWymiar> ::W() const
{
SMacierz<STyp,SWymiar> Temp=(*this);
SWektor <STyp,SWymiar> wek;
STyp wyznacznik,a;
  
  for( int i=0 ; i< SWymiar-1 ; i++)
  {
     a=(Temp.wektor(i+1)[i])/(Temp.wektor(i)[i]);
    for(int x=0 ; x<SWymiar ; x++){
      Temp(i+1,x)=Temp(i+1,x)-(Temp(i,x)*a);
    }
  }
  wyznacznik=1.0 ;
  for(int i=0; i<SWymiar; i++)
    wyznacznik = wyznacznik * Temp(i,i);

return wyznacznik;
}

/*
 * To przeciarzenie pozwala na mnozenie maciezy i wektora
 */
template <typename STyp, int SWymiar>
 SWektor<STyp,SWymiar>  SMacierz<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &we) const
{ 
    SWektor<STyp,SWymiar> odp;
   
    for ( int i=0 ; i< SWymiar ; i++)
    {
      for(int x =0 ; x<SWymiar ; x++)
       odp[i]=odp[i]+we[x]*(*this)(i,x);
    }
    
    return odp;
}

/*
 * To przeciarzenie wypisuje na wyjsciu zawartosc macierzy 
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp,SWymiar> &Mac)
{
  for (int i= 0; i< SWymiar ; i++) 
  { 
    for(int j = 0; j < SWymiar; j++)
    {
      Strm<<Mac(i,j)<<" ";
    }
    
   Strm<<std::endl;
  }
  return Strm;
}
/*
 * To przeciarzenie pobiera na wejściu zawartosc macierzy 
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp,SWymiar> &Mac)
{
  for (int i= 0; i< SWymiar ; i++) 
  { 
    for(int j = 0; j < SWymiar; j++)
    {
      Strm>>Mac(i,j);
    }
    
   
  }
  return Strm;
}

#endif
