#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct elemento{
    int vn;
    struct elemento* prox;
}Elemento;

Lista* criar(){
    Lista* ldse;
    ldse = (Lista*)malloc(sizeof(Lista));
    if (ldse)
        *ldse = NULL;
    return ldse;
}

int insIni(Lista* ldse, int n){
    if (!ldse)
        return 0;
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if(!novo)
        return 0;
    novo->vn = n;
    novo->prox = *ldse;
    *ldse = novo;
    return 1;
}

int remIni(Lista* ldse){
    if(!ldse)
        return 0;
    Elemento* aux = *ldse;
    *ldse = aux->prox;
    free(aux);
    return 1;
}

int printList(Lista* ldse){
    if(!ldse)
        return 0;
    Elemento* aux = *ldse;
    printf(" -> ");
    while(aux){
        printf("v%-2d -> ",aux->vn);
        aux = aux->prox;
    }
    printf("||\n");
    return 1;
}

int acessPrim(Lista* ldse, int* vn){
    if(!ldse || !(*ldse))
        return 0;

    *vn = (*ldse)->vn;
    return 1;
}

void visitaVer(Lista* grafo[],int v,int marca[]){
    Elemento* u = *(grafo[v]);
    while(u){
        if(marca[u->vn]==0){
            printf("Visitou v%-2d\n",u->vn);
            marca[u->vn]=1;
            visitaqtd_ver(grafo,u->vn,marca);
        }
        u = u->prox;
    }
    printf("Percorreu v%-2d\n", v);
    marca[v] = 2;
}

int percursoRec(Lista* grafo[],int qtd_ver,int v){
    for(int i=0;i<qtd_ver;i++)
        if(!grafo[i]) return 0;

    int marca[qtd_ver];
    for(int i=0;i<qtd_ver;i++)
        marca[i]=0;

    marca[v]=1;
    printf("Visitou v%-2d\n",v);
    visitaVer(grafo,v,marca);

    /*
    for(int i=0;i<qtd_ver;i++)
        printf("%d ",marca[i]);
    */
    return 1;
}

int percursoIte(Lista* grafo[],int qtd_ver, int v){
    for(int i=0;i<qtd_ver;i++)
        if(!grafo[i]) return 0;

    int marca[qtd_ver];
    for(int i=0;i<qtd_ver;i++)
        marca[i]=0;

    marca[v]=1;
    Lista* pilha = criar();
    insIni(pilha,v);
    printf("Visitou v%-2d\n",v);

    int topo=0;
    while(*pilha){
        acessPrim(pilha,&topo);
        Elemento* u = *(grafo[topo]);
        while(u && marca[u->vn]!=0)
            u = u->prox;
        if(!u){
            printf("Percorreu v%-2d\n",topo);
            marca[topo]=2;
            remIni(pilha);
        }
        else{
            printf("Visitou v%-2d\n",u->vn);
            marca[topo]=1;
            insIni(pilha,u->vn);
        }
    }
    /*
    for(int i=0;i<qtd_ver;i++)
        printf("%d ",marca[i]);
    */
    return 1;
}

