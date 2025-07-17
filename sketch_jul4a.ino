const int potPin = 2;// Potentiometer connected to GPI027
const int ledPin = 5;//LED connected to GPI02

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);//Range: 0-4095
  int brightness = map(potValue, 0, 4095, 0, 1023);//Manual PWM range

  //Simple PWM using delayMicroseconds
  for(int i = 0; i < 50; i++) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(brightness); //On-time
    digitalWrite(ledPin, LOW);
    delayMicroseconds(1023 - brightness); //off-time
  }

  Serial.println(brightness);
}