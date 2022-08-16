#include <Servo.h>               //library  servo motor ra include mikonim                                    

Servo sg90;                                                     

int servopin=9;                 //ye PWM pin migirim
int LDR1 = A0;                  //Ldr1 be pin A0                                
int LDR2 = A1;                  //Ldr2 be pin A1                                

int pos = 90;                   //be sorate pishfarz 90                   
int error = 5;                  //mizan telorance ya khataie beine 2 Ldr                                

void setup()
{ 
  sg90.attach(servopin);                                       
  pinMode(LDR1, INPUT);                                         
  pinMode(LDR2, INPUT);
  sg90.write(pos);             //set servo in 90 degree                    
  delay(2000);      
}  
 
void loop() 
{ 
  int R1 = analogRead(LDR1);    //Read Ldr 1 va 2                       
  int R2 = analogRead(LDR2);
                                  
  int diff= abs(R2 - R1);       //ghadre motlagh ekhtelaf
  
  if(diff < error) {}           //age kochiktar az         
  else 
  {    
    if(R1 > R2) { pos = pos-1; }      
    if(R1 < R2) { pos = pos+1; }      
  }
  if(pos>180)  { pos=180; }     //in ghesmat baraie ineke
  if(pos<0)    { pos=0; }       //dar zavaiaie bozorgtar az 180 mesl 361
  sg90.write(pos);              //error nade va sari az 180 bar nagarde                   
  delay(100);                   //ro 1 daraje
}
