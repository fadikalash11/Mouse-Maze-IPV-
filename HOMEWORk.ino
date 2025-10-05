int LEDPin [] ={2,3,4}; // 2 =Red 3 =Green   4=Yellow
int buttonPIN=5;
int buzzerPin=6;
unsigned long StartGreenLight;
const int GreenLightDuration=500;
void setup() {

randomSeed(analogRead(0));//  Without this you get Same SHiffle  Every  one 
for(int i=0;i<3;++i)
pinMode(LEDPin[i],OUTPUT);
pinMode(buzzerPin,OUTPUT);

pinMode(buttonPIN,INPUT_PULLUP);
pinMode(buzzer,OUTPUT);


}

void loop() {

int RandomLEd=random(1,4);
switch(RandomLEd)
{
case 1 :
RedLed();
break;
case 2 :  // GReen 
GreenLed();
break;
case 3 :
YellowLed();
break;
}
delay(500);
TurnoffLed();

}


void RedLed()
{
  digitalWrite(LEDPin[0],HIGH);//  red
if(digitalRead(buttonPIN)==LOW){
TurnoffLed();
GameOverMan();
}
delay(2000);
}
void GreenLed()
{
digitalWrite(LEDPin[1],HIGH);
StartGreenLight=millis();
while (millis()-StartGreenLight<GreenLightDuration)
 if(diditalRead(buttonPin)==LOW)
 {
WinSound();
return;
 }
 GameOverMan();

}

void YellowLed()
{
digitalWrite(LEDPin[1],HIGH);
if(digitalRead(buttonPin)==LOW)
{
   alertSound();
}
delay(1700);
}
void WinSound()
{

tone(6,523,200);
delay(200);
tone(6,659,200);
delay(200);
tone(6,784,200);
delay(300);
noTone(6);


}

void alertSound()
{
for(int i=0;i<3;++i)
tone(6,1000,100)
delay(100);
noTone(6);
delay(100);

}
void GameOverMan()
{
tone(6,392,300);
delay(300);
tone(6,330,300);
delay(300);
tone(6,261,500);
delay(500);
noTone(6);

}
void TurnoffLed()
{
  for(int i=0;i<3;++i)
{
ditalWrite(LEDPin[i],LOW);
}
}

