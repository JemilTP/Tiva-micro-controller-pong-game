#include <stdint.h>
#include "Lib_2.h"
#include <stdio.h>
#include <string.h>
#include "func.h"
#include <math.h>
void adc_setup(void){
		RCGCADC |= 0x03;
		while((PRADC&0x03) == 0){}
		PORTE_Afsel |= 0x30;
		PORTE_den &= ~0x30;
		PORTE_Dir &= ~0x30;
		PORTE_Afsel |= 0x30;
		
		ADC0_PP |= 0x1;
		ADC1_PP_1 |= 0x1;
		ADC0_ACTSS &= ~0x8;
		ADC1_ACTSS &= ~0x8;
		//ADC0_SSPRI |= 0x0312;
		ADC0_EMUX |= 0xF000;
		ADC1_EMUX |= 0xF000;
	
		ACSSMUX3 |= 0x8;

		ACSSMUX_1_3 |= 0x9;
		ADCSSCTL1_3 |= 0x6;
		ADCSSCTL3   |= 0x6;
		ADC0_ACTSS |= 0x8;
		ADC1_ACTSS |= 0x8;
		
			
		ADC_PSSI |= 0x8;
		ADC_PSSI_1 |= 0x8;
		
		
}

int U0_GPIO(void){
		RCGCGPIO |= 0x35; 
		while( (PRGPIO&0x35)== 0){}
		PORTA_AFSEL |= 0x03;		
		PORTA_PCTL |= 0x11;  
		PORTA_DEN |= 0x03;
	
	PORTF_PUR |= 0x10;			
	PORTF_Dir |= 0xE;
	PORTF_AFSEL &= ~0x1E;
	PORTF_4R |= 0xE;
	PORTF_DEN |= 0x1E;
				
	PORTC_Dir |= 0xFF;
	PORTC_AFSEL &= ~0xFF;
	PORTC_4R |= 0xFF;
	PORTC_DEN |= 0xFF;
	
		
}
int delay(int d){
	for(int i = 0; i < 37000; i++){
		
		for(int i = 0; i < d; i++){}
		
	}
}

//what i have so far
int U0_Setup(void){
	RCGCUART |= 0x01; 
	while( (PRUART&0x01)== 0){}
	UART_CTL = 0;
	UART_IBRD = 10;
	UART_FBRC = 54;
	UART_LCRH = 0x62;
	UART_CTL = 0x321;
}

void write(uint8_t charc){
	
 while( (UART_FR&0x20) == 0x20 ){}
				
				UART_DR |= charc;
		
	
}

uint8_t read(void){
		if( (UART_FR&0x10) == 0x0){
		return(UART_DR);
		}
}
void print_uart(int scores[]){
	 char value[100] ;
	write('\n');
	write('\n');
	  sprintf(value,"Player 1: %d  Player 2: %d", scores[0],scores[1]);
		int len = strlen(value);
		for (int i = 0; i < len; i++){
		 write(value[i]);			
		}
write('\n');
		write('\n');

}



uint16_t read_adc_1(void){
		uint16_t data ;
		while((ADC_RIS_1&0x8) == 0x0 ){}
		data = ADC_SSFIFO1_3;
		ADC_ISC1 |= 0x8;		 
		
		return(data);
	}
uint16_t read_adc_0(void){
	uint16_t data ;
		while((ADC_RIS&0x8) == 0x0){}
		data = ADC_SSFIFO3;
		ADC_ISC |= 0x2;				
		return(data);
		
}



void print_game(int pos[], int pos1, int pos2){

	
	
	
	for (int b = 0;b < pos1; b++){
			write(' ');
	}
	for (int d = 0;d < 4; d++){
			write('=');
	}
	
	
	
	for(int u = 0; u < pos[0]; u++){
		
			write('\n');
	}
	for (int b = 0;b < pos[1]; b++){
			write(' ');
	}

	for(int d = 0; d < 4;d++){
		write('O');
	}
	write('\n');
		for (int b = 0;b < pos[1]; b++){
			write(' ');
	}
	for(int d = 0; d < 4;d++){
		write('O');
	}
	write('\n');
			for (int b = 0;b < pos[1]; b++){
			write(' ');
	}
		for(int d = 0; d < 4;d++){
		write('O');
	}
		
	if (pos[0] <= 48){
	for(int l = 0; l < (50 - pos[0] - 2); l++){
			write('\n');
	}
}
	for (int b = 0;b < pos2; b++){
			write(' ');
	}
	for (int d = 0;d < 4; d++){
			write('=');
	}
	write('\n');
		for(int k = 0; k < 100;k++){
			write('-');
	}
	
}

int contact(int *pos, int *player, int *ball_movement){
		int diff ;
	  int p = *player;
		
				   if (p >= pos[1]){
							diff = p - pos[1];
						}else{
							diff = pos[1] - p; 
						}
			
						if(diff == 0){					
								ball_movement[1] = 0;
						}
						if(diff == 1 ){							
								ball_movement[1] = 1;								
						}
						
					  	if(diff == 2 ){							
								ball_movement[1] = 2;								
						}
							if(diff == 3 ){							
								ball_movement[1] = 3;								
						}
						if(p > pos[1]){
								ball_movement[1] *= -1;
						}
						ball_movement[0] *= -1;
					
}
void reset(int *pos, int *p2,int *p1, int *ball_movement){
					pos[0] = 25;
					pos[1] =  50;
					*p1 = 50;
					*p2 = 50;
					ball_movement[0] = 1;
					ball_movement[1] = 0;
					
}
void led_scores(int s){
		
		
		if (s == 1){
					PORTC_Data = 1;
					PORTF_Data = 2;
			
		}
		if (s == 2){
			PORTC_Data = 3;
				PORTF_Data = 4;
		
		}
		if (s == 3){
		    PORTC_Data = 7;
				PORTF_Data = 8;
		
		}
		if (s == 4){
		    PORTC_Data = 15;
				PORTF_Data = 6;
		
		}
		if (s == 5){
		    PORTC_Data = 31;
				PORTF_Data = 10;
		
		}
}
int main(void) {
	SetSysClock_80MHz() ;
	U0_GPIO();	
	adc_setup();
	U0_Setup();	
	

	PORTF_Data = 8;
	 int pos[] = {25,50} ; //{down, across}
	 int p2 = 50;
	 int p1 = 50;
	 int scores[] = {0,0};
	 int ball_movement[] = {1,0};
	
		int diff1;
	 int diff2;
	 int count_ball = 0;
	 int speed = 2;
	 
	 //start
	  write('\n');
	  write('\n');
	 char welcome[75] = {"                                  WELCOME TO PONG, PRESS BUTTON TO START"};
	 for (int l = 0; l < strlen(welcome); l ++){
					write(welcome[l]);
	 }
	 write('\n');
	 while((PORTF_Data&0x10) == 0x10){}
				
	 
	while(scores[1] != 5 && scores[0] != 5){
		
			
		  p1 = round(read_adc_0() / 40);
		  p2 = round(read_adc_1() / 40);
				if (p1 > 96){
					p1 = 96;
				}
				if (p2 > 96){
						p2 = 96;
				}
				
				
				if (p1 >= pos[1]){
							diff1 = p1 - pos[1];
						}else{
							diff1 = pos[1] - p1; 
						}
						
					
						if (p2 >= pos[1]){
							diff2 = p2 - pos[1];
						}else{
							diff2 = pos[1] - p2;
						
						}
				 if(count_ball == speed){
				
						if(pos[0] == 1 && diff1 <= 3){  //vertical
								contact( pos, &p1, ball_movement);
						}
						
						if(pos[0] == 48 && diff2 <= 3){
								contact( pos, &p2, ball_movement);
							
						
						} 
						if(pos[1] >= 96){ //horizaontal
								ball_movement[1] *= -1;	
								
						} 
						if(pos[1] <= 0 ){
								ball_movement[1] *= -1;	
								
						}
					pos[0] += ball_movement[0];
						pos[1] += ball_movement[1];
						
						if(pos[0] == 0 || pos[0] == 49){
							if(pos[0] == 0 ){
									scores[1] += 1;
							}else{
									scores[0] += 1;
							}					
							print_game(pos, p1, p2);
							reset(pos, &p2, &p1, ball_movement);
							print_uart(scores);
							print_game(pos, p1, p2);
							while((PORTF_Data&0x10) == 0x10){}
						}

						count_ball = 0;
					}else{
							count_ball++;
					}
					
		 // print_uart(scores);
			//print_uart(pos);
			print_uart(scores);
		  print_game(pos, p1, p2);
			led_scores(scores[0]);
					delay(40);
			led_scores(scores[1]);
			
	} 

	int winner = 0;
	if(scores[0] == 5){
				winner = 1;
	}else{
			winner = 2;
	}
	char message[30];
	sprintf(message, "The winner is player %d ",winner  );
		for(int i = 0; i < 50; i ++){
						for(int g = 0; g < strlen(message); g++){ 
									write(message[g]);
							
						}
								for(int p = 0; p < i; p++){
												write('!');
									}
						delay(20);
						write('\n');
}
		}

