int leds = 6;

void setup() {
  // put your setup code here, to run once:
  for(int i=1;i<leds+1;i++){
   pinMode(i,OUTPUT); 
  }
}

void loop() {
    for(int i=1;i<leds;i++){
     Blink(i,100); 
    }
    for(int i=leds;i>1;i--){
     Blink(i,100); 
    }
}

void Blink(int port, int dur){
    digitalWrite(port,HIGH);
    delay(dur);
    digitalWrite(port,LOW);
}
