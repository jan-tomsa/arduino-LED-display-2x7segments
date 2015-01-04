#define DELAY_IN_MS 990
#define SHORT_DELAY_IN_MS 100

#define OFF 0
#define ON 1


#define Bit_out 12
#define CLK  11
#define CLK2 7
#define CLR  10
#define LEDON 9
#define DBG  13

byte counter = 0;
// fba.cgde
char segments[][9] = {
  "fba c de",
  " b  c   ",
  " ba  gde",
  " ba cgd ",
  "fb  cg  ",
  "f a cgd ",
  "f a cgde",
  " ba c   ",
  "fba cgde",
  "fba cgd "
};

// the setup routine runs once when you press reset:
void setup() {              
  pinMode(Bit_out, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(CLR, OUTPUT);
  pinMode(LEDON, OUTPUT);
  pinMode(DBG, OUTPUT);

  digitalWrite(LEDON, OFF);  //HIGH tuns on LEDs
  digitalWrite(CLK, OFF); 
  digitalWrite(CLR, HIGH); // active LOW
}


// inverts state of pin, delays, then reverts state back
void pulsout(byte pinCLK, int delayInMs)   {
  byte z = digitalRead(pinCLK);
  z = !z;
  digitalWrite(pinCLK, z);
  delayMicroseconds(delayInMs);
  z = !z; // return to original state
  digitalWrite(pinCLK, z);
  return;
} // end pulsout()


void displayBitsWord(String val) {
    digitalWrite(DBG, ON);
    for (int j=0; j<=15; j++)  {
      int data = (val.charAt(j) == ' ') ? HIGH : LOW;
      String c = String(val.charAt(j));
      digitalWrite(Bit_out, data); 
      pulsout(CLK, 10); 
    }  // next j
    digitalWrite(DBG, OFF);
}


void displayNumber( byte n ) {
  byte digit2 = n / 10;
  byte digit1 = n - (digit2 * 10);
  String segmentBits2 = String(segments[digit2]);
  String segmentBits1 = String(segments[digit1]);
  String segmentBits = segmentBits2 + segmentBits1;
  displayBitsWord( segmentBits );
}


// the loop routine runs over and over again forever:
void loop() {
  if (counter > 99) {
    counter = 0;
  }
  if (counter == 0) {
    displayBitsWord("                "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("fba.cgdefba.cgde"); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("  a             "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("          a     "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("         b      "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("            c   "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("              d "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("      d         "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("       e        "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("     g          "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("             g  "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("         b      "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("          a     "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("  a             "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("                "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("   .            "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("           .    "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("   .            "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("           .    "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
    displayBitsWord("                "); digitalWrite(LEDON, ON); delay(SHORT_DELAY_IN_MS); digitalWrite(LEDON, OFF);
  }
  displayNumber( counter );
  digitalWrite(LEDON, ON);
  delay(DELAY_IN_MS);
  digitalWrite(LEDON, OFF);
  counter++;
}
