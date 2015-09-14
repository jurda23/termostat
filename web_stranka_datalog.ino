/****************************************************************
              Stranka s datalogem teplot (datalog.htm)
****************************************************************

- namerene hodnoty se ctou z SD karty a formatuji 
  do tabulky v HTML strance
- Vzhledem k rychlosti cteni z SD karty muze odeslani 
  velkeho datalogu dost trvat!!!
    pripojenyClient.println F(("Vzhledem k rychlosti cteni z SD karty muze odeslani velkeho datalogu dost trvat!!!"));
  pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("</br>"));
***************************************************************/

void vypisStrankuDatalogu()
{
  Serial.println("Vypisuji web stranku s datalogem");
  long startVypisu = millis();  
  
  HTMLstart();
  
  // Kostra HTML dokumentu, hlavicka, nadpis...
  pripojenyClient.println("<!DOCTYPE HTML>\n<html>\n<head>\n<title>Arduino server</title>\n</head>\n<p><h2>Obsah datalogu Vzhledem k rychlosti cteni z SD karty muze odeslani velkeho datalogu dost trvat!!!</h2>\n<p><table>\n<tr><td>");
pripojenyClient.println F(("</br>"));
pripojenyClient.print F(("<h3 align=center>Stranka se nacte automaticky jednou za 15min</h3>"));
pripojenyClient.println F(("</br>"));
pripojenyClient.println F(("</br>"));
  File dataFile = SD.open("teploty.txt");
  
  if(dataFile)
  {
    // Smycka dokud jsou v souboru nejake znaky ke cteni
    while(dataFile.available())
    {
  // Pokud je precteny znak specialni (novy radek, tabulator)
      // je treba pridat HTML tag pro novy radek tabulky/novou bunku 
      char znak = dataFile.read();
      if(znak == '\n')pripojenyClient.print("</td></tr>\n<tr><td>");
      else if(znak == '\t')pripojenyClient.print("&nbsp;&nbsp;</td><td>&nbsp;&nbsp;");
      else if(znak == 13);
      else pripojenyClient.print(znak);
      pripojenyClient.print F(("<meta http-equiv=\"refresh\" content=\"900\">")); //stránka se načte automaticky jednou za 3 s
    }
    dataFile.close();
  }
  else
  {
    Serial.println("Chyba cteni souboru s datalogem");
  }
  
  pripojenyClient.println("</table>\n</html>");
  Serial.println("Konec web stranky");
  Serial.print("Trvani: ");
  Serial.print(millis()-startVypisu);
  Serial.println(" ms");   
}
  
