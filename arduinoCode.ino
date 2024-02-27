//Arduino Code
int redPin = A3;
int greenPin = A4;
int bluePin = A5;
float output=0;
float lrCoef[12] = { 0.80895733,  0.4342965 , -0.05852968, -0.17319995,  0.38599882,
        0.01639689,  7.83231267,  0.01621023,  0.31806085, -0.22162928,
       -0.22705113, -0.24487506};
float lrintercept = 15.32442564650681;

void setup() {
  

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
  // delay(1000);

  float PM25 = 0;
  float PM10 = 0;
  float NO = 5.9;
  float NO2 = 15;
  float NOx = 30;
  float NH3 = 11.15;
  float CO = 0.5 ;
  float SO2 = 6.87;
  float O3 = 19.90;
  float Benzene = 1.5;
  float Toluene = 5.3;
  float Xylene = 1.45;

  output = multiLinReg(PM25,PM10,NO,NO2,NOx,NH3,CO,SO2,O3,Benzene,Toluene,Xylene );
  Serial.print(output, 5);

}

void loop() {

  if(output<=100){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 255);
     
  }
  else if(output<=200){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 255);
    
  }
  else{
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255); 
  }
  delay(250);
  analogWrite(redPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(greenPin, 0);
  delay(250);
  
}

float multiLinReg(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l) {
  return lrintercept + a * lrCoef[0] + b * lrCoef[1] + c * lrCoef[2] + d * lrCoef[3] + e*lrCoef[4] + 
  f * lrCoef[5] + g * lrCoef[6] + h * lrCoef[7]+ i * lrCoef[8] + j * lrCoef[9] + k * lrCoef[10] + l * lrCoef[11];
}

