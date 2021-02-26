#include "main.h"

void pwm_set_duty(uint8_t duty)
{
    OCR0A = duty;
}
void init_PWM(pwm_freq prescaler, pwm_mode mode)
{
    //    TCCR0B = TCCR0B & ~(1 << CS02) | (1 << CS01) & ~(1 << CS00); // clkIO/8
    TCCR0B = TCCR0B & ~_BV(CS02) & ~_BV(CS01) & ~_BV(CS00) | prescaler;

    switch (mode)
    {
    case CTC:
        TCCR0B &= ~(1 << WGM02);                // mode 2
        TCCR0A |= (1 << WGM01) & ~(1 << WGM00); // mode 2

        TCCR0A = TCCR0A & ~(1 << COM0A1) | (1 << COM0A0); // toggle
        //        TCCR0A = TCCR0A | (1 << COM0A1) & ~(1 << COM0A0); // Clear OC0A on Compare Match

        break;
    case FAST:
        TCCR0A |= _BV(COM0A1); // connect PWM signal to pin (AC0A => PB0)
        //! cannot use mode 7
        // TCCR0B = TCCR0B | (1 << WGM02);        // mode 3 Fast PWM
        TCCR0A |= _BV(WGM01) | _BV(WGM00); // mode 3 Fast PWM
        break;

    default:
        break;
    }
}
void init_IO()
{
    DDRB |= _BV(DDB0); // set PWM pin as OUTPUT
}

int main()
{
    init_IO();
    init_PWM(DIV_64, FAST);

    PRR |= _BV(PRADC); // shut down Timer/Counter0 module and ADC module

    while (1)
    {
        //     PORTB = ~PORTB;
        //     _delay_ms(2000);

        for (uint8_t cntDuty = 0; cntDuty < 256; ++cntDuty)
        {
            pwm_set_duty(cntDuty);
            _delay_ms(10);
        }
        for (uint8_t cntDuty = 255; --cntDuty;)
        {
            pwm_set_duty(cntDuty);
            _delay_ms(10);
        }
    }
}
// ISR(INT0_vect)
