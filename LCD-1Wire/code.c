#include <mega8.h>
#include <delay.h>

#define HC595_PIN PORTC .0

void HC595_Send(unsigned char data)
{
    char i;
    for (i = 0; i < 7; i++)
    {
        if (data & 0x80) //bit 1
        {
            HC595_PIN = 0;
            delay_us(1);
            HC595_PIN = 1;
            delay_us(15);
        }
        else //bit 0
        {
            HC595_PIN = 0;
            delay_us(15);
            HC595_PIN = 1;
            delay_us(30);
        }
        data <<= 1;
    }
    //bit cuoi + LAT
    HC595_PIN = 0;
    delay_us(200);
    HC595_PIN = 1; // 0->1
    delay_us(300);
}

//------------------------------Giao tiep LCD 1602-------------------------//
unsigned char data_MASK = 0xFF; //byte mat na
void LCD_Enable(void)
{
    //      E
    // 0000 1000
    data_MASK |= 0x08; //SET Enable
    HC595_Send(data_MASK);
    data_MASK &= ~0x08; //RESET Enable
    HC595_Send(data_MASK);
}
void LCD_Send4Bit(unsigned char Data) //chi su dung 4 bit thap cua Data
{
    data_MASK &= 0x0F;               //clear 4 bit cao
    data_MASK |= (Data & 0x01) << 4; // lay ra bit 0 dua vao vi tri bit 4
    data_MASK |= (Data & 0x02) << 4; // lay ra bit 1 dua vao vi tri bit 5
    data_MASK |= (Data & 0x04) << 4; // lay ra bit 2 dua vao vi tri bit 6
    data_MASK |= (Data & 0x08) << 4; // lay ra bit 3 dua vao vi tri bit 7
}
void LCD_Send1Byte(unsigned char byte)
{
    LCD_Send4Bit(byte >> 4); /* Gui 4 bit cao */
    LCD_Enable();
    LCD_Send4Bit(byte); /* Gui 4 bit thap*/
    LCD_Enable();
}
// Ham di chuyen con tro: row=0-1; col=0-15 (2 hang + 16 cot)
void LCD_chonvitri(unsigned char x, unsigned char y)
{
    unsigned char address;
    if (y == 0)
        address = (0x80 + x); // row=0 - hang 1
    else
        address = (0xC0 + x); // row=1 - hang 2
    delay_us(1000);
    LCD_Send1Byte(address);
    delay_us(50);
}
// Ham hien thi ra man hinh chuoi ki tu
void LCD_guichuoi(char *s)
{
    while (*s)
    {
        data_MASK |= 0x02; //dua chan RS len vcc
        HC595_Send(data_MASK);
        LCD_Send1Byte(*s);
        data_MASK &= ~0x02; //dua chan RS xuong mass
        HC595_Send(data_MASK);
        s++;
    }
}
void LCD_guikitu(int s)
{
    data_MASK |= 0x02; //dua chan RS len vcc
    HC595_Send(data_MASK);
    LCD_Send1Byte(s);
    data_MASK &= ~0x02; //dua chan RS xuong mass
    HC595_Send(data_MASK);
}
// Ham xoa man hinh
void LCD_xoamanhinh()
{
    LCD_chonvitri(0, 0);
    LCD_guichuoi("                ");
    LCD_chonvitri(1, 0);
    LCD_guichuoi("                ");
    LCD_chonvitri(0, 0);
}
// Ham khoi tao LCD
void LCD_khoitao()
{
    data_MASK &= ~0x04; //dua chan RW xuong mass
    data_MASK &= ~0x02; //dua chan RS xuong mass
                        //HC595_Send(data_MASK);
    LCD_Send4Bit(0x03);
    LCD_Enable();
    delay_ms(5);
    LCD_Enable();
    delay_ms(100);
    LCD_Enable();
    LCD_Send4Bit(0x02); // dua con tro ve dau man hinh
    LCD_Enable();

    LCD_Send1Byte(0x28);
    LCD_Send1Byte(0x0C); // Bat hien thi, bat con tro	 0x0C neu muon tat con tro
    LCD_Send1Byte(0x06);
    delay_ms(20);
    LCD_xoamanhinh();
}

void main(void)
{
    PORTC = 0xff;
    DDRC = 0xff;
    LCD_khoitao();
    LCD_guichuoi("LCD1602 1 Write");
    LCD_chonvitri(0, 1);
    LCD_guichuoi("Hello World !");
    while (1)
    {
    }
}
