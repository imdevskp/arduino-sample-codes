int led = 13;
int pot = A0;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
}

void loop() {
  int potval = analogRead(pot);
  potval = map(potval,0,1023,0,255);
  analogWrite(led,potval);
}
