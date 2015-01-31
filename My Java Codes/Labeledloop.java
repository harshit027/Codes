//labelled loop example


class Labeledloop
{
	public static void main(String args[])
	{
		foo:
		    for (int i = 1; i <= 5; i++)
		        for (int j = 1; j <= 3; j++) {
		            System.out.println("i is " + i + ", j is " + j);
		            if ((i + j) > 4)
		                break foo;
		        }
System.out.println("end of loops");

	}
}