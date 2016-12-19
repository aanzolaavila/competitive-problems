import java.io.*;
import java.util.*;

public class taxi {
    public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    public static int pint(String s) { return Integer.parseInt(s); }

    public static int[] gs;
    public static int n;
    
    public static int calc(){
    	int i = 0, j = n-1;
    	int a;
    	int c = 0;
    	while(i < j) {
    		if (gs[j] == 4) {
    		      ++c;
    		      --j;
    		} else if (gs[j] + gs[i] == 4) {
    		  ++c;
    		  --j;
    		  ++i;
    		} else if (gs[i] + gs[j] > 4) {
    		  ++c;
    		  --j;
    		} else if ((a = gs[i++] + gs[j--]) < 4) {
    		    if (a <= 4) {
    		    	while(a + gs[i] <= 4){
    		    		a += gs[i++];
    		    	}
    		        ++c;
    		    }
    		    }
    		  }
    		  if (i == j) ++c;
    		  return c;
    }
    
    public static void main(String [] args) throws Throwable {
    	while((n = pint(in.readLine())) != 0) {
    		String[] tok = in.readLine().split("\\s+");
    		gs = new int[tok.length];
    		for(int i = 0; i < tok.length; ++i) {
    			gs[i] = pint(tok[i]);
    		}
    		Arrays.sort(gs);
    		out.println(calc());
    	}
    	out.close();
    }
}

//int gs[SZ];
//int n, i;
//
//int calc() {
//  int i = 0, j = n-1;
//  int a;
//  int c = 0;
//  while(i < j) {
//    if (gs[j] == 4) {
//      ++c;
//      --j;
//    } else if (gs[j] + gs[i] == 4) {
//      ++c;
//      --j;
//      ++i;
//    } else if (gs[i] + gs[j] > 4) {
//      ++c;
//      --j;
//    } else if ((a = gs[i++] + gs[j--]) < 4) {
//      if (a <= 4) {
//	while(a + gs[i] <= 4){
//	  a += gs[i++];
//	}
//	++c;
//      }
//    }
//  }
//  if (i == j) ++c;
//  return c;
//}
//
//int main() {
//  while(scanf("%d", &n), n) {
//    loop(i, 0, n) {
//      scanf("%d", &gs[i]);
//    }
//
//    sort(gs, gs+n);
//    printf("%d\n", calc());
//  }
//  
//  return 0;
//}