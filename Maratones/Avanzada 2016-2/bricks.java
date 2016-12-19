import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;

public class bricks {
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    public static int pint(String s) { return Integer.parseInt(s); }
    public static String pstr(int n) { return String.valueOf(n); }

    public static HashMap<Integer, Integer> mem = new HashMap<Integer, Integer>();
    
    public static int f(int n) {
    	if (mem.containsKey((Integer)n)){
    		return mem.get(n);
    	} else {
    		if (0 <= n && n <= 2) {
    			mem.put((Integer)n, (Integer)1);
    			return 1;
    		}
    		mem.put((Integer)n, f(n-1) + f(n-3));
    		return mem.get((Integer)n);
    	}
    }
    
    public static void main(String [] args) throws Throwable {
    	int n;
    	while((n = pint(in.readLine())) != -1) {
    		out.println(f(n));
    	}
    	out.close();
    }
}

//map<int, int> mem;
//
//int f(int n) {
//  if (mem.count(n) != 0)
//    return mem[n];
//  else {
//    if (0 <= n && n <= 2)
//      return (mem[n] = 1);
//    return (mem[n] = f(n-1) + f(n-3));
//  }
//}
//
//int main() {
//  int n;
//  while(scanf("%d", &n), n != -1) {
//    printf("%d\n", f(n));
//  }
//
//  return 0;
//}