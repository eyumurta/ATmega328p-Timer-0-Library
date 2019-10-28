# ATmega328p-Timer-0-Library


ENGLİSH REFERENCE İS DOWN OF THE PAGE.
//Sorry for my English.;) 

******************************************************************************************
Ben sadece amatör biriyim bu yüzden kütüphaneyi kullanırken lütfen dikkatli olunuz.
Eğer bana bir sorunuz olursa erkuhuk@gmail.com üzerinden ulaşabilirsiniz.

Kütüphaneyi kullanırken şu adımları izleyin.
1) Kütüphaneyi çalışmanıza ekleyin.
#include "pwm.c"

2) Zamanlayıcıyı çalıştırın ve önderecelendirici değerini seçin.
TC0_init(256);//PD5 ve PD6 çıkış,önderecelendirici 256 olarak ayarlandı.
Öndereclendirici seçenekleri:1024,256,64,8,1


3) PWM modunu seçin(3 mod).
void fast_pwm (int value,int pin, int Register);//Terslenmiş dalga formu.
veya
void phase_pwm(int phase);//0-255 dalga periyotu),Çıkış OC0A pininden alınacak.
veya
void ctc_frequency(int frequency);//CTC frekansı,Çıkış OC0A pininden alınacak.

******************************************************************************************

I'm only amateur so using the library please be carefully.If you have questions you can
contact me erkuhuk@gmail.com.


Please using the library following this step.


1) Add the library your project.
#include "pwm.c"
 
2) Start the timer and set prescaler value.
TC0_init(256);//Setting prescaler and Pd5,Pd6 as an output
Prescaler settings:1024,256,64,8,1


3) Select PWM mode(3 mode).
void fast_pwm (int value,int pin, int Register);//İnverted waveform
or
void phase_pwm(int phase);//0-255 wave period,Output is in OC0A pin
or
void ctc_frequency(int frequency);//ctc frequency,Output is in OC0A pin

******************************************************************************************
