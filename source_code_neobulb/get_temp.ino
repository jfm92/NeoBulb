/*******************************************
 * Proyecto realizado por Juan Flores Muñoz
 * Electronica Creativa
 * 4º GISE
 *******************************************/

void get_temp(){
  byte temp = 0;
  byte hum = 0;
  dht11.read(pinDHT11, &temp, &hum, NULL);
  while(temp==0 && hum ==0){//sometimes is neccesary to try a few times to get a good one
    dht11.read(pinDHT11, &temp, &hum, NULL);
    delay(1500);
  }
  PSerial.print(temp);
  PSerial.print(" ");
  PSerial.print(hum);
}

