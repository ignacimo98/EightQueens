
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      64

String a;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);


void setup () {
     pixels.begin();
             int i;

         int fila = 0;
         for (i = 0; i < 65; i++){

          if ((i) % 8 == 0){
            fila++;
            }
          
          if(i%2 == 0 and fila % 2 == 0){
            pixels.setPixelColor(i, pixels.Color(0,0,0));
          } 
          else if(i%2 == 0 and fila % 2 == 1){
            pixels.setPixelColor(i, pixels.Color(150,150,150));
          }
          else if(i%2 == 1 and fila % 2 == 0){
            pixels.setPixelColor(i, pixels.Color(150,150,150));
            }
          else if(i%2 == 1 and fila % 2 == 1){
            pixels.setPixelColor(i, pixels.Color(0,0,0));
            }
          } 
     pixels.show();
     Serial.begin(9600);
     while(!Serial) { ; }
     pinMode(LED_BUILTIN, OUTPUT);
}
void loop () {
//    Serial.print("Hello World");


      int listaLeds[8];

      while(Serial.available()) {

        char received[16];
  
        a= Serial.readBytes(received, 16);// read the incoming data as string


        int i;
        int maxCol = 0;

        

        if (a == "16"){
        int toTurnOn;
        float cantCols = -1;

        if (received[0] == 'D'){
          done(listaLeds);
          }

        for (i = 0; i < 16; i += 2){
          if (received[i] == '-'){
            break;
            }
            cantCols++;
        }


        for (i = 0; i < 16; i += 2){
          if (received[i] == '-'){

//            pixels.setPixelColor(maxCol, pixels.Color(c,69,69));
            break;
            }
          char number[2] = {received[i], received[i+1]};
          toTurnOn = atoi(number);
          listaLeds[i/2] = toTurnOn;
          if(toTurnOn % 8 > maxCol % 8)
            maxCol = toTurnOn;
          int colorVerde = 0;
          int colorRojo = 0;

          if (cantCols == 0){
            colorRojo = 0;
          }
          else{
            Serial.println("Entró!");
            colorRojo = ((toTurnOn % 8) / cantCols) * 255;
            Serial.println(cantCols);
            
            Serial.println(colorRojo);
          }


          colorVerde = 255 - colorRojo;
          
          
          pixels.setPixelColor(toTurnOn, pixels.Color(colorRojo, colorVerde, 0));
          
//          pixels.setPixelColor(toTurnOn, pixels.Color((toTurnOn % 8+1)*(255/(cantCols)),0*(cantCols - (toTurnOn % 8)-1)*(255/cantCols),0));
          }
          pixels.show();

//        while( !received.startsWith('-') ){
//          int toTurnOn = a.substring(0,2).toInt();
//          Serial.print(toTurnOn);
//          pixels.setPixelColor(toTurnOn, pixels.Color(0,0,150));
//          a = a.substring(2);
//          }
//         pixels.show();
//         int i;

         int fila = 0;
         for (i = 0; i < 65; i++){

          if ((i) % 8 == 0){
            fila++;
            }
          
          if(i%2 == 0 and fila % 2 == 0){
            pixels.setPixelColor(i, pixels.Color(0,0,0));
          } 
          else if(i%2 == 0 and fila % 2 == 1){
            pixels.setPixelColor(i, pixels.Color(150,150,150));
          }
          else if(i%2 == 1 and fila % 2 == 0){
            pixels.setPixelColor(i, pixels.Color(150,150,150));
            }
          else if(i%2 == 1 and fila % 2 == 1){
            pixels.setPixelColor(i, pixels.Color(0,0,0));
            }
          } 
//         Serial.flush();

//        if (a.startsWith("E")){
//          String color = a.substring(1,2);
//          Serial.print("Enc");
//          Serial.print(a.substring(2));
//          if (color == "R"){
//            pixels.setPixelColor(a.substring(2).toInt(), pixels.Color(150,0,0));
//          }
//          else if (color == "B"){
//            pixels.setPixelColor(a.substring(2).toInt(), pixels.Color(0,0,150));
//          }
//          else if (color == "G"){
//            pixels.setPixelColor(a.substring(2).toInt(), pixels.Color(0,150,0));
//          }
//        }
//
//        else if (a.startsWith("A")){
//          Serial.print("Apa");
//          Serial.print(a.substring(1));
//          pixels.setPixelColor(a.substring(1).toInt(), pixels.Color(0,0,0));
//          }
//        pixels.show();
        }

}
delay(0);
}

int x    = matrix.width();
int pass = 0;

void done(int listaLeds[8]){
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(matrix.Color(255, 102, 204));
  
  int i;

  int fila = 0;
  for (i = 0; i < 65; i++){
  
  if ((i) % 8 == 0){
    fila++;
    }
  
  if(i%2 == 0 and fila % 2 == 0){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  } 
  else if(i%2 == 0 and fila % 2 == 1){
    pixels.setPixelColor(i, pixels.Color(150,150,150));
  }
  else if(i%2 == 1 and fila % 2 == 0){
    pixels.setPixelColor(i, pixels.Color(150,150,150));
    }
  else if(i%2 == 1 and fila % 2 == 1){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  } 

  pixels.show();
  delay(250);
  
  for (i = 0; i < 8; i++){
    pixels.setPixelColor(listaLeds[i], pixels.Color(0,0,255));
    }

  pixels.show();
  delay(250);

  fila = 0;

    for (i = 0; i < 65; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    
  } 

  pixels.show();
  delay(250);
  
  for (i = 0; i < 8; i++){
    pixels.setPixelColor(listaLeds[i], pixels.Color(200,100,255));
    }

  pixels.show();
  delay(250);

  for (i = 0; i < 65; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    
  }
  pixels.show();
  delay(250);
  
  fila = 0;
    for (i = 0; i < 65; i++){
  
  if ((i) % 8 == 0){
    fila++;
    }
  
  if(i%2 == 0 and fila % 2 == 0){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  } 
  else if(i%2 == 0 and fila % 2 == 1){
    pixels.setPixelColor(i, pixels.Color(150,150,150));
  }
  else if(i%2 == 1 and fila % 2 == 0){
    pixels.setPixelColor(i, pixels.Color(150,150,150));
    }
  else if(i%2 == 1 and fila % 2 == 1){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  } 
  
  for (i = 0; i < 8; i++){
    int colorRojo, colorVerde;
   
    colorRojo = ((listaLeds[i] % 8) / 8) * 255;
    colorVerde = 255 - colorRojo;

    pixels.setPixelColor(listaLeds[i], pixels.Color(colorRojo, colorVerde, 0));
            
      
    }
    
  pixels.show();
  delay(3000);


  while(true){
    matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("Isaac Rico :3"));
  if(--x < -74) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(matrix.Color(255, 102, 204));
  }
  matrix.show();
  delay(150);
  }
  
  }
