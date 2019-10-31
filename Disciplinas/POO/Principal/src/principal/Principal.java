/*
 Aula Pratica 2
 Aluno : Luis Fernando Costa de Oliveira
 NUSP: 10716532
 */
package principal;

/**
 *
 * @author luis
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Lista lista;
    
        lista = new ListaSequencial();
        
        lista.inserir(new Usuario("Marcelo"));
        lista.inserir(new Usuario("Joao"));
        lista.inserir(new Usuario("Pedro"));
        lista.inserir(new Usuario("Gustavo"));
        lista.inserir(new Usuario("Larissa"));
        lista.inserir(new Usuario("Flavia"));
        lista.imprimir();
        lista.remover(new Usuario("Gustavo"));
        lista.imprimir();
        
    }
    
    /*Questoes de prova
    
    1. Quais são os métodos polimórficos do diagrama acima? 
    R: imprimir, inserir, remover e equals.
    
    2. Por  quê  Lista  foi implementada como uma classe abstrata e Imprimivel foi definida como uma interface?
    R: Isto ocorreu porque não faz sentido instanciar uma Lista sem saber qual o seu tipo, logo, implementando Lista como uma classe
    abstrata podemos garantir que o usuário deverá escolher um tipo quando quiser instanciar uma Lista. Imprimivel foi definida como
    uma interface pois assim podemos agrupar classes que podem ser impressas e forçar que elas implementem o método imprimir em seu
    interior.

    3. Como você poderia estender o diagrama acima para permitir que sua lista armazene	objetos	de uma classe Data (contendo mês, dia e ano)? Implemente.
    R: Para tanto, bastaria criar um classe Data que implementa a interface IElemento, com isto, a classe seria forçada a implementar 
    todos os metodos necessarios para a utilizacao das listas.
    
    4. Explique quais (se existir) relacionamentos são do tipo: generalização (herança e interface),	
    associação,	agregação, composição e dependência.
    R: 
    Generalização:
    ListaEncadeada -> Herda -> Lista
    ListaSequencial -> Herda -> Lista
    Lista -> Implementa -> imprimivel
    Usuario -> Implementa -> IElemento
    
    Agregação:
    Principal -> ListaEncadeada
    Principal -> ListaSequencial
    Principal -> Usuario
    
    Composição:
    ListaEncadeada -> No
    
    Dependência:
    ListaEncadeada -> IElemento
    ListaSequencial -> IElemento
    
    
    

    */
}
