/*
ID: xfrostb1
LANG: JAVA
TASK: b
*/

import java.io.*;
import java.util.*;

public class kvn {
    public static void main(String[] args) throws IOException {
        InputStreamReader in = new InputStreamReader(System.in);

        BufferedReader f = new BufferedReader(in);
        int N = Integer.parseInt(f.readLine());
        for(int i = 0; i < N; i++) {
//            long M = Long.parseLong(f.readLine());
            StringTokenizer s = new StringTokenizer(f.readLine());
            int M = Integer.parseInt(s.nextToken());
            int K = Integer.parseInt(s.nextToken());
            long[] values = new long[M];
            long[] prefix = new long[M];
            s = new StringTokenizer(f.readLine());
            for(int j = 0; j < M; j++){
                values[j] = Long.parseLong(s.nextToken());
                if(j==0){
                    prefix[j] = values[j];
                }else{
                    prefix[j] = prefix[j-1]+values[j];
                }
            }

            long ret = 0;

            for(int j = M-1; j > 0; j--){
                long next = 100*values[j];
                long compare = K*prefix[j-1];
                if(compare < next){
                    ret = Math.max((long)Math.ceil((double)(next-compare)/K),ret);
                }
            }

            System.out.println(ret);

        }

    }
    static class Input {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        public String next() throws IOException{
            while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return next();
        }
        public int nextInt() throws IOException{
            return Integer.parseInt(next());
        }
    }
}

