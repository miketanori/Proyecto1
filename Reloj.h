// Reloj.h
#include <iostream>
#include <iomanip>

class Reloj
{
public:
    Reloj();
    Reloj(int a, int b);
    void setHora(int){hora = ((h>=0 && h<25) ? h : 0);};
    void setMin(int m){minu = ((m>=0 && m<=59) ? m : 0);};
    int getHora();
    int getMin();
    void muestra();
private:
    int hora, minu;
};

Reloj:: Reloj(){
    hora = 0;
    minu = 0; 
}

Reloj:: Reloj(int a, int b){
    hora = a;
    minu = b; 
}

/*void Reloj::setHora(int h)
{
    //if (h >= 0 && h<25)
        hora = ((h>=0 && h<25) ? h : 0);
    else
        hora=0;*/
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
