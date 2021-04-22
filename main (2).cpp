#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int dinero = 10;       //Cantidad de dinero que tiene el jugador (inicialmente 10)
    bool seguir = true;    //Variable que controla que el jugador siga o no en la partida (inicialmente true)
    int apuesta;           //Cantidad de dinero que va a apostar el jugador
    int numeroApostado;    //Numero por el que el jugador va a apostar
    char colorApostado;    //Color por el que el jugador va a apostar
    char opcn;
    
    int option;
    int num; //Variable que controla el resultado de la ruleta (numero entre 0 y 36)
    int banca = 0;  //Variable que controla el dinero de la banca
    int suma = 0;
    srand(time(NULL));
    do{
        if(seguir == true){              //Bloques condicionales que muestran el dinero actualizado de cada jugador
            cout<<"Dinero: "<<dinero<<"€ ";  //cada ronda (lo he incluido por pura estetica del programa)
        }
        cout<<endl;
        if(seguir == true && dinero > 0){ //Condiciones necesarias para que el jugador pueda jugar
            do{
                cout<<"¿Apostar o retirarse (0|1)?: ";
                cin>>option;
            }while(option != 0 && option != 1);
            if(option == 0){ //Si el jugador elige apostar, se procede con la apuesta
                do{
                    cout<<"¿Cuanto dinero desea apostar?: ";
                    cin>>apuesta;
                }while(apuesta>dinero); //Condicion que controla que el jugador hace una apuesta dentro de sus capacidades
                dinero = dinero - apuesta; //Se actualiza la variable *dinero* del jugador tras realizar la apuesta
                do{
                    cout<<"¿Que apuesta desea hacer, color o numero (c|n)?: ";
                    cin>>opcn;
                }while(opcn != 'c' && opcn != 'n');
                if(opcn == 'c'){
                    do{
                        cout<<"¿A que color desea apostar, rojo o negro (r|n)?: ";
                        cin>>colorApostado;
                    }while(colorApostado != 'r' && colorApostado != 'n');
                }
                else{
                    do{
                        cout<<"Seleccione un numero al que apostar 1-36: ";
                        cin>>numeroApostado;
                    }while(numeroApostado<1 || numeroApostado>36);
                }
            }
            else{
                seguir = false; //El jugador ha elegido retirarse por lo que su variable *segir* se pone a false
            }
        }//Una vez acabada la fase de apuestas de los jugadores que juegan la ronda, se lanza la ruleta
        num = rand()%37; //Se genera un numero aleatorio (0-36)
        if(num == 0){ //Si el numero es 0, todo el dinero va a la banca
            if(seguir == true){
                suma = suma + apuesta;
            }
            banca = banca + suma;
            suma = 0; //Se resetea la variable *suma* para futuras rondas
        }
        else{ //Si el numero no es 0, se contemplan las opciones para cada jugador
            if(seguir == true){ //Condicion para que solo se recompense a los que han jugado esta ronda
                if(opcn == 'n'){ //Para aquellos jugadores que hayan apostado a un numero
                    if(numeroApostado == num){ //Si se ha acertado con el numero apostado, x35 el dinero apostado
                        dinero = dinero + (apuesta * 35);
                    }
                }
                else if(opcn == 'c'){ //Para aquellos jugadores que hayan apostado a un color
                    if(num % 2 == 0 && colorApostado == 'r'){ //los pares son rojos
                        dinero = dinero + apuesta * 2;
                    }
                    else if(num % 2 != 0 && colorApostado == 'n'){ //los impares son negros
                        dinero = dinero + apuesta * 2;
                    }
                }
            }
        }
        //Si un jugador se queda sin dinero, no continua en la partida
        if(dinero<1){
            seguir = false;
        }
        cout<<"Ha salido el número "<<num<<" - "; //Se muestra el resultado (numero y color)
        if(num % 2 == 0){
            cout<<"Rojo"<<endl;
        }
        else{
            cout<<"Negro"<<endl;
        }
    }while(seguir == true);
    //Al finalizar el juego, se muestra cuanto ha ganado cada jugador y la banca
    cout<<"Has acabado con "<<dinero<<" euros"<<endl;
    cout<<"La banca ha acabado con "<<banca<<" euros";
    return 0;
}


