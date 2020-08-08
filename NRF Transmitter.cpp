NRF TRANSMITTER
#include

#include

#include

#include

#include

"RF24.h" //SCK -> 13//MISO -> 12//MOSI -> 11//CSN -> 7//CE ->8

int msg[1];

RF24 radio(8,7);

const uint64_t pipe = 0xE8E8F0F0E1LL;

int potpin = 0;

int val;

MPU9250 mpu;

// void setup() { radio.begin(); Serial.begin(115200); radio.openWritingPipe(pipe);

//Sending the Data } void loop() { while(Serial.available()) { Vector normaccel = mpu.readNormalizeAccel();

int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;

int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;

Serial.print(" \nPitch = ");

Serial.print(pitch);

Serial.print(" Roll = ");

Serial.print(roll);

if(pitch > 20) { msg[0] = 1;

Serial.println(msg[0]);

radio.write(msg, 1);

delay(1000);

} else if(pitch < -20) { msg[0] = 2;

Serial.println(msg[0]);

radio.write(msg, 1);

delay(1000);

} else { msg[0] = 0;

Serial.println(msg[0]);

radio.write(msg, 1);

delay(1000);

}

if(roll > 20) { msg[0] = 3;

Serial.println(msg[0]);

radio.write(msg, 1);

delay(1000); }

else if(roll < -20) { msg[0] = 4;

Serial.println(msg[0]);

radio.write(msg, 1);

delay(1000); }

else { msg[0] = 0;

Serial.println(msg[0]);

radio.write(msg, 1);

delay(1000); }

}

}