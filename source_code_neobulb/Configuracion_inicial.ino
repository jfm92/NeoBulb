/*******************************************
 * Proyecto realizado por Juan Flores Muñoz
 * Electronica Creativa
 * 4º GISE
 *******************************************/
//añadir el guardado en rom del color que se quiere por defecto
void init_conf(){
  //1º comprobar si es el 1er arranque que hace, y si no coger los valores
  int r_aux,g_aux,b_aux;
  if(EEPROM.read(dir+3)==1){
    r_aux=EEPROM.read(dir);
    g_aux=EEPROM.read(dir+1);
    b_aux=EEPROM.read(dir+2);
    set_color(r_aux,g_aux,b_aux);
  }
  else{
     set_color(255,255,255);//default on color->white
  }
 
}

