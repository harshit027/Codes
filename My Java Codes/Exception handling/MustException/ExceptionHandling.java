import java.util.*;
class MustException extends Exception {
	private String val;
	MustException (String val) {
		this.val = val;
	}
	public boolean isNull() {
		if(val == null || val.equals("") ) {
			return true;
		}
		return false;
	}
	public String toString() {
		return "Value Can not be null";
	}
}
class ExceptionHandling {
	public static void main(String args[]) {
		int rollno;
		try {
			java.util.Scanner obj = new java.util.Scanner(System.in);
			String n = null;
			rollno = obj.nextInt();

			MustException me  = new MustException(n);
			if(me.isNull()) {
				throw me;
			}
			rollno = Integer.parseInt(n);
			System.out.println("Roll Number Inputted Correctly : "+rollno);
		}
		catch(MustException me) {
			System.out.println(me);
		}
		catch(InputMismatchException e) {
			System.out.println("Galat Rollno :" +e);
		}
	}
}