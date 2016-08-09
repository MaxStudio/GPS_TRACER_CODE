#ifndef __G_086_PC_H_
#define __G_086_PC_H_



#include "includes.h"

#define lcd_cs1 		PDout(3)		// PA0��ӦҺ�����ӿ�"cs1"��Ƭѡ��
#define lcd_reset 	PDout(4)		// PA1��ӦҺ�����ӿ�"reset"	(��λ��
#define lcd_rs			PDout(5)		// PA2��ӦҺ�����ӿ�"rs"��Register Select:ָ������ݼĴ���ѡ��	
#define lcd_sid 		PDout(6)		// PA3��ӦҺ�����ӿ�"SDA"���������ݣ�	
#define lcd_sclk 		PDout(7)		// PA4��ӦҺ�����ӿ�"SCLK"������ʱ�ӣ�	

#define Rom_CS			PBout(8)  	// PA5��Ӧ�ֿ�IC�ӿ�"Rom_CS"(Ҳ�����ֿ�IC��CS#��
#define Rom_SCK			PBout(9)  	// PA6��Ӧ�ֿ�IC�ӿ�"Rom_SCK"��Ҳ�����ֿ�IC��SCK��
#define Rom_OUT			PEin(0)  	// PA7��Ӧ�ֿ�IC�ӿ�"Rom_OUT"��Ҳ�����ֿ�IC��SO��SPI�ӿڵ�"MISO" ��
#define Rom_IN			PEout(1)  	// PC4��Ӧ�ֿ�IC�ӿ�"Rom_IN"��Ҳ�����ֿ�IC��SI��SPI�ӿڵ�"MOSI"��

#define LCD_PWR_OFF() 	GPIO_SetBits(GPIOB, GPIO_Pin_7);
#define LCD_PWR_ON()    GPIO_ResetBits(GPIOB, GPIO_Pin_7);

//--------------------------
#define uchar unsigned char 
#define uint unsigned int
#define ulong unsigned long
//--------------------------
extern u32  fontaddr;
extern uchar bmp_12864_1[];
extern uchar bmp_12864_2[];


extern void waitkey(void);
//��ʼ��PA��Ϊ�����.��ʹ�����IO�ڵ�ʱ��		    
//IO��ʼ��
extern void lcd_port_init(void);



//дָ�LCDģ��
extern void transfer_command_lcd(int data1)   ;
//д���ݵ�LCDģ��
extern void transfer_data_lcd(int data1);


//LCDģ���ʼ��
extern void initial_lcd();
//����Һ��������ʾ��ַ��page��column��
extern void lcd_address(uchar page,uchar column);

//ȫ������
extern void clear_screen();
//һЩ��������õĻ��棬����ȫ�ԣ�������ʾ��������ʾ�ȵ�
extern void full_screen_test(uchar data1,uchar data2);

//һЩ��������õĻ��棬����ȫ�ԣ�������ʾ��������ʾ�ȵ�
extern void test( void);

//��ʾ128x64����ͼ��
extern void display_graphic_128x64(uchar page,uchar column,uchar *dp);

//***��ָ�����Ѷ�ֿ�IC**
extern void send_command_to_ROM( uchar datu );


//***�Ӿ���Ѷ�ֿ�IC��ȡ���ֻ��ַ����ݣ�1���ֽڣ�**
static uchar get_data_from_ROM( );


//��ָ����ַ��������д��Һ����ָ����page,column)������
extern void get_and_write_16x16(ulong fontaddr,uchar reverse,uchar page,uchar column);


//��ָ����ַ��������д��Һ����ָ����page,column)������
extern void get_and_write_8x16(u32 fontaddr,uchar reverse,uchar page,uchar column);


//��ָ����ַ��������д��Һ����ָ����page,column)������
extern void get_and_write_5x8(u32 fontaddr,uchar reverse,uchar page,uchar column); 


//****************************************************************

//��ʾ16x16����ĺ���/ȫ�Ƿ���/ȫ�Ǳ�㣬��8x16���������/Ӣ��/��Ǳ��/ASCII����ţ�
//����reverse=1��ʱѡ���ԣ�����reverse=0��ʱѡ������
extern void display_GB2312_string(uchar page,uchar column,uchar reverse,uchar *text);


//��ʾ5x8��������/��Ƿ���/��Ǳ��
//����reverse=1��ʱѡ���ԣ�����reverse=0��ʱѡ������
extern void display_string_5x8(uchar page,uchar column,uchar reverse,uchar *text);
extern void display_char_5x8(uchar page,uchar column,uchar reverse,uchar text);
void  lcd_show_rx_buf(char *str);
#endif
