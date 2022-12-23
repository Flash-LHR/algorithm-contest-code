import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
		int k = cin.nextInt();
		BigIn
        String s = cin.nextLine();
        int x = cin.nextInt();
        int y = cin.nextInt();
        System.out.println(Transform(s,x,y));
    }

    //s:输入的数字　　x:原数的进制　　y:要转化成的进制
    public static String Transform(String s,int x,int y) {
        return new java.math.BigInteger(s,x).toString(y);
    }
}
