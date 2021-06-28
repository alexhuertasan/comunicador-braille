byte Braille[255];
byte ascii;
byte mascara = 1; //Permitira extraer ciertos bits de una cadena binaria almacenada en otro conjunto

void setup() {
   for (int i = 0; i < 255; i = i + 1) {
    Braille[i] = 255; // Inicialmente, se asigna el valor 255 a todos los valores del array Braille[i]
  } 

  // A continuación, se crea un diccionario codigo ASCII - codigoBinario
  Braille[32] = 0;  // espacio en blanco 000000
  Braille[33] = 26;  // exclamacion ¡! 011010
  Braille[34] = 25;  // comillas dobles 011001
  Braille[40] = 27;  // parentesis izquierdo 011011
  Braille[41] = 27;  // parentesis derecho 011011
  Braille[42] = 10;  // asterisco/multiplicacion * 001010
  Braille[43] = 26;  // mas +
  Braille[44] = 16;  // coma , 010000
  Braille[45] = 9;  // menos/guion - 001001
  Braille[46] = 8;  // punto .  010011
  Braille[47] = 19; // division / 010011
  Braille[48] = 22; // 0  011100
  Braille[49] = 32; // 1  100000
  Braille[50] = 48; // 2  101000
  Braille[51] = 36; // 3  110000
  Braille[52] = 38; // 4  110100
  Braille[53] = 34; // 5  100100
  Braille[54] = 52; // 6  111000
  Braille[55] = 53; // 7  111100
  Braille[56] = 50; // 8  101100
  Braille[57] = 20; // 9  011000
  Braille[58] = 24; // dos puntos 011000  
  Braille[59] = 18; // punto y coma 010010
  Braille[61] = 15; // igual = 001111
  Braille[63] = 17; // interrogacion 010001
  Braille[64] = 35; // arroba @ 100011
  Braille[65]  = 32; // A  100000
  Braille[66]  = 48; // B  110000
  Braille[67]  = 36; // C  100100
  Braille[68]  = 38; // D  100110
  Braille[69]  = 34; // E  100010
  Braille[70]  = 52; // F  110100
  Braille[71]  = 54; // G  110110
  Braille[72]  = 50; // H  110010
  Braille[73]  = 20; // I  010100
  Braille[74]  = 22; // J  010110
  Braille[75]  = 40; // K  101000
  Braille[76]  = 56; // L  111000
  Braille[77]  = 44; // M  101100
  Braille[78]  = 46; // N  101110
  Braille[164] = 39; // Ñ  110111  
  Braille[79]  = 42; // O  101010
  Braille[80]  = 60; // P  111100
  Braille[81]  = 62; // Q  111110
  Braille[82]  = 58; // R  111010
  Braille[83]  = 28; // S  011100
  Braille[84]  = 30; // T  011110
  Braille[85]  = 41; // U  101001
  Braille[86]  = 57; // V  111001
  Braille[87]  = 23; // W  010111
  Braille[88]  = 45; // X  101101
  Braille[89]  = 47; // Y  101111
  Braille[90]  = 43; // Z  101011
 
  Braille[97]  = 32; // a  100000
  Braille[98]  = 48; // b  110000
  Braille[99]  = 36; // c  100100
  Braille[100] = 38; // d  100110
  Braille[101] = 34; // e  100010
  Braille[102] = 52; // f  110100
  Braille[103] = 54; // g  110110
  Braille[104] = 50; // h  110010
  Braille[105] = 20; // i  010100
  Braille[106] = 22; // j  010110
  Braille[107] = 40; // k  101000
  Braille[108] = 56; // l  111000
  Braille[109] = 44; // m  101100
  Braille[110] = 46; // n  101110
  Braille[195] = 39; // ñ  110111
  Braille[111] = 42; // o  101010
  Braille[112] = 60; // p  111100
  Braille[113] = 62; // q  111110
  Braille[114] = 58; // r  111010
  Braille[115] = 28; // s  011100
  Braille[116] = 30; // t  011110
  Braille[117] = 41; // u  101001
  Braille[118] = 57; // v  111001
  Braille[119] = 23; // w  010111
  Braille[120] = 45; // x  101101
  Braille[121] = 47; // y  101111
  Braille[122] = 43; // z  101011
  
  //Inicializacion de los pines de salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);

  Serial.begin(9600); // inicio de la transmisión serie
  

  //Inicializacion de todos los puntos
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  delay(1000);
  
  Serial.println("Introduce una frase");
}


void loop() {
  
   // Comprueba si hay información en el puerto Serie
    if (digitalRead(8) == HIGH) {
    digitalWrite(2, HIGH);
 
  }
  else {
    digitalWrite(2, LOW);
  }
   
   if (Serial.available() > 0) {
    
      // lee el byte entrante:
      ascii = Serial.read();
      
      // se muestra en pantalla el dato recibido
      Serial.print("Recibido (ascii): ");
      Serial.println(ascii);
      
      // comprueba ascii en la array Braille
      Serial.print("Valor binario Modulo Braille (Braille[ascii]): ");
      Serial.println(Braille[ascii]);

      
      // Compara si es un caracter válido o no
      if (Braille[ascii] == 255) 
      {
         Serial.println("Caracter no traducible");
         delay(500); 
        
      }
       else{ 
              int pinActual = 2;
              for (mascara = 000001; mascara<64; mascara <<= 1) {  //desplaza una posición hacia la izquierda
                   
                  if (Braille[ascii] & mascara){ 
                     digitalWrite(pinActual,HIGH); // estado arriba      
                  }
                  else{     
                     digitalWrite(pinActual,LOW); //estado abajo     
                  }
              pinActual = pinActual + 1;   // avanza al siguiente pin de salida
              }
      } 
      delay(2000); // tiempo de espera entre caracteres
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      delay(200);
   }
}
