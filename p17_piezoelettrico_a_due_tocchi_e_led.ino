/*
 * Accensione del led mediante doppio tocco su sensore piezoelettrico
 */
const int sensorPin = A0;           // dichiara il pin del piezoelettrico
const int readDelay = 50;           // dichiara intervallo di pulizia del dato
const int knockDelay = 300;         // dichiara intervallo per due tocchi consecutivi
const int ledPin = 13;              // dichiara il pin del led
int sensorValue = 0;                // assegna a 0 il valore del sensore in ingresso
int maxInput = 0;                   // assegna a 0 il valore massimo
int ledValue = LOW;                 // spegne il led
long lastReadTime = 0;              
long readInterval = 0;              // due variabili per la routine di pulizia del dato
long lastKnockTime = 0;             
long knockInterval = 0;             // due variabili per rilevare il doppio tocco
  void setup() {
    pinMode (ledPin,OUTPUT);            // dichiara il pin del led come output
    Serial.begin (9600);                // dichiara il monitor seriale
  }
  void loop() {
    sensorValue = analogRead(sensorPin);                  // legge il valore del piezo e lo assegna alla variabile
    if (sensorValue > 0) lastReadTime = millis();         // verifica del dato letto dal sensore
    if (maxInput < sensorValue) maxInput = sensorValue;   // calcolo dell'intervallo
    readInterval = millis () - lastReadTime;              routine eseguita quando l'imput è terminto
    if(sensorValue == 0 && maxInput > 0 && readInterval > readDelay) {    // valore comunicato solo se superiore alla soglia
    if(maxInput>potValue) {                               
    knockInterval = millis() - lastKnockTime;
    if (knockInterval < knockDelay) {
    Serial.println("doppio knock");
    ledValue = !ledValue;
    digitalWrite (ledPin, ledValue);
  } else {
      lastKnockTime = millis();   }     }
maxInput = 0;                                             // reset della variabile
}
}
