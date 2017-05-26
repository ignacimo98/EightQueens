
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      64

String a;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup () {
     pixels.begin();
     pixels.show();
     Serial.begin(9600);
     while(!Serial) { ; }
     pinMode(LED_BUILTIN, OUTPUT);
}
void loop () {
//    Serial.print("Hello World");


      

      while(Serial.available()) {

        char received[16];
  
        a= Serial.readBytes(received, 16);// read the incoming data as string


        int i;
        int maxCol = 0;

        if (a == "16"){
        int toTurnOn;
        float cantCols = -1;

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
         for (i = 0; i < 65; i++){
          pixels.setPixelColor(i, pixels.Color(0,0,0));
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
