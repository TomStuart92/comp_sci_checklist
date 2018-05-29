public class LongestSubsequence {
  public static int lcs(String string1, String string2) {
    char[] X = string1.toCharArray();
    char[] Y = string2.toCharArray();
    int xLength = X.length;
    int yLength = Y.length;

    int L[][] = new int[xLength + 1][yLength + 1];

    for(int i = 0; i <= xLength; i++) {
      for(int j = 0; j <= yLength; j++) {
        if(i == 0 || j == 0)
          L[i][j] = 0;   // cannot have substring if one string has zero length.
        else if(X[i-1] == Y[j-1])
          L[i][j] = L[i-1][j-1] + 1;  // next letter in substring matches, add one to max
        else
          L[i][j] = Math.max(L[i-1][j], L[i][j-1]);   // no match, lcs is max of prefix and suffix.
      }
    }
    return L[xLength][yLength];
  }
}
