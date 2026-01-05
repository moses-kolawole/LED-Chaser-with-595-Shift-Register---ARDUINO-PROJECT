int latchpin = 11;
int clockpin = 9;
int datapin = 12;

int button1 = A0;
int button2 = A1;
int button3 = A2;
int button4 = A3;

int button1_state;
int button2_state;
int button3_state;
int button4_state;

int pattern_state = 0;
int LEDS1 = 2;
int LEDS2 = 255;
byte LEDS3 = 0x0f;
byte LEDS4 = 0b11001100;

int delay_time = 500;


void pattern(int n){
  switch(n){
    case 1:
    for(int i = 0; i < 8; i++){
      digitalWrite(latchpin, LOW);
      shiftOut(datapin, clockpin, LSBFIRST, LEDS1);
      LEDS1 = int(LEDS1 * 2);
      delay(delay_time);
      digitalWrite(latchpin, HIGH);
      if(LEDS1 == 256){
        LEDS1 = 2;
        }
    }
      break;


      case 2:
      for(int i = 0; i < 8; i++){
      digitalWrite(latchpin, LOW);
      shiftOut(datapin, clockpin, LSBFIRST, LEDS2);
      LEDS2 = int(LEDS2 / 2);
      delay(delay_time);
      digitalWrite(latchpin, HIGH);
      if(LEDS2 == 0){
        LEDS2 = 255;
        }
      }
      break;


      case 3:
      digitalWrite(latchpin, LOW);
      shiftOut(datapin, clockpin, LSBFIRST, LEDS3);
      delay(delay_time);
      digitalWrite(latchpin, HIGH);
      digitalWrite(latchpin, LOW);
      shiftOut(datapin, clockpin, MSBFIRST, LEDS3);
      delay(delay_time);
      digitalWrite(latchpin, HIGH);
      break;


      case 4:
      digitalWrite(latchpin, LOW);
      shiftOut(datapin, clockpin, LSBFIRST, LEDS4);
      delay(delay_time);
      digitalWrite(latchpin, HIGH);
      LEDS4 = (LEDS4 * 128) + (LEDS4 / 2);
      break;
}
  }


void setup() {
  // put your setup code here, to run once:

pinMode(latchpin, OUTPUT);
pinMode(clockpin, OUTPUT);
pinMode(datapin, OUTPUT);

pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);

}


void loop() {
// put your main code here, to run repeatedly:
button1_state = digitalRead(button1);
button2_state = digitalRead(button2);
button3_state = digitalRead(button3);
button4_state = digitalRead(button4);


if(button1_state == 1){
  pattern_state = 1;
}else if(button2_state == 1){
  pattern_state = 2;
}
else if (button3_state == 1){
  pattern_state = 3;
}
else if(button4_state == 1){
  pattern_state = 4;
}

pattern(pattern_state);

}
