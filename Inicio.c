#include <stdio.h>

int main()
{
    typedef struct
    {
        int dia;
        int mes;
        int ano;
    } Data;

    Data data;
    printf("informe uma data em formato dd/mm/aaaa\n");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    printf("%d/%d/%d", data.dia, data.mes, data.ano);
}