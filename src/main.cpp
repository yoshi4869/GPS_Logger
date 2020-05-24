#include <Arduino.h>
#include <Wire.h>
#include "SSD1306.h"//ディスプレイ用ライブラリを読み込み

const int ledpin = 5;
const int sclpin = 22;
const int sdapin = 21;

const int ledtime = 50;//LEDの点滅間隔



SSD1306  display(0x3c, sdapin, sclpin); //SSD1306インスタンスの作成（I2Cアドレス,SDA,SCL）
void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(sclpin,INPUT_PULLUP);
  pinMode(sdapin,INPUT_PULLUP);
  // シリアルポートを9600 bps[ビット/秒]で初期化
  Serial.begin(115200);
  // 開始メッセージ
  Serial.write("START");
  Serial.write("\n");

  display.init();    //ディスプレイを初期化
  display.setFont(ArialMT_Plain_16);    //フォントを設定
  display.drawString(0, 0, "Hello World");    //(0,0)の位置にHello Worldを表示
  display.display();   //指定された情報を描画
}

void loop() {
/*   digitalWrite(ledpin,HIGH);
  delay(ledtime);
  digitalWrite(ledpin,LOW);
  delay(ledtime);
 */
 String input;
 if(Serial.available() > 0){
   //シリアルポートより1文字読み込む
   input = Serial.readStringUntil(';');
     Serial.print(input);
     Serial.write("\n");
 }
}