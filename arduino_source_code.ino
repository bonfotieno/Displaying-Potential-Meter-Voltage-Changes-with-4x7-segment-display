/*
  Developer: Bonface Otieno
  Project Title: Displaying Potential Meter Voltage Changes with 4x7 segment display
  Description: Arduino project for working with Potential Meter with 4x7 segment display to display voltage changes
  Linkedin Profile: https://www.linkedin.com/in/bonface-otieno-a7ab77163/
  Github username: bonfotieno
*/


//initializing pins for each segment of the 4x7 segment display
int segment4 = 4;
int segment3 = 3;
int segment2 = 2;
int segment1 = 7;

//initializing pins for each display LED
int A = 5;
int B = 6;
int C = 8;
int D = 9;
int E = 10;
int F = 11;
int G = 12;
int dp = 13;

int potPin = A3;
int currentSegment;
float voltage;
float Vol;

void setup() {
  Serial.begin(9600);
  pinMode(segment1, OUTPUT);
  pinMode(segment2, OUTPUT);
  pinMode(segment3, OUTPUT);
  pinMode(segment4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(dp, OUTPUT);
}

void loop() {
  // the void loop function
  Vol = analogRead(potPin);
  voltage = ((5.0 / 1023.0) * Vol);
  clear_display();
  currentSegment = 1;
  print_voltage_to_4x7display(voltage);
}

void clear_display() {
  /*this function clears the the 4x7 segment display*/
  digitalWrite(segment1, HIGH);
  digitalWrite(segment2, HIGH);
  digitalWrite(segment3, HIGH);
  digitalWrite(segment4, HIGH);
}

void display_1() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.print(1);
}
void display_2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  Serial.print(2);
}
void display_3() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  Serial.print(3);
}
void display_4() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(4);
}
void display_5() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(5);
}
void display_6() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(6);
}
void display_7() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.print(7);
}
void display_8() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(8);
}
void display_9() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(9);
}
void display_0() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  Serial.print(0);
}

void change_segment(int d) {
  if (d == 1) {
    digitalWrite(segment1, LOW);
    digitalWrite(segment2, HIGH);
    digitalWrite(segment3, HIGH);
    digitalWrite(segment4, HIGH);
    digitalWrite(dp, HIGH);
  }
  if (d == 2) {
    digitalWrite(segment1, HIGH);
    digitalWrite(segment2, LOW);
    digitalWrite(segment3, HIGH);
    digitalWrite(segment4, HIGH);
    digitalWrite(dp, LOW);
  }
  if (d == 3) {
    digitalWrite(segment1, HIGH);
    digitalWrite(segment2, HIGH);
    digitalWrite(segment3, LOW);
    digitalWrite(segment4, HIGH);
    digitalWrite(dp, LOW);
  }
  if (d == 4) {
    digitalWrite(segment1, HIGH);
    digitalWrite(segment2, HIGH);
    digitalWrite(segment3, HIGH);
    digitalWrite(segment4, LOW);
    digitalWrite(dp, LOW);
  }
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  //digitalWrite(p, LOW);
}

void print_voltage_to_4x7display(float num) {

  // converting the the num value to string so that we can loop through to display in 4x7 segment display
  String numStr = String(num);                  // define the variable that hold the string
  int strlength = numStr.length() + 1;          // length (with one extra char for the null terminator)
  char numStrArray[strlength];                  // Prepare the char array (the buffer)
  numStr.toCharArray(numStrArray, strlength);   // Copy it over

  /* displaying the voltage values */
  for (int i = 0; i < strlen(numStrArray); i++) {
    char current_char = numStrArray[i];
    if (current_char != '.') {
      change_segment(currentSegment);
      if (current_char == '1') {
        display_1();
        delay(5);                              // delay of 5 milisecond to enable the the display to print properly
      }
      else if (current_char == '2') {
        display_2();
        delay(5);
      }
      else if (current_char == '3') {
        display_3();
        delay(5);
      }
      else if (current_char == '4') {
        display_4();
        delay(5);
      }
      else if (current_char == '5') {
        display_5();
        delay(5);
      }
      else if (current_char == '6') {
        display_6();
        delay(5);
      }
      else if (current_char == '7') {
        display_7();
        delay(5);
      }
      else if (current_char == '8') {
        display_8();
        delay(5);
      }
      else if (current_char == '9') {
        display_9();
        delay(5);
      }
      else if (current_char == '0') {
        display_0();
        delay(5);
      }

      currentSegment += 1;
    }
  }
  Serial.println();
}
