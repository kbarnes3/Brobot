// Accelerometer test sketch

#include "Arduino.h"

const int sensorPin = A0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int analog = analogRead(sensorPin);
    char szOutput[6] = {};

    sprintf(szOutput, "%d", analog);
    Serial.println(szOutput);
    delay(10);
}

