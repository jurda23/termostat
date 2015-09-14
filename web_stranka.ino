/****************************************************************
                Hlavni stranka serveru (index.htm)
****************************************************************

- Je ulozena v programove flash pameti - jinak dlouhe stringy
  zabraji misto v RAM
- Funkce vypis_stranku() zajisti precteni HTML kodu z flash
  a odeslani klientovi, vcetne doplneni zmerenych hodnot atd 
  
***************************************************************/

// Priprava na odeslani HTML stranky
void HTMLstart()
{
  pripojenyClient.println("HTTP/1.1 200 OK");
  pripojenyClient.println("Content-Type: text/html");
// pripojenyClient.println ("<meta charset=utf-8 >");
  pripojenyClient.println("Connection: close");
  pripojenyClient.println();
}

// Webova stranka ulozena v programove flash pameti
const char radek_1[] PROGMEM = "<!DOCTYPE HTML>";   
const char radek_2[] PROGMEM = "<html>";
const char radek_3[] PROGMEM = "<head>""<meta charset=utf-8 >";
const char radek_4[] PROGMEM = "<title>juricekpavel.net</title>";
const char radek_5[] PROGMEM = "</head>";
const char radek_6[] PROGMEM = "<p><h2>Arduino web server</h2>";
const char radek_7[] PROGMEM = "<p><b>Odeslání kratké zpravy na LCD MAX 64 ZNAKŮ!!! </b>";
const char radek_8[] PROGMEM = "<form  method=get name=form>";
const char radek_9[] PROGMEM = "<p><input type=\"text\" name=\"textBox\" value=\"\" size=\"64\" maxlength=\"64\">";
const char radek_10[] PROGMEM = "<button name=tlacitko value=1 type=submit style=height:25px;width:80px>Odeslat</button>";
const char radek_11[] PROGMEM = ""; // Zobrazuje se naposled odeslana zprava (pokud nejaka byla);
const char radek_12[] PROGMEM = "<p><b>Ovládaní </b>";
const char radek_13[] PROGMEM = "<p><button name=tlačítko value=2 type=submit style=height:25px;width:80px>On</button>";
const char radek_14[] PROGMEM = "<button name=tlačítko value=3 type=submit style=height:25px;width:80px>Off</button>";
const char radek_15[] PROGMEM = "</form>";
const char radek_16[] PROGMEM = "<p>Aktualní stav:  ";
const char radek_17[] PROGMEM = "<p><b>Meřeni teploty:</b>";
const char radek_18[] PROGMEM = "<p>Bazén      : ";
const char radek_19[] PROGMEM = "<p>Venkovní teplota je : ";
const char radek_20[] PROGMEM = "<p>Vlhkost       : ";
const char radek_21[] PROGMEM = "<p><a href=\"datalog.htm\">Datalog zmeřenych teplot</a>";
const char radek_22[] PROGMEM = "<p><hr width=\"350\" align=\"left\">";
const char radek_23[] PROGMEM = "<p><i>Založeno na platformě <a href=\"http://arduino.cc/en/Main/ArduinoBoardUno\" target=\"_blank\">Arduino</a>";
const char radek_24[] PROGMEM = " s <a href=\"http://arduino.cc/en/Main/ArduinoEthernetShield\" target=\"_blank\">Ethernet shieldem</a></i>";
const char radek_25[] PROGMEM = "<p>Vygenerováno naposledy: ";
const char radek_26[] PROGMEM = "<p><a href=\"teploty.htm\">Teploty</a>";
const char radek_27[] PROGMEM = "</html>";

// tabulka odkazujici na radky straky
const char* const webStranka[] PROGMEM = 	   
{   
  radek_1, radek_2, radek_3, radek_4, radek_5, radek_6, radek_7, radek_8, radek_9, radek_10,
  radek_11, radek_12, radek_13, radek_14, radek_15, radek_16, radek_17, radek_18, radek_19,
  radek_20, radek_21, radek_22, radek_23, radek_24, radek_25, radek_26, radek_27
};
//, radek_26
// Buffer potrebny pro kopirovani
// Minimalne tak velky, jako nejdelsi radek/string !!!
char buffer[150];

// Funkce, ktera vypise stranku klientovi
void vypis_stranku()
{
  Serial.println("Vypisuji web stranku");
  long startVypisu = millis();  
  
  HTMLstart();
  
  // Jednotlive radky web stranky 
  for (int radek = 0; radek < 27; radek++)
  {
    // kopirovani z programove flash pameti do bufferu
    strcpy_P(buffer, (char*)pgm_read_word(&(webStranka[radek])));
    switch (radek)
    {
      // radek 11 - naposledy odeslana zprava
      case 10:
        if(obsahTextBoxu.length() > 0)pripojenyClient.println("<p>Odeslali jste: " + obsahTextBoxu);
        break;
      
      // radek 16 - stav LED
      case 15:
        pripojenyClient.print(buffer);
        if(ModraLEDon) pripojenyClient.println("Zapnuto.");
        else pripojenyClient.println("Vypnuto.");
        break;
        
      // radek 18 vnitrni teplota
      case 17:
        pripojenyClient.print(buffer);
        pripojenyClient.print(Teplota1); 
        pripojenyClient.println(" &#176;C");
        break;
        
      // radek 18 venkovni teplota
      case 18:
        pripojenyClient.print(buffer);
        pripojenyClient.print(Teplota6); 
        pripojenyClient.println(" &#176;C");
        break;
        // radek 19 venkovni teplota
      case 19:
        pripojenyClient.print(buffer);
        pripojenyClient.print(dhth); 
        pripojenyClient.println F((" % Rh "));
        break;

         case 24:
        pripojenyClient.print(buffer);
        pripojenyClient.print(timeStamp(true, true)); 
        pripojenyClient.println("");
        break;
        
      default:
        pripojenyClient.println(buffer);
    }
  }
  
  Serial.println("Konec web stranky");
  Serial.print("Trvani: ");
  Serial.print(millis()-startVypisu);
  Serial.println(" ms");  
}
