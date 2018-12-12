/*
 * Macros
 */

/* Pin definitions */
#define E_PORT   PORTB
#define E_DDR    DDRB
#define E        0

#define RS_PORT  PORTB
#define RS_DDR   DDRB
#define RS       1

#define RW_PORT  PORTB
#define RW_DDR   DDRB
#define RW       2

#define DATA_PORT PORTC
#define DATA_DDR  DDRC
#define DATA_PIN  PINC
#define DB4      0
#define DB5      1
#define DB6      2
#define DB7      3

/* Commands */
#define lcd_cmd(x)  lcd_send(x, 0)
#define lcd_char(x) lcd_send(x, 1)

#define LCD_CLEAR   0x01
#define LCD_HOME    0x02
#define LCD_LINE_1  0x80
#define LCD_LINE_2  0xC0

/* Bit switch shortcuts */
#define lcd_rs_on()    RS_PORT |=  (1 << RS)
#define lcd_rs_off()   RS_PORT &= ~(1 << RS)
#define lcd_rw_on()    RW_PORT |=  (1 << RW)
#define lcd_rw_off()   RW_PORT &= ~(1 << RW)
#define lcd_e_on()     E_PORT  |=  (1 << E)
#define lcd_e_off()    E_PORT  &= ~(1 << E)
#define lcd_e_delay()  _delay_us(E_PULSE_TIME)

/* Magic numbers */
#define E_PULSE_TIME  250
#define LCD_LINE_1    0x80
#define LCD_LINE_2    0xC0

/*
 * Function prototypes
 */

void lcd_epulse(void);

void lcd_send(int data, int rs);

int lcd_read(void);

void lcd_newline(void);

void lcd_putc(char c);

void lcd_puts(char* s);

void lcd_init(void);

void lcd_io_init(void);
