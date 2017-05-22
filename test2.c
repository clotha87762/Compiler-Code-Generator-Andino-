int main() {
int a = 1;
while(a < 10)
{
	int b = 0;
	if( a > 5){
	b = a * 1000;
	}
	else{
	b= b / 2;	
	}
	digitalWrite(13, HIGH);
	delay(b);
	digitalWrite(13, LOW);
	delay(b);
	a = a+1;
}
}
