const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;

const int ENB = 3;
const int IN3 = 5;
const int IN4 = 4;

const int S1 = A0;
const int S2 = A1;
const int S3 = A2;
const int S4 = A3;
const int S5 = A4;
const int S6 = A5;

const int baseSpeed = 150;
const int turnSpeed = 120;
const int sharpTurnSpeed = 180;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);

  Serial.begin(9600);
}

void loop() {
  int val1 = digitalRead(S1);
  int val2 = digitalRead(S2);
  int val3 = digitalRead(S3);
  int val4 = digitalRead(S4);
  int val5 = digitalRead(S5);
  int val6 = digitalRead(S6);

  if (val1 == 1) {
    sharpLeft();
  }
  else if (val6 == 1) {
    sharpRight();
  }
  else if (val2 == 1) {
    turnLeft();
  }
  else if (val5 == 1) {
    turnRight();
  }
  else if (val3 == 1 || val4 == 1) {
    moveForward();
  }
  else {
    stopBot();
  }
}

void moveForward() {
  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, turnSpeed / 2); 
  analogWrite(ENB, turnSpeed);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed / 2);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void sharpLeft() {
  analogWrite(ENA, sharpTurnSpeed);
  analogWrite(ENB, sharpTurnSpeed);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void sharpRight() {
  analogWrite(ENA, sharpTurnSpeed);
  analogWrite(ENB, sharpTurnSpeed);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopBot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}