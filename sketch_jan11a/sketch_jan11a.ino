
  int buttonred = 2;
  int buttongrey = 3;
  int buttonblue = 4;
  int buttonState = 0;
  int counter = 30;
  String stringa; 
  int meta = 0;
  String number;
  String giocatore1;
  String nG1;
  String giocatore2;
  String nG2;
  bool terminato;
  String sommanumeri;
  



 void setup() {
  // put your setup code here, to run once:
pinMode(buttonred, INPUT_PULLUP);
pinMode(buttongrey, INPUT_PULLUP);
pinMode(buttonblue, INPUT_PULLUP);
Serial.begin(9600);
terminato = false;
 }

 void loop() {
  // put your main code here, to run repeatedly:

  
  if(!terminato)
  {
    turnoG1();
  }
  else
  {
   turnoG2();
  }

  somma();
  vittoria();
  
    
 

 }

  
 void Meta()
 {
   Serial.println("Inserire un numero compreso tra 30 e 99");
  while(Serial.available() == 0)
  {}
    meta = Serial.parseInt();
    Serial.println("Meta settata a  :");
    Serial.println(String(meta));
 }

void turnoG1()
{
  Serial.println("G1 deve inserire un numero compreso tra 1 e 6");
  if(Serial.available() > 0)
  {
    
   nG1 =  Serial.readString();

   Serial.println(nG1.toInt());
    terminato = true;
    }
    
  }

  void turnoG2()
  {
    Serial.println("G2 deve inserire un numero compreso tra 1 e 6");
  if(Serial.available() > 0)
  {
    
   nG2 =  Serial.readString();

   Serial.println(nG2.toInt());
    terminato = true;
    }
  }

 void somma()
 {
  sommanumeri = nG1.toInt() + nG2.toInt();
  Serial.println(sommanumeri.toInt());
  }

  void vittoria()
  {
    if(nG1.toInt() == meta)
    {
      Serial.println("Vince il giocatore 1");
      }
      else if (nG1.toInt() > meta)
      {
        Serial.println("Vince il giocatore 2");
        }
        if(nG2.toInt() == meta)
        {
          Serial.println("Vince giocatore 2");
          }
          else if (nG2.toInt() > meta)
          {
            Serial.println("Vince giocatore 1");
            }
      
    }
