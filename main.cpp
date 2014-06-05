#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

//ATRIBUTOS GLOBALES
int ingreso[100];
void menu(); 
void inicio(int level);

void continuar(int level){
     int seleccion = 0;
     cout<<" ________________________________"<<endl;
     cout<<"|                                |"<<endl;
     cout<<"| ¿DESEA CONTINUAR CON EL JUEGO? |"<<endl;
     cout<<"|________________________________|"<<endl;
     cout<<"|               |                |"<<endl;
     cout<<"|     1. SI     |      2. NO     |"<<endl;
     cout<<"|_______________|________________|"<<endl;
     cin>>seleccion;
     if(seleccion==1){
                      inicio(level+1);
                      }     
     }
/** menu
* Esta funcion se encarga de imprimir el menu disponible para el usuario
*/
void menu(){
     cout<<"_________________________________________"<<endl;
     cout<<"|                                       |"<<endl;
     cout<<"| BIENVENIDO AL PRIMER JUEGO DE MEMORIA |"<<endl;
     cout<<"|_______________________________________|"<<endl;
     cout<<"|                                       |"<<endl;
     cout<<"|       SELECCIONE UNA OPCION           |"<<endl;
     cout<<"|_______________________________________|"<<endl;
     cout<<"|                                       |"<<endl;
     cout<<"|  1. INICIAR                           |"<<endl;
     cout<<"|_______________________________________|"<<endl;
     cout<<"|                                       |"<<endl;
     cout<<"|  2. NIVEL                             |"<<endl;
     cout<<"|_______________________________________|"<<endl;
     cout<<"|                                       |"<<endl;
     cout<<"|  3. SALIR                             |"<<endl;
     cout<<"|_______________________________________|"<<endl;   
          
}
/**
*/
void ingreso_numeros_memorizados(int level){
     //atributos
     string num_ingresados="";
     int aux=0;
     
     //se ingresan los valores
     for(int j=0; j<level; j++){
             cout<<"Ingrese  el valor memorizado numero "<<j+1<<" con enter"<<endl;
             cin>>num_ingresados;
             //se convierte de string a entero
             aux = atoi(num_ingresados.c_str());
             ingreso[j] = aux;
     }
} 
     
/** inicio
*  Este es el centro del juego de memoria
*/
void inicio(int level){
     
     //arreglo para almacenar los valores seleccionados por la funcion rand()
     int memoria[level];
     int opcion=0;
     
     //se limpia la pantalla
     system("CLS");
     
     cout<<" _______________________________________________"<<endl;
     cout<<"|                                               |"<<endl;
     cout<<"|               NIVEL "<<level<<"                         |"<<endl;
     cout<<"|_______________________________________________|"<<endl;
     //se seleccionan los numeros
     for(int i=0; i<level; i++){
             cout<<" ___"<<endl;
             cout<<"| ";
             memoria[i]=rand()%100;
             cout<<memoria[i]<<" | "<<endl;
     }
     cout<<endl;
     //comienza el juego de memoria
     cout<<"Oprima una tecla si ya memorizo los numeros"<<endl;
     system("PAUSE");
     
     system("CLS");
     
     ingreso_numeros_memorizados(level);
     //se comparan los valores dados con los establecidos
     
     //contador: hara el incremento para la comparacion de valores
     int contador = 0;
     do{
         if(memoria[contador]==ingreso[contador]){                
                                           contador++;             
                                           }
                           else{
                                cout<<"Los valores no son iguales, intente nuevamente"<<endl;
                                cout<<" 1. seguir   |   2. salir"<<endl;
                                cin>>opcion;
                                if(opcion!=2){
                                              ingreso_numeros_memorizados(level);
                                              contador=0;
                                              }
                                else{
                                     break;
                                     }
                                
                                }
     }while(contador<level);
     cout<<"FELICITACIONES, Usted tiene una memoria increible"<<endl;
     cout<<endl;
     continuar(level);
     system("CLS");
        
     //system("PAUSE");
     system("CLS");
}

/** ingreso_nivel
* ingreso del nivel deseado por la persona
* @return: int level
*/
int ingreso_nivel(){
    int level = 0;
    cout<<"ingrese nivel: ";
    cin>>level;
    while((level<=0)||(level>100)){
                                cout<<"El nivel maximo es de 100, y minimo de 1"<<endl;
                                cin>>level;
    }
    return level;
    }

int main(int argc, char *argv[])
{
    //atributos
    int entrada=0;
    int nivel=1;
    
    //MENU DEL JUEGO
    while(entrada!=3){
                      menu();
                      //se recibe el dato ingresado y se asigna a entrada
                      cin>>entrada;
                      if(entrada==1){
                                     inicio(nivel);
                                     }
                      if(entrada==2){
                           nivel = ingreso_nivel();
                           inicio(nivel);
                           }
    }    
    return EXIT_SUCCESS;
}


