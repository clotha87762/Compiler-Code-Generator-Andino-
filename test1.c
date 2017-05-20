int main(){
   int a = 3000;
   int b = 3000;
   
   b = a / 3 + b * 3 - b;

  digitalWrite(13, LOW);
  delay(a);
  digitalWrite(13, HIGH);
  delay(b);

}
