//register addresses

#define RCGCGPIO  (*((uint32_t volatile *)0x400FE608))   	
#define PRGPIO   (*((uint32_t volatile *)0x400FEA08))		
#define RCGCUART (*((uint32_t volatile *)0x400FE618))
#define PRUART (*((uint32_t volatile *)0x400FE618))
	
#define PORTA_PCTL (*((uint32_t volatile *)0x4000452C))	  	
#define PORTA_AFSEL (*((uint32_t volatile *)0x40004420))
#define PORTA_DEN (*((uint32_t volatile *)0x4000451C))

	  	
#define PORTF_Dir (*((uint32_t volatile *)0x40025400))
#define PORTF_DEN (*((uint32_t volatile *)0x4002551C))	
#define PORTF_4R (*((uint32_t volatile *)0x40025504))
#define PORTF_Data (*((uint32_t volatile *)0x400253FC))
#define PORTF_AFSEL (*((uint32_t volatile *)0x40025420))
#define PORTF_PUR (*((uint32_t volatile *)0x40025510))
	
	  	
#define PORTC_Dir (*((uint32_t volatile *)0x40006400))
#define PORTC_DEN (*((uint32_t volatile *)0x4000651C))	
#define PORTC_4R (*((uint32_t volatile *)0x40006504))
#define PORTC_Data (*((uint32_t volatile *)0x400063FC))
#define PORTC_AFSEL (*((uint32_t volatile *)0x40006420))
#define PORTC_PUR (*((uint32_t volatile *)0x40006510))
	

#define	UART_DR (*((uint32_t volatile *)0x4000C000))
#define	UART_IBRD (*((uint32_t volatile *)0x4000C024))
#define	UART_FBRC (*((uint32_t volatile *)0x4000C028))
#define	UART_LCRH (*((uint32_t volatile *)0x4000C02C))
#define	UART_CTL (*((uint32_t volatile *)0x4000C030))
#define UART_FR (*((uint32_t volatile *)0x4000C018))
	
#define GPIOE_IS (*((uint32_t volatile *)0x40024404 ))
#define GPIOE_IBE (*((uint32_t volatile *)0x40024408 ))
#define GPIOE_IEV (*((uint32_t volatile *)0x4002440C ) )
#define GPIOE_IM (*((uint32_t volatile *)0x40024410 ))
#define GPIOE_RIS (*((uint32_t volatile *)0x40024414 ))
#define GPIOE_MIS (*((uint32_t volatile *)0x40024418 ))
#define GPIOE_ICR (*((uint32_t volatile *)0x4002441C ))

#define PORTE_Dir (*((uint32_t volatile *)0x40024400 ))
#define PORTE_Afsel (*((uint32_t volatile *)0x40024420 ))
#define PORTE_Amsel (*((uint32_t volatile *)0x40024528 ))
#define PORTE_pctl (*((uint32_t volatile *)0x4002452C ))
#define PORTE_den (*((uint32_t volatile *)0x4002451C ))


#define RCGCADC (*((uint32_t volatile *)0x400FE638 ))
#define PRADC (*((uint32_t volatile *)0x400FEA38))
#define ADC_0 (*((uint32_t volatile *)0x40038000))
#define ADC0_PP (*((uint32_t volatile *)0x40038FC0))	
#define ADC0_ACTSS (*((uint32_t volatile *)0x40038000))
#define ADC0_SSPRI (*((uint32_t volatile *)0x40038020))
#define ADC0_EMUX (*((uint32_t volatile *)0x40038014))

#define ACSSMUX1 (*((uint32_t volatile *)0x40038060))
#define ACSSMUX3 (*((uint32_t volatile *)0x400380A0))

#define ADCSSCTL1 (*((uint32_t volatile *)0x40038064))
#define ADCSSCTL3 (*((uint32_t volatile *)0x400380A4))

#define ADC_PSSI (*((uint32_t volatile *)0x40038028))
#define ADC_RIS (*((uint32_t volatile *)0x40038004))

#define ADC_SSFIFO1 (*((uint32_t volatile *)0x40038068))
#define ADC_SSFIFO3 (*((uint32_t volatile *)0x400380A8))

#define ADC_ISC (*((uint32_t volatile *)0x4003800C))
#define ADC_SSOP2 (*((uint32_t volatile *)0x4003800C))
#define ADC_FIFO_Status_1 (*((uint32_t volatile *)0x4003806C))
#define ADC_FIFO_Overflow_1 (*((uint32_t volatile *)0x40038010))




#define ADC_1 (*((uint32_t volatile *)0x40039000))
#define ADC1_PP_1 (*((uint32_t volatile *)0x40039FC0))	
#define ADC1_ACTSS (*((uint32_t volatile *)0x40039000))
#define ADC1_SSPRI (*((uint32_t volatile *)0x40039020)
#define ADC1_EMUX (*((uint32_t volatile *)0x40039014))

#define ACSSMUX_1_1 (*((uint32_t volatile *)0x40039060))
#define ACSSMUX_1_3 (*((uint32_t volatile *)0x400390A0))

#define ADCSSCTL1_1 (*((uint32_t volatile *)0x40039064))
#define ADCSSCTL1_3 (*((uint32_t volatile *)0x400390A4))

#define ADC_PSSI_1 (*((uint32_t volatile *)0x40039028))
#define ADC_RIS_1 (*((uint32_t volatile *)0x40039004))

#define ADC_SSFIFO1_1 (*((uint32_t volatile *)0x40039068))
#define ADC_SSFIFO1_3 (*((uint32_t volatile *)0x400390A8))

#define ADC_ISC1 (*((uint32_t volatile *)0x4003900C))
#define ADC_SSOP2_1 (*((uint32_t volatile *)0x4003900C))
#define ADC_FIFO_Status1_1 (*((uint32_t volatile *)0x4003906C))
#define ADC_FIFO_Overflow1_1 (*((uint32_t volatile *)0x40039010))