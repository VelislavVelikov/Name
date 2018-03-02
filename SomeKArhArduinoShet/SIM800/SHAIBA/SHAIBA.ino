int old_num = 0;
int mode_dial, num_mode;//contact

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  Serial.println("Ready!");
  //2=Chisla; 3=Kontakt
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}


int processShaiba() {
int num = 0;

    for(;digitalRead(3) == LOW;) {
    num_mode = digitalRead(2);
    if(old_num == HIGH && num_mode == LOW)
      num++;
    old_num = num_mode;
    delay(5);
  }

  if(num) {
    if(num == 10)
      return 0;
    //Serial.print(">>");
    //Serial.println((int)num);
    return num;
  } else return -1;
}


void loop() {
  //Serial.println((int)digitalRead(3));
  int sha = processShaiba();

  if(sha != -1)
    Serial.println((int)sha);




    
  // put your main code here, to run repeatedly:
 // mode_dial = digitalRead(3);
  
/*
  if(!(int)mode_dial){
    Serial.println((int)mode_dial);
  Serial.println("Nabirame Maikati!!1!");
  delay(2000);
  }else{
  Serial.println("Mui ne nabirayu tvoia maiku!1!!11!!");
  }
  */

}
