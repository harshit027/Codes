import java.util.Scanner;

class Common4  {
	private int n;
	private boolean flag = true;
	synchronized public int getN() {
		int t=-1;
		if(flag==false ){
			t = n;
			flag=true;
			notify();
		}
		else {
			try {
				wait();
			}
			catch(Exception e){
			}
		}
		return t;
	}
	synchronized public void setN(int n) {
		if(flag==true) {
			this.n=n;
			flag=false;
			notify();
		}
		else {
			try {
				wait();
			}
			catch(Exception e) {
			}
		}
	}
}
class Thread42 implements Runnable {
	Thread t;
	Common4 ref;
	Thread42(Common4 ref) {
		this.ref = ref;
		t = new Thread(this);
		t.start();
	}
	public void run() {
		for(int i=1;i<=10;i++) {
			int n = ref.getN();
			if(n==-1)
				i--;
			else {
				System.out.print(n+" : ");
				while(n-- >0) {
					System.out.print("*");
				}
				System.out.println();
			}
			//try { t.sleep(1000);}
			//catch(Exception e) {}
		}
	}
}

class Thread41 extends Thread {
	Common4 ref;
	Thread41(Common4 ref) {
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

class MultiThreadingExample4 {
	public static void main(String args[]) {
		try {
			Common4 cr = new Common4();
			Thread41 obj1 = new Thread41(cr);
			Thread42 obj2 = new Thread42(cr);
			obj1.join();
			obj2.t.join();
		}
		catch(Exception e) {
		}
	}
}
