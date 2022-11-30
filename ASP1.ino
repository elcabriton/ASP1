int pinA = 3;
int pinB = 10;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 5;
int pinDP = 6;
int verde = 12;
int contador=0;
int count=0;    //TIMER
int interrupcao=2;//INT0

void setup() {
  //CONFIGURANDO OS 7 segmentos
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(verde, OUTPUT);//ajuda para ver se ta funcionando
  pinMode(pinDP, OUTPUT);

  pinMode(interrupcao, INPUT_PULLUP);//INTO
  //INTERRUPCAO INT0
  //INTO, INT1
 
  attachInterrupt(digitalPinToInterrupt(interrupcao),botaoAcionado,RISING);

                                                                  //FALLING
                                                                  //LOW
                                                                  //CHANGE

  
  //TIMER
  TCCR1A = 0;            //configura timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;            //limpa registrador
  TIMSK1 |= (1 << TOIE1);// habilita a interrupção do TIMER1
  TCCR1B = 1;            // modo normal sem prescaler
  TCNT1 = 0;             //SEM PRESCALER
  // 65536 ciclos * 6.25e-08 (periodo do ciclo em s) =  0.004096 s = 4.09ms tempo para interrupcao
  // 10000 ms / 4.09 ms/interrupcao = +-245 
  // 245 ciclos teremos 1S  


}


void status();
void loop() {
      status();

      
}
void botaoAcionado()
{
  static unsigned long delayEstado;
  if((millis()-delayEstado)>1000){
  contador--;
  delayEstado=millis();
  }
}

  
  
  

      
 

ISR(TIMER1_OVF_vect)//interrupção do TIMER1 
{ 
   if(count==245){//H
     contador++;
   }
   if(count==490){//E
     contador++;
   }
   if(count==735){//L
     contador++;
   }
   if(count==980){//L
     contador++;
   }
   if(count==1225){//O
     contador++;
   }
   if(count==1470){//A
     contador++;
   }
   if(count==1715){//T
     contador++;
   }
   if(count==1960){//3
     contador++;
   }
   if(count==2205){//2
     contador++;
   }
   if(count==2450){//8
     contador++;
   }
   if(count==2695){//P
     contador++;
   }

  

  

  count++;
  TCNT1=0;
}



void status(){
  if (contador==0){

      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, HIGH);
      
      
      
  }
  if(contador==1){//H
      digitalWrite(pinA,LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP,LOW);
      
      
  }
  if(contador==2){//E
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP,LOW);
      
      
  }
  if(contador==3){//L
      digitalWrite(pinA,LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP,LOW);
      
      digitalWrite(verde,HIGH);
  }
  if(contador==4){//L
      digitalWrite(pinA,LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP,LOW);

      digitalWrite(verde,LOW);
  }
  if(contador==5){//O
      digitalWrite(pinA,HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP,LOW);

      digitalWrite(verde,HIGH);
      
  }
  if(contador==6){//A
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        digitalWrite(pinDP,LOW);

      digitalWrite(verde,LOW);
      
  }
  if(contador==7){//T
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, LOW);
        digitalWrite(pinDP,LOW);
      
      
      
  }
   if(contador==8){//3
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, LOW);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, HIGH);
        digitalWrite(pinDP,LOW);
      
      
     
  
  }
   if(contador==9){//2
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, LOW);
        digitalWrite(pinG, HIGH);
        digitalWrite(pinDP,LOW);
      
      
     
  }
   if(contador==10){//8
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        digitalWrite(pinDP,LOW);
      
      
      
  }
   if(contador==11){//P
        digitalWrite(pinA,HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, LOW);
        digitalWrite(pinD, LOW);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        digitalWrite(pinDP,LOW);
        contador=-1; 
      
      
  }
  
}