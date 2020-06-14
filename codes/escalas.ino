// Tones table definition
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int pitch[] = {
 NOTE_B0,
 NOTE_C1,
 NOTE_CS1,
 NOTE_D1,
 NOTE_DS1,
 NOTE_E1,
 NOTE_F1,
 NOTE_FS1,
 NOTE_G1,
 NOTE_GS1,
 NOTE_A1,
 NOTE_AS1,
 NOTE_B1,
 NOTE_C2,
 NOTE_CS2,
 NOTE_D2,
 NOTE_DS2,
 NOTE_E2,
 NOTE_F2,
 NOTE_FS2,
 NOTE_G2,
 NOTE_GS2,
 NOTE_A2,
 NOTE_AS2,
 NOTE_B2,
 NOTE_C3,
 NOTE_CS3,
 NOTE_D3,
 NOTE_DS3,
 NOTE_E3,
 NOTE_F3,
 NOTE_FS3,
 NOTE_G3,
 NOTE_GS3,
 NOTE_A3,
 NOTE_AS3,
 NOTE_B3,
 NOTE_C4,
 NOTE_CS4,
 NOTE_D4,
 NOTE_DS4,
 NOTE_E4,
 NOTE_F4,
 NOTE_FS4,
 NOTE_G4,
 NOTE_GS4,
 NOTE_A4,
 NOTE_AS4,
 NOTE_B4,
 NOTE_C5,
 NOTE_CS5,
 NOTE_D5,
 NOTE_DS5,
 NOTE_E5,
 NOTE_F5,
 NOTE_FS5,
 NOTE_G5,
 NOTE_GS5,
 NOTE_A5,
 NOTE_AS5,
 NOTE_B5,
 NOTE_C6,
 NOTE_CS6,
 NOTE_D6,
 NOTE_DS6,
 NOTE_E6,
 NOTE_F6,
 NOTE_FS6,
 NOTE_G6,
 NOTE_GS6,
 NOTE_A6,
 NOTE_AS6,
 NOTE_B6,
 NOTE_C7,
 NOTE_CS7,
 NOTE_D7,
 NOTE_DS7,
 NOTE_E7,
 NOTE_F7,
 NOTE_FS7,
 NOTE_G7,
 NOTE_GS7,
 NOTE_A7,
 NOTE_AS7,
 NOTE_B7,
 NOTE_C8,
 NOTE_CS8,
 NOTE_D8,
 NOTE_DS8};

//const int tonosme[] = {0 ,-3, -2, -2, -3, -2, -3, -3, -2, -2, -3, -2, -3};
const int tonosme[] = {0 ,-3, -5, -7, -10, -12, -15, -18, -20, -22, -25, -27, -30}; // separación de pentatonica menor el 22 tiene que ser una variable, para cambiar de tono
//const int tonosma[] = {0, 2, 2, 3, 2, 3, 2, 2, 3, 2, 3, 2, 2}; // separación de pentatonica mayor
//const int tono[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
String escala[] = {"tonosme" , "tonosma"};
//const int countTonos = 13;
const int i = 25;
const int e = 1;

 // C = 25 Cs = 26 D =2 Ds = 30  E = 31  F = 32 Fs = 33  G = 34  Gs = 35   A = 36  As = 37 B = 38


const int EchoPin = 9;
const int TriggerPin = 10;
const int pinBuzzer = 7;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}

void loop() {
   int cm = ping(TriggerPin, EchoPin);
 // intervalos para entrar en cada nota.. HAyque dar intervalos de distancia en cm para entrar en las 11 notas
//

  // if(digitalRead(3)==HIGH){
                                   //cm de separación
          // Mapping the value of the Potentiometer to have a wider range of values
     if (cm >= 2 && cm <= 40) {
/*
      if ((cm>=4) && (cm<6)) // Discretization of the pot intervals - in order to assign the note
    tone(pinBuzzer,(pitch[i]+tonosme[12]));  //cambiar el pitch de
      if ((cm>=6) && (cm<8))
    tone(pinBuzzer,(pitch[i]+tonosme[11]));
       if ((cm>=8) && (cm<10))
    tone(pinBuzzer,(pitch[i]+tonosme[10]));
      if ((cm>=10) && (cm<12))
    tone(pinBuzzer,(pitch[i]+tonosme[9]));
      if ((cm>=12) && (cm<14))
    tone(pinBuzzer,(pitch[i]+tonosme[8]));
      if ((cm>=14) && (cm<16))
    tone(pinBuzzer,(pitch[i]+tonosme[7]));
      if ((cm>=16) && (cm<18))
    tone(pinBuzzer,(pitch[i]+tonosme[6]));
      if ((cm>=18) && (cm<20))
    tone(pinBuzzer,(pitch[i]+tonosme[5]));
      if ((cm>=20) && (cm<22))
    tone(pinBuzzer,(pitch[i]+tonosme[4]));
      if ((cm>=22) && (cm<=24))
    tone(pinBuzzer,(pitch[i]+tonosme[3]));
      if ((cm>=24) && (cm<=26))
    tone(pinBuzzer,(pitch[i]+tonosme[2]));
      if ((cm>=26) && (cm<=28))
    tone(pinBuzzer,(pitch[i]+tonosme[1]));
      if ((cm>=28) && (cm<=30))
    tone(pinBuzzer,(pitch[i]+tonosme[0]));
 }
 else noTone(pinBuzzer);

*/


      if ((cm>=4) && (cm<6)) // Discretization of the pot intervals - in order to assign the note
    tone(pinBuzzer,(tonosme[11]));  //cambiar el pitch de
      if ((cm>=6) && (cm<8))
    tone(pinBuzzer,pitch[i]+tonosme[11]);
       if ((cm>=8) && (cm<10))
    tone(pinBuzzer,pitch[i]+tonosme[10]);
      if ((cm>=10) && (cm<12))
    tone(pinBuzzer,pitch[i]+tonosme[9]);
      if ((cm>=12) && (cm<14))
    tone(pinBuzzer,pitch[i]+tonosme[8]);
      if ((cm>=14) && (cm<16))
    tone(pinBuzzer,pitch[i]+tonosme[7]);
      if ((cm>=16) && (cm<18))
    tone(pinBuzzer,(pitch[i]+tonosme[6]));
      if ((cm>=18) && (cm<20))
    tone(pinBuzzer,(pitch[i]+tonosme[5]));
      if ((cm>=20) && (cm<22))
    tone(pinBuzzer,(pitch[i]+tonosme[4]));
      if ((cm>=22) && (cm<=24))
    tone(pinBuzzer,(pitch[i]+tonosme[3]));
      if ((cm>=24) && (cm<=26))
    tone(pinBuzzer,(pitch[i]+tonosme[2]));
      if ((cm>=26) && (cm<=28))
    tone(pinBuzzer,(pitch[i]+tonosme[1]));
      if ((cm>=28) && (cm<=30))
    tone(pinBuzzer,(pitch[i]+tonosme[0]));
 }
 else noTone(pinBuzzer);





   Serial.print("  Distancia cm:  ");
   Serial.println(cm);
    Serial.println ("--------- escala ------");
   Serial.println (pitch[i]);

   delay(5);




}

int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;

   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);

   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}