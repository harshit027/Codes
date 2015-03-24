package backTracking;

public class KnightsTour {

	public static int gridSize;
	public static boolean isSafe(int x, int y, int[][] solution)
	{
		if(x>=0 && x<gridSize && y >=0 && y<gridSize && solution[x][y]==-1)
			return true;
		
			return false;
	}
	
	public static void printSolution(int [][] solution)
	{
		for(int i=0;i<solution.length;i++)
		{
			for(int j=0;j<solution.length;j++)
				System.out.print(solution[i][j]+",");
			
			System.out.println();
		}
		
	}
	
	public static boolean getTour()
	{
		int [][] solution= new int[gridSize][gridSize];
		
		for(int i=0;i<gridSize;i++)
			for(int j=0;j<gridSize;j++)
				solution[i][j]=-1;
		
		//moves of knight from a position
		int [] xMoves={2,2,1,-1,-2,-2,-1,1};
		int [] yMoves={1,-1,-2,-2,-1,1,2,2};
		
		//random starting point
		solution[0][0]=0;
		if(!traverseGrid(0,0,1,solution,xMoves,yMoves))
		{
			System.out.println("Solution doesn't exist");
			return false;
		}
		else
			printSolution(solution);
		
		return true;
	}
	
	public static boolean traverseGrid(int x, int y, int moveCounter, int [][]solution, int [] xMoves, int [] yMoves)
	{
		if(moveCounter == gridSize*gridSize)
			return true; 
		
		for(int i=0;i<8;i++)
		{
			int nextXMove=x+xMoves[i];
			int nextYMove=y+yMoves[i];
			
			if(isSafe(nextXMove,nextYMove,solution))
			{
				System.out.println(nextXMove+","+nextYMove+"->"+moveCounter);
				solution[nextXMove][nextYMove]=moveCounter;
				if(traverseGrid(nextXMove,nextYMove,moveCounter+1,solution,xMoves,yMoves)==true)
				{
					//printSolution(solution);
					//System.out.println();
					return true;
				}
				else
					solution[nextXMove][nextYMove]=-1;
			}
		}
		
		return false;
	}
	
	public static void main(String args[])
	{
		gridSize=5;
		getTour();
	}
}
