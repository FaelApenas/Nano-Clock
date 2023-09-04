#include <Arduino.h>
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

/*
Function to initialize the 7 segment display. 


*/

void init_segment(segment *s,int8_t a, int8_t b,int8_t c,int8_t d,int8_t e,int8_t f,int8_t g,int8_t dp);

/*
function to write a number 
paramenters(Number,display,type of display)

c-> indicates if the display was cathode common or anode common 

if it was cathode c=1, if it was anode c=0 or any other number


*/
void write_number(int number,segment s,int c); 