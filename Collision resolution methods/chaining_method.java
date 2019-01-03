import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class chaining_method {
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner in = new Scanner(System.in);
        ArrayList<LinkedList<String>> alist=new ArrayList<>();
        ArrayList<String> collisions= new ArrayList<>();
        int number_of_collisions=0;
        for (int i = 0; i < 1000000; i++)
        {
            LinkedList<String> m=new LinkedList<>();
            m.add("");
            alist.add(m);
        }
        while(in.hasNextLine())
        {
            String s = in.nextLine();
            LinkedList<String> l = new LinkedList<>();
            l.add(s);
            if(alist.get(Hash2(s)).contains(""))
                alist.set(Hash2(s),l);
            else {
                number_of_collisions++;
                collisions.add(s);
                alist.get(Hash2(s)).addAll(l);
            }
        }
        System.out.println("Колличество коллизий : " + number_of_collisions);
        for (int i = 0; i <collisions.size() ; i++) {
            System.out.println(collisions.get(i));
        }
        System.out.println();
        for (int i = 0; i <alist.size() ; i++)
        {
            if(!alist.get(i).contains("")) {
                System.out.print("Хэш : "+i+" ");
                for (int j = 0; j < alist.get(i).size(); j++)
                    System.out.print(alist.get(i).get(j) + " ");
                System.out.println();
            }
        }
        long finish = System.currentTimeMillis();
        long timeConsumedMillis = finish - start;
        System.out.println(timeConsumedMillis);
    }
    static int Hash(String str)
    {
        String curstr=str;
        curstr.toUpperCase();
        return (str.charAt(0)-1040);
    }
    static  int Hash1(String str)
    {
        double answerhash=0,a=2,m=67;
        for (int i = 0; i <str.length() ; i++)
            answerhash+=str.charAt(i)*Math.pow(a,i);
        return (int)(answerhash/m);
    }
    static int Hash2(String str)
    {
        double answerhash=0,a=2,m=67,l=str.length()-1;
        for (int i = 0; i <str.length() ; i++) {
            answerhash+=str.charAt(i)*Math.pow(a,l--);
        }
        return (int)(answerhash/m);
    }
}
