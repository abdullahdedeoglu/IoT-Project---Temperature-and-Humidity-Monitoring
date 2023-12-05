//Abdullah Dedeoglu 20010011046 Nesnelerin Interneti Odev-1

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
//DH22 sensoru ve LCD icin gerekli kutuphaneler

#define DHTPIN 2 //DHT sensorunu uygun pine bagliyor
#define DHTTYPE DHT22 //DHT sicaklik ve nem sensorunun tipi

//Nesnelerimi olusturdum
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {

  //DHT sensoru ve LCD'yi baslatiyorum
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  dht.begin();


}

void loop() {
  
  //sicaklik ve nem degiskenlerimi tanitiyorum ve sensorden degerlerini aliyorum
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();


  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C || Humidity: ");
  Serial.print(humidity);
  Serial.print("%");

/*Sicaklik degeri ve eger sicaklik 0'dan kucukk ise "TEMPERATURE-LOW" mesaji
LCD'ye yaziliyor, aksi takdirde "TEMPERATURE-HIGH" mesaji LCD'ye yaziliyor*/
  if (temperature < 0) {

    lcd.setCursor(2,0);
    lcd.print("TEMPERATURE");
    lcd.setCursor(3,1);
    lcd.print(temperature);
    lcd.print("-LOW");
    
  } else {

    lcd.setCursor(2,0);
    lcd.print("TEMPERATURE");
    lcd.setCursor(3,1);
    lcd.print(temperature);
    lcd.print("-HIGH");
    
  }

  delay(2000);
  lcd.clear();

  /*Nem degeri ve eger nem 50'den kucuk esit ise "HUMIDITY-LOW" mesaji
  LCD'ye yaziliyor, aksi takdirde "HUMIDITY-HIGH" mesaji LCD'ye yaziliyor*/
  if (humidity <= 50) {

    lcd.setCursor(4,0);
    lcd.print("HUMIDITY");
    lcd.setCursor(3,1);
    lcd.print(humidity);
    lcd.print("-LOW");

  } else {

    lcd.setCursor(4,0);
    lcd.print("HUMIDITY");
    lcd.setCursor(3,1);
    lcd.print(humidity);
    lcd.print("-HIGH");
    
  }

  delay(2000);
  lcd.clear();
  

  
}

