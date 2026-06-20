//calculos.h
#ifndef calculos
#define calculos

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int DmM(Data data, Data data2);
int DmA(Data data, Data data2);
int DmAC(Data data, Data data2);
long converterParaDias(Data data);
int DmAQ(Data data, Data data2);
Data descobrirData(long total);
int ehbissexto(Data data);

#endif