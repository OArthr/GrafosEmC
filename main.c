#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    //Variáveis utilizadas
    int qtd_ver,n;
    int direcionado;
    int i,j;


    do{
        printf("Digite quantos vertices: ");
        scanf(" %d",&qtd_ver);
    }while(qtd_ver<1);

    //Cria uma Lista para cada indice do vetor
    Lista* grafo[qtd_ver];
    for(i=0;i<qtd_ver;i++)
        grafo[i] = criar();

    do{
        printf("Grafo direcionado(1) ou nao direcionado(0)? ");
        scanf(" %d",&n);
    }while(n!=0 && n!=1);
    direcionado = n;

    //Loop para adicionar vizinhos para cada indice de grafo[]
    do{
        //printa o grafo inteiro no formato de lista de adjacencia
        for(i=0;i<qtd_ver;i++){
            printf("|v%-2d|",i);
            printList(grafo[i]);
        }
        do{
            printf("\nDigite um vizinho de v%d(-1 = prox; -2 = fim): ",j);
            scanf(" %d",&n);
        }while(n<-2 || n>=qtd_ver);

        //Insere o vertice escolhido na lista de grafo[j]
        if(n>-1){
            insIni(grafo[j],n);
            if(!direcionado && j!=n)
                insIni(grafo[n],j);
        }
        else j++;

    }while(j<qtd_ver && n!=-2);

    do{
        printf("\nDigite o vertice origem do percurso: ");
        scanf(" %d",&n);
    }while(n<0 || n>=qtd_ver);

    printf("\n\tPercurso recursivo\n");
    percursoRec(grafo,qtd_ver,n);
    printf("\n\tPercurso iterativo\n");
    percursoIte(grafo,qtd_ver,n);
}
