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
int* ingreso_numeros_memorizados(int level){
     //atributos
     string num_ingresados="";
     int aux=0;
     int ingreso[level];
     int* puntero_ingreso;
     
     //se ingresan los valores
     for(int j=0; j<level; j++){
             cout<<"Ingrese los valores separados por enter"<<endl;
             cin>>num_ingresados;
             //se convierte de string a entero
             aux = atoi(num_ingresados.c_str());
             ingreso[j] = aux;
     }
     //se asigna ingreso al puntero a retornar
     puntero_ingreso = ingreso;
     
     return puntero_ingreso;
     } 
     
/** inicio
*  Este es el centro del juego de memoria
*/
void inicio(int level){
     
     //arreglo para almacenar los valores seleccionados por la funcion rand()
     int memoria[level];
     int* puntero_recibido;     
     //se limpia la pantalla
     system("CLS");
     
     //se seleccionan los numeros
     for(int i=0; i<level; i++){
             memoria[i]=rand()%100;
             cout<<memoria[i]<<endl;
     }
     //comienza el juego de memoria
     cout<<"Oprima una tecla si ya memorizo los numeros"<<endl;
     system("PAUSE");
     
     system("CLS");
     
     //cout<<num_ingresados<<endl;
     
     puntero_recibido = ingreso_numeros_memorizados(level);
     
     for(int i=0;i<level;i++){
             cout<<"i: "<<i<<" -> "<<*puntero_recibido<<endl;
             }
     //cout<<*puntero_recibido<<endl;
     
     //se comparan los valores dados con los establecidos
     
     //contador: hara el incremento para la comparacion de valores
     int contador = 0;
     do{
         cout<<memoria[contador]<<endl;
         cout<<puntero_recibido[contador]<<endl;
         if(memoria[contador]==puntero_recibido[contador]){                
                                           contador++;             
                                           }
                           else{
                                cout<<"Los valores no son iguales, intente nuevamente"<<endl;
                                puntero_recibido = ingreso_numeros_memorizados(level);
                                contador=0;
                                }
     }while(contador<level);
                           
     //cout<<aux<<endl;
}
