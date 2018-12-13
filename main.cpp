#include <iostream>
#include "Bst.h"
using namespace std;
int main(){
    Bst<int> arvore;
    cout <<"BST"<< endl;
    int opc=0,num=0,opc2=0;
    do{
        cout<<"-----Digite a acao desejada-----"<<endl;
        cout<<"1 - Inserir Dado."<<endl;
        cout<<"2 - Remove"<<endl;
        cout<<"3 - Percurso"<<endl;
        cout<<"4 - Buscar"<<endl;
        cout<<"5 - Maximo"<<endl;
        cout<<"6 - Minimo"<<endl;
        cout<<"9 - Sair"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                cout<<"Digite o numero que deseja inserir:";
                cin>>num;
                arvore.insere(arvore.pRaiz,num);
                cout<<"Numero Inserido"<<endl;
                cout<<endl;
            break;
            case 2:
                cout<<"Digite o numero que deseja cancelar:";
                cin>>num;
                arvore.excluir(arvore.pRaiz,num);
            break;
            case 3:
                do{
                    cout<<"Qual o percurso desejado"<<endl;
                    cout<<"1 - PreOrdem."<<endl;
                    cout<<"2 - EmOrdem."<<endl;
                    cout<<"3 - ProOrdem."<<endl;
                    cout<<"9 - Voltar."<<endl;
                    cin>>opc2;
                    switch(opc2){
                    case 1:
                        cout<<endl;
                        cout<<"Pre Ordem"<<endl;
                        arvore.preOrdem(arvore.pRaiz);
                        cout<<endl;
                    break;
                    case 2:
                        cout<<endl;
                        cout<<"Em Ordem"<<endl;
                        arvore.emOrdem(arvore.pRaiz);
                        cout<<endl;
                    break;
                    case 3:
                        cout<<endl;
                        cout<<"Pos Ordem"<<endl;
                        arvore.posOrdem(arvore.pRaiz);
                        cout<<endl;
                    break;
                    }
                }while(opc2!=9);
            break;
            case 4:
                cout<<"Digite o valor q deseja procurar:";
                cin>>num;
                if(arvore.busca(arvore.pRaiz,num)==0){
                    cout<<"Numero nao encontrado"<<endl;
                }
            break;
            case 5:
                arvore.valorMaximo(arvore.pRaiz);
            break;
            case 6:
                arvore.valorMinimo(arvore.pRaiz);
            break;
        }
    }while(opc!=9);
    cout<<"Programa Finalizado!"<<endl;
    return 0;
}
