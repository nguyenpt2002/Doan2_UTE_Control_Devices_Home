#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
RTC_DS1307 rtc;
//LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tue", "Wed", "Thu", "Friday", "Sat"};
int sensorPin = A0;// chân analog kết nối tới cảm biến LM35

void setup_RTC()
{
    Serial.begin(9600); //Khởi động Serial ở mức baudrate 9600
    lcd.begin(20,4);
    lcd.backlight();
    if (!rtc.begin())
    {
        lcd.print("Couldn't find RTC");
        while(1);
    }
    if (!rtc.isrunning())
    {
        lcd.print("RTC is NOT running!");
    }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //auto update from computer time
    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy
}
void loop_RTC(){
    DateTime now = rtc.now();
    lcd.setCursor(6,1);
    if (now.hour() <= 9)
    {
        lcd.print("0");
        lcd.print(now.hour());
    }
    else
    {
        lcd.print(now.hour());
    }
    lcd.print(':');
    if (now.minute() <= 9)
    {
        lcd.print("0");
        lcd.print(now.minute());
    }
    else
    {
        lcd.print(now.minute());
    }
    lcd.print(':');
    if (now.second() <= 9)
    {
        lcd.print("0");
        lcd.print(now.second());
    }
    else
    {
        lcd.print(now.second());
    }
    lcd.print("   ");
    lcd.setCursor(1, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(",");
    if (now.day() <= 9)
    {
        lcd.print("0");
        lcd.print(now.day());
    }
    else
    {
        lcd.print(now.day());
    }
    lcd.print('/');
    if (now.month() <= 9)
    {
        lcd.print("0");
        lcd.print(now.month());
    }
    else
    {
        lcd.print(now.month());
    }
    lcd.print('/');
    if (now.year() <= 9)
    {
        lcd.print("0");
        lcd.print(now.year());
    }
    else
    {
        lcd.print(now.year());
    }
// ​int reading = analogRead(sensorPin); ​//đọc giá trị từ cảm biến LM3
// ​float voltage = reading * 5.0 / 1024.0;//tính ra giá trị hiệu điện thế (đơn vị Volt) từ giá trị cảm biến
// ​//mỗi 10mV=1độ C. if biến voltage là biến lưu hiệu điện thế. đơn vị Volt thì nhđộ = voltage x100
// ​float temp = voltage * 100.0;
// ​Serial.println(temp);
// ​delay(1000);//đợi 1 giây cho lần đọc tiếp theo
// 
// // Xuất thông tin cảm biến ra màn hình LCD
//    ​lcd.clear();
//    ​lcd.setCursor(0, 2)
//    ​lcd.print("Nhiet do: ");
//    ​lcd.setCursor(10, 2);
//    ​lcd.print(temp, 1);
////  ​lcd.write(223)
////    ​lcd.print("C");
}
