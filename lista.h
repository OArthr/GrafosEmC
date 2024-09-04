typedef struct lista{
    struct elemento* ini;
    struct elemento* fim;
}Lista;

Lista* criar();

int insIni(Lista*, int);
int insFim(Lista*,int);
int remIni(Lista*);
int printList(Lista* ldse);
int acessPrim(Lista*, int*);


int percursoRec(Lista*[],int,int);
int percursoIte(Lista*[],int,int);
