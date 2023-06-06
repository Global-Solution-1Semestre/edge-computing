// C++ code
#include <LiquidCrystal.h>

bool welcome = true;
//var for temp
int celsius = 0;
//var for humidity
int humidityOut = 0;
int humidity_val = 0;
//var for light
int light_val = 0;
//var for LSD
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
//var for status
String status = "NoStats"; // 0 - NoStats; 1 - Bad;2 - Good

void setup()
{
  // Set up the number of columns and rows on the LCD.
  lcd_1.begin(16, 2); 
  //Set up vars
  Serial.begin(9600);
  pinMode(A0, INPUT); //temperaturePin
  pinMode(A1, INPUT); //humidityPin
  pinMode(A2, INPUT); //photoresistorPin

  // Print a message to the LCD.
  lcd_1.setCursor(3, 0);
  lcd_1.print("Welcome to");
  lcd_1.setCursor(3,1);
  lcd_1.print("HiControl!");
}

void loop()
{
  //Clear Welcome message
  if (welcome){
  	delay(3000);
    welcome = false;
  }
  lcd_1.clear();
  
  //Transform to Celsius -40 to 125
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  //Simulate humidity 0 to 80
  humidityOut = analogRead(A1);
  humidity_val = map(humidityOut, 0, 1023, 10, 80);
  
  //Take light intensity value 6 to 679
  light_val = analogRead(A2);
  
  //Analysis for Strawberry 
  //tmp = 10-26; humidity = 60-75;
  lcd_1.setCursor(3, 0);
  lcd_1.print("Strawberry");
  if (celsius < 10 or humidity_val < 60){
  	status = "Bad"; //Bad
  	lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }else if(celsius <= 26 and humidity_val <= 75){
  	status = "Good"; //Good
    lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }else{
  	status = "Bad"; //Bad
  	lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }
  
  delay(3500);
  lcd_1.clear();

  //Analysis for Tomato
  //tmp = 18-30; humidity = 65-85;
  lcd_1.setCursor(5, 0);
  lcd_1.print("Tomato");
  if (celsius < 18 or humidity_val < 65){
  	status = "Bad"; //Bad
  	lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }else if(celsius <= 30 and humidity_val <= 85){
  	status = "Good"; //Good
    lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }else{
  	status = "Bad"; //Bad
  	lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }
  
  delay(3500);
  lcd_1.clear();
  
  //Analysis for Letucce
  //tmp = 15-18; humidity = 50-70;
  lcd_1.setCursor(4, 0);
  lcd_1.print("Lettuce");
  if (celsius < 15 or humidity_val < 50){
  	status = "Bad"; //Bad
  	lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }else if(celsius <= 18 and humidity_val <= 70){
  	status = "Good"; //Good
    lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }else{
  	status = "Bad"; //Bad
  	lcd_1.setCursor(2, 1);
    lcd_1.print("Status: " + status);
  }
  
  //Debug
  Serial.print("Temperature:");
  Serial.println(celsius);
  Serial.print("Humidity:");
  Serial.println(humidity_val);
  Serial.print("Light:");
  Serial.println(light_val);
  Serial.println("--------------");
  delay(3000);

}