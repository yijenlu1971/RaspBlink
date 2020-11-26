#include <wiringPi.h>
#include "TFT.h"

// LED Pin - wiringPi pin 0 為 BCM_GPIO 17。
// 我們必須在以 wiringPiSetupSys 初始化時使用 BCM 編號方式
// 選擇不同 pin 編號時，請使用 BCM 編號方式，並
// 更新 [屬性頁] - [建置事件] - [Remote Post-Build Event] 命令 
// 其對 wiringPiSetupSys 的設定使用 gpio export
#define	LED	18

int main(void)
{
	const char str[] = "HAN YA\0";

	wiringPiSetupSys();

	pinMode(LED, OUTPUT);
	TFT* tftLCD = new TFT(17, 25, 24);

	tftLCD->begin();
	tftLCD->background(0, 0, 0);
	tftLCD->stroke(255, 255, 255);
	tftLCD->line(0, tftLCD->height()/2, tftLCD->width(), tftLCD->height() / 2);

	tftLCD->fill(0, 255, 0);
	tftLCD->circle(20, 20, 10);
	tftLCD->setTextSize(2);
	tftLCD->text(str, 50, 20);

	while (true)
	{
		digitalWrite(LED, HIGH);  // 開啟
		delay(500); // 毫秒
		digitalWrite(LED, LOW);	  // 關閉
		delay(500);
	}
	return 0;
}