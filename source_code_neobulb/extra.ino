/*******************************************
 * Proyecto realizado por Juan Flores Muñoz
 * Electronica Creativa
 * 4º GISE
 *******************************************/


int f=0;

void espera(int seg){
  int esp=0; 
    while(esp<seg*2){
      delay(500);//cada 0.5seg comprobamos si tenemos algun mensaje entrante
      if(PSerial.available()>0){//si tenemos mensaje entrante cortamos el bucle y atendemos al mensaje
        String aux=PSerial.readString();
        if(aux[0]=='c'){
          f=1;//condicion de funcionamiento del bucle
          break;
        }
        else if(aux[0]=='t'){
          get_temp();
        }
      }
      esp++;
    }
}

void color_aleatorio(){
 f=0;
  while(f==0){
      int a_r=random(0,255);
      int a_g=random(0,255);
      int a_b=random(0,255);
    for(int i=0;i<21;i++){
      
      pixels.setPixelColor(i, pixels.Color(a_r,a_g,a_b));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(30);
      
    }
    espera(5);
  } 
}

void aurora(){
  int der[11]={0,1,2,12,13,11,9,20,18,16,9};
  int izq[10]={3,4,5,6,7,8,14,15,16,17};
 
  f=0;
  while(f==0){
    int a_g=random(0,255);
    int a_b=random(0,255);
    int a_r=random(0,200);
    for(int i=0;i<10;i++){
      pixels.setPixelColor(der[i], pixels.Color(0,255,a_b));
      pixels.setPixelColor(izq[i], pixels.Color(a_r,a_g,255));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(75);
    }
     
    delay(75);//cada 0.5seg comprobamos si tenemos algun mensaje entrante
    if(PSerial.available()>0){//si tenemos mensaje entrante cortamos el bucle y atendemos al mensaje
      f=1;//condicion de funcionamiento del bucle
      break;
    }
   
  }
}

void vela(){
  /* f=0;
  int interior[9]={12,13,14,15,16,17,18,19,20};
   for(int i=0;i<20;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(10);
    }
    int buf=0;
  while(f==0){
    int a_g=random(0,255);
    int a_r=random(0,255);
     int a_b=random(0,255);
    int num=random(0,20); 
    pixels.setPixelColor(buf, pixels.Color(0,0,0));
    pixels.setPixelColor(num, pixels.Color(a_r,a_g,a_b));
    pixels.show();
   /* for(int i=0;i<10;i++){
      pixels.setPixelColor(interior[i], pixels.Color(a_r,a_g,15));
    
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(45);
    }*/
   
    /*delay(random(0,1000));
    buf=num;
  }*/
  
}

void fuego(){
  f=0;
  int interior[9]={12,13,14,15,16,17,18,19,20};
  int exterior[12]={0,1,2,3,4,5,6,7,8,9,10,11};
  while(f==0){
    int a_g=random(0,50);
    int a_r=random(125,180);
    for(int i=0;i<10;i++){
      pixels.setPixelColor(interior[i], pixels.Color(a_r,a_g,0));
      pixels.setPixelColor(exterior[i], pixels.Color(180,a_g,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(45);
    }
    pixels.setPixelColor(10, pixels.Color(180,a_g,0));
    pixels.setPixelColor(11, pixels.Color(180,a_g,0));
    delay(150);
  }
}

void extra(int opt){

switch (opt){
  case 1:
    aurora();
  break;
  
  case 2:
    fuego();
  break;

  case 3:
    vela();
  break;

  case 4:
    color_aleatorio();
  break;
  }
}



