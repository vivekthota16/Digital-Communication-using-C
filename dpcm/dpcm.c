//Dpcm generation
//m1,m2,m3 ,m5, m6 quantization levels 

#include "DSK6713_AIC23.h"	                //codec support
Uint32 fs=DSK6713_AIC23_FREQ_8KHZ;	        //set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; 

#define looplength 11 
int s[looplength]={0,5.8779,9.5106,9.5106,5.8779,0,-5.8779,-9.5106,-9.5106,-5.8779,0};
int m3[6]={0,0,1000,1000,1000,1000},m2[6]={0,0,1000,1000,0,0},m1[6]={0,0,0,0,1000,1000},m5[6]={1000,1000,0,0,1000,1000},m6[6]={1000,1000,1000,1000,0,0};
int i,j,k=0,level,diff[looplength-1];
int output[60];                           

void main()
{
for(i=0,j=0;i<looplength;i++,j++)
 diff[j]=s[i+1]-s[i];

for(i=0;i<11;i++)
 {
     if(diff[i]==0)

   {level=3;
       for(j=0;j<6;j++)

	{output[k]=m3[j];
	k++;}
   }
     if(diff[i]==5)
   {level=2;
      for(j=0;j<6;j++)
	{output[k]=m2[j];
	k++;}
   }
      if(diff[i]==4)
   {level=1;
        for(j=0;j<6;j++)
	{output[k]=m1[j];
	k++;}
   }
      if(diff[i]==-5)
   {level=5;
       for(j=0;j<6;j++)
	{output[k]=m5[j];
	k++;}
   }
      if(diff[i]==-4)
   {level=6;
      for(j=0;j<6;j++)
	{output[k]=m6[j];
	k++;}
   }
}//i 
}
