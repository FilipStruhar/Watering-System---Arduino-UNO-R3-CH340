#include <Arduino.h>

// === Piny ===
const int soilSensorPin = A0;    // Analogový pin pro senzor vlhkosti
const int relayPin = 7;          // Digitální pin pro relé (IN)

const int dryThreshold = 600;    // Mezní hodnota — vyšší = sušší půda


// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);

  pinMode(soilSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW); // Na začátku čerpadlo vypnuté (LOW = vypnuto při HIGH-trig.)
}

void loop() {
  int soilValue = analogRead(soilSensorPin);
  Serial.print("Soil moisture value: ");
  Serial.println(soilValue);

  if (soilValue > dryThreshold) {
    // Půda je suchá → sepni čerpadlo
    digitalWrite(relayPin, HIGH);
    Serial.println("Zalévám...");
  } else {
    // Půda je dost vlhká → vypni čerpadlo
    digitalWrite(relayPin, LOW);
    Serial.println("Dostatečná vlhkost, nezalévám.");
  }

  delay(2000); // Čekej 2 sekundy mezi měřeními
}