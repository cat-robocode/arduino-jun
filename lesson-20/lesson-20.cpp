#include <lesson-20.hpp>
#include <Servo.h>
#include <NewPing.h>

static Servo servo;
static NewPing sonar(12, 11, 200);
static int angle;

void ServoPotentiometer::init()
{
    servo.attach(10);
}
void ServoPotentiometer::update()
{
    int pot = analogRead(0);
    angle = map(pot, 0, 1023, 0, 180);
    servo.write(angle);
    delay(50);
}
void SonarPotentiometer::init()
{
    Serial.begin(9600);
    servo.attach(10);
}
void SonarPotentiometer::update()
{
    delay(50);
    int distance = sonar.ping_cm();
    Serial.print(distance);
    Serial.println("см");
    if (distance < 20)
    {
        servo.write(180);
    }
    else
    {
        servo.write(0);
    }
}
