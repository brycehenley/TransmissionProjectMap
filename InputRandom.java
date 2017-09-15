import java.util.*;

public class InputRandom{
  public static void main(String args[]){
    for (int i = 0; i < 200; i++){
      System.out.print("T");
      double numo = Math.random()*1000000;
      int num = (int)(numo + 100000);

      System.out.print(num + " ");
      System.out.print("Project name goes here ");

      double type = Math.random() * 4;
      int t = (int)type;

      if(t == 1){
        System.out.print("Design ");
      }else if(t == 2){
        System.out.print("Construction ");
      }else if(t == 3){
        System.out.print("Complete ");
      }else{
        System.out.print("Planning ");
      }

      double ttype = Math.random() * 5;
      double tt = type;

      if(tt < .5){
        System.out.print("Storm ");
      }else if(tt >= .5 && tt <= 3){
        System.out.print("STARR: "); //: for c++ parsing original
      }else if(tt > 4){
        System.out.print("Customer Requested ");
      }else{
        System.out.print("SM 202"); //also for parsing
      }

      System.out.print(" etc ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ");

      double rand1 = Math.random() * 57 - 2;
      if(rand1 > 20){
          if((Math.random()*10)>5){
              rand1 = Math.random() * 20 - 2;
          }else{
              rand1 = Math.random() * 50 - 2;
          }
      }
      double rand2 = Math.random() * 35.0 - 20;
      if(rand2 > 10 || rand2 < -10){
          if((Math.random()*10)>5){
            rand2 = Math.random()* 10 - 10;
          }else{
            rand2 = Math.random() * 35.0 - 20;
          }
      }
      System.out.printf("%.2f %.2f %n",rand1,rand2);
    }
  }
}
