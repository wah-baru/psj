void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
Serial.write(343);
Serial.write(0xAB);
Serial.write(0x00);
delay(1000);

Serial.write(512);
Serial.write(0xAB);
Serial.write(0x01);
delay(1000);

Serial.write(729);
Serial.write(0xAB);
Serial.write(0x02);
delay(1000);