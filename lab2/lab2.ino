//Pin Config

//Select your own pin for Gate Inputs
#define Gate_Input_A 12
#define Gate_Input_B 14
String command; // commands to input the value A and B to the gates via the Serial Monitor

void setup() { 

Serial.begin(115200);  //Define baud
//Pin Mode Config  
//Set Gate Inputs as OUTPUT
pinMode(Gate_Input_A,OUTPUT); 
pinMode(Gate_Input_B,OUTPUT);
// pinMode(LED,INPUT);
}


void loop() {
    /*do not change below code*/
    // Check if data is available to read
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
    /*do not change above code*/
         // based on the command set different values of A and B examples of setting A=1 B=1 is given
        if (command == "11") {
            digitalWrite(Gate_Input_A, HIGH);
            digitalWrite(Gate_Input_B, HIGH);
            delay(500);
            Serial.println("A: 1   B: 1");
            Serial.println("Decimal: 2   sum: 0  carry:1");
            // Serial.println(digitalRead(LED));
        } 
        else if (command == "10") {
            digitalWrite(Gate_Input_A, HIGH);
            digitalWrite(Gate_Input_B, LOW);
            delay(500);
            Serial.println("A: 1   B: 0");
            Serial.println("Decimal: 1   sum: 1  carry:0");
            // Serial.println(digitalRead(LED));
        } 
        else if (command == "01") {
            digitalWrite(Gate_Input_A, LOW);
            digitalWrite(Gate_Input_B, HIGH);
            delay(500);
            Serial.println("A: 0   B: 1");
            Serial.println("Decimal: 1   sum: 1  carry:0");
            // Serial.println(digitalRead(LED));
        } 
        else if (command == "00") {
            digitalWrite(Gate_Input_A, LOW);
            digitalWrite(Gate_Input_B, LOW);
            delay(500);
            Serial.println("A: 0   B: 0");
            Serial.println("Decimal: 0   sum: 0  carry:0");
            // Serial.println(digitalRead(LED));
        } 
        else {
            // Invalid command
            Serial.println("Invalid command. Please enter 11, 10, 01, or 00.");
        }
    }
}


