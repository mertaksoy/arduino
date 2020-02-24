#include <Debounce.h>

void matrix(char matrix[7]) {
  int map[10];
  map[0] = 2;
  map[1] = 3;
  map[2] = 4;
  map[3] = 5;
  map[4] = 6;
  map[5] = 7;
  map[6] = 8;
  map[7] = 9;  

  int i=0;
  for(i=0;i<=7; i++) {
   if(matrix[i] == 0x30) { // 0x31=1, 0x30=0
      Serial.println(map[i]);
      digitalWrite(map[i],LOW);
   }
   else digitalWrite(map[i],HIGH);
  }
}

void show(int number) {
  switch(number) {
    case 0:
      matrix("11111100");
      break;
    case 1:
      matrix("01100000");
      break;
    case 2:
      matrix("11011010");
      break;
    case 3:
      matrix("11110010");
      break;
    case 4:
      matrix("01100110");
      break;
    case 5:
      matrix("10110110");
      break;
    case 6:
      matrix("10111110");
      break;
    case 7:
      matrix("11100000");
      break;
    case 8:
      matrix("11111110");
      break;
    case 9:
      matrix("11110110");
      break;
    default:
      matrix("00000010");
      break;
  }
}

#define t1 13
#define t2 12

Debounce debouncert1 = Debounce( 20 , t1 ); 
Debounce debouncert2 = Debounce( 20 , t2 ); 

void setup()   {
  Serial.begin(9600); 

  // initialize the digital pin as an output:
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

int setCountPlus(int count){
  if(count == 9){
    count = 1;
  }
  else{
    count++;
    count %= 10;
  }
  return count;
}

int setCountMinus(int count){
  if(count==1){
    count = 9;
  }
  else{
  count--;
  count %= 10;
  }
  return count;
}

void loop()
{
  int i=-1;
  show(i);
  while(1){
    debouncert1.update();
    debouncert2.update();
    if(debouncert1.read()){
      i=setCountPlus(i);
    }
    if(debouncert2.read()){
      i=setCountMinus(i);
    }
    if(i==10){
      i=1;
    }
    show(i);
    delay(250);
  }
}