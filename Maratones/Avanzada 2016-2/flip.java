import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;

public class flip {
	public static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    public static int pint(String s) { return Integer.parseInt(s); }
    public static String pstr(int n) { return String.valueOf(n); }
    
    public static int[] l = new int[10010];
    
    public static void main(String [] args) throws Throwable {
    	int n, i;
    	while((n = pint(in.readLine())) > 0) {
    		String[] tok = in.readLine().split("\\s+");
    		for(i = 0; i < tok.length; ++i) {
    			l[i] = pint(tok[i]);
    		}
    		//out.println(Arrays.toString(l));
    		Arrays.sort(l, 0, tok.length);
    		
    		String o = "";
    		//out.println(Arrays.toString(l));
    		for(i = 0; i < tok.length; ++i) {
    			//out.println(o);
    			if (i != 0) o = o.concat(" ");
    			o.concat(String.valueOf(l[i]));
    		}
    		out.println(o);
    	}
    	
    	out.close();
    }
}


//int l[SZ];
//
//int main() {
//  int n, i;
//  while(scanf("%d", &n), n) {
//    loop(i, 0, n) {
//      scanf("%d", l+i);
//    }
//    sort(l, l+n);
//
//    loop(i, 0, n){
//      if (i != 0) printf(" ");
//      printf("%d", l[i]);
//    }
//    
//    printf("\n");
//  }
//  return 0;
//}