#include <Arduino.h>
#include <7seg.h>
/*
A-D7
B-D5
C-D9
D-D11 
E-D12
F-D6
G-D8
DP-D10

C1-A1
C2-A2
C3-A3
C4-A4

*/


//Constants 
#define button      2
#define button2     3
#define time_init   0 
#define time_cmp    62500

//Global variables--------
segment s1;
int8_t min1; 
int8_t min2; 
int8_t hour1; 
int8_t hour2; 
int counter=0;
//------------------------

//interruptions 
ISR(TIMER1_COMPA_vect){
  TCNT1=time_init; 
  counter++;

}



//functions---------------
void att_clock(void); 
void adjust_clock(void); 
void start_clock(segment *s);
//------------------------

void setup() {


  Serial.begin(9600);
  
  TCCR1A=0; 
  TCCR1B |= (1<<CS12); 
  TCCR1B &= ~(1<<CS11); 
  TCCR1B &= ~(1<<CS10);
  TCNT1= time_init;
  OCR1A=time_cmp; 

  

  TIMSK1=(1<<OCIE1A);
  //Setting the pins------

  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(button,INPUT);
  DDRD |=(0<<PORTD3); 
  DDRD |=(0<<PORTD2); 


  //----------------------


  init_segment(&s1,7,5,9,11,12,6,8,10);// init the segment
  start_clock(&s1);
}

void loop(){
  
  if(digitalRead(button)==1){adjust_clock(); delay(250);}// Will start the function to adjust de hour


  //Write the first digit  
  digitalWrite(A1,1); 
  write_number(min1,s1,1); 
  digitalWrite(10,0);//Turn the DP as High: 
  delay(5); 
  digitalWrite(A1,0);

  //Write the second digit  
  digitalWrite(A2,1); 
  write_number(min2,s1,1); 
  digitalWrite(10,0);//Turn the DP as High: 
  delay(5); 
  digitalWrite(A2,0);

  //Write the third digit 
  digitalWrite(A3,1);
  write_number(hour1,s1,1); 
  digitalWrite(10,0);//Turn the DP as High: 
  delay(5); 
  digitalWrite(A3,0);

  //Write the fourth digit 
  digitalWrite(A4,1); 
  write_number(hour2,s1,1); 
  digitalWrite(10,0);//Turn the DP as High: 
  delay(5); 
  digitalWrite(A4,0);

  if(counter==60){
    min1++;
    att_clock();
    counter=0;

  }
  
}



void start_clock(segment *s){
  min1=0;
  min2=0; 
  hour1=0;
  hour2=0; 
  digitalWrite(A1,1); 
  digitalWrite(A2,1); 
  digitalWrite(A3,1);
  digitalWrite(A4,1); 
  
  digitalWrite(s->A,1);
  digitalWrite(s->B,1);
  digitalWrite(s->C,1);
  digitalWrite(s->D,1);
  digitalWrite(s->E,1);
  digitalWrite(s->F,1);

  digitalWrite(s->G,0);
  delay(1000);

 


}


void att_clock(){
  
  if(min1>9){min2++;min1=0;}

  if(min2>5){hour1++;min2=0;}

  if(hour1>9){hour2++;hour1=0;}
  
  if(hour2==2 && hour1==4){hour2=0;hour1=0;min1=0;min2=0;}




} 


void adjust_clock(){
  int8_t ad_counter=0; 

  while (ad_counter<5)
  {
    if (digitalRead(button)==1){
      if(hour2==2 && hour1>3){
        start_clock(&s1);
        return;
      }
      

      delay(250);
      ad_counter++; 

    }


    switch (ad_counter)
    {
    case 1:  // Case 1: Adjust the first digit  
      digitalWrite(A2,0); 
      digitalWrite(A3,0);
      digitalWrite(A4,0); 
      digitalWrite(A1,1);

      write_number(min1,s1,1);

      if(digitalRead(button2)==1){
        min1++; 
        if(min1>9){
          min1=0;
        }
        delay(250);
      }


      delay(10);
    break; // End case 1 --------------------

    case 2:// case 2: Adjust the second digit 
    digitalWrite(A2,1); 
    digitalWrite(A3,0);
    digitalWrite(A4,0); 
    digitalWrite(A1,0);
    write_number(min2,s1,1);
    if(digitalRead(button2)==1){
      min2++; 
      if(min2>5){
        min2=0;
      }
      delay(250); }

      delay(10);
      break;// end case 2--------------------

    case 3:// case 3 : adjust the third digit 
    digitalWrite(A2,0); 
    digitalWrite(A3,1);
    digitalWrite(A4,0); 
    digitalWrite(A1,0);
    write_number(hour1,s1,1);
    if(digitalRead(button2)==1){
      hour1++; 
      if(hour1>9){
          hour1=0;
        } 

      delay(250);}

      delay(10); 
      break;// End case 3 ---------------------

    case 4:// case 4: adjust the fourth digit
      digitalWrite(A2,0); 
      digitalWrite(A3,0);
      digitalWrite(A4,1); 
      digitalWrite(A1,0);
      write_number(hour2,s1,1);

      if(digitalRead(button2)==1){
        hour2++;
        if(hour2>2){
          hour2=0;
        } 
        delay(250);} 


      delay(10);
      break;// end case 4--------------------------------
    
    default:
      
      break;
    }


    
  }
  


}
