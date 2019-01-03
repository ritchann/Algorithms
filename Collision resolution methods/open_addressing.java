import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class open_addressing {
    public static int sizeTable=100;
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        Scanner in = new Scanner(System.in);
        ArrayList<String> alist = new ArrayList<>();
        ArrayList<String> collisions = new ArrayList<>();
        ArrayList<Integer> count_prob=new ArrayList<>();
        for (int i = 0; i < sizeTable; i++)
            alist.add("");
        int m = -1, number_of_collisions = 0,count=1;
        while (count<=sizeTable)
        {
            count++;
            String s = Random();
            int k=Hash1(s);
            if(alist.get(k).isEmpty())
                alist.set(k,s);
            else {
                collisions.add(s);
                number_of_collisions++;
                count_prob.add(Insert(alist, s));
            }
        }
          for (int i = 0; i < collisions.size(); i++) {
              System.out.println(collisions.get(i) +" номер пробы: "+count_prob.get(i));
          }
          System.out.println();
          for (int i = 0; i < alist.size(); i++) {
              if (!alist.get(i).isEmpty()) {
                  System.out.println("хэш: " + i + " " + alist.get(i) );
              }
          }
            System.out.println("Колличество коллизий: " + number_of_collisions);
    }

    static String Random() {
        String symbols = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ123456789";
          Random rand=new Random();
          int count = 1 + rand.nextInt(7);
        StringBuilder randString = new StringBuilder();
         for (int i = 0; i < count; i++)
             randString.append(symbols.charAt((int) (Math.random() * symbols.length())));
        return String.valueOf(randString);
    }
    static int Hash1(String str) {
        double answerhash = 0, a = 2, m = 113;
        String current = str;
        current = current.toUpperCase();
        for (int i = 0; i < current.length(); i++)
            answerhash += current.charAt(i) * Math.pow(a, i);
        return (int) (answerhash / m);
    }
    static int Hash(String str,int number_proba)
    {
        double answerhash=0,a=2,m=113;
        String current=str;
        current=current.toUpperCase();
        for (int i = 0; i <current.length() ; i++) {
            answerhash+=current.charAt(i)*Math.pow(a,i);
        }
        return (int) ((answerhash/m+number_proba) %sizeTable);
    }

    static  int Insert(ArrayList<String> temp,String insstr)
    {
        for(int i=0;i<temp.size();i++)
        {
            int j=Hash(insstr,i);
            if(temp.get(j).isEmpty())
            {
                temp.set(j,insstr);
                return i;
            }
        }
        return 0;
    }
}


