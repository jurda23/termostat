/****************************************************************
                  Vyhodnoceni GET pozadavku klienta
****************************************************************

- etr slouzi string prvniRadek, ktery obsahuje prvni
  radek HTTP pozadavku klienta
- V prvnim radku jsou informace o tom, ktera stranka serveru
  ma byt zobrazena a data z formulare
- Dalsi funkce data zpracuje - tlacitka, textbox...
- Zavola vypis prislusne webove stranky
  
***************************************************************/

String obsahTextBoxu = "";

void vyhodnoceni_get(String prvniRadek){
  Serial.print("Prvni radek: ");
  Serial.println(prvniRadek);
Serial.print("Volna RAM = ");
Serial.println(getFreeMemory());
  Serial.println(" B");
  
  // vyhodnoceni pozadavku pokud odpovida formatu GET /?textBox=&tlacitko=1 HTTP/1.1
  // Dorazi, pokud byl pouzit formular
  if(prvniRadek.indexOf("?textBox") != -1)
  {
    zpracujFormular(prvniRadek);
    vypis_stranku();
    if(obsahTextBoxu.length() > 0) ulozZpravu(obsahTextBoxu);
  }
   // pozadavek na stranku teploty
  else if(prvniRadek.indexOf("teploty.htm") != -1)
  
  {
     HTMLteploty_start();
    
  }
    // pozadavek na stranku rele
  else if(prvniRadek.indexOf("rele.htm") != -1)
  
  {
    RELE();
    
  }
 // pozadavek na stranku s datalogem
  else if(prvniRadek.indexOf("datalog.htm") != -1)
  {
  vypisStrankuDatalogu();
  }
  // Zadny specificky pozadavek - vypise hlavni stranku
  else
  {
    vypis_stranku();
  }
}

// Zpracovani dat z formulare
void zpracujFormular(String prvniRadek)
{
  byte zacatekTextBoxu = 0;
  byte konecTextBoxu = 0;
  obsahTextBoxu = "";
  byte tlacitkoPozice = 0;
  char tlacitko = '0';
    
  zacatekTextBoxu = prvniRadek.indexOf('=') + 1;
  konecTextBoxu = prvniRadek.indexOf('&');
  tlacitkoPozice = prvniRadek.indexOf('=',konecTextBoxu) + 1;
    
  obsahTextBoxu = prvniRadek.substring(zacatekTextBoxu, konecTextBoxu);
  // Osetreni specialnich znaku jako mezera, tecka, otaznik atd 
  obsahTextBoxu.replace('+',' '); 
  obsahTextBoxu.replace("%2C",","); 
  obsahTextBoxu.replace("%3F","?");
  obsahTextBoxu.replace("%3A",":");
  obsahTextBoxu.replace("%3B",";");
  tlacitko = prvniRadek.charAt(tlacitkoPozice);
        
  // zmeny vystupu
  if (tlacitko == '2') {ModraLEDon = true; digitalWrite(rele1, LOW);}
  else if (tlacitko == '3') {ModraLEDon = false; digitalWrite(rele1, HIGH);}
    
  // informace do konzole
  Serial.println("");
  Serial.println("Byl pouzit formular:");
  if(obsahTextBoxu.length() > 0)Serial.println("Obsah text boxu: " + obsahTextBoxu);
  Serial.print("Tlacitko: ");
  Serial.println(tlacitko);
  Serial.println("");
    
  // na displej
  if(obsahTextBoxu.length() > 0)
  {
    if(obsahTextBoxu.length() > 16 && obsahTextBoxu.length() <= 64)
    {
      String radek1 = obsahTextBoxu.substring(0, 16);
      String radek2 = obsahTextBoxu.substring(16,32);
      String radek3 = obsahTextBoxu.substring(32, 48);
      String radek4 = obsahTextBoxu.substring(48, 64);
      lcd1.clear();
      lcd1.print(radek1);
      lcd1.setCursor(0,1);
      lcd1.print(radek2);
      lcd1.setCursor(0,2);
      lcd1.print(radek3);
      lcd1.setCursor(0,3);
      lcd1.print(radek4);
    }
    else
    {  
      lcd1.clear();
      lcd1.print("Prijato: ");
      lcd1.setCursor(0,1);
      lcd1.print(obsahTextBoxu);
    }
    zpravaPrectena = false;  
  }
}


