float Pi = 3.141593;
int inputH;
int inputD;
int outputV;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Ingevoerde getallen moeten in cm zijn");
  Serial.print("Cylinder hooghte: ");
  while (Serial.available() == 0) {}
  inputH = Serial.parseInt();
  Serial.println(inputH);
  
  Serial.print("Cylinder diameter: ");
  while (Serial.available() == 0) {}
  inputD = Serial.parseInt();
  Serial.println(inputD);
  
  outputV = Pi * (inputD / 2) * (inputD / 2) * inputH;
  Serial.print("Cylinder volume is: ");
  Serial.print(outputV);
  Serial.println("cm3");
  Serial.println("");
}
