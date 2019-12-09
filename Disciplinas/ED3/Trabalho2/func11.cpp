#include "trabalho2.hpp"

int func11(map<string,lista_ad*> hash, string cidade){          //Algoritmo de Prim
    map<string,lista_ad*> U;
    map<string,lista_ad*>::iterator it;
    map<string,string> ant;
    map<pair<string,string>,int> pesos;
    map<pair<string,string>,int>::iterator itp;
    pair<string,string> aresta;
    pair<string,string> tmp;
    lista_ad * aux;
    string auxs;
    bool repetido;
    int peso;
    if(!hash.count(cidade)){                        //Verifica se o vértice inicial está presente no grafo
        cout << "Cidade inexistente.";
        return 1;
    }
    aux = hash[cidade];
    U.insert(pair<string,lista_ad*>(cidade,aux));           //Insere o vértice inicial no grupo dos vértices processados

    while(U.size() != hash.size()){                                    //Enquanto grupo de processados (U) é diferente do grupo de vértices(V)
        aresta = extrai_min_prim(U);                                        //Extrai a aresta com menor distância que liga U a U-V
        peso = CalcPeso(aresta,hash);                                          //Calcula o peso dessa aresta
        pesos.insert(pair<pair<string,string>,int> (aresta,peso));                  //Insere o a aresta no grupo de arestas e o vértice ao grupo U
        U.insert(pair<string,lista_ad*>(aresta.second,hash[aresta.second]));
    }

    for(it=U.begin();it!=U.end();it++){                                 //Algoritmo de impressão            
        aux = it->second;
        auxs = aux->cidade;
        for(itp=pesos.begin();itp!=pesos.end();itp++){
            repetido = false;
            aresta = itp->first;
            if(auxs == aresta.first){
                if(aresta.first == tmp.first){                          //Imprime as arestas obtidas e as suas respectivas distâncias
                    repetido = true;
                    cout << " ";
                }else{
                    if(itp != pesos.begin()){                             
                        cout << endl;
                    }
                }
                aux = hash[aresta.first];                                            
                if(!repetido){
                    cout << aux->cidade << " " << aux->estado << " ";               //Imprime o vértice origem e os vértices adjacentes
                }     
                while(aux != NULL){
                    if(aux->cidade == aresta.second){
                        break;
                    }
                    aux = aux->next;
                }
                cout << aux->cidade << " " << aux->estado << " " << itp->second;
                if(aux->temp_viagem != ""){
                    cout << " " << aux->temp_viagem;
                }
                tmp = aresta;
            }
        }
        if(dontFirst(auxs,pesos)){                                          //Vértices nos extremos são impressos sozinhos
            aux = hash[auxs];
            cout << endl << aux->cidade << " " << aux->estado;
        }
    }
    cout << endl;
}