#include <Keyboard.h>

const int nuButton=2;
const int huButton=3;
const int nuhuButton=4;
bool loopflg=false;

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  pinMode(nuButton, INPUT_PULLUP);
  pinMode(huButton, INPUT_PULLUP);
  pinMode(nuhuButton, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(nuButton)==0){
    loopflg=false;
    // Nu
    Keyboard.print("nu");
    for (int i=0;i<20;i++){
      delay(20);
      if (digitalRead(nuButton)==1) return;
    }
    while (digitalRead(nuButton)==0){
      Keyboard.print("nu");
      delay(80);
    }
  } else if (digitalRead(huButton)==0){
    loopflg=false;
    // Hu
    Keyboard.print("hu");
    for (int i=0;i<20;i++){
      delay(20);
      if (digitalRead(huButton)==1) return;
    }
    while (digitalRead(huButton)==0){
      Keyboard.print("hu");
      delay(80);
    }
  } else if (digitalRead(nuhuButton)==0){
    // Nuhu
    loopflg=!loopflg;
    while (digitalRead(nuhuButton)==0);
  }
  
  if (loopflg) {
    Keyboard.print("nuhu");
  }
  
  delay(50);
}
