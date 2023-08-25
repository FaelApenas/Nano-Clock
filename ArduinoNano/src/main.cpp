#include <Arduino.h>
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

typedef struct  {
  int A; 
  int B; 
  int C; 
  int D; 
  int E; 
  int F; 
  int G; 
  int DP; 

}segment;
//Global variables--------
#define button    2
#define button2   3
segment s1;
int8_t min1; 
int8_t min2; 
int8_t hour1; 
int8_t hour2; 
int counter=0;
//------------------------

//functions---------------
void init_segment(segment *s,int a, int b,int c,int d,int e,int f,int g,int dp);
void write_number(int number,segment s,int c); 
void att_clock(void); 
void adjust_clock(void); 
void start_clock(segment *s);
//------------------------

void setup() {
  Serial.begin(9600);
  //Setting the pins------

  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(button,INPUT);
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

  att_clock(); //Function to att the clock 
  counter++; //We have 5x4 delay(When counter=3000,1 minute has been passed)
  
     
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
void init_segment(segment *s,int a, int b,int c,int d,int e,int f,int g,int dp){
  s->A=a; 
  s->B=b;
  s->C=c;
  s->D=d;
  s->E=e;
  s->F=f;
  s->G=g;
  s->DP=dp;
  pinMode(s->A,OUTPUT);
  pinMode(s->B,OUTPUT);
  pinMode(s->C,OUTPUT);
  pinMode(s->D,OUTPUT);
  pinMode(s->E,OUTPUT);
  pinMode(s->F,OUTPUT);
  pinMode(s->G,OUTPUT);
  pinMode(s->DP,OUTPUT);



}
void write_number(int number,segment s,int c){
    digitalWrite(s.A,0); 
    digitalWrite(s.B,0);
    digitalWrite(s.C,0); 
    digitalWrite(s.D,0);
    digitalWrite(s.E,0); 
    digitalWrite(s.F,0); 
    digitalWrite(s.G,0); 
    digitalWrite(s.DP,0);
 
    if(number==0){
      digitalWrite(s.A,1); 
      digitalWrite(s.B,1);
      digitalWrite(s.C,1); 
      digitalWrite(s.D,1);
      digitalWrite(s.E,1);
      digitalWrite(s.F,1);

    }
    if(number ==1){
    digitalWrite(s.B,1); 
    digitalWrite(s.C,1);

    }
    if(number==2){
      digitalWrite(s.A,1); 
      digitalWrite(s.B,1);
      digitalWrite(s.G,1); 
      digitalWrite(s.E,1);
      digitalWrite(s.D,1);

    }
    if(number==3){
      digitalWrite(s.A,1); 
      digitalWrite(s.B,1);
      digitalWrite(s.G,1); 
      digitalWrite(s.C,1);
      digitalWrite(s.D,1);

    }
    if(number==4){
      digitalWrite(s.F,1); 
      digitalWrite(s.G,1);
      digitalWrite(s.B,1); 
      digitalWrite(s.C,1);

    }
    if(number==5){
      digitalWrite(s.A,1); 
      digitalWrite(s.F,1);
      digitalWrite(s.C,1); 
      digitalWrite(s.D,1);
      digitalWrite(s.G,1);
    }
    if(number==6){
      digitalWrite(s.A,1); 
      digitalWrite(s.F,1);
      digitalWrite(s.C,1); 
      digitalWrite(s.D,1);
      digitalWrite(s.G,1);
      digitalWrite(s.E,1);

    }
    if(number==7){
      digitalWrite(s.A,1); 
      digitalWrite(s.B,1);
      digitalWrite(s.C,1); 
    

    }
    if(number==8){
      digitalWrite(s.A,1); 
      digitalWrite(s.B,1);
      digitalWrite(s.F,1);
      digitalWrite(s.C,1); 
      digitalWrite(s.D,1);
      digitalWrite(s.G,1);
      digitalWrite(s.E,1);

    }
    if(number==9){
      digitalWrite(s.A,1); 
      digitalWrite(s.B,1);
      digitalWrite(s.F,1);
      digitalWrite(s.C,1); 
      digitalWrite(s.D,1);
      digitalWrite(s.G,1);

    }
  if(c==1){
    digitalWrite(s.A,!digitalRead(s.A)); 
    digitalWrite(s.B,!digitalRead(s.B));
    digitalWrite(s.C,!digitalRead(s.C)); 
    digitalWrite(s.D,!digitalRead(s.D));
    digitalWrite(s.E,!digitalRead(s.E)); 
    digitalWrite(s.F,!digitalRead(s.F)); 
    digitalWrite(s.G,!digitalRead(s.G)); 
    digitalWrite(s.DP,!digitalRead(s.DP));


  }







}

void att_clock(){
  
  if(counter==2900){
    min1++; 
    counter=0;

  }
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
        delay(250);} // increase the second digit of hour


      delay(10);
      break;// end case4; 
    
    default:
      
      break;
    }


    
  }
  


}
