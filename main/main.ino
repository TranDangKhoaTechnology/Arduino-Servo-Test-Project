/*
 * Arduino Servo Angle Controller (Serial Input)
 * ---------------------------------------------
 * A simple demo project to control a servo motor with Arduino via Serial Monitor.
 * Enter an angle from 0–180, and the servo will rotate accordingly.
 *
 * Author: Tran Dang Khoa (CodeWithKhoa)
 * Year: 2025
 *
 * License: MIT License
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */

#include <Servo.h>

Servo myServo;
int servoPin = 9;  // Servo pin (D9 on Arduino UNO)

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);  // Attach servo to pin
  Serial.println("Nhap goc servo (0 - 180):");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Read until Enter key
    input.trim(); // Remove whitespace and \r \n
    
    if (input.length() > 0) {
      // Validate if input is a number
      bool isNumber = true;
      for (unsigned int i = 0; i < input.length(); i++) {
        if (!isDigit(input[i])) {
          isNumber = false;
          break;
        }
      }

      if (isNumber) {
        int angle = input.toInt();
        if (angle >= 0 && angle <= 180) {
          myServo.write(angle);
          Serial.print("✅ Servo da quay den goc: ");
          Serial.println(angle);
        } else {
          Serial.println("⚠️ Goc khong hop le! (0 - 180)");
        }
      } else {
        Serial.println("⚠️ Vui long nhap so nguyen!");
      }

      Serial.println("Nhap goc servo (0 - 180):"); // Prompt again
    }
  }
}
