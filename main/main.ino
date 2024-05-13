const cap_delay = 1; //1uS
const t_ref_final = 220; //220 uS
int t_ref = 0;
int t_in = 0;
bool take_measurement = 0;
bool comp_out = 1;
int i = 0;
int measurements [100];


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


//REGISTER AND PORT CONFIGURATIONS:
//Configure PB6 for external clk input

//Configure PB7 for external clk input

//Configure PC0 to be an output pin, stays high and gets driven low upon activation. Enable pull up resistor

//Reset ADC -- drive PC0 low for 1 clk cycle

//Configure PC1 to be an output pin, stays low and gets driven high upon activation.

//Toggle ADC input -- drive PC1 high for a CLK cycle. 

//Configure PD2 to be an input (or interrupt) pin (experiment with timing on both)

//Configure PB0 to be an input pin

//Connect timer T0 to a certain CLK

//Prescale CLK to 1MHz

//Read PD2 pin

//Read PB0 pin


