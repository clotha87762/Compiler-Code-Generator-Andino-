int main(){
   int a = 3000;
   int b = 3000;
   int c = 1000;    
   b = a / 3 + b * 3 - b;
   
   a =  ((a + b) / 5  - 1000)  * (4  / 2)  + (3000) ;	

  digitalWrite(13, LOW);
  delay(a);
  digitalWrite(13, HIGH);
  delay(b);
  

}
