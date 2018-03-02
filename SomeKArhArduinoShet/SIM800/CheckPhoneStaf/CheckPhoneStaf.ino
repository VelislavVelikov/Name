/* Some phone stuff */

int input = 2, dial = 4,  check=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Set.");
  pinMode(input, INPUT);
  pinMode(check, INPUT);
  pinMode(dial, OUTPUT);
  digitalWrite(dial, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int check_active;
  check_active = digitalRead(check);
  if(check_active=="HIGH"){
    Serial.println("Standby!");
    }else{
      Serial.println("Entering number..."); 
      delay(500); 
    }
   Serial.print("Value of check : ");
   Serial.println(check_active);
}
