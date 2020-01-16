int led = 13;
int pot = A0;
String input;
int bright = 0;
int incr = 5;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
  Serial.print("1-On | 2-Off | 3-Fade | 4-Blink | 5-Pot Controlled");
}

void loop() {
  
  while (Serial.available() > 0){
    input = (char) Serial.read();
    delay(5);
  }
    if(input=="1"){
      analogWrite(led,200);
    }
    else if(input=="2"){
      analogWrite(led,0);
    }
    else if(input=="3"){
      analogWrite(led, bright);
      bright = bright + incr;
      if (bright <= 0 || bright >= 255) {
        incr = -incr;
      }
      delay(30);
    }
    else if(input=="4"){
      analogWrite(led, 255);
      delay(500);
      analogWrite(led, 0);
      delay(500);
    }
    else if(input=="5"){
      int potval = analogRead(pot);
      potval = map(potval,0,1023,0,255);
      analogWrite(led,potval);
    }
    else{
      analogWrite(led,0);
    }
  
}
