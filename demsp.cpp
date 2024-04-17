#include <main.h>

void spdemduoc(void);
void gioihansp(void);
void chuongtrinhngat(void);

#define LCD_ENABLE_PIN  PIN_E0
#define LCD_RS_PIN PIN_E1
#define LCD_RW_PIN PIN_E2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7

#include <lcd.c>
#int_ext
#int_RB


#define cambien   input(PIN_B0)
#define tang      input(PIN_B1)
#define giam      input(PIN_B2)

unsigned int8 sp,ghsp;

void spdemduoc()
{
   lcd_gotoxy(1,2);
   printf(lcd_putc,"SP DEM DUOC: %02U",sp);

   if(cambien==0)
   {
      while(cambien==1);
      sp++;
   }
   if(sp>ghsp)
   {
      delay_ms(100);
      sp=ghsp;
   }
   
}

void gioihansp()
{
   lcd_gotoxy(1,1);
   printf(lcd_putc,"GIOI HAN SP: %02U",ghsp);
   if(tang==0)
      {
         while(tang==1);
         delay_ms(100);
         if(tang==1)
         {
          
          ghsp++;
         }
         if(ghsp>99)
         {
            ghsp=10;
         }
        
      }
      if(giam==0)
      {
         while(giam==1);
          delay_ms(100);
         if(giam==1)
         {
          
         ghsp--;
         }
         if(ghsp<10)
         {
           ghsp=99;
         }
       }
}
void chuongtrinhngat()
{
   enable_interrupts(int_RB);
   enable_interrupts(Global);
}
void main()
{
   set_tris_d(0);
   set_tris_e(0);
   set_tris_b(0xff);
   lcd_init ();
   lcd_putc("\f");
   ghsp=10;
   setup_timer_0(t0_ext_L_to_H|t0_div_1);
   set_timer0(0);
   while(true)
   {
      sp=get_timer0();
      spdemduoc();
      gioihansp();
      chuongtrinhngat();
      //TODO: User Code
   }
}

