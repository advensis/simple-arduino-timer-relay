/*
  Simple Timer Relay for Arduino
  by Advensis Co.
  https://advensis.co

  Small Arduino app that makes it work together with relay module 
  like a timer relay. In exact code it will be off for 15 minutes 
  and on for 1 minute.
*/

// You if DEBUG is 1 then can connect board to computer with USB and 
// use Serial Monitor to see when relay should on or off.
#define DEBUG 1

// This defines a pin where you need to connect the relay COM pin.
#define RELAY1PIN 13

// Define how long relay should be off and how long on.
#define OFFPERIOD 900
#define ONPERIOD 60

// Counter variables used to see how long the cycle still should work.
int relayOff = 0;
int relayOn = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  if( DEBUG) {
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    Serial.println("Relays");
  }
  // initialize digital pin RELAY1PIN as an output and turn it LOW.
  pinMode(RELAY1PIN, OUTPUT);
  digitalWrite(RELAY1PIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  delay(1000);
  if( relayOff < OFFPERIOD ) {
    relayOff++;
    digitalWrite(RELAY1PIN, LOW);
    if( DEBUG ) {
      Serial.print(" relayOff = ");
      Serial.println( relayOff );
    }
  } else {
    if( relayOn < ONPERIOD ) {
      relayOn++;
      digitalWrite(RELAY1PIN, HIGH);
      if( DEBUG ) {
        Serial.print(" relayOn = ");
        Serial.println( relayOn );
      }
    } else {
      relayOff = 0;
      relayOn = 0;
    }
  }
}
