#include "trabalho2.hpp"

int func10(map<string,lista_ad*> hash, map<city,int> *dist, map<city,city> *ant, string cidade){  //Algoritmo de Dijkstra
    map<string,lista_ad*>::iterator itera;  
    map<city,int>::iterator it;
    city *c = new city();
    int i;
    int tam = hash.size();
    city vazia;
    vazia.cidade = "";
    vazia.estado = "";
    city nProc[tam];
    lista_ad * aux;
    city * cid = new city();
    city aux2;
    int d;

    if(!hash.count(cidade)){                                //Verifica se o vértice de inicio existe na lista de adjacências
        cout << "Cidade inexistente." << endl;
        return 1;
    }else{
        aux = hash[cidade];                                 //Caso exista, o mesmo é buscado na hash
        cid->cidade = aux->cidade;
        cid->estado = aux->estado;
    }

    for(itera = hash.begin(), i=0; itera != hash.end(); itera++, i++){
        c->cidade = itera->second->cidade;
        c->estado = itera->second->estado;
        nProc[i].cidade = c->cidade;
        nProc[i].estado = c->estado;                                   //inicializa vetor de cidades não processadas
        (*ant).insert(pair<city,city>(*c,vazia));                       //inicializa vetor de antecessores               
        if(c->cidade == cid->cidade && c->estado == cid->estado){       //inicializa vetor de distâncias
            (*dist).insert(pair<city,int>(*c,0));
        }else{
            (*dist).insert(pair<city,int>(*c,INT_MAX));
        }
    }
  
    while(!isEmpty(nProc,tam)){                                        //Enquanto ainda há vertices para serem processados
        extrai_min((*dist),nProc,tam,c);                     //Obtém o vétice com menor distância
        aux = hash[c->cidade];
        aux = aux->next;
        while(aux != NULL){
            aux2.cidade = aux->cidade;
            aux2.estado = aux->estado;                  //Caso uma distãncia menor seja encontrada, ela é atribuida ao vetor de distancias
            d = (*dist)[aux2];
            if(d > (*dist)[*c] + aux->peso){
                (*dist)[aux2] = (*dist)[*c] + aux->peso;        //Atualiza distancia e vetor de adjacentes 
                (*ant)[aux2] = *c;
            }
            aux = aux->next;
        }
        
    }
    
    for(it = (*dist).begin(); it != (*dist).end(); it++){                                       //Impressão das distâncias obtidas 
        if(it->first.cidade != cid->cidade || it->first.estado != cid->estado){
           cout << cid->cidade << " " << cid->estado << " " << it->first.cidade << " " 
            << it->first.estado << " " << it->second << " " << (*ant)[it->first].cidade << " " << (*ant)[it->first].estado << endl;
        }
    }

}



