
#define S7 		      *((volatile byte*) 0x2B) 			             // PORTD
#define D1_7	      *((volatile byte*) 0x2A) |= 0b11111110 	  // DDRD
#define BUTTON	    *((volatile byte*) 0x23) &(1<<PINB0)      // PINB&(1<<PINB0)
#define setDDRB     *((volatile byte*) 0x24) &= ~(1<<DDD0)    // DDRB

//	  E D C B A F G 0  		<== 7 segment led indise
//    7 6 5 4 3 2 1 0  		<== pin in arduino
// 0b 1 1 1 0 1 1 1 0  		<== number in 7S 6

byte num[10] = {0xFD, 0x30, 0xDA, 0x7A, 0b00110110, 0b01101110,
               0b11101110, 0b00111000, 0b11111110, 0b01111110};
int main ( void )
{
  char i = 0;
  D1_7; 		                    // from 1-7 output
  setDDRB;                      // set pin 8 ti input
  while (1)
  {
    if (BUTTON)
    {
      while (BUTTON)	          // while button pressed wait
      	_delay_ms(10);
      i++;
      if (i == 10)
        i = 0;
    }
    S7 = num[i];
  }
}
