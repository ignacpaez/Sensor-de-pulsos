
// Esto ejemplo muestra un pulso de latido del corazón humano en directo.
// Se puede visualizar en "Serial Plotter" de arduino o en aplicación de APP inventor.
// Sonará un buzzer con cada latido de tu corazón.
// Esta es la señal directa del sensor de pulso.
 
//  Variables
int buzzer = 11;
int led1 = 13;
int led2 = 9;   
int pulso;  
// contiene los datos brutos entrantes. El valor de la señal puede variar entre 0-1024
int limite = 500;            // Determine qué señal "se contará como un latido" y qué señal ignorar.
void setup() {
  pinMode(buzzer,OUTPUT);         //buzzer sonará al ritmo de tu corazón!
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   Serial.begin(9600);         // Configura la comunicación serial a 9600(depende tu adaptador bluetooth como esté configurado)
}
void loop() {
 pulso = analogRead(A0);  // Lee el valor del pin analógico 0, y Asigna este valor a la variable "pulso".                       
Serial.print("*");//Este caracter lo filtra la aplicación en APP inventor
Serial.println(pulso);// Envíe el valor de pulso al Plotter serial. Comentar si queremos visualizar en "serial ploter"
   if(pulso > limite){                          // Si la señal es superior a "550", entonces suena el buzzer y se enciende led1
     digitalWrite(buzzer,HIGH);
     digitalWrite(led1,HIGH);
     digitalWrite(led2,LOW);
     delay(30);
   } else {
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
     digitalWrite(buzzer,LOW);                //  De lo contrario, deja de sonar el buzzer y led2
   }
delay(50);
}
