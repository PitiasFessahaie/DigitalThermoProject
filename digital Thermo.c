// LCD module connections
sbit LCD_RS at RB5_bit;
sbit LCD_EN at RB4_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB5_bit;
sbit LCD_EN_Direction at TRISB4_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End LCD module connections
unsigned int temperature=0;
float mv;
unsigned char txt[15];

void main() 
{
ADCON1=0X0E;
TRISA.RA0=1;
OSCCON=0X76;
ADC_Init();

Lcd_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);

Lcd_Out(1,1,"Pitias THERMO");
Delay_ms(1000);
Lcd_Cmd(_LCD_CLEAR);

Lcd_Out(1,1,"TEMPERATURE:");
Lcd_Chr(2,8,223);
Lcd_Chr(2,9,'C');
do
{ temperature=ADC_Read(0);
mv = temperature*5000.0/1024.0;
mv= mv/10.0;
FloatToStr(mv,txt);
txt[4] = 0;
Lcd_Out(2,3,txt);
Delay_ms(300);
}while(1);

}