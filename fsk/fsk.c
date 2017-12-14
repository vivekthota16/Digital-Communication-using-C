//	FSK
 #include "DSK6713_AIC23.h"				//codec support
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;			//set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC;	//select input

#define LOOPLENGTH1 8  
#define LOOPLENGTH2 16 
int car1[LOOPLENGTH1]={0,707,1000,707,0,-707,-1000,-707};
int car2[LOOPLENGTH2]={0,382,707,923,1000,923,707,382,0,-382,-707,-923,-1000,-923,-707,-382};
int i,j,k,l=0,msg[4]={1,0,1,0};				//table index
int output[256]; 						//buffer index

void main()
{
   comm_poll();
   while(1)
   {
    for(i=0;i<4;i++)
	 {
	   if(msg[i]==1)
	    {
		  for(j=0;j<2;j++)
		 {
		  for(k=0;k<LOOPLENGTH1;k++)
		 {
			output_left_sample(car1[k]);
			 output[l++]=car1[k];
		  }//k 

		 }//j
		}//if
	   else
	   {
		for(j=0;j<2;j++)
		 {
		  for(k=0;k<LOOPLENGTH2;k++)
		 {
			output_left_sample(car2[k]);
			 output[l++]=car2[k];
		  }//k
		 }//j
		}//else
	}//i
	  }//while
}