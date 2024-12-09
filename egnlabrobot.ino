// Motor output pins, may have to change polarity of motors based on your wiring
int motorR1 = 7; 
int motorR2 = 2;
int motorL1 = 3;
int motorL2 = 4;

// These should be set to the DO pins on the LDR sensors
int sensorR = 8; 
int sensorL = 6;

void setup() {
  Serial.begin(9600);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(sensorR, INPUT);
  pinMode(sensorL, INPUT);
}

void loop() {
  int ldrRight = digitalRead(sensorR);
  int ldrLeft = digitalRead(sensorL);

  if (!ldrRight && !ldrLeft) {
    forward();
  }
  else if (!ldrRight) {
    right();
  }
  else if (!ldrLeft) {
    left();
  }
  else {
    allStop();
  }
}

void forward() {
  Serial.println("forward");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void right() {
  Serial.println("right");
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void left() {
  Serial.println("left");
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
}

void allStop() {
  Serial.println("stop");
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
}
