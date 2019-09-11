package com.lowfree02;

import com.lowfree01.Pair;

public class PairTest1 {
    public static void main(String[] args) {
        String[] words = {"Marry", "has", "a", "little", "lamb"};
        Pair<String> mm = ArrayAlg.minmax(words);
        System.out.println("min = " + mm.getFirst());
        System.out.println("max = " + mm.getSecond());
    }
}

class ArrayAlg{
    /**
     * gets the minimum and maximum of an array of strings
     * @param a
     * @return a pair with the min and max value, or null if null or empty
     */
    public  static Pair<String > minmax(String[] a){
        if (a == null || a.length == 0) return  null;
        String min = a[0];
        String max = a[0];
        for (int i = 1 ; i < a.length ; i++){
            if( min.compareTo(a[i])> 0) min = a[i];
            if (max.compareTo(a[i])< 0) max = a[i];
        }
        return new Pair<String >(min , max);
    }
}