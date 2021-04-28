package D_Graph;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
// ��ǰ
public class Q08_WordSearch {
	/// DFS ����
	public static void main(String[] args) {
		Q08_WordSearch q08 = new Q08_WordSearch();
		String word = "ABCB";
		char[][] grid = {
				{'A','B','C','E'},
				{'S','F','C','S'},
				{'A','D','E','E'}
		};
		System.out.println(q08.solution(grid, word));
	}
//				   �� �� �� ��
	int[] dRow = {-1,1,0,0};
	int[] dCol = {0,0,-1,1};
	int m,n;
	public boolean solution(char[][] grid,String word) {
		if(grid==null || grid.length==0 || grid[0].length==0)
			return false;
		m = grid.length;
		n = grid[0].length;
		boolean[][] visited = new boolean[m][n];
		for(int i=0 ; i<m ; i++) {
			for(int j=0 ; j<n ; j++) {
				if(dfs(grid,visited,i,j,0,word)) {
					return true;
				}
			}
		}
		return false;
	}
	public boolean dfs(char[][] grid, boolean[][] visited, int row, int col, int dep, String word) {
		if(dep==word.length()) 		// �������� ����
			return true;
		if(row<0 || row>=m || col<0 || col>=n)	// �迭 ���� ��
			return false;
		if(visited[row][col])	// �̹� ������
			return false;
		if(grid[row][col]!=word.charAt(dep))	// ��ġ�� ö�ڰ� �ٸ�
			return false;
		
		visited[row][col] = true;
		for(int i=0 ; i<4 ; i++) {
			int nRow = row + dRow[i];
			int nCol = col + dCol[i];
			if(dfs(grid,visited, nRow,nCol, dep+1,word)) {
				System.out.printf("%d : [%d][%d] = %c\n",dep,row,col,grid[row][col]);
				return true;
			}
		}
		visited[row][col] = false;
		return false;
	}
}
