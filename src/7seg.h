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


void init_segment(segment *s,int a, int b,int c,int d,int e,int f,int g,int dp);
void write_number(int number,segment s,int c); 