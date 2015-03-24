package dataStructures;

public class LinkedListImpl
{
	public static void main(String args[])
	{
		SinglyLinkedList head= new SinglyLinkedList();
		head.setNext(null);
		head.setKey(10);
		
		int i=0;
		SinglyLinkedList prev=head;
		while(i<4)
		{
			SinglyLinkedList temp= new SinglyLinkedList();
			temp.setNext(null);
			temp.setKey(i++);
			
			prev.setNext(temp);
			prev=temp;
		}
		
		SinglyLinkedList temp= head;
		while(temp!=null)
		{
			System.out.println(temp.getKey());
			temp=temp.getNext();
		}
	}
}
 class SinglyLinkedList {

	private SinglyLinkedList next;
	private int key;
	
	public SinglyLinkedList getNext() {
		return next;
	}
	public void setNext(SinglyLinkedList next) {
		this.next = next;
	}
	public int getKey() {
		return key;
	}
	public void setKey(int key) {
		this.key = key;
	}
	
}
 
 class DoublyLinkedList
 {
	 private LinkedListImpl next,prev;
	 private int key;
	public LinkedListImpl getNext() {
		return next;
	}
	public void setNext(LinkedListImpl next) {
		this.next = next;
	}
	public LinkedListImpl getPrev() {
		return prev;
	}
	public void setPrev(LinkedListImpl prev) {
		this.prev = prev;
	}
	public int getKey() {
		return key;
	}
	public void setKey(int key) {
		this.key = key;
	}
 }
