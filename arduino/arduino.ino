

void setup() {
 Serial.begin(115200);
 pinMode(8,OUTPUT);
}



String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
  
  String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  // 92-0-130
  String command = getValue(computerText, ' ',0);

    if (command == "on") {
      digitalWrite(8, HIGH);
    }
    if (command == "off") {
      digitalWrite(8, LOW);
    }
   
    Serial.println(command);
  Serial.println("WORKING");
  delay(1000);

}
