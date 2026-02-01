
#include "GD5800_Serial.h"

GD5800_Serial mp345(0,1);

void setup() {

mp345.begin(9600);


   
  mp345.setVolume(10);
  mp345.playFileByIndexNumber(1);

}

void loop()  {

   mp345.play();

}
