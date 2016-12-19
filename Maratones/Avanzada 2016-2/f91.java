package f91;

import java.io.*;
import java.util.*;

public class f91 {
    public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    public static int pint(String s) { return Integer.parseInt(s); }

    public static HashMap<Integer, Integer> mem = new HashMap<Integer, Integer>();
    
    public static int f(int n) {
	if(mem.containsKey((Integer)n)) {
	    return mem.get((Integer)n);
	} else {
		mem.put((Integer)n, n <= 100 ? f(f(n+11)) : n - 10);
	    return n <= 100 ? f(f(n+11)) : n - 10;
	}
    }

    public static void main(String [] args) throws Throwable {
	int n;
	while((n = pint(in.readLine())) > 0) {
	    out.println("f91(" + n + ") = " + f(n));
	}
	out.close();
    }
}
