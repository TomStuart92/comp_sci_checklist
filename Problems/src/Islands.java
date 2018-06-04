//Given a matrix of 1s and 0s, return the number of "islands" in the matrix
//A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring and their perimiter is surrounded by water.
//
//For example, this matrix has 4 islands.
//
//1 0 0 0 0
//0 0 1 1 0
//0 1 1 0 0
//0 0 0 0 0
//1 1 0 0 1
//1 1 0 0 1

public class Islands {
    private static final int rowNeighbours[] = new int[] {-1, -1, -1, 0, 0, 1, 1, 1};
    private static final int columnNeighbours[] = new int[] {-1, 0, 1, -1, 1, -1, 0, 1};

    private static boolean isValid(int M[][], int row, int col, boolean visited[][])
    {
        int rows = M.length;
        int columns = M[0].length;
        return (row >= 0) && (row < rows) &&  (col >= 0) && (col < columns) && (M[row][col] == 1 && !visited[row][col]);
    }


    private static void DFS(int M[][], int startRow, int startColumn, boolean[][] visited ) {
        visited[startRow][startColumn] = true;
        for (int k = 0; k < 8; ++k) {
            if (isValid(M, startRow + rowNeighbours[k], startColumn + columnNeighbours[k], visited) ) {
                DFS(M, startRow + rowNeighbours[k], startColumn + columnNeighbours[k], visited);
            }
        }
    }

    public static int countIslands(int M[][]) {
        int rows = M.length;
        int columns = M[0].length;

        boolean visited[][] = new boolean[rows][columns];
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (M[i][j] == 1 && !visited[i][j]) {
                    DFS(M, i, j, visited);
                    ++count;
                }
            }
        }
        return count;
    }
}
