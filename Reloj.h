// Reloj.h
#include <iostream>
#include <iomanip>

class Reloj
{
public:
    Reloj();
    Reloj(int a, int b);
    void setHora(int h);
    void setMin(int m);
    int getHora();
    int getMin();
    void muestra();
private:
    int hora, minu;
};

void Reloj::setHora(int h)
{
    if (h >= 0 && h<25)
    hora = h;
    else
        hora=0;
}

void Reloj::setMin(int m)
{
    if (m>= 0 && m <=59)
    minu = m;
    else
        minu=0;
}

int Reloj::getHora()
{
    return hora;
}

int Reloj::getMin()
{
    return minu;
}

void Reloj::muestra()
{
    std::cout << std::setw(2) << std::setfill('0') << hora << ":"
    << std::setw(2) << std::setfill('0') << minu << std::endl;
}
