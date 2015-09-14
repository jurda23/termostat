void termostat(){

      if (31 <= Teplota1) {
          digitalWrite(rele1, HIGH);
//        //  Serial.println("rele1 off");
//         //  Serial.println(rele1);
       } else {
          digitalWrite(rele1,LOW );
//        //  Serial.println("rele1 on");
//          // Serial.println(rele1);
//        //  Serial.println(rele1);
        }
         if (42 >= Teplota2 ) {
         digitalWrite(rele2, HIGH);
         //  Serial.println(rele2);
        } else {
          digitalWrite(rele2,LOW );
        // Serial.println(rele2);
      } 
       }  
