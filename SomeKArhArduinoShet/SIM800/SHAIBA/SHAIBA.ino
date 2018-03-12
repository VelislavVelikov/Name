#define PHONE_LEN 15
#define DELAY_BTW_NUMS  4000
unsigned long last_num = 0;

int old_num = 0;
int mode_dial, num_mode;//contact
int i = 0;
char str[PHONE_LEN] = {};
int size = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Ready!");
  //2=Chisla; 3=Kontakt
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}


int processShaiba() {
  int num = 0;

  for (; digitalRead(3) == LOW;) {
    num_mode = digitalRead(2);
    if (old_num == HIGH && num_mode == LOW)
      num++;
    old_num = num_mode;
    delay(3);
  }

  if (num) {
    if (num == 10)
      return 0;
    //Serial.print(">>");
    //Serial.println((int)num);
    return num;
  } else return -1;
}


void clear_str() {
  for (int p = 0; p < PHONE_LEN; p++)
    str[p] = 0;
}

void loop() {
  //Serial.println((int)digitalRead(3));
  int sha = processShaiba();

  if (sha != -1) {
    if ( i < PHONE_LEN) {
      str[i] = (int)sha + 48;
      Serial.println((int)sha);
      i++;
      last_num = millis();
    }
    //      free(str);
  }

  if ( millis() >= last_num + DELAY_BTW_NUMS && i > 0) {
    Serial.print(">>");
    Serial.println(str);
    clear_str();
    i = 0;
  }
}
