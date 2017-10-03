void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  for (int i = 2; i < 20; ++i) {
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(9600);
}

// this map maps logical PC numbers to pin numbers use to ping them
// e.g. pin_map[1] should result in the correct pin for PC #1
// PC numbering starts at 1, not 0
// pin numbers start at 2, and then number 13 is omitted as it's the status LED pin

int pin_map[18] = {  0,   // not used
                     2,   // PC 01
                     3,   // PC 02
                     4,   // PC 03
                     5,   // PC 04
                     6,   // PC 05
                     7,   // PC 06
                     8,   // PC 07
                     9,   // PC 08
                    10,   // PC 09
                    11,   // PC 10
                    12,   // PC 11
                    // pin 13 omitted by design
                    14,   // PC 12
                    15,   // PC 13
                    16,   // PC 14
                    17,   // PC 15
                    18,   // PC 16
                    19    // PC 17
};

void loop() {
  while (Serial.available() > 0) {
    int address = Serial.parseInt();
    int timeout = Serial.parseInt();

    if (Serial.read() == '\n') {

      Serial.print(address, DEC);
      Serial.print(" ");
      Serial.print(timeout, DEC);
      Serial.print("\n");
      Serial.flush();
    
      if (address > 0 && address < 18) {
        Serial.print("start... ");
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(pin_map[address], HIGH);
        delay(timeout);
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(pin_map[address], LOW);
        Serial.println("end.");
      }
    }
  }
}

