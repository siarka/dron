#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "SWektor.hh"
    /**
     * klasa dziedziczona z szablonu SWektor , tworzy 3 wspolczynniki double w wektorze
     */
class wektor3D : public SWektor<double,3>{
    /**
     *  pole z liczba stooonych wektorow
     */
    static int stwozone;
     /**
     * pole z liczba zniszczonch wektorow
     */
    static int zniszczone;

    public:
    /**
     * metoda zwraca ile stwozono wektorw
     */
    int ilestworzono(){return stwozone;}
    /**
     * metoda zwraca ile jest obecnie wektorw
     */
    int ileobecnie(){return stwozone-zniszczone;}
     /**
     * Konstruktor pustego wektora3D.
     */
    wektor3D() : SWektor<double,3>() {stwozone++;}
     /**
     * Konstruktor parametryczny wektora3D.
     */
    wektor3D(double x,double y,double z) : SWektor<double,3>(){(*this)[0]=x;(*this)[1]=y;(*this)[2]=z;}
     /**
     * Konstruktor kopiujący wektora3D.
     */
    wektor3D(const SWektor &w){(*this) = w; stwozone++;}
     /**
     * Konstruktor kopiujący wektora3D.
     */
    wektor3D(const SWektor<double, 3> &m) : SWektor<double, 3>(m) {stwozone++;}
     /**
     * Destruktor wektora3D.
     */
    ~wektor3D(){zniszczone++;}
    
};
#endif