void delay_cycles(long cycles){
	for(; cycles; cycles--)
		__delay_cycles(1);
}
