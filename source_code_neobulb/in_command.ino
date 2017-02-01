/*******************************************
 * Proyecto realizado por Juan Flores Muñoz
 * Electronica Creativa
 * 4º GISE
 *******************************************/


//Read serial commands and decide wich command is and which values have
String buff_in;//buffer to load input datas

char r_aux[4],g_aux[4],b_aux[4];
int r,g,b;//final data to introduce
int i,e;

bool error=0;
void rCommand(){
  
  if(PSerial.available()>0){//Waiting for input
    buff_in=PSerial.readString();//command receive
    switch(buff_in[0]){
      case 't'://asking about temperature
          get_temp();
      break;

      case 'c'://to configure a static colour
        
        /**********Red Value******************/
        i=0;
        while(1){//looking for red value
          if(buff_in[i+1]=='/'){
            if(i==2){//if the value that we receive have 2 digits or 1 en caso que solo tenga 2 digitos
              r_aux[2]=r_aux[1];
              r_aux[1]=r_aux[0];
              r_aux[0]='0';
            }
            else if(i==1){//si tiene solo 1 digito
              r_aux[2]=r_aux[0];
              r_aux[1]='0';
              r_aux[0]='0';
            }
             break;
          }
          else{
            r_aux[i]=buff_in[i+1];//introducing into char array for red value
          }
          i++;
          if(i==4){
            error = 1;
            break;
          }
        }

        if(error != 1){
           r_aux[3]='\0';
           r=atoi(r_aux);//transforming to int value
        }
        else{
          error=0;
        }
      
        
        /**************Green Value**************/
         e=i+2;
         i=0;
         while(1){//looking for red value
          if(buff_in[e]=='/'){
            if(i==2){//if the value that we receive have 2 digits or 1
              g_aux[2]=g_aux[1];
              g_aux[1]=g_aux[0];
              g_aux[0]='0';
            }
            else if(i==1){
              g_aux[2]=g_aux[0];
              g_aux[1]='0';
              g_aux[0]='0';
            }
             break;
          }
          else{
            g_aux[i]=buff_in[e];//introducing into char array for red value
          }
          e++;
          i++;
          if(i==4){
           error=1;
           break;
         }
          
        }
        
       if(error != 1){
           g_aux[3]='\0';
           g=atoi(g_aux);//transforming to int value
      }
      else{
        error=0;
      }
      
       /************Blue Value*******************/
        i=e+1;
        e=0;
         while(1){//looking for red value
          if(buff_in[i]=='/'){
            if(e==2){//if the value that we receive have 2 digits or 1
              b_aux[2]=b_aux[1];
              b_aux[1]=b_aux[0];
              b_aux[0]='0';
            }
            else if(e==1){
              b_aux[2]=b_aux[0];
              b_aux[1]='0';
              b_aux[0]='0';
            }
             break;
          }
          else{
            b_aux[e]=buff_in[i];//introducing into char array for red value
          }
          e++;
          i++;
          if(e==4){//more characters than should be
            error=1;
            break;
          }
        }
       if(error != 1){
           b_aux[3]='\0';
           b=atoi(b_aux);//transforming to int value
        }
        else{
          error=0;
        }
       //falta implementar el brillo
        set_color(r,g,b);
      break;

      case 'e'://to start special mode
        char c_aux[2];
        c_aux[0]=buff_in[1];
        c_aux[1]='\0';
        int aux;
        aux=atoi(c_aux);
        extra(aux);//choose special mode
      break;
      
      case 's':
        //save default color value in EEPROM
        b_red=r;
        b_green=g;
        b_blue=b;
        inicio=1;
        
        EEPROM.write(dir, b_red);
        EEPROM.write(dir+1, b_green);
        EEPROM.write(dir+2, b_blue);
        EEPROM.write(dir+3, inicio);
        
      break;

      default:
        
      break;

    
    }
    
  }
}



