#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main()
{
//Primeiro bloco - entrada do valor e validação
printf("Programa de validacao de numero de cartao de credito\n");
int valida1;
char cartao[256];
char bandeira[256]="";
do{
    valida1=0; //Variavel para validacao de entrada
    char entrada[256];
    char mensagem[256]=" ";
    printf("\nEntre com um numero valido de cartao de credito: ");
    gets(entrada);
    int temp, cont2=0;
    //percorre a string a procura de valores diferentes de numeros
    for (int cont=0;cont<strlen(entrada);cont++){
        temp=entrada[cont]-'0';//conversao para int para o teste
        if(temp < 0 || temp > 9){
                valida1++;
                //concatena os caracteres nao permitidos para apresentacao
                mensagem[cont2]=entrada[cont];
                cont2++;
                mensagem[cont2]=' ';
                cont2++;
            }
            fflush(stdin); //limpa as entradas
    }
    if(strlen(mensagem) > 1){
        printf("\n\nEntrada incorreta: caracter(es) invalido(s): %s\n",mensagem); // exibe os caracteres invalidos da entrada

    }
    //Verifica se aoperadora é valida
    else{
        char temp[3]=" ";
        int op;
        for (int cont=0;cont<2;cont++){
        temp[cont]=entrada[cont];
       }
       op = atoi(temp);
       if(op < 34 || op > 55){
            printf("\n\nOperadora incorreta. Tente novamente!\n");
            valida1++;
       }
       else if ((temp[0]-'0') == 4){
            strcpy(bandeira,"Visa");
       }else if(op == 34 || op == 37){
            strcpy(bandeira,"AMEX");
       }else if(op > 50 && op < 56){
            strcpy(bandeira,"Master Card");
       }else{
            printf("\n\nOperadora incorreta. Tente novamente!\n");
            valida1++;
       }
    }
    printf("operadora %s",bandeira);
    fflush(stdin); //limpa as entradas
}while(valida1>0);

}
