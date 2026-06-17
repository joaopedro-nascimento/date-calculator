#include <stdlib.h>
#include "calculos.h"

int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ehbissexto(Data data)
{
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int DmM(Data data, Data data2)
{
    int diferenca;
    diferenca = data.dia - data2.dia;
    if (data.dia < data2.dia)
    {
        diferenca = -diferenca;
    }
    return diferenca;
}

int dma(Data data, Data data2)
{
    int soma = 0;

    if (data.mes > data2.mes)
    {
        for (int i = data2.mes; i <= data.mes; i++)
        {
            soma += diasDoMes[i];
        }
    }

    else
    {
        for (int i = data.mes; i <= data2.mes; i++)
        {
            soma += diasDoMes[i];
        }
    }

    int dia1 = diasDoMes[data.mes] - data.dia;
    int somaDia = dia1 + data2.dia;
    return soma - somaDia;
}

int DmAC(Data data, Data data2)
{
    int soma1 = 0;
    int soma2 = 0;
    int total;

    diasDoMes[2] = ehbissexto(data) ? 29 : 28;
    soma1 = (diasDoMes[data.mes] - data.dia);
    for (int i = data.mes + 1; i <= 12; i++)
    {
        soma1 += diasDoMes[i];
    }

    diasDoMes[2] = ehbissexto(data2) ? 29 : 28;
    for (int i = 1; i < data2.mes; i++)
    {
        soma2 += diasDoMes[i];
    }
    soma2 += data2.dia;
    total = soma1 + soma2;

    if (data.ano > data2.ano)
    {
        total = -total;
    }

    return total;
}

long converterParaDias(Data data)
{
    long total = 0;
    int anosAnteriores = data.ano - 1;

    total = (long)anosAnteriores * 365 + (anosAnteriores / 4) - (anosAnteriores / 100) + (anosAnteriores / 400);

    diasDoMes[2] = ehbissexto(data) ? 29 : 28;
    for (int i = 1; i < data.mes; i++)
    {
        total += diasDoMes[i];
    }

    total += data.dia;

    return total;
}

int DmAQ(Data data, Data data2)
{
    long dias1 = converterParaDias(data);
    long dias2 = converterParaDias(data2);

    return labs(dias2 - dias1);
}

Data descobrirData(long total)
{
    Data dataResultado;
    dataResultado.ano = 1;

    while (1)
    {
        int diasDesteAno = ehbissexto(dataResultado) ? 366 : 365;
        if (total > diasDesteAno)
        {
            total -= diasDesteAno;
            dataResultado.ano++;
        }
        else
        {
            break;
        }
    }
    diasDoMes[2] = ehbissexto(dataResultado) ? 29 : 28;
    dataResultado.mes = 1;

    while (total > diasDoMes[dataResultado.mes])
    {
        total -= diasDoMes[dataResultado.mes];
        dataResultado.mes++;
    }

    dataResultado.dia = (int)total;

    return dataResultado;
}