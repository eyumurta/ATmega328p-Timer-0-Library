/*

Bu kütüphane Atmel Atmega328p için yazýlmýþtýr.Kütüphane TC0 zamanlyýcýsýný kullanmaktadýr.
Kütüphaneyi kullanabilir,deðiþiklik yapabilir ve yeniden daðýtabilirsiniz.Bu kütüphane açýk kaynaklýdýr.
Eðer bir hata bulursanýz lütfen benimle iletiþime geçiniz.->>erkuhuk@gmail.com

This library writing for Atmel ATmega328p.Libary using TC0 timer.
You can use,modify and redistribute this library.It's Open source.
If you found a bug please contact me->>erkuhuk@gmail.com
*/
/* pwm.c kaynak kodu. */
//pwm.c source code
/************************************************************************/
/* Yazar(author):Muhammed Selim ERKÜHÜK(Elektronik Yumurta)                   
Facebook:Elektronik Yumurta
Website(Turkish):elektronikyumurta.blogspot.com
E-mail:erkuhuk@gmail.com                                                  */
/************************************************************************/
//NOT:Bu kütüphane amatör bir çalýþmadýr.
//NOTE:This libray is amateour project.


//NOT:Fast PWM çýkýþ dalga þekli terstrir.
//NOTE:Fast PWM output waveform is inverted!

#include <avr/io.h>
#include <stdint.h>
#include "pwm.h"



  void init_TC0(int prescaler){

DDRD=0x60;//Pd5 ve Pd6 pinleri çýkýþ olarak ayarlandý.
//Pd5 and Pd6 pins as an output.

//Öndereclendirici tercihleri.
// prescaler settings.

switch ( prescaler){

	case 1024:
	TCCR0B=0x5;

	break;
	case 256:
	TCCR0B=0x4;

	break;
	case 64:
	TCCR0B=0x3;

	break;
	case 8:
	TCCR0B=0x2;
	

	break;
	case 1:
	TCCR0B=0x1;
	break;
	
	default:
	TCCR0B=0x0;

	break;
}

}
 void fast_pwm (int value,int pin, int Register) {
	 //Fast Pwm mode(Ýnverted)
	 
	 //Çýkýþ frekansýný hesaplamak isterseniz ATmega328p veri kitaðçýðý sayfa 133'e bakýnýz.
	 //If you want to calculate output frequency please see ATmega328p datasheet page 133.
	 
	
	 TCCR0A|=(1<<WGM00)|(1<<pin)|(1<<WGM01);
	
    //A ve B bu fonksiyon için tanýmlanmýþtýr.
	//A and B defined for this function.
	
	 if(Register==2){
 OCR0B=value;
 
 }
  else if(Register==1){
	 OCR0A=value;
 }

	
 }






 void ctc_frequency(int frequency){

 //CTC mode.
	// CTC modu yalnýzca OC0A'pininden kullanýlabilir.
	//Çýkýþ frekansýný hesaplamak isterseniz lütfen ATmega328p veri kitapçýðý sayfa 132'ye bakýnýz.
	//CTC mode using only for OC0A pin.
	//If you want to calculate output frequency please see ATmega328p datasheet page 132.
   
	
TCCR0A|=(1<<WGM01)|(1<<COM0A0);
OCR0A=frequency;


}
 void phase_pwm(int phase){
	 
	 //Phase Correct Mode
	 //Çýkýþ frekansýný hesaplamak isterseniz lütfen ATmega328p veri kitapçýðý sayfa 135'e bakýnýz.
	 //If you want to calculate output frequency please see ATmega328p datasheet page 135.
	 
TCCR0A|=(1<<WGM00)|(1<<COM0A1)|(1<<COM0A0);

OCR0A=phase;


}