#include <Arduino.h>
#include <7seg.h>





void init_segment(segment *s,int8_t a, int8_t b,int8_t c,int8_t d,int8_t e,int8_t f,int8_t g,int8_t dp,int8_t dt){
 s->pins[7]=a; 
 s->pins[6]=b; 
 s->pins[5]=c; 
 s->pins[4]=d; 
 s->pins[3]=e; 
 s->pins[2]=f; 
 s->pins[1]=g; 
 s->pins[0]=dp; 
 s->display_type= dt;

for(int i=0;i<=7;i++)
{
  pinMode(s->pins[i],OUTPUT); 
}



}


void display_clear(segment s)
{
  for(int i=0;i<=7;i++) digitalWrite(s.pins[1],0); 
}

void write_number(int number,segment s)
{

    display_clear(s); 
    byte numbers[]
    {
        0B11111100,  //  0
        0B01100000,  //  1
        0B11011010,  //  2
        0B11110010,  //  3
        0B01100110,  //  4
        0B10110110,  //  5
        0B10111110,  //  6
        0B11100100,  //  7
        0B11111110,  //  8
        0B11100110,  //  9
    };

    for(int i=0; i<8;i++)
    {
      int number_bits=numbers[number]>>i & 0x01; // pick each 0 and 1 

      if (s.display_type== 1)number_bits=number_bits ^ 0x01; // If the display is anode, invert the bits 
      
      digitalWrite(s.pins[i], number_bits); 
      
    }

    


}


void test_display(segment s)
{
  for(int i=0 ;i<=7 ;i++ )
  {
    digitalWrite(s.pins[i],0); 
  }

  delay(1000); 

  display_clear(s);
} 

