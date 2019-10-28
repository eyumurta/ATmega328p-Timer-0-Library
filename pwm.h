
//Sorry for my English.;) 

//ATmega328P Timer0 k�t�phanesi.
//ATmega328P Timer0 library.


//Frekans hesaplamalar� i�in l�tfen ATmega328P veri kitap����na bak�n�z.
//Please see ATmega328P dataseheet for frequency calculations.

#define OC0A COM0A1// TCCR0A 7.bit
#define OC0B COM0B1//  TCCR0A 5.bit

int value;//Fast PWM modu i�in Periyot ayar�(Period for Fast PWM mode.)
int pin;//Fast PWM modu  Pd6,Pd5 ayar de�i�keni(Pd6 and Pd5 setting variable for Fast PWM mode)
int Register;//Fast PWM i�in yazma� se�imi(Register selection for Fast PWM mode)
int prescaler;//�n derecelndirici de�i�keni(Prescaler variable )
int frequency;//CTC modu i�in frekans se�imi(Setting frequency fot CTC mode)
int phase;//Phase Crrect PWM modu i�in ayar de�i�keni(Period variable for Phase Correct PWM  )

#define A 1 //Fast PWM modu pin yazma� se�imi(Fast PWM mode pin register selection )
#define B 2

static void init_TC0(int prescaler);//Burada Pd5,PD6 pinleri ��k�� yap�l�yor ve �n derecelendirici ayarlan�yor.
									//�ndereclendirici se�enekleri:1024,256,64,8,1
									    //Setting prescaler and Pd5,Pd6 an an output.
									    //Prescaler settings:1024,256,64,8,1
									
static void fast_pwm (int value,int pin, int Register); //OC0A ve OC0B pinleri i�in fast pwm modu
														  //Fast pwm for OC0A and OC0B
														
static void phase_pwm(int phase);//Phase Correct PWM modu(phase=0-255),��k�� OC0A pininden al�nacak.
								     //Phase correct PWMmode(phase=0-255),Output is in OC0A pin
                                     
static void ctc_frequency(int frequency);//OC0A i�in CTC modu.  (frequency=0-255),��k�� OC0A pininden al�nacak.
										     //CTC mode for OC0A pin (frequency=0-255),Output is in OC0A pin
