/*******************************************
 * Proyecto realizado por Juan Flores Muñoz
 * Electronica Creativa
 * 4º GISE
 *******************************************/

//Function that set color all leds, working like a bulb light
void set_color(int r,int g,int b){

  //configurar colores en los leds
 

   for(int i=1;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
     pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.setPixelColor(i, pixels.Color(r,g,b)); // Moderately bright green color.
   

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(25); // Delay for a period of time (in milliseconds).

  }
  return;
}

