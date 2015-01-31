import java.util.Scanner;

class Common  {
	private int n;
	synchronized public int getN() {
		return n;
	}
	synchronized public void setN(int n) {
		this.n=n;
	}
}
class Thread2 implements Runnable {
	Thread t;
	Common ref;
	Thread2(Common ref) {
		this.ref = ref;
		t = new Thread(this);
		t.start();
	}
	public void run() {
		for(int i=1;i<=10;i++) {
			int n = ref.getN();
			System.out.print(n+" : ");
			while(n-- >0) {
				System.out.print("*");
			}
			System.out.println();
			try { t.sleep(1000);}
			catch(Exception e) {}
		}
	}
}

class Thread1 extends Thread {
	Common ref;
	Thread1(Common ref) {
		this.ref= ref;
		start();
	}
	public void run() {
		java.util.Random rnd = new java.util.Random();
		for(int i=1;i<=10;i++) {
			int n = rnd.nextInt(75);
			System.out.print(n+" : ");
			ref.setN(n);
			try { sleep(1000); }
			catch(Exception e){}
		}
	}
}

class MultiThreadingExample3 {
	public static void main(String args[]) {
		try {
			Common cr = new Common();
			Thread1 obj1 = new Thread1(cr);
			Thread2 obj2 = new Thread2(cr);
			obj1.join();
			obj2.t.join();
		}
		catch(Exception e) {
		}
	}
}
