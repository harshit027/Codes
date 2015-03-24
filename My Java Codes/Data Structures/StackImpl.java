package dataStructures;

public class StackImpl {
	public static void main(String args[])
	{
		Stack stack= new Stack(5);
		int i=0;
		while(i<=5)
		{
			stack.push(i++);
		}
		
		while(!stack.isEmpty())
		{
			System.out.println(stack.pop());
		}

	}

}
class Stack
{
	private int[] array;
	private int top;
	
	public Stack(int size)
	{
		array= new int[size];
		top=-1;
	}
	
	public void push(int val)
	{
		if(top<array.length-1)
		{
			top++;
			array[top]=val;
		}
		else
		{
			System.out.println("Stack Overflow");
		}
		
	}
	public int pop()
	{
	int val;
		if(top>=0)
		{
			val=array[top];
			top--;
			return val;
		}
		else
		{
			System.out.println("Stack Empty");
			return -1;
		}
	}
	
	public boolean isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	
	public boolean isFull()
	{
		if(top==array.length)
			return true;
		else
			return false;
	}
	
	public int getSize()
	{
		return this.array.length;
	}
}
