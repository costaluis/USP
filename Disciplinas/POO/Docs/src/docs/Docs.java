
package docs;

import java.io.File;
import java.util.LinkedList;
import java.util.Scanner;
import javax.swing.JFrame;

/**
 * Classe do programa principal.
 * @author João Pedro 
 * @author Luis Fernando
 */
public class Docs {
    private LinkedList <Comando> pilha;
    private Text texto;
    private String copy_paste;
    private File f;
    
    /**
     * Construtor da classe Docs.
     * @author João Pedro
     * @author Luis Fernando
     */
    public Docs() {
        this.f = null;
        this.pilha = new LinkedList();
        this.texto = new Text();
        this.copy_paste = new String();
    }
    
    /**
     * Função principal do programa.
     * @param args vetor de Strings que a main recebe como parâmetro
     * @author João Pedro
     * @author Luis Fernando
     */
    public static void main(String[] args) {
        Docs programa = new Docs();
        File F;
        Server s = new Server(programa);
        GraphicDocs teste = new GraphicDocs(programa,s);
        teste.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        teste.setVisible(true);
    }
    
    /**
     * Insere um texto passado como parâmetro.
     * @param programa Objeto associado ao programa principal
     * @param entrada String a ser inserida
     * @param flag Indica se o comando será ou não empilhado
     * @author João Pedro
     * @author Luis Fernando
     */
    public static void InsereTexto(Docs programa, Text entrada, boolean flag){
        Comando comandos = new Comando();
        comandos.setInstrucao(1);
        for(int i=0; i < programa.pilha.size() && flag;i++){
            if(programa.pilha.get(i).getInstrucao() == 3 || programa.pilha.get(i).getInstrucao() == 4){
                programa.pilha.remove(i);
            }
        }
        for(int i=0; i < entrada.getTexto().size();i++){
            programa.texto.getTexto().add(entrada.getTexto().get(i));
            comandos.getOperando().getTexto().add(entrada.getTexto().get(i));
        }
        if(flag)
            programa.pilha.push(comandos);
    } 
    
   /**
    * Remove um trecho do texto relativo ao número passado como parâmetro.
    * @param programa Objeto associado ao programa principal
    * @param num Número de caracteres a serem removidos
    * @param flag Indica se o comando será ou não empilhado
    * @author João Pedro
    * @author Luis Fernando
    */
    public static void RemoveTexto(Docs programa, int num, boolean flag) throws IllegalArgumentException{
        if(num < 0){
            throw new IllegalArgumentException(); 
        }
        if(num > programa.getTexto().getTexto().size()){
            num = programa.getTexto().getTexto().size();
        }
        Comando comandos = new Comando();
        comandos.setInstrucao(2);
        
        for(int i=0; i < programa.pilha.size() && flag;i++){
            if(programa.pilha.get(i).getInstrucao() == 3 || programa.pilha.get(i).getInstrucao() == 4){
                programa.pilha.remove(i);
            }
        }
        
        for(int i=0; i<num; i++){ 
            comandos.getOperando().getTexto().push(programa.texto.getTexto().getLast());
            programa.texto.getTexto().removeLast();
        }
        
        if(flag && num != 0)
            programa.pilha.push(comandos);     
    }
    
    public static void RemoveTexto(Docs programa, int num, boolean flag, int fim){
        Comando comandos = new Comando();
        comandos.setInstrucao(2);
        for(int i=fim-1; num >= fim-i; i--){
            comandos.getOperando().getTexto().push(programa.texto.getTexto().get(i));
            programa.texto.getTexto().remove(i);
        }
    }
    
    /**
     * Desfaz a última ação realizada pelo usuário.
     * @param programa Objeto associado ao programa principal
     * @author João Pedro
     * @author Luis Fernando
     */
    public static void Desfazer(Docs programa) throws NullPointerException{
        if(programa.pilha.isEmpty()){
            throw new NullPointerException();
        }
        Comando comandos;
        comandos = programa.pilha.getFirst();
        int i = 1;
        while(comandos.getInstrucao() != 1 && comandos.getInstrucao() != 2){
            if(i>=programa.pilha.size()){
                return;
            }
            comandos = programa.pilha.get(i);
            i++;
        }
        
        programa.pilha.remove(i-1);
        
        if(comandos.getInstrucao()==1){
            Docs.RemoveTexto(programa,comandos.getOperando().getTexto().size(),false);
            comandos.setInstrucao(4);
            programa.pilha.push(comandos);
        }
        else{
            Docs.InsereTexto(programa,comandos.getOperando(), false);
            comandos.setInstrucao(3);
            programa.pilha.push(comandos);
            
        }
    }
    
    /**
     * Refaz a última ação desfeita pelo usuário.
     * @param programa Objeto associado ao programa principal
     * @author João Pedro
     * @author Luis Fernando
     */
    public static void Refazer(Docs programa){
        Comando comandos;
        
        if(programa.pilha.isEmpty()){
            return;
        }
        
        comandos = programa.pilha.getFirst();
        int i = 1;
        while(comandos.getInstrucao() != 3 && comandos.getInstrucao() != 4){
            if(i>=programa.pilha.size()){
                return;
            }
            comandos = programa.pilha.get(i);
            i++;
        }
        
        programa.pilha.remove(i-1);
        
        if(comandos.getInstrucao() == 3){
            Docs.RemoveTexto(programa, comandos.getOperando().getTexto().size(), false);
            comandos.setInstrucao(2);
            programa.pilha.push(comandos);
        }
        else{
            Docs.InsereTexto(programa, comandos.getOperando(), false);
            comandos.setInstrucao(1);
            programa.pilha.push(comandos);
        }
        
    }
    
    /**
     * Recebe uma string informada pelo usuário e a converte em um objeto Text.
     * @return 
     * @author João Pedro
     * @author Luis Fernando
     */
    public static Text InputString(String entrada){
        Text texto = new Text();
        for(int i=0; i<entrada.length(); i++){
            texto.getTexto().add(entrada.charAt(i));
        }
        return texto; 
    }
    
    /**
     * Recebe um valor inteiro correspondente ao número de caracteres a serem removidos do texto.
     * @return
     * @author João Pedro
     * @author Luis Fernando
     */
    public static int InputInt(){
        Scanner ent = new Scanner(System.in);
        int entrada;
        System.out.print("Digite o numero de caracteres a serem removidos: ");
        entrada = ent.nextInt();
        return entrada;
    }

    public Text getTexto() {
        return texto;
    }

    public String getCopy_paste() {
        return copy_paste;
    }

    public void setCopy_paste(String copy_paste) {
        this.copy_paste = copy_paste;
    }

    public void setTexto(Text texto) {
        this.texto = texto;
    }

    public File getF() {
        return f;
    }

    public void setF(File f) {
        this.f = f;
    }

    public void setPilha(LinkedList<Comando> pilha) {
        this.pilha = pilha;
    }
    
    
    
}
