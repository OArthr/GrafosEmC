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
    if (ldse){
        ldse->ini = NULL;
        ldse->fim = NULL;
    }

    return ldse;
}

int insIni(Lista* ldse, int n){
    if (!ldse)
        return 0;
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if(!novo)
        return 0;
    novo->vn = n;
    novo->prox = ldse->ini;
    if (!ldse->fim)
        ldse->fim = novo;
    ldse->ini = novo;
    return 1;
}

int insFim(Lista* ldse, int n){
    if (!ldse)
        return 0;
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if(!novo)
        return 0;
    novo->vn = n;
    novo->prox = NULL;
    if (!ldse->fim)
        ldse->ini = novo;
    else
        ldse->fim->prox = novo;
    ldse->fim = novo;
    return 1;
}

int remIni(Lista* ldse){
    if(!ldse || !ldse->ini)
        return 0;

    Elemento* aux = ldse->ini;
    ldse->ini = ldse->ini->prox;
    if(!ldse->ini)
        ldse->fim = NULL;

    free(aux);
    return 1;
}

int printList(Lista* ldse){
    if(!ldse)
        return 0;
    Elemento* aux = ldse->ini;
    printf(" -> ");
    while(aux){
        printf("v%-2d -> ",aux->vn);
        aux = aux->prox;
    }
    printf("||\n");
    return 1;
}

int acessPrim(Lista* ldse, int* vn){
    if(!ldse || !ldse->ini)
        return 0;

    *vn = ldse->ini->vn;
    return 1;
}

void visitaVer(Lista* grafo[],int v,int marca[]){
    Elemento* u = grafo[v]->ini;
    while(u){
        if(marca[u->vn]==0){
            printf("Visitou v%-2d\n",u->vn);
            marca[u->vn]=1;
            visitaVer(grafo,u->vn,marca);
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

    int u=0;
    while(pilha->ini){
        acessPrim(pilha,&u);
        remIni(pilha);
        Elemento* w = grafo[u]->ini;

        while(w){
            if (marca[w->vn]==0){
                printf("Visitou v%-2d\n",w->vn);
                marca[w->vn]=1;
                insIni(pilha,w->vn);
            }
            w=w->prox;
        }
        marca[u]=2;
        printf("Percorreu v%-2d\n",u);
    }
    /*
    for(int i=0;i<qtd_ver;i++)
        printf("%d ",marca[i]);
    */
    return 1;
}

