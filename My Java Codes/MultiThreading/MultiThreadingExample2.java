import java.util.Scanner;

class MyChildThreadClass1 implements Runnable {
	Thread t;
	MyChildThreadClass1() {
		t = new Thread(this);
		t.start();
	}
	public void run() {
		for(int i=1;i<=10;i++) {
			System.out.println("JABALPUR");
			try { t.sleep(1000); }
			catch(Exception e){}
		}
	}
}

class MyChildThreadClass2 extends Thread {
	MyChildThreadClass2() {
		start();
	}
	public void run() {
		for(int i=1;i<=10;i++) {
			System.out.print("BUREAU ");
			try { sleep(1000); }
			catch(Exception e){}
		}
	}
}

class MultiThreadingExample2 {
	public static void main(String args[]) {
		MyChildThreadClass2 obj2 = new MyChildThreadClass2();
		MyChildThreadClass1 obj1 = new MyChildThreadClass1();
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
