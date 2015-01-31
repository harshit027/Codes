import java.util.*;

class Matrix
{
	private int rows,columns;
    private int sum;
	private int[][] elements;

    public Matrix()
    {
	}
	public Matrix(int rows,int columns)
	{
		this.rows=rows;
		this.columns=columns;
	}
	public void setRows(int rows)
	{
		this.rows=rows;
	}
	public int getRows()
	{
		return this.rows;
	}
	public void setColumns(int columns)
	{
		this.columns=columns;
	}
	public int getColumns()
	{
		return this.columns;
	}

	public void setElements(int elements[][])
	{
		this.elements=new int[this.rows][this.columns];
		this.elements=elements;
		//Scanner object=new Scanner(System.in);
		/*for(int i=0;i<this.rows;i++)
		{
			for(int j=0;j<this.columns;j++)
			this.elements[i][j]=object.nextInt();
		}*/
	}

	public int[][] getElements()
	{
		return this.elements;
	}
	public int getRowSum(int rowNumber)
	{
        this.sum=0;
		for(int i=0;i<this.getColumns();i++)
		this.sum+=this.elements[rowNumber-1][i];
		return sum;
	}
	public int getColumnSum(int columnNumber)
	{
		this.sum=0;
		for(int i=0;i<this.getRows();i++)
		this.sum+=this.elements[i][columnNumber-1];
		return this.sum;
	}

	public int getForwardDiagonalSum()
	{
		if(this.rows!=this.columns)
		{
			System.out.println("The Matrix is not a square matrix");
			return 0;
		}
		this.sum=0;
		for(int i=0;i<this.getRows();i++)
		this.sum+=this.elements[i][i];
		return this.sum;
	}

	public int getBackwardDiagonalSum()
	{
		if(this.rows!=this.columns)
		{
			System.out.println("The Matrix is not a square matrix");
			return 0;
		}
		this.sum=0;
		for(int i=0, j=this.getRows()-1;i<this.getRows();i++,j--)

		this.sum+=this.elements[i][j];

		return this.sum;
	}

	public int getTotalSum()
	{
		this.sum=0;
		for(int i=0;i<this.getRows();i++)
		{
			for(int j=0;j<this.getColumns();j++)
			this.sum+=elements[i][j];
		}
		return this.sum;
	}

}