#include <Wire.h>
#include "RTClib.h"
#include "HardwareSerial.h"

RTC_DS3231 rtc;

HardwareSerial gsm(1);
HardwareSerial df(2);

// IR sensors
int IR[4] = {34, 35, 32, 33};
bool taken[4] = {false, false, false, false};
int medHour[4] = {8, 13, 20, 22};  

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(IR[i], INPUT);
  }

  Wire.begin(21, 22);
  rtc.begin();

  gsm.begin(9600, SERIAL_8N1, 26, 27);
  df.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("Smart Medicine System Started");
}

void loop() {
  DateTime now = rtc.now();

  for (int i = 0; i < 4; i++) {

    int sensor = digitalRead(IR[i]);

    // CHECK TIME SLOT
    if (now.hour() == medHour[i]) {

      // CASE 1: NOT TAKEN ON TIME
      if (sensor == HIGH && taken[i] == false) {
        Serial.println("Medicine NOT taken on time");
        playAudio(2);  // alert audio
        sendSMS("Medicine NOT taken on time!");
      }

      // CASE 2: TAKEN ON TIME
      if (sensor == LOW && taken[i] == false) {
        Serial.println("Medicine taken on time");
        playAudio(1);
        sendSMS("Medicine taken on time");

        taken[i] = true;  
      }

      // CASE 3: SAME MEDICINE TAKEN AGAIN
      if (sensor == LOW && taken[i] == true) {
        Serial.println("Duplicate intake detected!");
        playAudio(4);
        sendSMS("Warning: Same medicine taken again!");
      }
    }

    //  CASE 4: WRONG MEDICINE 
    // If any other IR is triggered in wrong slot time
    for (int j = 0; j < 4; j++) {
      if (i != j && digitalRead(IR[j]) == LOW && now.hour() == medHour[i]) {
        Serial.println("Wrong medicine taken!");
        playAudio(3);
        sendSMS("Wrong medicine taken!");
      }
    }
  }

  delay(2000);
}

// DFPlayer
void playAudio(int track) {
  df.write(0x7E); df.write(0xFF); df.write(0x06);
  df.write(0x03); df.write(0x00);
  df.write(0x00); df.write(track);
  df.write(0xEF);
}

// GSM
void sendSMS(String msg) {
  gsm.println("AT+CMGF=1");
  delay(500);

  gsm.println("AT+CMGS=\"+91XXXXXXXXXX\"");
  delay(500);

  gsm.print(msg);
  delay(500);

  gsm.write(26);
  delay(3000);
}
