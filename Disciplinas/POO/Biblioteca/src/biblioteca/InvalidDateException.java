/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package biblioteca;

/**
 *
 * @author luis
 */
 public class InvalidDateException extends Exception {
     
    public InvalidDateException() {
    }

    public InvalidDateException(String message) {
        super(message);
    }
        
}