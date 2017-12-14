//	QPSK
 #include "DSK6713_AIC23.h"	 			//codec support
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;			//set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC;	// select input

#define LOOPLENGTH 7 
int car1[LOOPLENGTH]={0,707,1000,707,0,-707,-1000,};	//0?
int car2[LOOPLENGTH]={1000,707,0,-707,-1000,-707,0};	//90?
int car3[LOOPLENGTH]={0,-707,-1000,-707,0,707,1000};	//180?
int car4[LOOPLENGTH]={-1000,-707,0,707,1000,707,0};		//270?
int msg[8]={0,0,0,1,1,1,1,0};   					
int output[56]; 
int i,j,k,l=0;                          

void main()
{
   comm_poll();
   while(1)
   {
    

for(i=0;i<8;i=i+2)
	 {
	   if(msg[i]==0&msg[i+1]==0)
	    {
		  for(j=0;j<2;j++)
		 {
		  for(k=0;k<LOOPLENGTH;k++)
		 {
			output_left_sample(car1[k]);
			 output[l++]=car1[k];
		  }//k
		 }//j
		}//if
	   else if(msg[i]==0&msg[i+1]==1)
	   {
		for(j=0;j<2;j++)
		 {
		  for(k=0;k<LOOPLENGTH;k++)
		 {
			output_left_sample(car2[k]);
			 output[l++]=car2[k];
		  }//k
		 }//j
		}//else
 else if(msg[i]==1&msg[i+1]==1)
	   {
		for(j=0;j<2;j++)
		 {
		  for(k=0;k<LOOPLENGTH;k++)
		 {
			output_left_sample(car3[k]);
			 output[l++]=car3[k];
		  }//k
		 }//j
		}//else
 else if(msg[i]==1&msg[i+1]==0)
	   {
		for(j=0;j<2;j++)
		 {
		  for(k=0;k<LOOPLENGTH;k++)
		 {
			output_left_sample(car4[k]);
			 output[l++]=car4[k];
		  }//k
		 }//j
		}//else

	}//i
	  }//while
}
