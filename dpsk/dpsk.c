#include "DSK6713_AIC23.h"				//codec support
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;			//set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC;	// select input

#define LOOPLENGTH 8  
int car1[LOOPLENGTH]={0,707,1000,707,0,-707,-1000,-707};	//0?
int car2[LOOPLENGTH]={0,-707,-1000,-707,0,707,1000,707};	//180?


int l,i,j,k=0,n=0,msg[8]={1,1,1,1,0,0,0,0};   					
int output[72],d[9];  

void main()
{
   
  d[0]=0;
  for(k=1;k<=8;k++)
  {
   if(d[k-1]==msg[k-1]) 
	 d[k]=1;
   else
      d[k]=0;

  }//k

while(1)
{
   for(i=0;i<=8;i++)
  {
   if(d[i]==1) 
   {
	for(j=0;j<8;j++)
	{ 
	 output[n]=car1[j];
	
	n++;
	}//j
   }//if
  else
 {
	for(j=0;j<8;j++)
	{ 
	 output[n]=car2[j];
	
	n++;
	}//j
   }//else
  }//i
}//while
}