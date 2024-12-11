#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define sw1 6 // 1
#define sw2 5 // 0 
#define LED1 2
#define LED2 3
#define LED3 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
//สุนัข
byte customChar0[8] = {//สุ
  B00001,
  B00010,
  B11110,
  B00010,
  B11010,
  B10110,
  B00110,
  B00010
};
byte customChar1[8] = {//นั
  B00001,
  B00110,
  B11010,
  B01010,
  B01111,
  B01011,
  B00000,
  B00000
};
byte customChar2[8] = {//ข
  B00000,
  B00000,
  B11010,
  B01010,
  B10010,
  B11110,
  B00000,
  B00000
};

//ลูกอม
byte customChar3[8] = {  //ลู
  B00000,
  B11110,
  B00010,
  B11110,
  B10010,
  B10010,
  B00110,
  B00110
};
byte customChar4[8] = {  //ก
  B00000,
  B00000,
  B11110,
  B01010,
  B10010,
  B10010,
  B00000,
  B00000
};
byte customChar5[8] = {  //อ
  B00000,
  B00000,
  B11100,
  B00100,
  B10100,
  B11100,
  B00000,
  B00000
};
byte customChar6[8] = {  //ม
  B00000,
  B00000,
  B11001,
  B01001,
  B11111,
  B11001,
  B00000,
  B00000
};
byte customChar7[8] = {  //แ
  B00000,
  B00000,
  B10100,
  B10100,
  B10100,
  B10100,
  B11110,
  B00000
};
byte customChar8[8] = {  //ว
  B00000,
  B00000,
  B01110,
  B00010,
  B00110,
  B00110,
  B00000,
  B00000
};
byte customChar9[8] = {  //วั
  B00001,
  B00110,
  B01110,
  B00010,
  B00110,
  B00110,
  B00000,
  B00000
};
byte customChar10[8] = {  //บุ
  B00000,
  B00000,
  B11010,
  B11010,
  B01010,
  B01110,
  B00110,
  B00010
};
byte customChar11[8] = {  //ค
  B00000,
  B00000,
  B11110,
  B10010,
  B11010,
  B10010,
  B00000,
  B00000
};
byte customChar12[8] = {  //ล
  B00000,
  B00000,
  B11100,
  B00100,
  B11100,
  B10100,
  B00000,
  B00000
};
byte customChar13[8] = {  //า
  B00000,
  B00000,
  B11100,
  B00100,
  B00100,
  B00100,
  B00000,
  B00000
};
byte customChar14[8] = {  //ร
  B00000,
  B01110,
  B11000,
  B00100,
  B00100,
  B01100,
  B00000,
  B00000
};
byte customChar15[8] = {  //ย
  B00000,
  B00000,
  B11010,
  B10010,
  B01010,
  B11110,
  B00000,
  B00000
};
byte customChar16[8] = {  //ช
  B00000,
  B00001,
  B11010,
  B01010,
  B10010,
  B11110,
  B00000,
  B00000
};
byte customChar17[8] = {  //ง
  B00000,
  B00000,
  B01100,
  B10100,
  B01100,
  B00100,
  B00000,
  B00000
};
byte customChar18[8] = {  //น
  B00000,
  B00000,
  B11010,
  B01010,
  B01111,
  B01011,
  B00000,
  B00000
};
byte customChar19[8] = {  //มี
  B00010,
  B01110,
  B11010,
  B01010,
  B11110,
  B11010,
  B00000,
  B00000
};
byte customChar20[8] = {  //ด
  B00000,
  B00000,
  B11110,
  B10010,
  B10110,
  B11010,
  B10010,
  B00000
};
byte customChar21[8] = {  //ถู
  B00000,
  B11110,
  B01010,
  B10010,
  B10010,
  B11010,
  B00110,
  B00110
};
byte customChar22[8] = {  //ต้
  B00101,
  B00110,
  B01010,
  B10101,
  B10101,
  B11001,
  B10001,
  B00000
};

int answer[] = { 1, 1, 0, 1, 0, 0, 1, 1, 1, 0 }; //คำตอบ
int lifePlayer = 3; //ชีวิตของผู้เล่น(ใช้หลอดไฟในการแทนชีวิต)
int score = 0; //คะแนน
int question = 0; //คำถามที่


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(sw1, INPUT); 
  pinMode(sw2, INPUT); 
  digitalWrite(LED1,1);
  digitalWrite(LED2,1);
  digitalWrite(LED3,1);
}

void loop() { //Loop แสดงคำถาม
  Serial.print(lifePlayer) ; 
  lcd.clear() ;
  question1(question) ;
  question ++ ; 
  lcd.clear() ; 
  question2(question) ;
    question ++ ;
  lcd.clear() ;  
  question3(question) ;
    question ++ ;
  lcd.clear() ; 
  question4(question) ;
    question ++ ;
  lcd.clear() ; 
  question5(question) ;
    question ++ ;
  lcd.clear() ; 
  question6(question) ;
    question ++ ;
  lcd.clear() ;
  question7(question) ;
    question ++ ;
  lcd.clear() ; 
  question8(question) ;
    question ++ ;
    lcd.clear() ; 
  question9(question) ;
    question ++ ;
    lcd.clear() ; 
  question10(question) ;

    lcd.clear() ; 
    endgame() ; 
  }

   

void question1(int number) { //ฟังก์ชันคำถามที่ 1
  lcd.createChar(0, customChar0);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  
  lcd.setCursor(3, 0);
  lcd.print("DogDag");
  lcd.setCursor(10, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  choice(number);

}
void question2(int number) { //ฟังก์ชันคำถามที่ 2
  lcd.createChar(0, customChar3);
  lcd.createChar(1, customChar4);
  lcd.createChar(2, customChar5);
  lcd.createChar(3, customChar6);

  lcd.setCursor(0, 0);
  lcd.print("ChupaChups");
  lcd.setCursor(11, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.write((uint8_t)3);
  choice(number);

}
void question3(int number) { //ฟังก์ชันคำถามที่ 3
  lcd.createChar(0, customChar7);
  lcd.createChar(1, customChar6);
  lcd.createChar(2, customChar8);

  lcd.setCursor(5, 0);
  lcd.print("Cat");
  lcd.setCursor(9, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  choice(number);
}
void question4(int number) { //ฟังก์ชันคำถามที่ 4
  lcd.createChar(0, customChar19);
  lcd.createChar(1, customChar20);

  lcd.setCursor(5, 0);
  lcd.print("Eto");
  lcd.setCursor(9, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  choice(number);
}
void question5(int number) { //ฟังก์ชันคำถามที่ 5
  lcd.createChar(0, customChar9);
  lcd.createChar(1, customChar8);

  lcd.setCursor(5, 0);
  lcd.print("Cow");
  lcd.setCursor(9, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  choice(number);
}
void question6(int number) { //ฟังก์ชันคำถามที่ 6
  lcd.createChar(0, customChar10);
  lcd.createChar(1, customChar11);
  lcd.createChar(2, customChar12);
  lcd.createChar(3, customChar13);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar14);

  lcd.setCursor(0, 0);
  lcd.print("Personnel");
  lcd.setCursor(10, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)5);
  choice(number);
}
void question7(int number) { //ฟังก์ชันคำถามที่ 7
  lcd.createChar(0, customChar3);
  lcd.createChar(1, customChar4);
  lcd.createChar(2, customChar16);
  lcd.createChar(3, customChar13);
  lcd.createChar(4, customChar15);

  lcd.setCursor(4, 0);
  lcd.print("Sun");
  lcd.setCursor(9, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  choice(number);
}
void question8(int number) { //ฟังก์ชันคำถามที่ 8
  lcd.createChar(0, customChar14);
  lcd.createChar(1, customChar5);

  lcd.setCursor(4, 0);
  lcd.print("Coin");
  lcd.setCursor(10, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  choice(number);
}
void question9(int number) { //ฟังก์ชันคำถามที่ 9
  lcd.createChar(0, customChar18);
  lcd.createChar(1, customChar4);
  lcd.createChar(2, customChar4);
  lcd.createChar(3, customChar14);
  lcd.createChar(4, customChar17);

  lcd.setCursor(3, 0);
  lcd.print("Egret");
  lcd.setCursor(9, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  choice(number);
}
void question10(int number) { //ฟังก์ชันคำถามที่ 10
  lcd.createChar(0, customChar21);
  lcd.createChar(1, customChar4);
  lcd.createChar(2, customChar22);
  lcd.createChar(3, customChar5);
  lcd.createChar(4, customChar17);

  lcd.setCursor(2, 0);
  lcd.print("Correct");
  lcd.setCursor(10, 0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  choice(number);
}
void choice(int question) { //อ่านค่า YES/NO จากปุ่ม
  lcd.setCursor(0, 1);
  lcd.print("1.YES");
  lcd.setCursor(11, 1);
  lcd.print("2.NO");
  while (!digitalRead(sw1) && !digitalRead(sw2)) {
    delay(50);
  }
  if (digitalRead(sw1)) {
    if(!check(0, question)) delay(100) ,lifePlayer -- , life(lifePlayer) ;  
  }
  if (digitalRead(sw2)) {
    if(!check(1, question)) delay(100) , lifePlayer -- , life(lifePlayer) ;
  }

}

void endgame(){ 
  lcd.setCursor(0, 0);
  lcd.print("Score : ") ;
  lcd.setCursor(7, 0);
  lcd.print(score) ;
  while (true){
    if (digitalRead(sw1) == 1 || digitalRead(sw2) == 1) {
      question =  0 ;
      lifePlayer = 3 ;
      score = 0 ; 
      break ; 
    }  
  }
}
bool check(int choice, int q) {
  if (choice == answer[q]) {
    score ++ ; 
    return true;
  }
  return false;
}

void life(int l) { //แสดงหลอดไฟ LED ตามพลังชีวิต
  if (l == 3) {
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
  }
  else if (l == 2) {
    digitalWrite(LED1, 0);
        digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
  }
  else if (l == 1) {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
  } else if (l <= 0 ){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    lcd.clear() ; 
    
    endgame() ; 
    // exit(0) ; 
    
  }
}