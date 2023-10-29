#include <Arduino.h>

typedef struct  {
  int pins[8];
  int display_type; // 0==Cathode common,1==Anode common 
}segment;

/*
Function to initialize the 7 segment display. 
dt-> defines if the display is a cathode or anode common 
cathode -> 0 
Anode -> 1

*/

void init_segment(segment *s,int8_t a, int8_t b,int8_t c,int8_t d,int8_t e,int8_t f,int8_t g,int8_t dp,int8_t display_type);


/*
clers the display 
*/
void display_clear(segment s); 


/*
function to write a number 
paramenters(Number,display)

*/
void write_number(int number,segment s); 

void write_char(char ch,segment s); 
