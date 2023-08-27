import java.util.ArrayList;
import java.util.Comparator;
import java.util.Optional;

public class Tender implements Runnable {
	static boolean tenderIsAlive = true;
	static ArrayList<Buyer> byers = new ArrayList<Buyer>();
    public void run() {
		tenderIsAlive = false;
		try {
			Thread.sleep(2500);
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		}
		System.out.println("тендр закончился");
		Optional<Buyer> minThread = byers.stream().min(Comparator.comparingInt(Buyer::getBet));
		Buyer thread = minThread.orElse(null);
		System.out.println("Победитель " + thread.getName() + " " + thread.getBet());
    }
}