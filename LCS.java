import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class LCS {
    public static void main(String[] args) {

        System.out.println("LCS len {}" + findlcs("AGGTAB", "GXTXAYB"));
    }

    public static int findlcs(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] L = new int[m + 1][n + 1];
        for (var i = 0; i <= m; i++) {
            L[i][0] = i;
        }
        for (var j = 0; j <= n; j++) {
            L[0][j] = j;
        }

        for (var i = 0; i < m; i++) {
            for (var j = 0; j < n; j++) {
                if (s.charAt(i) == t.charAt(j))
                    L[i + 1][j + 1] = L[i][j];
                else {
                    L[i + 1][j + 1] = 1 + Collections.min(new ArrayList<>(Arrays.asList(
                            L[i][j],
                            L[i][j + 1],
                            L[i + 1][j]
                    )));
                }
            }
        }

        return L[m][n];
    }

   }
