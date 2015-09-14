/****************************************************************
              Stranka teplot (teplota.htm)
****************************************************************


  
***************************************************************/
void HTMLteploty_start()
{
  Serial.println("Vypisuji web stranku teploty");
  long startVypisu = millis();  
  
  HTMLstart();
 
  // Kostra HTML dokumentu, hlavicka, nadpis...
  pripojenyClient.println("<!DOCTYPE HTML>\n<html>\n<head>\n<meta charset=utf-8 >\n<title>Arduino server</title>\n</head>\n<p><h2>Teploty</h2>\n<p><table>\n<tr><td>");
  
pripojenyClient.print F(("<h3 align=center>Program pro vypsani  vsech teplot, stranka se nacte automaticky jednou za 5 s</h3>"));
pripojenyClient.println F(("</br>"));

        
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Bazen:        "));
        pripojenyClient.println (Teplota1);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Bazen ohrev:  "));
        pripojenyClient.println (Teplota2);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("TUV:          "));
        pripojenyClient.println (Teplota3);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Topeni:       "));
        pripojenyClient.println (Teplota4);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Solar:        "));
        pripojenyClient.println (Teplota5);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Venek:        "));
        pripojenyClient.println (Teplota6);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Garaz:        "));
        pripojenyClient.println (Teplota7);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Teplota8:     "));
        pripojenyClient.println (Teplota8);
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Teplota9:     "));
        pripojenyClient.println (Teplota9);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("Teplota10:    "));
        pripojenyClient.println (Teplota10);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("TeplotaDht11:"));
        pripojenyClient.println (dhtt);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("VlhkostDht11:"));
        pripojenyClient.println (dhth);
        pripojenyClient.println F(("%Rh"));
        pripojenyClient.println F(("</br>"));
        pripojenyClient.println F(("TeplotniIndex:"));
        pripojenyClient.println (dhthic);
        pripojenyClient.println F(("°C"));
        pripojenyClient.println F(("</br>"));
       

        pripojenyClient.print F(("<meta http-equiv=\"refresh\" content=\"5\">")); //stránka se načte automaticky jednou za 3 s
        pripojenyClient.println F(("</body>"));
        pripojenyClient.println F(("</html>"));

//   default:
        pripojenyClient.println(buffer);
      }
     
