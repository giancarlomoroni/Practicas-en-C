#include "SPI.h" // libreria del bus spi
#include <Adafruit_GFX.h>       //Adafruit libreria grafica
#include <ILI9341_Fast.h> 

//DECLARACION DEL BUS SPI
#define ILI9341_SPI_MODE_DMA  
#define ILI9341_SPI_CLKDIVIDER SPI_CLOCK_DIV2
#define COMPATIBILITY_MODE
#define TFT_SCK 13          // Bus spi
#define TFT_MISO 12         //bus spi
#define TFT_MOSI 11         // Bus spi
const int TFT_CS = 10 ;    // TFT CS  pin esta conectado l arduino pin 8
const int TFT_RST  = 8;     // TFT RST pin sin uso, directamente a masa con una resistencia 4k7
const int TFT_DC  =  9 ;   // TFT DC  pin is connected to arduino pin 10

// Inicializamos TFT
ILI9341 tft = ILI9341(TFT_DC, TFT_RST, TFT_CS);

//DECLARACIONES DE PINES

const int joystick_x = A0;      // Entrada de datos analogicos del eje X
const int joystick_y = A1;      // Entrada de datos analogicos del eje Y
const int pulsador_1 = 3;       // Entrada digital de datos
const int pulsador_2 = 2;       // Entrada digital de datos
const int leds = 4;             // Salida que controla ambos leds
const int pulsador_joy = 5;     // sin uso por el momento

//JUEGO GENERAL
int score = 0; // Cuenta la cantidad de aciertos 

//JOYSTICK
int lectura_x;        // lectura analogica 
int lectura_y;        // lectura analogica
int mapX = 0;         // guardar el mapeo del eje x
int mapY = 0;         // guardar el mapeo del eje y

//PANTALLA DE CARGA
int i = 0;                                        // auxiliar para loop de pantalla de carga
boolean flag = 0;                                 //flag para la pantalla de carga
boolean flag_4 = 0;                               // flag de pantalla de carga
unsigned long tiempo_inicial;                     // Guardar tiempo inicial de millis
unsigned long tiempo_final;                       // Guardar tiempo final en millis
boolean auxMillis;                                // Auxiliar para luego activar tiempo final
unsigned long tiempoActual = 0;                   // Guardar tiempo inicial de millis
unsigned long tiempoAnt = 0;                      // Guardar tiempo final en millis
boolean auxMillis_2 = 0;                          // Auxiliar para luego activar tiempo final

//DISPARO
int cantDisparo = 6;                                // En todos los niveles se inicializa con una cantidad de disparo de 6
int valorAnterior;                                  // Guardar valor anterior al momento de pasar de cuadrado rojo cuando movemos 
int CADENCIA = 500;                                 // cadencia de disparo 

//OBSTACULOS E IMPRESION
int hilera;                                          //Fija la hilera del cuadrado
int rojos[7]={};                                     // Ubicacion de los rectangulos rojos a partir de la seleccion random de cada fila
int contFilas = 0;                                   // Cuenta la cantidad de filas en el loop FOR
int impresionUnica = 0;                              // Variable para imprimir solo una vez el camino y el fondo
int Fila_Y = 15;                                     // Inicio de impresion de ladrillos
int Ancho_Ladrillo = 57;                             // Ancho regulable segun nivel
#define ALTO_LADRILLO 20 
#define INICIO_LADRILLO 20                           // Donde comienza la hilera

// OBSTACULOS CON MOVIMIENTOS
int auxObj = 0;
unsigned long Tfinal;
#define VELOCIDAD 500                                 //Velocidad de refresco para el movimiento de los ladrillos


//Borrado
int largo = 195;

//FUNCIONES
void cursor(int posicionX, int posicionY);                          // Tiene como parametros las nuevas ubicaciones determinadas por el joystick, y escribe y borra rapidamente la nueva ubicacion del cursor.
void disparo(int disparoX, int disparoY);                           // disparo se encarga de ver si se acerto el tiro
void obstaculosSinMov(int level);                                   // Funcion para imprimir obstaculos sin movimientos
void obstaculosConMov(int level);                                   // Funcion para imprimir obstaculos con movimientos
void LoadingScreen();                                               // Pantalla de carga
int verifColision(int ubicacionX, int numDisparo, int level);       // verificacion de colision con el eje x, dependiendo de cuanto es el ancho del rectangulo
void borradoHilera();                                               // Se encarga de borrar la hilera una vez que se acerto el disparo
int solicitarFila(int fila);                                        // Solicita el valor del punto de choque entre el rectangulo y la bala
void level(int nivel);                                              // Impresion de pantalla de carga de nivel
void maquina(bool movimiento);                                      // Vemos si en el nivel que nos encontramos, hay o no movimiento.

//MAQUINA DE ESTADO
#define LEVEL_1 1                                                   // 3 Cuadrados sin movimiento
#define LEVEL_2 2                                                   // 4 Cuadrados sin movimiento
#define LEVEL_3 3                                                   // 5 Cuadrados sin movimiento
#define LEVEL_4 4                                                   // 3 Cuadrados con movimiento
#define LEVEL_5 5                                                   // 4 Cuadrados con movimiento
#define LEVEL_6 6                                                   // 5 Cuadrados con movimiento

bool motion = 0;                     //Encargada ver si hay movimiento o no
//Pantalla de niveles
int nivel = LEVEL_1;                      // Contador de niveles, el cual se incializa en 1
int auxPantalla = 0;                // Imprime una vez una instancia antes de los movimientos de los ladrillos

void setup() {
  
  // Declaraciones basicas del hard
  tft.begin();
  Serial.begin(9600);
  pinMode(pulsador_1, INPUT);
  pinMode(pulsador_2, INPUT);
  pinMode(leds, OUTPUT);
  analogReference(DEFAULT);

  // Codigo del programa
  LoadingScreen();
  randomSeed(analogRead(0));  // Semilla de la funcion random en el pin 0
  digitalWrite(leds, HIGH);
}

void loop(void){
  
  //Lecturas analogicas y conversiones
  lectura_x = analogRead(joystick_x);
  lectura_y = analogRead(joystick_y);

  //La funcion MAP convierte los valores del rango de 10 bits, a lo que nosotros querramos.
  mapX = map(lectura_x, 0, 1023, 23, 213);      // 23 es el rango minimo del camino y 213 el maximo
  mapY = map(lectura_y, 0, 1023, 250, 300);     // 250 es lo mas arriba que se puede ir con el cursor y 300 lo mas abajo
  //Variaciones X 115 - 125
  //Variaciones Y 270 - 280 
  
  tiempoActual = millis(); // Mide el tiempo constantemente
  
  if(nivel <= LEVEL_6){          //Si se completaron todos los niveles(6), se pasa a la pantalla de GAME OVER
    maquina(motion);
    cursor(mapX, mapY);
  }

  else{                         //Pantalla de GAME OVER
    tft.fillScreen(BLACK); 
    tft.setTextColor(WHITE); 
    tft.setCursor(40,140);
    tft.setTextSize(3);
    tft.print("GAME OVER");
    digitalWrite(leds,!digitalRead(leds)); // Titilan al terminar los 6 niveles
  }
  
  if(digitalRead(pulsador_1) == LOW and auxMillis_2 == 0){
    disparo(mapX, mapY - 20);
    tiempoAnt = tiempoActual;
    auxMillis_2 = 1; // La variable auxMillis nos determina si nos deja disparar o no, dependiendo del tiempo que paso para cumplir la cadencia
  }
  
  if(((tiempoActual - tiempoAnt) > CADENCIA) and auxMillis_2 == 1){ // Medimos la CADENCIA 
    auxMillis_2 = 0;
  }
  
  if(cantDisparo < 0){ //Paso al proximo nivel
    cantDisparo = 6;
    nivel++;
    impresionUnica = 0;
    auxPantalla = 0;
    auxObj = 0;
    largo = 195;
    if (nivel == LEVEL_4){ // Reseteamos ancho del ladrillo
     Ancho_Ladrillo = 57; 
     motion = 1; //Comienza haber movimiento
   }
  }
}

void maquina(bool movimiento){
  if(movimiento == 0){ // Si no hay movimiento, sucede lo siguiente

    if(auxPantalla == 0){
      level(nivel);                       //Impresion pantalla de nivel
      auxPantalla = 1;
      tft.fillScreen(CYAN);               //Relleno de fondo de pantalla
      tft.fillRect(15,0,210,320,WHITE);   //PATH
      obstaculosSinMov(nivel);            // Impresion obstaculos
      impresionUnica = 1;
    }
  }

  if(movimiento == 1){ // Si hay movimiento, la unica diferencia es el tiempo de refresco de movimiento de los ladrillos

    if(auxPantalla == 0){
      level(nivel);                     //Impresion pantalla de nivel
      auxPantalla = 1;        
      tft.fillScreen(CYAN);             //Relleno de fondo de pantalla
      tft.fillRect(15,0,210,320,WHITE); //PATH
    }

    if((tiempoActual - Tfinal) >= VELOCIDAD){   // Tiempo a trasncurrir para mover los ladrillos
      obstaculosConMov(nivel);                  // Impresion de obstaculos
      Tfinal = tiempoActual;                    //Actualizamos valor
    } 
  }
}

void cursor(int posicionX, int posicionY){
  
  tft.fillTriangle((posicionX-10), posicionY, (posicionX+10), posicionY , posicionX , (posicionY - 20), GREEN);// CURSOR
  tft.fillTriangle((posicionX-10), posicionY, (posicionX+10), posicionY , posicionX , (posicionY - 20), WHITE);// BORRADO DE CURSOR
}

void disparo(int disparoX, int disparoY){
  
   int auxFila;
   int posicion = disparoY - 5;                            // posicion inicial del circulo

  if((verifColision(disparoX, cantDisparo, nivel)) == 0){ // devuelve 0, es decir que va haber colision
    
    score++;                                              // Aumentamos la cantidad de puntos
    auxFila = solicitarFila(cantDisparo);                 // Solicitamos la fila en la que se encuentra

    if (cantDisparo <= 3){                                // Si la cantidad de disparos restantes es menor igual a 3, aumentamos la distancia con la fila, para que no se borre parte del cuadrado
      auxFila += 30 ; //10
    }
    
    while((posicion) > auxFila ){
      tft.fillCircle(disparoX, posicion - 3, 5,BLUE);   // -3 porque es el punto de choque del circulo
      tft.fillCircle(disparoX, posicion - 3, 5,WHITE);
      posicion --;                                      //Movimiento del cursor
    } 
    
    if(posicion == auxFila){
      tft.fillCircle(disparoX, posicion - 3, 5,WHITE);
      borradoHilera();                                  // boramos la hilera
      cantDisparo--;                                    // Se acerto el disparo, se reduce uno la cantidad de disparos
      Fila_Y -= 30;                                     // Pasamos una fila mas arriba porque se acerto el disparo
      
    }
  }

  else{ 
    
    auxFila = solicitarFila(cantDisparo);
    
    if (cantDisparo <= 3){
      auxFila += 30 ;
    }
    while((posicion) > auxFila + 25){                 // Margen de error + 25 para que no borre sin querer cuando la pelota no impacta
      tft.fillCircle(disparoX, posicion, 5,BLUE);
      tft.fillCircle(disparoX, posicion, 5,WHITE);
      posicion --;
    }
    
    if(posicion == auxFila + 30){
      tft.fillCircle(disparoX, posicion, 5,WHITE);
    }
  }
}

void obstaculosSinMov(int level)
{
  Fila_Y = 15;
  //AnchoLadrillo esta inicializado en 57, para el level 1
  
  for(int contFilas = 0; contFilas < 7; contFilas++)            // variable encargada de imprimir diferentes filas
  {
    hilera = random(level + 2);
    
    switch(hilera)
    {
      case 0:
        if(level == 2)
        {
          Ancho_Ladrillo = 41;
          tft.fillRect( INICIO_LADRILLO + (Ancho_Ladrillo + 10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        if(level == 3)
        {
          Ancho_Ladrillo = 30;// en el caso de tener un nivel del tipo 3, al tener mas ladrillos para imprimir, el ancho de estos disminuye e imprime mas ladrillos
          tft.fillRect( INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect( INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
      break;

      case 1:
        if(level == 2)
        {
          Ancho_Ladrillo = 41;
          tft.fillRect( INICIO_LADRILLO + (Ancho_Ladrillo + 10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        if(level == 3)
        {
          Ancho_Ladrillo = 30;// en el caso de tener un nivel del tipo 3, al tener mas ladrillos para imprimir, el ancho de estos disminuye e imprime mas ladrillos
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
      break;

      case 2:
        if(level == 2)
        {
          Ancho_Ladrillo = 41;
          tft.fillRect( INICIO_LADRILLO + (Ancho_Ladrillo + 10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        if(level == 3)
        {
          Ancho_Ladrillo = 30;// en el caso de tener un nivel del tipo 3, al tener mas ladrillos para imprimir, el ancho de estos disminuye e imprime mas ladrillos
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
      break;

      case 3:
      
        Ancho_Ladrillo = 41;
        
        if(level == 3)
        {
          Ancho_Ladrillo = 30;// en el caso de tener un nivel del tipo 3, al tener mas ladrillos para imprimir, el ancho de estos disminuye e imprime mas ladrillos
          tft.fillRect( 20 + (Ancho_Ladrillo + 10) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        }
        tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
      break;

      case 4:
        
        Ancho_Ladrillo = 30;// en el caso de tener un nivel del tipo 3, al tener mas ladrillos para imprimir, el ancho de estos disminuye e imprime mas ladrillos
        tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
        tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
        
      break;

    }
    Fila_Y = Fila_Y + 30;
    rojos[contFilas] = hilera;
  }
  impresionUnica = 1;
}

void obstaculosConMov(int level){
 
  if(auxObj == 0){
    obstaculosSinMov(level - 3); // - 3 ya que es la misma impresion del nivel 1 , pero esta se va a empezar a mover
    auxObj = 1;
    Fila_Y = 195;
  }
  
  switch(level){
    case 4:
    {
      Ancho_Ladrillo = 57;
      switch(rojos[cantDisparo]){
        case 0:{
          tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED); // Printea rojo
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK); // Borra el del estado anterior
          valorAnterior = rojos[cantDisparo]; // Guardamos el valor ya que luego incrementaremos el mismo
          rojos[cantDisparo]++; // Incrementamos valor
        }
        break;

        case 1:{
            tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK); // Borramos estado anterior
            tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED); // printeamos el siguiente en rojo
            valorAnterior = rojos[cantDisparo]; // Guardamos el estado para luego comparar al momento de disparar
            rojos[cantDisparo]++; // Incrementamos valor
        }
        break;

        case 2:{
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo] = 0;
        }
        break;
      }
      
    }
    break;

    case 5:
    {
      Ancho_Ladrillo = 41;
      switch(rojos[cantDisparo]){
        case 0:{
          tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo]++;
        }
        break;

        case 1:{
            tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
            tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
            valorAnterior = rojos[cantDisparo];
            rojos[cantDisparo]++;
        }
        break;

        case 2:{
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo]  ++;
        }
        break;

        case 3:
        {
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo] = 0;
        }
        break;
      }
    }
    break;

    case 6:
    {
      Ancho_Ladrillo = 30;
      switch(rojos[cantDisparo]){
        case 0:{
          tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo]++;
        }
        break;

        case 1:{
            tft.fillRect(INICIO_LADRILLO , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
            tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
            valorAnterior = rojos[cantDisparo];
            rojos[cantDisparo]++;
        }
        break;

        case 2:{
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo + 10) , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo] ++;
        }
        break;

        case 3:
        {
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 2 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo] ++;
        }
        break;

        case 4:
        {
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 3 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , BLACK);
          tft.fillRect(INICIO_LADRILLO + (Ancho_Ladrillo +10 ) * 4 , Fila_Y , Ancho_Ladrillo , ALTO_LADRILLO , RED);
          valorAnterior = rojos[cantDisparo];
          rojos[cantDisparo] = 0;
        }
        break;
      }
    }
    break; 
  }
   
}

int verifColision(int ubicacionX, int numDisparo, int level){

  int valorColumna;             // Almacenar valor de en que columna se encuentra
  int inicialColumna;           // Almacena el valor de donde comienza el cuadrado de la columna en la que se encuentra

  if(level == LEVEL_1 or level == LEVEL_4){

  if(level == LEVEL_1)        // Damos el valor de la columna
    valorColumna = rojos[numDisparo];

  if(level == LEVEL_4)         // Debido que trabajamos con obstaculos en movimiento, debemos usar el valor anterior de la ubicacion de la columna
    valorColumna = valorAnterior;

   
    Ancho_Ladrillo = 57;                                                            // Ancho del ladrillo correspondiente a los niveles 1 y 4
    inicialColumna = INICIO_LADRILLO + ((valorColumna) * (Ancho_Ladrillo + 10));   // + 10 porque es de donde empiezan los rectangulos y 67 es la diferencia entre los obstaculos
    
    if (ubicacionX > inicialColumna and ubicacionX < inicialColumna + Ancho_Ladrillo){
      return 0;  // Si se acerto el disparo, devolvemos un 0
    }
  
    else{
      return 1; // Si no se acerto el disparo, devolvemos un 1
    }
  }

  if(level == LEVEL_2 or level == LEVEL_5){

  if(level == LEVEL_2) // Damos el valor de la columna
    valorColumna = rojos[numDisparo];

  if(level == LEVEL_5) // Debido que trabajamos con obstaculos en movimiento, debemos usar el valor anterior de la ubicacion de la columna
    valorColumna = valorAnterior;

    Ancho_Ladrillo = 41;
    inicialColumna = INICIO_LADRILLO +  ((valorColumna) * (Ancho_Ladrillo + 10)); // + 20 porque es de donde empiezan los rectangulos
    
    if (ubicacionX > inicialColumna and ubicacionX < inicialColumna + Ancho_Ladrillo){
      return 0;
    }
  
    else{
      return 1;
    }
  }
  
  
  if(level == LEVEL_3 or level == LEVEL_6){

  if(level == LEVEL_3) // Damos el valor de la columna
    valorColumna = rojos[numDisparo];

  if(level == LEVEL_6) // Debido que trabajamos con obstaculos en movimiento, debemos usar el valor anterior de la ubicacion de la columna
    valorColumna = valorAnterior;
    
    Ancho_Ladrillo = 30; 
    inicialColumna = INICIO_LADRILLO +  ((valorColumna) * (Ancho_Ladrillo + 10)); // + 20 porque es de donde empiezan los rectangulos
    
    if (ubicacionX > inicialColumna and ubicacionX < inicialColumna + Ancho_Ladrillo){
      return 0;
    }
  
    else{
      return 1;
    }
  }
}

int solicitarFila(int fila){
  
  fila -= 1;                        //restamos uno 
  return 35 + ( 35 * fila);         // debido a como se forma la fila, con esta cuenta nos da la parte inferior del rectangulo

}

void borradoHilera(){
    
   tft.fillRect(INICIO_LADRILLO, largo, 195, ALTO_LADRILLO + 10, WHITE); // lo va borrando automaticamente sin darle ningun valor de referencia a medida que vamos disparando
   largo -= 30;
}

void LoadingScreen()
{
  
  boolean flag_2 = 0;// segundo flag, para la linea de carga
  boolean flag_3 = 0;// tercer flag, para el cartel de loading...
  int i = 0;// variable para la linea de carga
    
  while(flag == 0)
  {
    
    if(flag_4 == 0)
    {
      tft.fillScreen(BLACK);
      tft.setCursor(55,30);
      tft.setTextColor(MAGENTA);
      tft.setTextSize(3);
      tft.print("WELCOME");
      tft.drawFastHLine(55,56,123,MAGENTA);
      tft.setCursor(5,270);
      tft.setTextSize(2);
      tft.print("Developed by:");
      tft.setCursor(10,85);
      tft.setTextSize(2.8);
      tft.print("Press any key");
      tft.setCursor(5,300);
      tft.setTextSize(1);
      tft.print("Giancarlo Moroni and Juan Pablo Birsa");
      tft.setCursor(5,170);
      tft.setTextSize(2);
      tft.print("START");
      flag_4 = 1;
    }
    
    if(digitalRead(pulsador_1) == LOW or digitalRead(pulsador_2) == LOW)
    {
      tft.setCursor(5,170);
      tft.setTextColor(GREEN);
      tft.print("START");
      if(auxMillis == 0){
        tiempo_inicial = millis();
        auxMillis = 1;
      } 
      while(flag_2 == 0)                // PUSE TANTOS WHILE PARA QUE SE EJECUTE UNA SOLA VEZ POR TAREA
      {
         if(flag_3 == 0)
         {
           tft.setCursor(65,215);
           tft.print("LOADING...");
           flag_3 = 1; 
         }
         tft.drawFastHLine(0,200,i/30,GREEN);
         i++;
         if( i > 7200/* (240*30) = 7200 */)
         {
          flag_2 = 1; // Sale del primer while
         } 
      }
    }
    if(auxMillis == 1)
      tiempo_final = millis();
    
    if((tiempo_final - tiempo_inicial) >= 3500){
      auxMillis = 0;
      flag = 1; // Sale del segundo while
    }  
  }
}

void level (int nivel){

  unsigned long tiempo_inicial = millis();
  unsigned long tiempo_final;
  boolean flag = 0;
  tft.fillScreen(BLACK); 
  tft.setTextColor(WHITE); 
  while(flag == 0){
    tiempo_final = millis();
    tft.setCursor(60,140);
    tft.setTextSize(3);
    tft.print("Level ");
    tft.print(nivel);
    if((tiempo_final - tiempo_inicial) >= 5000){ // en esta parte del codigo es bloqueante, quizas conviene sacar esto y ponerlo en el loop
      flag = 1;
    }
}
}
