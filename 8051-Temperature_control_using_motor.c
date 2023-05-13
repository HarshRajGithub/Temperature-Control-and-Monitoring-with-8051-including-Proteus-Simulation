###

#include <reg51.h>  //Header file for 8051 microcontroller
 
void delay (void);         //delay function prototype
//Defining P3.0 bit as an ADDR_C of ADC 
sbit ADDR_C = P3^0;      //Defining P3.1 bit as an EN which is Enable pin to 
                       //DC motor
sbit ADDR_B = P3^1; //Defining P3.2 bit as an IN2 which is input2 pin to DC motor
sbit ADDR_A = P3^3;
sbit ALE = P3^2; //Defining P3.1 bit as an EN which is Enable pin to DC motor
sbit OE = P3^5; //Defining P3.2 bit as an IN2 which is input2 pin to DC motor
sbit START = P3^4;
sbit EOC = P3^7;
sbit RELAY = P3^6;
 
void main (void)
{         //main function starts here
unsigned char mybyte; 
        P1=0xff;  //P1 acts as an input port, reads the value of ADC
        EOC=1;
        ALE=0;
        START=0;
        OE=0;
 
        while (1)         //Do forever
   {
          
ADDR_C=0;
ADDR_B=1;
ADDR_A=1;
 
delay ();   
                                    ALE=1;
delay();
START=1;
                                    delay();
ALE=0;
                                  START=0;
while (EOC !=1)
{
 OE=1;
                                     mybyte=P1;
 mybyte=mybyte-35;
 if (mybyte > 40)       
 {
  delay();
  RELAY=1;
               delay();delay();
  }
  else
  {
   delay();
    RELAY=0;
                delay();delay();
   }
}
 
  
}//while end
}         //End of main program
 
 
void delay (void)         
{         //delay function starts here
unsigned int i;         //variable defined
for (i=0;i<=600;i++);         //This for loop generates delay
}         //End of program
 
 

###