#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main()
{
printf("Programa de validacao de numero de cartao de credito\n");
int valida1;
char cartao[256];
char bandeira[256]="";
char multiplicacoes[256]=" ";
char nMultiplicados[256]=" ";
int verificador;
do{
    //Primeiro bloco - entrada do valor e validação
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
    //Verifica se a operadora é valida
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
    //Calculo dos dígitos a serem multiplicados
    if (valida1==0){
        int temp1;
        char temp2[3];
        int controle=0;
        for (int cont3=(strlen(entrada)-2);cont3>=0;cont3--){
            temp1=(entrada[cont3]-'0')*2;
            sprintf(temp2, "%i", temp1);// inteiro temp1 para a string temp2
            if (controle==0){
                strcpy(multiplicacoes,temp2);
                controle++;
                 cont3--;
            }
            else{
                strcat(multiplicacoes,temp2);
                 cont3--;
            }
        }
        int soma1=0;
        for(int cont4=0;cont4<strlen(multiplicacoes);cont4++){
            soma1=soma1+(multiplicacoes[cont4]-'0');
        }
        //Calculo da soma dos demais numeros
        controle=0;
        for (int cont3=(strlen(entrada)-1);cont3>=0;cont3--){
            temp1=(entrada[cont3]-'0');
            sprintf(temp2, "%i", temp1);// inteiro temp1 para a string temp2
            if (controle==0){
                strcpy(nMultiplicados,temp2);
                controle++;
                 cont3--;
            }
            else{
                strcat(nMultiplicados,temp2);
                 cont3--;
            }
        }
        int soma2=0;
        for(int cont4=0;cont4<strlen(nMultiplicados);cont4++){
            soma2=soma2+(nMultiplicados[cont4]-'0');
        }
        verificador=soma2+soma1;
    }
    if (verificador%10==0){
        printf("operadora %s",bandeira);
    }
    else {
        printf("INVÁLIDO");
    }

    fflush(stdin); //limpa as entradas
}while(valida1>0);

}
