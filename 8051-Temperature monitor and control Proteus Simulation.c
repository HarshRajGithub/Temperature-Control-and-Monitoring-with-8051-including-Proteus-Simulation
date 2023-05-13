//LCD Module connection
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D4 at P2_2_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;
//End of LCD Module connection

// ADC pin specification
sbit cs at P3_0_bit;
sbit rd at P3_1_bit;
sbit wr at P3_2_bit;
sbit intr at P3_3_bit;
sbit heat at P0_0_bit;
sbit cool at P0_1_bit;
sbit fan at P2_6_bit;
// end of ADC pin specification

char count=0;
char display[]="000.00";
char txt1[]="Fan OFF";
char txt12[]="Fan ON";
char adc_read=0,value=0;

void conversion()
{
cs=0;
wr=0;
delay_ms(2);
cs=1;
wr=1;
while(intr==1);
cs=1;
rd=1;
delay_ms(2);
cs=0;
rd=0;
}
void print()
{
display[2]=count%10+48;
display[1]=(count/10)%10+48;
display[0]=(count/100)%10+48;
display[4]=(value/1000)%10+48;
display[5]=(value/10000)%10+48;
lcd_out(1,7,display);
lcd_chr(1,14,223);
lcd_chr(1,15,'C');
}

void main()
{
Lcd_Init();                   //Initializes Lcd
Lcd_Cmd(_LCD_CLEAR);          // Clear LCD Screen
Lcd_Cmd(_LCD_CURSOR_OFF);     // LCD Cursor OFF
Lcd_out(1,1,"Temp");
fan=0
delay_ms(5000);
Lcd_Cmd(_LCD_CLEAR);
Lcd_out(1,1,"Temp:  ");
fan=0
while(1)
{
conversion();
count=p1;
count=count*1.95;
print();

if(count>0&&count<35)
{
cool=fan=0;
Lcd_out(2,5,txt1);
}else
{
cool=1;
}

if(count>35&&count<151)
{
heat=0;
fan=0;
Lcd_out(2,5,txt2);
}else
{
heat=1;
}


}
}

