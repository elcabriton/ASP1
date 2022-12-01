int pinA = 3;
int pinB = 10;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 5;
int pinDP = 6;
//segunda pinagem
int e=53;
int d=52;
int c=51;
int dp=50;
int a=49;
int b=48;
int f=47;
int g=46;
int contador=0;
int count=0;    //TIMER
int aux=0;


void setup() {
  //CONFIGURANDO OS 7 segmentos
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT); 
  pinMode(dp, OUTPUT);
  
  TCCR1A = 0;            //configura timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;            //limpa registrador
  TIMSK1 |= (1 << TOIE1);// habilita a interrupção do TIMER1
  TCCR1B = 1;            // modo normal sem prescaler
  TCNT1 = 0;             //SEM PRESCALER
  // 65536 ciclos * 6.25e-08 (periodo do ciclo em s) =  0.004096 s = 4.09ms tempo para interrupcao
  // 10000 ms / 4.09 ms/interrupcao = +-245 
  // 245 ciclos teremos 1S  
  
  


}
void loop() {
      escolha();
      countDecimal();


      
}
void escolha(){
  switch(contador){
    case 1:
    um();
    break;
    case 2:
    dois();
    break;
    case 3:
    tres();
    break;
    case 4:
    quatro();
    break;
    case 5:
    cinco();
    break;
    case 6:
    seis();
    break;
    case 7:
    sete();
    break;
    case 8:
    oito();
    break;
    case 9:
    nove();
    break;
    case 0:
    zero();
    break;
    
  }
}
 void countDecimal(){
   switch(aux){
    case 1:
    Dum();
    break;
    case 2:
    Ddois();
    break;
    case 3:
    Dtres();
    break;
    case 4:
    Dquatro();
    break;
    case 5:
    Dcinco();
    break;
    case 6:
    Dseis();
    break;
    case 7:
    Dsete();
    break;
    case 8:
    Doito();
    break;
    case 9:
    Dnove();
    break;
    case 0:
    Dzero();
    break;   
    }
 }
ISR(TIMER1_OVF_vect)//interrupção do TIMER1 
{ 
  count++;
 if (count==245){
   contador++;
   count=0;
 }
 if(contador==9){
   contador=0;
   aux++;
   
 }
   

  

  

  
}









//DEZENA
void Dzero(){
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinE,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(pinDP,LOW);
}
void Dum(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinB,LOW);
  digitalWrite(pinD,LOW);
  digitalWrite(pinE,LOW);
  digitalWrite(pinG,LOW);
  digitalWrite(pinF,LOW);
  digitalWrite(pinDP,LOW);

}
void Ddois(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,LOW);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinD,HIGH);
  digitalWrite(pinE,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinF,LOW);
  digitalWrite(pinDP,LOW);
}
void Dtres(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinD,HIGH);
  digitalWrite(pinE,LOW);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinF,LOW);
  digitalWrite(pinDP,LOW);
}
void Dquatro(){
    digitalWrite(pinA,LOW);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinD,LOW);
    digitalWrite(pinE,LOW);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinDP,LOW);
}
void Dcinco(){
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,LOW);
    digitalWrite(pinC,HIGH);
    digitalWrite(pinD,HIGH);
    digitalWrite(pinE,LOW);
    digitalWrite(pinF,HIGH);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinDP,LOW);
}
void Dseis(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinB,LOW);
  digitalWrite(pinD,HIGH);
  digitalWrite(pinE,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinF,HIGH);
  digitalWrite(pinDP,LOW);
}
void Dsete(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinD,LOW);
  digitalWrite(pinE,LOW);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinF,LOW);
  digitalWrite(pinDP,LOW);
}
void Doito(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinD,HIGH);
  digitalWrite(pinE,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinF,HIGH);
  digitalWrite(pinDP,LOW);
}
void Dnove(){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinD,HIGH);
  digitalWrite(pinE,LOW);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinF,HIGH);
  digitalWrite(pinDP,LOW);
}


//UNIDADE 
void zero(){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
}
void um(){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(g,LOW);
  digitalWrite(f,LOW);
  digitalWrite(dp,LOW);

}
void dois(){
  digitalWrite(a,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(dp,LOW);
}
void tres(){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(dp,LOW);
}
void quatro(){
  digitalWrite(a,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(dp,LOW);
}
void cinco(){
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void seis(){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(dp,LOW);
}
void sete(){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(dp,LOW);
}
void oito(){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(dp,LOW);
}
void nove(){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(dp,LOW);
}







