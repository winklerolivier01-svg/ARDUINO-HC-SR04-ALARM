#define TRIG 9
#define ECHO 10
#define BUZZER 13
#define LED 11

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
  
  Serial.begin(9600);
}

void loop() {
  long duree;
  int distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duree = pulseIn(ECHO, HIGH, 30000);
  
  if (duree > 0) {
    distance = duree * 0.034 / 2;
  } else {
    distance = 999;
  }
  
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 20) {
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  
  delay(100);
}
