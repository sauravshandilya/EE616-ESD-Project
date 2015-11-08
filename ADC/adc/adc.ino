/*
 * This code test ADC.
 * input is connected to A3 pin.
 * Frequency is 16MHz 
 * Aref pin is given voltage from power supply
 * ADC is configured in 10-bit mode
 */
int val = 0;            // variable to store the raw value of ADC conversion 
float volt = 0;         // ADC value in volts
float Aref = 4.42;      // voltage supplied at Aref pin of UC

void setup()
{
  //analogReference(DEFAULT);     // default is 5V; 
  analogReference(EXTERNAL);     // external; voltage applied on AREF pin
  pinMode(A3, INPUT);           // input connected to pin A3
  Serial.begin(9600);          //  setup serial - for debugging purpose
}

/*
 * Function to convert raw value to volts
 */
void convert_to_volt()
{
  volt = (Aref/1024)*val ; 
 // return volt;
}

void loop()
{
  val = analogRead(A3);    // read the input pin A3
  convert_to_volt();       // convert raw value to volts
  
  Serial.print("Analog Value is: "); //
  Serial.println(val);             // debug value
  Serial.print ("Analog Value(in volts):");
  Serial.print(volt);             // debug value
  Serial.println("V");       
  delay(2000);
}



