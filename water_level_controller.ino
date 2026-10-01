/*
  Automatic Water Level Controller with Pump Cutoff
  Board: Arduino Uno | Sensor: HC-SR04 | Output: relay module

  Example thresholds:
  Start filling when distance >= 15 cm
  Stop filling when distance <= 5 cm

  Verify relay polarity and calibrate thresholds before use.
  This is starter code; hardware testing is pending.
*/
const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const byte RELAY_PIN = 7;

const float LOW_LEVEL_CM = 15.0;
const float FULL_LEVEL_CM = 5.0;

const byte RELAY_ON = LOW;   // Common active-LOW relay module
const byte RELAY_OFF = HIGH;

const unsigned long ECHO_TIMEOUT_US = 30000;
const unsigned long SAMPLE_DELAY_MS = 1000;

bool pumpOn = false;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);
  if (duration == 0) return -1.0;

  return duration * 0.0343 / 2.0;
}

void setPump(bool state) {
  pumpOn = state;
  digitalWrite(RELAY_PIN, pumpOn ? RELAY_ON : RELAY_OFF);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(RELAY_PIN, RELAY_OFF);
  pumpOn = false;

  Serial.begin(9600);
  Serial.println("Water Level Controller Started");
  Serial.println("Pump initialized to OFF");
}

void loop() {
  float distance = readDistanceCm();

  if (distance < 0 || distance > 400) {
    setPump(false);
    Serial.println("Invalid sensor reading: Pump OFF");
    delay(SAMPLE_DELAY_MS);
    return;
  }

  if (!pumpOn && distance >= LOW_LEVEL_CM) {
    setPump(true);
    Serial.println("Low level detected: Pump ON");
  } else if (pumpOn && distance <= FULL_LEVEL_CM) {
    setPump(false);
    Serial.println("Full level detected: Pump OFF");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Pump: ");
  Serial.println(pumpOn ? "ON" : "OFF");

  delay(SAMPLE_DELAY_MS);
}
