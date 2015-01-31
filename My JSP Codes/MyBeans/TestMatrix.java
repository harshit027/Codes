//import matrix.*;
import java.util.*;
class TestMatrix
{
	public static void main(String args[])
		{
			Matrix m1=new Matrix(2,2);

			System.out.println("Size : "+m1.getRows()+","+m1.getColumns());
			int temp[][]=new int[m1.getRows()][m1.getColumns()];
			Scanner object=new Scanner(System.in);
			System.out.println("Enter Elements of matrix :");
			for(int i=0;i<m1.getRows();i++)
			{
				for(int j=0;j<m1.getColumns();j++)
				temp[i][j]=object.nextInt();
			}
			m1.setElements(temp);
		    int  [][] matrix=new int[2][2];
			matrix=m1.getElements();
			System.out.println("Matrix ... ");
			for(int i=0;i<m1.getRows();i++)
			{
				System.out.print("|");
				for(int j=0;j<m1.getColumns();j++)
				System.out.print(matrix[i][j]+",");
				System.out.print("|");
				System.out.print("\n");
			}
			System.out.println("2nd Row Sum = "+m1.getRowSum(2));
			System.out.println("1st Column Sum = "+m1.getColumnSum(1));
			System.out.println("Forward Diagonal Sum = "+m1.getForwardDiagonalSum());
			System.out.println("Backward Diagonal Sum = "+m1.getBackwardDiagonalSum());
			System.out.println("Total Sum = "+m1.getTotalSum());
	}
}