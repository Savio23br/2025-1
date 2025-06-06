#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no* direita;
    struct no* esquerda;
} no;

no* criarNo(int c){
    no* novo=(no*)malloc(sizeof(no));
    if(novo){
        novo->dado=c;
        novo->direita=novo->esquerda=NULL;
        return (no*) novo;
    }else{
        printf("Erro ao alocar memoria\n");
    }
}

void remover(no* T){
    if(T){
        remover(T->esquerda);
        remover(T->direita);
        free(T);
    }else{
        printf("Erro: arvore vazia!\n");
    }
}

no* buscar(no* raiz, int c){
    no* t = NULL;
    if(raiz == NULL && c != 0){
        printf("Erro: arvore vazia!\n");
        return NULL;
    }
    if(raiz == NULL){
        t = criarNo(c);
        return t;
    }
    if(raiz->dado==c){
        return raiz;
    }
    if(raiz->dado>c){
        raiz=buscar(raiz->esquerda, c);
    }
    if(raiz->dado<c){
        raiz=buscar(raiz->direita, c);
    }
}
no* inserir(no* T,int c){
if (T == NULL){
return criarNo(c);
}
if (c < T->dado){
T->esquerda = inserir(T->esquerda, c);
}
if (c > T->dado){
T->direita = inserir(T->direita, c);
}
if (c == T->dado){
return T;
}
}

void imprimir(no* T){
    if(T != NULL){
        printf("%d ", T->dado);
        imprimir(T->esquerda);
        imprimir(T->direita);
    }
}

void emOrdem(no* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direita);
    }
}

void preOrdem(no* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(no* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

int altura(no* raiz) {
    if (raiz == NULL)
        return -1;
    int esq = altura(raiz->esquerda);
    int dir = altura(raiz->direita);
    return 1 + (esq > dir ? esq : dir);
}

int profundidade(no* raiz, int valor, int nivel) {
    if (raiz == NULL)
        return -1;
    if (raiz->dado == valor)
        return nivel;
    if (valor < raiz->dado)
        return profundidade(raiz->esquerda, valor, nivel + 1);
    else
        return profundidade(raiz->direita, valor, nivel + 1);
}

int soma(no* raiz) {
    if (raiz == NULL)
        return 0;
    return raiz->dado + soma(raiz->esquerda) + soma(raiz->direita);
}

int nivel(no* raiz, int valor) {
    return profundidade(raiz, valor, 0);
}

int contarNos(no* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(no* raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int main(){
    no* raiz = NULL;
    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    int i;
    for (i = 0; i < 7; i++){
        raiz = inserir(raiz, valores[i]);
    }
    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pre ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Pos ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura: %d\n", altura(raiz));
    printf("Profundidade de 7: %d\n", profundidade(raiz, 7, 0));
    printf("Nivel de 12: %d\n", nivel(raiz, 12));
    printf("Soma: %d\n", soma(raiz));
    printf("Numero de nos: %d\n", contarNos(raiz));
    printf("Numero de folhas: %d\n", contarFolhas(raiz));

    remover(raiz);
    imprimir(raiz);
    free(raiz);
    return 0;
}