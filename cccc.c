int game[3][3] = {   {0,0,0},
                      {0,0,0},
                      {0,0,0}  };
                      
 int green[3] = {3,5,7};
 int red[3] = {2,4,6};
 int but_col[3] = {8,9,10};
 int but_row[3] = {11,12,13};
 char z[] = {A0, A1, A2};

void setup() {
  int i=2;
  //setting led anodes and half the buttons
  while(i<11){
    pinMode(i,OUTPUT);
      digitalWrite(i,LOW);
    i++;
  } 
  //setting the other half of buttons
  while(i>10 &&i<14){
    pinMode(i,INPUT);
    i++;
  }
  //setting cathodes
  pinMode(A0, OUTPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1, OUTPUT);
  digitalWrite(A1,HIGH);
  pinMode(A2, OUTPUT);
  digitalWrite(A2,HIGH);
}







void loop(){
 int bc, br, dr, dc, turn=1;
 for(bc=0; bc<3;bc++){
   digitalWrite(but_col[bc],HIGH);
   for(br=0;br<3;br++){
	if(digitalRead(but_row[br])==HIGH) {
		if(game[bc][br]==0){
			if(turn%2==0){		
				game[bc][br] = 2;
				turn++;
			}
			else{
				game[bc][br] = 1;
				turn++;				
			}
		}
	}  
   }
	digitalWrite(but_col[bc],LOW);
 }
 
 
}








 /*int game[3][3] = {   {1,1,0},
                      {2,0,1},
                      {1,2,0}  };
                      
  int green[3] = {3,5,7};
  
  int red[3] = {2,4,6};
  int i, p, d=0,a=0;
  char z[] = {A0, A1, A2};
 
 for(p=0; p<3;p++){
   digitalWrite(z[p],LOW);
   for(i=0; i<3; i++ ){ 
   
    
    if(game[p][i]!=0){
      if(game[p][i]==1){
      digitalWrite(green[i],HIGH);
      delay(0.5);
      digitalWrite(green[i],LOW);
      }
      else{
         digitalWrite(red[i],HIGH);
         delay(0.5);
         digitalWrite(red[i],LOW);
      }
    }
  }
  digitalWrite(z[p],HIGH);
 }
}