package by.belstu.it.kovkel.basejava;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        /**
        *
        * @author Cham
         * @version 3.22.2.2.2.
        */
        /**
        * This is the main method
        * which is very important for
        * execution for a java program.
        */
        char _char = 'd';
        int _int = 1;
        short _short = 1;
        byte _byte = 2;
        long _long = 1;
        boolean _boolean = true;
        String _string = "test";
        double _double = 1.32;
        Integer _integer =123;
        System.out.println(_integer + _double);

        String test1 = _string + _int;
        String test2 = _string + _char;
//        byte _test3 = _byte + _int;
//        int _test4 = _double + _long;
        long _test5 = _int + 2147483647;
        System.out.println(TextFunction.Print());

        boolean test6 = true && true;
        boolean test7 = true ^ false;
//        boolean test8 = true + true;
        long test8_1 = 9_223_372_036_854_775_807L;
        long test8_2 = 0x7fff_ffff_fffL;

        char test9_1 = 'a';
        char test9_2 = '\u0061';
        char test9_3 = 97;

        String test9_4 = "" +test9_1 + test9_2 + test9_3;

        System.out.println(test9_4);
        System.out.println(3.45 % 2.4);
        System.out.println(1.0 / 0.0);
        System.out.println(0.0 / 0.0);
        System.out.println(Math.log(-345));
        System.out.println(Float.intBitsToFloat(0x7F800000));
        System.out.println(Float.intBitsToFloat(0xFF800000));

        double pi = Math.PI;
        double e = Math.E;
        double roundedPi = Math.round(pi);
        double roundedE = Math.round(e);
        double min = Math.min(pi, e);
        double randomNum = Math.random();

        System.out.println("PI: " + pi);
        System.out.println("E: " + e);
        System.out.println("Rounded PI: " + roundedPi);
        System.out.println("Rounded E: " + roundedE);
        System.out.println("Min: " + min);
        System.out.println("Random Number: " + randomNum);

        Boolean bool1 = true;
        Boolean bool2 = false;
        System.out.println(bool1 & bool2);
        System.out.println(bool1 | bool2);
        System.out.println(bool1 ^ bool2);
        System.out.println(!bool1);

        Character char1 = 'a';
        Character char2 = 'b';
        System.out.println(char1 + char2);
        System.out.println(char1 - char2);
        System.out.println(char1 | char2);
        System.out.println(char1 & char2);

        Integer int1 = 10;
        Integer int2 = 5;
        System.out.println(int1 + int2);
        System.out.println(int1 - int2);
        System.out.println(int1 * int2);
        System.out.println(int1 / int2);
        System.out.println(int1 % int2);

        Byte byte1 = 100;
        Byte byte2 = 50;
        System.out.println(byte1 << 1);
        System.out.println(byte1 >> 1);
        System.out.println(byte1 | byte2);
        System.out.println(byte1 & byte2);

        Short short1 = 1000;
        Short short2 = 500;
        System.out.println(short1 + short2);
        System.out.println(short1 - short2);
        System.out.println(short1 * short2);
        System.out.println(short1 / short2);
        System.out.println(short1 % short2);

        Long longValue = Long.MAX_VALUE;
        System.out.println(Long.MIN_VALUE);
        System.out.println(longValue);

        Double doubleValue = Double.MAX_VALUE;
        System.out.println(Double.MIN_VALUE);
        System.out.println(doubleValue);

        int intValue = int1;
        byte byteValue = byte1;
        Integer int3 = intValue;
        Byte byte3 = byteValue;

        System.out.println(Integer.parseInt("10"));
        System.out.println(Integer.toHexString(16));
        System.out.println(Integer.compare(10, 5));
        System.out.println(Integer.toString(10));
        System.out.println(Integer.bitCount(10));
        System.out.println(Double.isNaN(Double.NaN));

        String s34 = "2345";
        int test15 = new Integer(s34);
        int test16 = Integer.valueOf(s34);
        int test17 = Integer.parseInt(s34);

        byte[] bytes = s34.getBytes();
        String str1 = new String(bytes);

        boolean test18 = Boolean.parseBoolean("true");
        boolean test19 = new Boolean(s34);

        System.out.println(test18);
        System.out.println(test19);

        String s35 = "2345";
        System.out.println("----------------------");
        System.out.println(s35 == s34);
        System.out.println(s35.equals(s34));
        System.out.println(s35.compareTo(s34));

        System.out.println("----------null------------");
        s34 = null;
        System.out.println(s35 == s34);
        System.out.println(s35.equals(s34));
//        System.out.println(s35.compareTo(s34));

        System.out.println("-------------------");
        String str = "The quick brown fox jumps over the lazy black dog";

        String[] words = str.split(" ");
        System.out.println(Arrays.toString(words));

        boolean contains = str.contains("fox");
        System.out.println("Contains 'fox'? " + contains);

        int hashCode = str.hashCode();
        System.out.println("Hash code: " + hashCode);

        int index = str.indexOf("lazy");
        System.out.println("Index of 'lazy': " + index);

        int length = str.length();
        System.out.println("Length: " + length);

        String newStr = str.replace("fox", "cat");
        System.out.println("New string: " + newStr);

        char[][] c1;
        char[] c2[] = new char[1][1];
        char c3[][] = new char[1][1];

        int[] arr = new int[0];

        System.out.println("-------------------");
        char c4[][] = new char[3][];
        int len = 0;

        for (int i = 0; i < c4.length; i++){
            c4[i] = new char[len];
            len++;
        }
        System.out.println(c4.length);
        System.out.println(c4[0].length);
        System.out.println(c4[1].length);
        System.out.println(c4[2].length);

        boolean comRez = c2 == c3;
        System.out.print("comRez ");
        System.out.println(comRez);

        int[] numbers = {1, 2, 3, 4, 5};
        for (int num : numbers) {
            System.out.println(num);
        }

        System.out.println("----------------------");

        String strs = "Hello World!";
        String modifiedStr = new Object() {
            String strs = "Hello World!";

            public String replace(char oldChar, char newChar) {
                return strs.replace(oldChar, newChar);
            }

            public String delete(char charToDelete) {
                return strs.replace(Character.toString(charToDelete), "");
            }
        }.delete('l').replace('o', '*');
        System.out.println(modifiedStr);
    }
}