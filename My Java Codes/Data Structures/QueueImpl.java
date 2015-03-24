package dataStructures;

public class QueueImpl {

	public static void main(String args[])
	{
		Queue queue= new Queue(5);
		int i=1;
		while(!queue.isFull())
		{
			queue.enqueue(10*i++);
		}
		
		while(!queue.isEmpty())
		{
			System.out.println(queue.dequeue());
		}
	}
}

class Queue
{
	private int front,rear;
	private int[] array;
	
	public Queue(int size)
	{
		array= new int[size];
		front=-1;
		rear=-1;
	}
	
	public void enqueue(int val)
	{
		if(rear==array.length-1)
		{
			System.out.println("Queue if full");
		}
		else
		{
			rear++;
			array[rear]=val;
			if(front==-1)
				front++;
		}
			
	}
	
	public int dequeue()
	{
		int val=-1;
		if(front ==-1)
		{
			System.out.println("Queue is empty");
			return -1;
		}
		else
		{
			val=array[front];	
			if(front==rear)
			{
				val=array[front];
				front =rear=-1;
			}
			if(front!=-1)
			front++;
			
		
		}
		return val;
	}
	
	
	public boolean isEmpty()
	{
		if(front==rear && front ==-1)
		{
			return true;
		}
		else
			return false;
	}
	
	public boolean isFull()
	{
		if(rear==array.length-1)
			return true;
		else
			return false;
	}
}
