#include <Arduino.h>
#include <7seg.h>





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