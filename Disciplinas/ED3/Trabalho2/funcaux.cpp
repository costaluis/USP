#include "trabalho2.hpp"

bool isEmpty(city* aux, int tam){                       //Verifica se o vetor de cidades está vazio, ou seja, se ainda existem vértices a serem processados
    int i;                                              
    int cont = 0;                                       //Utilizada na func10
    for( i = 0; i < tam; i++){
        if(aux[i].cidade != "" && aux[i].estado != "")
            cont++;
    }

    return !cont ? true : false;                        //Retorna se está vazio ou não
}

void extrai_min(map<city,int> dist, city * vet, int tam, city * c){         //Extrai o vértice com menor distância entre o vértice origem e seus adjacentes
    int menor = INT_MAX;
    int indice;
    map<city,int>::iterator itera;
    for(int i=0; i<tam; i++){
        if(vet[i].cidade != "" && vet[i].estado != ""){                     //Utilizada na func10
            itera = dist.find(vet[i]);
            if(itera->second < menor){
                menor = itera->second;
                indice = i;
            }
        }
    }    
    c->cidade = vet[indice].cidade;
    c->estado = vet[indice].estado;                         //Vértice é retornado por referencia e removido da lista
    vet[indice].cidade = "";
    vet[indice].estado = "";
}

void print_hash(map<string,lista_ad*> hash){                //Função de impressão do grafo (Lista de adjacẽncias)
    map<string,lista_ad*>::iterator itera;                      //Utilizada na func9
    for(itera = hash.begin(); itera != hash.end(); itera++){
        lista_ad * tmp = itera->second;
        cout << tmp->cidade << " " << tmp->estado;
        tmp = tmp->next;
        while(tmp!=NULL){
            cout << " " << tmp->cidade << " " << tmp->estado << " " << tmp->peso;
            if(tmp->temp_viagem != ""){
                cout << " " << tmp->temp_viagem;
            }
            tmp = tmp->next;
        }
        cout << endl;
    }
}

pair<string,string> extrai_min_prim(map<string,lista_ad*>U){            //Função responsável por retornar a aresta de menor peso que liga U a U-V
    map<string,lista_ad*>::iterator it;
    lista_ad * aux;
    int menor = INT_MAX;                                                //Utilizada na func11
    string v = "";
    string u = "";
    for(it=U.begin(); it!=U.end(); it++){
        aux = it->second;
        aux = aux->next;
        while(aux!=NULL){
            if(IsInU(U,aux->cidade)){       //Verifica se o vértice já está em U
                aux = aux->next;
                continue;
            }
            if(aux->peso < menor){          //Caso não esteka, verifica se forma a aresta de menor peso
                menor = aux->peso;                                    
                v = aux->cidade;
                u = it->second->cidade;
            }
            aux = aux->next;
        }
    }
    return pair<string,string>(u,v);        //Retorna a aresta de menor peso
}

bool IsInU(map<string,lista_ad*> U, string cidade){     //Verifica se um vértice está em U
    map<string,lista_ad*>::iterator it;                 
    lista_ad * aux;
    if(U.count(cidade)){                                //Chamada pela função extrai_min_prim
        return true;
    }else{
        return false;
    }
}

int CalcPeso(pair<string,string> aresta, map<string,lista_ad*> hash){           //Calcula a distãncia entre duas cidades
    lista_ad * aux;
    aux = hash[aresta.first];
    aux = aux->next;
    while(aux!=NULL){
        if(aux->cidade == aresta.second){
            return aux->peso;
        }
        aux = aux->next;
    }
    return -1;                                                  //Retorna -1 caso os vértices não estejam ligados
}

bool dontFirst(string second, map<pair<string,string>,int> pesos){              //Verifica se um vértice pertecente a arvore geradaora mínima
    map<pair<string,string>,int>::iterator it;                                      //possui vértices adjacentes
    for(it=pesos.begin();it!=pesos.end();it++){
        if(it->first.first == second){
            return false;                                                   //Utilizada na impressão da func11
        }
    }
    return true;
}

void freeMem(map<string,lista_ad*> hash){                           //Libera a memória utilizada na Lista de adjacências
    map<string,lista_ad*>::iterator it;
    for(it=hash.begin();it!=hash.end();it++){
        freeLista(it->second);
    }
}

void freeLista(lista_ad * lista){                       //Função recursiva que libera todos os nós de uma lista dinâmica
    if(lista->next != NULL){
        freeLista(lista->next);
    }
    delete(lista);
}