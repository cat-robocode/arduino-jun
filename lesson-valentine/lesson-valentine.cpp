#include <lesson-valentine.hpp>
#include <NewPing.h>

static NewPing sonar(12, 11, 200);

void SonarRGB::init()
{
    Serial.begin(9600);
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);
    digitalWrite(6,LOW);
    digitalWrite(4,LOW);

}
void SonarRGB::update()
{
    delay(50);

    static int lastDistance = 200;

    int d = sonar.ping_cm();


    if (d > 0) lastDistance = d;

    lastDistance = constrain(lastDistance, 0, 200);

    int brightness = map(lastDistance, 0, 200, 255, 0);
    Serial.println(brightness);
    analogWrite(3, brightness);
    analogWrite(5, brightness);
}
