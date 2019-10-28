
//Sorry for my English.;) 

//ATmega328P Timer0 kütüphanesi.
//ATmega328P Timer0 library.


//Frekans hesaplamalarý için lütfen ATmega328P veri kitapçýðýna bakýnýz.
//Please see ATmega328P dataseheet for frequency calculations.

#define OC0A COM0A1// TCCR0A 7.bit
#define OC0B COM0B1//  TCCR0A 5.bit

int value;//Fast PWM modu için Periyot ayarý(Period for Fast PWM mode.)
int pin;//Fast PWM modu  Pd6,Pd5 ayar deðiþkeni(Pd6 and Pd5 setting variable for Fast PWM mode)
int Register;//Fast PWM için yazmaç seçimi(Register selection for Fast PWM mode)
int prescaler;//Ön derecelndirici deðiþkeni(Prescaler variable )
int frequency;//CTC modu için frekans seçimi(Setting frequency fot CTC mode)
int phase;//Phase Crrect PWM modu için ayar deðiþkeni(Period variable for Phase Correct PWM  )

#define A 1 //Fast PWM modu pin yazmaç seçimi(Fast PWM mode pin register selection )
#define B 2

static void init_TC0(int prescaler);//Burada Pd5,PD6 pinleri çýkýþ yapýlýyor ve ön derecelendirici ayarlanýyor.
									//Öndereclendirici seçenekleri:1024,256,64,8,1
									    //Setting prescaler and Pd5,Pd6 an an output.
									    //Prescaler settings:1024,256,64,8,1
									
static void fast_pwm (int value,int pin, int Register); //OC0A ve OC0B pinleri için fast pwm modu
														  //Fast pwm for OC0A and OC0B
														
static void phase_pwm(int phase);//Phase Correct PWM modu(phase=0-255),Çýkýþ OC0A pininden alýnacak.
								     //Phase correct PWMmode(phase=0-255),Output is in OC0A pin
                                     
static void ctc_frequency(int frequency);//OC0A için CTC modu.  (frequency=0-255),Çýkýþ OC0A pininden alýnacak.
										     //CTC mode for OC0A pin (frequency=0-255),Output is in OC0A pin
