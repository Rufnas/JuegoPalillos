#include <stdio.h>
#include <stdlib.h> //para poder usar el system("pause"); y return 0;

//FUNCIONES A UTILIZAR EN EL PROGRAMA----------------------------------------------------------------
//Funcion para mostrar la cantidad de palillos que quedan
void mostrarPalillos(int var){
    printf("\nQuedan %d palillos",var); 
    for (int i=1;i<=var;i++){
             printf("|");
             }
}

//Funcion donde se muestra en pantalla lo que se pide al jugador de turno
int turnoJugador(char jugador[20],int var){
     //char jugador[20];    
     printf("\nTurno de %s : Elige el numero de palillos que deseas quitar (1-3): ",jugador);
     scanf("%d",&var);
     return var;
}

//Funcion para mostrar en pantalla el perdedor de la partida
void perdedor(char jugador[20]){
     printf("\n%s ha perdido! Mejor suerte la proxima!!\n\n",jugador);
}

//PROGRAMA PRINCIPAL----------------------------------------------------------------------------------
#define JUGADORES 2 //Numero de jugadores
#define PALILLOS 15 //Numero total de palillos
#define MIN 1 //Numero minimo de palillos que puede quitar un jugador por turno
#define MAX 3 //Numero maximo de palillos que puede quitar un jugador por turno
int main(){
    int turno,numPalillos,palillos,i;
    char jug1[20],jug2[20];
    numPalillos=PALILLOS;
    
    //Nombre y reglas del juego
    printf("-JUEGO DE LOS PALILLOS-\n");
    printf("Hay 15 palillos, cada jugador quita entre 1 y 3 palillos por turnos.\nPierde el jugador que quita el ultimo palillo.\n\n");
    
    //Cogemos el nombre de cada jugador
    printf("Introduce el nombre del Jugador 1: ");
    gets(jug1);
    
    printf("Introduce el nombre del Jugador 2: ");
    gets(jug2);
    fflush(stdin);
    
    /*IGNORAR ESTO, QUIERO PREGUNTAR SI SE PUEDE PEDIR NOMBRE DE JUGADORES MEDIANTE BUCLE CONTROLADO
   for (i=1;i<=JUGADORES;i++){
        printf("Introduce nombre de Jugador %d: \n",i);
        gets(jug1);
        fflush(stdin);
    }*/
    
    printf("\nEmpieza el juego!\n");
    
    //Aqui colocamos el maximo de turnos que es el total de palillos a quitar
    for (i=1;i<=PALILLOS;i++){
    //Aqui separamos las acciones por turnos
        for (turno=1;turno<=JUGADORES;turno++){
            //Mostramos la cantidad de palillos al inicio de la partida y del turno
            mostrarPalillos(numPalillos);
            
            //Aqui se realiza la accion del jugador de turno
            switch (turno){
                           case 1:
                                  do {
                                     palillos=turnoJugador(jug1,palillos);
                                     } while(palillos<MIN || palillos>MAX);
                                  break;
                                  
                           case 2:
                                 do {
                                    palillos=turnoJugador(jug2,palillos);
                                    } while(palillos<MIN || palillos>MAX);
                                 break;
                           }
                           
            //Esta operacion resta el total de palillos menos los que descuenta el jugador de turno.
            numPalillos=numPalillos-palillos;
            
            //Pierde el jugador que quita el último palillo, aqui controlamos eso.
            if (numPalillos<=0) {
                                //Dividimos la accion por turnos (igual que antes) para saber quien es el perdedor
                                switch (turno){
                                               case 1:
                                                      mostrarPalillos(numPalillos);
                                                      perdedor(jug1);
                                                      break;
                                                       
                                               case 2:
                                                      mostrarPalillos(numPalillos);
                                                      perdedor(jug2);
                                                      break; 
                                               }
                                //Para cerrar el programa aun con el bucle activo despues que se conoce el ganador
                                system("pause");
                                return 0;
                                }
        }
    }
}
