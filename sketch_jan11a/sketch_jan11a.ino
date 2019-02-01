
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
  bool start;
  int punteggioG1 = 0;
  int punteggioG2 = 0;
  bool finito;



 void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
terminato = false;
start = false;
finito = false;
 }

 void loop() {
  // put your main code here, to run repeatedly:


if(start == false)
{
  Meta();
}
 else
 {
   if(!terminato)
  {
    turnoG1();
  }
  else
  {
   turnoG2();
  }
 }
 

    
 

 }

  
 void Meta()
 {
  Serial.println("Inserire un numero compreso tra 30 e 99");
  while(Serial.available() == 0)
  {}
    meta = Serial.parseInt();
    Serial.println("Meta settata a  :");
    
    Serial.println(String(meta));

    if(meta < 30)
    {
      Serial.println("META NON VALIDA, inserire un numero tra 30 e 99");
      terminato = false;
      }


      else
      {
        Serial.println(meta);
        start = true;
      }

/* else 
{
 Serial.println(String(meta)); 
  } 
  if(meta > 99)
  {
    Serial.println("META NON VALIDA,Inserire un numero compreso tra 30 e 99");
    }
    else
    {
     Serial.println(String(meta));
      }    
        }
        
  */    

 }
 

void turnoG1()
{
  Serial.println("G1 deve inserire un numero compreso tra 1 e 6");
  if(Serial.available() > 0)
  {
    
   nG1 =  Serial.readString();
   
   Serial.println(nG1.toInt());
    terminato = true;
    CheckG1();
    punteggioG1 = punteggioG1 + nG1.toInt();
    }
    
  }


  void turnoG2()
  {
    if(finito != true)
    {
      Serial.println("G2 deve inserire un numero compreso tra 1 e 6");
  if(Serial.available() > 0)
  {
    
   nG2 =  Serial.readString();
   
   Serial.println(nG2.toInt());
    terminato = false;
    CheckG2();
     punteggioG2 = punteggioG2 + nG2.toInt();
    }
  }

  else
  {
    Serial.end();
  }
    }
    

void Checknumbers()
{
  if(nG1.toInt() > 6)
  {
    Serial.print("PUNTATA NON VALIDA, inserire un numero compreso tra 1 e 6");
    }
    else if(nG2.toInt() > 6)
    {
      Serial.print("PUNTATA NON VALIDA, inserire un numero compreso tra 1 e 6");
      }
      else if(nG1.toInt() == nG2.toInt())
      {
        Serial.print("PUNTATA NON VALIDA, non puoi inserire un numero uguale a quello puntato dall'altro giocatore");
        }
        else if(nG2.toInt() == nG1.toInt())
        {
          Serial.print("PUNTATA NON VALIDA, non puoi inserire un numero uguale a quello puntato dall'altro giocatore");
          }
          
  }

  

  void CheckG1()
  {
    if(nG1.toInt() + punteggioG1 + punteggioG2 == meta)
    {
      Serial.println("Vince giocatore 1");
      finito = true;
      
      }
      else if (nG1.toInt() + punteggioG1 + punteggioG2 > meta)
      {
        Serial.println("Vince giocatore 2");
        finito = true;
        Serial.end();
        
        }
        
    
  }

  void CheckG2()
  {
    if(nG2.toInt() + punteggioG2 + punteggioG1 == meta)
    {
      Serial.println("Vince giocatore 2");      
      finito = true;
      Serial.end();
      }
      else if (nG1.toInt() + punteggioG1 + punteggioG2 > meta)
      {
        Serial.println("Vince giocatore 1");
        finito = true;
        Serial.end();
        }
 
        
    }

 void somma()
 {
  sommanumeri = punteggioG1 + punteggioG2;
  Serial.println(sommanumeri.toInt());
  }
    

  
