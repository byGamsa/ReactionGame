////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// Reaktions Spiel - made by Philipp & Lars //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Spiel C war leider zu groß für den Arduino UNO, weshalb wir es aus dem Program entnommen haben
//
//   Ladebildschirme sind nur zur optischen Verschönerung entstanden und haben keine wesentliche Funktion
//   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Cleart den Monitor

byte leer;

// Sorgt für den visuellen Spielstand vor und nach der Runde ( Timer / Durchschnittszeit / Punkte )

int startd;
int ended;
unsigned long dt;
unsigned long durchschnitttime;
unsigned long z;

unsigned long upTime;
int timer;

byte point;
byte sPoints = 20;

// Game auswahl im Menü

byte gas = 0;

// nebensächlich zu beachten (für die ausführung einer While Schleife)

byte gr;

// wählt zufälligen Pin aus

byte randomPin;

void setup() {
  Serial.begin(9600);

  // Ladescreen
  
  Serial.println("Spiel startet:");
  for(int starten = 0; starten <= 30; starten++) {
  Serial.print("⏹");
  delay(300);
  }
  delay(500);
  
  // LED Pin`s
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);                             
  
  // Taster Pin`s
  
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  delay(500);

  start();
}

void start() {

  delay(1000);
  
  // cleart optisch den Serial Monitor

  while (leer < 18) {                                       
    Serial.println(" ");
    leer ++;
  }

  leer = 0;

  // Menü-Anzeige
  
  Serial.println("-----------------------------------------Reaktionsspiel-----------------------------------------");
  Serial.println("                                     made by Lars & Phillip                                     ");
  Serial.println("------------------------------------------------------------------------------------------------");
  Serial.println(" ");
  Serial.println("Wählen Sie eines der Level aus!        ⍾  ⍾   ⍾ ");
  Serial.println("Drücken Sie einen der oberen Taster!   x   x   ⍾ (Seite neuladen) ");
  Serial.println("Taster 1: Reaktion auf Zeit");
  Serial.println("         (Sobald eine zufällige Lampe leuchtet, drücke den darunterliegenden Taster!)");
  Serial.println("         Schaffe so viele Punkte wie möglich innerhalb einer Minute!");
  Serial.println("Taster 2: So schnell wie`s geht");
  Serial.println("         (Sobald eine Zufällige Lampe leuchtet, drücke den darunterliegenden Taster!)");
  Serial.println("         Erreiche 20 Punkte so schnell wie möglich!");
  Serial.println("Taster 3: Abfolge Merken (In Progress) ");
  Serial.println("         Lampen leuchten hintereinander in einer bestimmten Reihenfolge.");
  Serial.println("         Wiedergebe diese Reihenfolge mit den darunterliegenden Tastern!");
  
  // testet welcher Taster gedrückt wurde
  
  while(gas == 0) {
    
  if (digitalRead(8) == 0) {
    gamea();
  }
  if (digitalRead(9) == 0) {
    gameb();
  }
  if (digitalRead(10) == 0) {
    Serial.println("Comming Soon");
  }
  if (digitalRead(13) == 0) {
    start();
  }
  }
}

void gamea()  {

  durchschnitttime = 0;
  dt = 0;
  startd = 0;
  ended = 0;

  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("-----------------------------------------Reaktionsspiel-----------------------------------------");
  Serial.println("                                     made by Lars & Phillip                                     ");
  Serial.println("----------------------------------------Reaktion auf Zeit---------------------------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Spiel startet:");
  for(int starten = 0; starten <= 20; starten++) {
  Serial.print("⏹");
  delay(300);
  }
  delay(500);

  while (leer < 18) {                                       
        Serial.println(" ");
        leer ++;
        }
        leer = 0;
        
  Serial.println("START");
  
  while (leer < 7) {                                       
        Serial.println(" ");
        leer ++;
        }
        leer = 0;
  
  //Läuft solange bis der Timer abgelaufen ist

  upTime = millis();

  while (millis() < upTime + 60000) {                                             
    startd = millis() - upTime;
    
    gr = 0;
    
    // wählt zufälligen Pin aus

    randomPin = random(2, 8);
    delay(500);

    // schaltet den mit LED belegten Pin ein
    
    digitalWrite(randomPin, HIGH);

    // wartet darauf, dass darunterliegender Taster gedrückt wird

    while(gr == 0) {
      if(digitalRead(randomPin + 6) == 0) {

        while (leer < 18) {                                       
        Serial.println(" ");
        leer ++;
        }

        leer = 0;
        
        // Durchschnittliche Reaktion
        
        ended = millis() - upTime;
        z = ended - startd;
        dt = dt + z;       
        durchschnitttime = dt / point;

        // Textausgabe
        
        digitalWrite(randomPin, LOW);
        Serial.print("Timer: ");
        Serial.println(millis() - upTime);
        point ++;
        Serial.print("Punkte: ");
        Serial.println(point);
        Serial.print("Reaktionsszeit: ");
        Serial.println(ended - startd);
        delay(500);
        gr ++;
        
        }
      }
    }

  
  Serial.println("-----------------------------------------Reaktionsspiel-----------------------------------------");
  Serial.println("                                     made by Lars & Phillip                                     ");
  Serial.println("----------------------------------------Reaktion auf Zeit---------------------------------------");
  Serial.println(" ");
  Serial.println("Ihre erreichten Punkte:");
  Serial.print("                                        ");
  Serial.println(point);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Ihre Durchschnittliche Reaktionszeit:");
  Serial.print("                                        ");
  Serial.println(durchschnitttime);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("");
  Serial.println("                                                              Wiederholen Taster    ⍾   x   x  ");
  Serial.println("                                                                     Menü Taster    x   x   ⍾  ");
  point = 0;    

  // Abfrage nach Wiederholung
  
  while(gr == 0){
    if(digitalRead(13) == 0) {
      gr ++;
      start();
    }

  // Abfrage nach Menü

    if(digitalRead(8) == 0) {
      gr ++;
      gamea();
    }
  }
                                                                
}

void gameb()  {

  durchschnitttime = 0;
  dt = 0;
  startd = 0;
  ended = 0;
  
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("-----------------------------------------Reaktionsspiel-----------------------------------------");
  Serial.println("                                     made by Lars & Phillip                                     ");
  Serial.println("--------------------------------------So schnell wie`s geht-------------------------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Spiel startet:");
  for(int starten = 0; starten <= 20; starten++) {
  Serial.print("⏹");
  delay(300);
  }
  delay(500);
  
  while (leer < 18) {                                       
        Serial.println(" ");
        leer ++;
        }
        leer = 0;
        
  Serial.println("START");
  
  while (leer < 7) {                                       
        Serial.println(" ");
        leer ++;
        }
        leer = 0;
  
  //Läuft solange bis Spiel abgeschlossen ist

  upTime = millis();

  while (point < sPoints) {                                                 

    startd = millis() - upTime;
    
    gr = 0;
    
    // wählt zufälligen Pin aus

    randomPin = random(2, 8);
    delay(500);

    // schaltet den mit LED belegten Pin ein
    digitalWrite(randomPin, HIGH);

    // wartet darauf, dass darunterliegender Taster gedrückt wird

    while(gr == 0) {
      if(digitalRead(randomPin + 6) == 0) {

        while (leer < 18) {                                       
        Serial.println(" ");
        leer ++;
        }

        leer = 0;

        // Durchschnittliche Reaktion
        
        ended = millis() - upTime;
        z = ended - startd;
        dt = dt + z;      
        durchschnitttime = dt / point;

        // Textausgabe
        
        digitalWrite(randomPin, LOW);
        point ++;
        Serial.print("Punkte: ");
        Serial.println(point);
        Serial.print("Reaktionsszeit: ");
        Serial.println(ended - startd);
        delay(500);
        gr ++;
        
        }
      }
    }

  gr = 0;
  Serial.println("-----------------------------------------Reaktionsspiel-----------------------------------------");
  Serial.println("                                     made by Lars & Phillip                                     ");
  Serial.println("--------------------------------------So schnell wie`s geht-------------------------------------");
  Serial.println(" ");
  Serial.println("Ihre erreichten Punkte:");
  Serial.print  ("                                        ");
  Serial.println(point);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Ihre Durchschnittliche Reaktionszeit:");
  Serial.print  ("                                        ");
  Serial.println(durchschnitttime);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Ihre insgesamt verbrauchte Zeit:");
  Serial.print  ("                                        ");
  Serial.print(millis() - upTime);                         
  Serial.println                                             ("                 Wiederholen Taster    ⍾   x   x  ");
  Serial.println("                                                                     Menü Taster    x   x   ⍾  ");
  point = 0;
  durchschnitttime = 0;       

  // Abfrage nach Wiederholung
  
  while(gr == 0){
    if(digitalRead(13) == 0) {
      gr ++;
      start();
    }

  // Abfrage nach Menü
    
    if(digitalRead(8) == 0) {
      gr ++;
      gameb();
    }
  }
                                                                  
}

void loop() {

}
