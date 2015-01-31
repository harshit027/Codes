import java.util.Scanner;

class MyChildThreadClass extends Thread {
	MyChildThreadClass() {
		start();
	}
	public void run() {
		for(int i=1;i<=10;i++) {
			System.out.println("BUREAU");
			try { sleep(1000); }
			catch(Exception e){}
		}
	}
}

class MultiThreadingExample1{
	public static void main(String args[]) {
		MyChildThreadClass obj1 = new MyChildThreadClass();
		for(int i=1;i<=10;i++) {
			System.out.print("PACE ");
			try {
				Thread.sleep(1000);
			}
			catch(Exception e) {
			}
		}
	}
}
