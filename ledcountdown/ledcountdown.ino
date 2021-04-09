int LED=8;
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  counter = counter+1;
  Serial.print("Blink Number # ");
  Serial.println(counter);
digitalWrite(LED, HIGH);
delay(1000-counter);
digitalWrite(LED, LOW);
delay(1000-counter);
}
