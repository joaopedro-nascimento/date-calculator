#include <stdio.h>
#include <locale.h>

typedef struct
    {
        int dia;
        int mes;
        int ano;
    } Data;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Data data;
    do{
        printf("informe uma data em formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    }while(!validarData(data));

    printf("A data é em %d/%d/%d", data.dia, data.mes, data.ano);
}

int validarData(Data data){
    if(data.dia<=0||data.dia>31){
        return 0;
    }
    if(data.mes<=0||data.mes>12){
        return 0;
    }
    if(data.ano<=0){
        return 0;
    }
    return 1;
}