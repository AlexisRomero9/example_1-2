#include "mbed.h"
#include "arm_book_lib.h"



int main()
{

   DigitalIn gasDetector(D2); //Se instancia el objeto gasDetector, de la clase DigitalIn
   DigitalIn overTempDetector(D3);//Se instancia el objeto overTempDetector, de la clase DigitalIn
   
   DigitalOut alarmLed(LED1);//Se instancia el objeto alarmLed, de la clase DigitalOut
   
   gasDetector.mode(PullDown); //Mensaje al objeto DigitalIn, el método utilizado es void mode() de la clase
   overTempDetector.mode(PullDown);//Mensaje al objeto DigitalIn, el método utilizado es void mode() de la clase
   while (true) {
      
      if ( gasDetector || overTempDetector ) {
          //La clase a la que se accede es DigitalIn, se utiliza el método int read(), que utiliza un método
          // de la estructura gpio_t "static inline int gpio_read(gpio_t *obj)" para devolver el valor que se
          // encuentra en reg_in.

          //El constructor de la clase DigitalIn es: DigitalIn(PinName pin) : gpio() o también DigitalIn(PinName pin, PinMode mode) : gpio()
          //Se observa que se puede crear un objeto de dos formas diferentes, esto se debe a la sobrecarga, que permite que un método con
          //el mismo nombre haga funciones diferentes, en este caso se reciben un parámetro mas que en el primer caso, que es el modo del pin.


         alarmLed = ON;
      } else {
         alarmLed = OFF;
      }
   }
}

/*
6a- Objeto: Es una instancia de una clase
    Clase: Es una plantilla que define propiedades y funcionalidades que puede tener un objeto
    Mensaje: Se refiere al "mensaje" que se le envia al objeto cuando se invoca una función que pertenezca al mismo.
    Método: Es una funcionalidad perteneciente a la clase que puede modificar sus propiedades
    Herencia: Los objetos pueden tener clases "padre", de la cual heredan propiedades o métodos.
    Interfaz: Las interfaces tienen métodos los cuales tienen una implementación en la clase padre, pero mediante el uso
    de clases abstractas, permiten indicar a las subclases que deben implementar el método.
    Constructor: Es el método de una clase que se invoca al instanciar un objeto, y define las propiedades y métodos del mismo
    Sobrecarga: Es la capacidad de definir múltiples versiones de una función o un operador con diferentes firmas 
6d-Mbed OS es un sistema operativo de tiempo real (RTOS) desarrollado por Arm, que le provee al usuario una capa de abstracción
a un nivel mas alto para facilitar el desarrollo del código sin necesidad de conocer a fondo como se configura el hardware
*/