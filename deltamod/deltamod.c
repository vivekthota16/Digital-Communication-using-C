//DM
 #include "DSK6713_AIC23.h"				//codec support
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;	 		//set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC;	// select input

#define LOOPLENGTH 16
int car1[40]= {0,1564,3090,4540,5878,7071,8090,8910,9511,9877,10000,9877,9511,8910,8090,7071,5878,4540,3090,1564,0,-1564,-3090,-4540,-5878,-7071,-8090,-8910,-9511,-9877,-10000,-9877,-9511,-8910,-8090,-7071,-5878,-4540,-3090,-1564};
int car2[40]={0};
int i, d[40],x[40],step=2500;					//step size=2500

void main()
{
   comm_poll();
   car2[1]=car2[0]=0;
   d[1]=0;
   x[1]=0;
   while(1)
   {
    for(i=2;i<40;i++)
	 {
	   if(car1[i]>car2[i-1])
	   
 {
			d[i]=1;
			x[i]=1;
			car2[i]=car2[i-1]+step;
		//	output_left_sample(car2[i]);
		}//if

		   else
	   {
	    
			d[i]=-1;
			x[i]=0;
			car2[i]=car2[i-1]-step;
		//	output_left_sample(car2[i]);
		}//else
	}//i
	  }//while
}