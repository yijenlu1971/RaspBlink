#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

extern "C"
{
#include "LCM1602.h"
}

// LED Pin - wiringPi pin 0 �� BCM_GPIO 17�C
// �ڭ̥����b�H wiringPiSetupSys ��l�Ʈɨϥ� BCM �s���覡
// ��ܤ��P pin �s���ɡA�Шϥ� BCM �s���覡�A��
// ��s [�ݩʭ�] - [�ظm�ƥ�] - [Remote Post-Build Event] �R�O 
// ��� wiringPiSetupSys ���]�w�ϥ� gpio export
#define	LED	17

int main(void)
{
	char msg[17];
	int	i = 0;

	wiringPiSetupSys();

	pinMode(LED, OUTPUT);
	int fd = lcm1602Setup(0x27, CURSOR_LEFT, SHIFT_OFF, DISPLAY_ON, CURSOR_OFF,
				CURSOR_BLINK_OFF, TWO_LINE, SMALL_FONT, LCD_BACKLIGHT_OFF);

	while (true)
	{
		digitalWrite(LED, HIGH);  // �}��

		memset(msg, 0, sizeof(msg));
		sprintf(msg, "Loop  %10d", i++);
		lcm1602WriteLine(fd, msg, 0, LCD_BACKLIGHT_ON);

		delay(500); // �@��
		digitalWrite(LED, LOW);	  // ����

		memset(msg, 0, sizeof(msg));
		sprintf(msg, "Loop  %10d", i++);
		lcm1602WriteLine(fd, msg, 1, LCD_BACKLIGHT_ON);

		delay(500);

//		if ((i % 10) == 0) printf("Hello Raspberry! count=%d\n", i);
	}
	return 0;
}