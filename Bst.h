#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
using namespace std;
template <typename Tipo>
struct Node{
    Tipo info;
    Node<int> *pEsq;
    Node<int> *pDir;
};
template <typename Tipo>
struct Bst{
    Node<Tipo> *pRaiz;
    Bst(){
        pRaiz=NULL;
    }
    bool arvoreVazia(){
        return pRaiz==NULL;
    }
    void insere(Node<Tipo> *&raiz,int entrada){
        if(raiz==NULL){
            raiz = new Node<Tipo>;
            raiz->info=entrada;
            raiz->pEsq=NULL;
            raiz->pDir=NULL;
        }else{
            if(entrada<raiz->info){
                insere(raiz->pEsq,entrada);
            }else{
                insere(raiz->pDir,entrada);
            }
        }
    }
    void preOrdem(Node<Tipo> *raiz){
        if(raiz!=NULL){
            cout<<raiz->info<<" ";
            preOrdem(raiz->pEsq);
            preOrdem(raiz->pDir);
        }
    }
    void emOrdem(Node<Tipo> *raiz){
        if(raiz!=NULL){
            emOrdem(raiz->pEsq);
            cout<<raiz->info<<" ";
            emOrdem(raiz->pDir);
        }
    }
    void posOrdem(Node<Tipo> *raiz){
        if(raiz!=NULL){
            posOrdem(raiz->pEsq);
            posOrdem(raiz->pDir);
            cout<<raiz->info<<" ";
        }
    }
    int busca(Node<Tipo> *&raiz,int valor){
        if(valor==raiz->info){
            cout<<valor<<" esta incluso."<<endl;
            return 1;
        }else{
            if(valor<raiz->info && raiz->pEsq!=NULL){
                busca(raiz->pEsq,valor);
            }else{
                return 0;
            }
            if(valor>raiz->info && raiz->pDir!=NULL){
                busca(raiz->pDir,valor);
            }else{
                return 0;
            }
        }
    }
    Node<Tipo>* valorMaximo(Node<Tipo> *raiz){
        Node<Tipo> *aux;
        aux=raiz;
        if(raiz->pDir==NULL){
            cout<<"O valor maximo e "<<raiz->info<<endl;
            return aux;
        }else{
            valorMaximo(raiz->pDir);
        }
    }
    void valorMinimo(Node<Tipo> *raiz){
        if(raiz->pEsq==NULL){
            cout<<"O valor minimo e "<<raiz->info<<endl;
        }else{
            valorMinimo(raiz->pEsq);
        }
    }
    int excluir(Node<Tipo> *&raiz, Tipo numero){
        Node<Tipo> *aux;
        if(raiz == NULL){
            return false;
        }
        if(raiz->info == numero){
            aux = raiz;
            if(raiz->pEsq == NULL){
                raiz = raiz->pEsq; }
            else{
                aux=valorMaximo(raiz->pEsq); }
            delete aux;
            return true;
        }else if(raiz->info > numero){
            excluir(raiz->pEsq, numero);
        }else{
            excluir(raiz->pDir, numero);
        }
    }
};
#endif // BST_H_INCLUDED
