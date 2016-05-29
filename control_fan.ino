char command;   //Declare a char variable to hold a command 1 on 0 off
char NOMBRE[10] = "MISTA";
char BPS = '4';
char PASS[10] = "1234";

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);/// set up Serial library at 9600 bps
  Serial.print("AT");
  delay(1000);

  Serial.print("AT+NAME");
  Serial.print(NOMBRE);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.print(BPS);
  delay(1000);  

  Serial.print("AT+PIN");
  Serial.print(PASS);
  delay(1000);
}

void loop() {
    while (!Serial.available());
    command = Serial.read();
    if (command == '1') {
      digitalWrite(13, HIGH);   // turn the FAN on (HIGH is the voltage level)
      //Serial.print("Fan ON success");
     }
    if (command == '0'){
      digitalWrite(13, LOW);    // turn the FAN off by making the voltage LOW
      //Serial.print("Fan OFF success");
    }
}
