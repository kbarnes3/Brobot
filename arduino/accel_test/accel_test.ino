// Accelerometer test sketch

#include "Arduino.h"

const int sensorPin = A0;
int cycle = 0;
unsigned long nextOutputTime = 0;
int minRead = 1024;
int maxRead = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int analog = analogRead(sensorPin);
    if (analog < minRead)
    {
        minRead = analog;
    }
    if (analog > maxRead)
    {
        maxRead = analog;
    }

    unsigned long currentTime = millis();

    if (currentTime > nextOutputTime)
    {
        char szOutput[35] = {}; // "Cycle: 999 - Min: 1024 - Max: 1024" with a null terminator

        sprintf(szOutput, "Cycle: %d - Min: %d - Max: %d", cycle, minRead, maxRead);
        Serial.println(szOutput);
        cycle++;
        nextOutputTime += 1000;
        minRead = 1024;
        maxRead = 0;
    }
}

