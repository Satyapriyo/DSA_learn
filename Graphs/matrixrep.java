import java.io.*;
import java.util.Scanner;
/**
 * matrixrep
 */
public class matrixrep {
    public static void main(String[] args) {
        int n=3,m=4;
        Scanner sc = new Scanner(System.in);
        int adj[][] =new int[n+1][m+1];
        for (int i = 0; i < n; i++) {
            int u,v;
            u=sc.nextInt();
            v=sc.nextInt();
            adj[u][v]=1;
            adj[v][u]=1;
        }
    }
}
