import java.util.Random;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class Buyer implements Runnable{
    CyclicBarrier cbar;
    public Integer bet;
    public String name;
    public Integer getBet() {
        return bet;
    }

    public String getName() {
        return name;
    }

    public void setBet(Integer bet) {
        this.bet = bet;
        System.out.println(name + " изменил ставку на " + bet);
    }

    Buyer(CyclicBarrier c, Integer n, String name) {
        cbar = c;
        bet = n;
        this.name = name;
        System.out.println(name + " поставил " + bet);
        new Thread(this).start();
        Tender.byers.add(this);
        Buyer.BetChanger bc = new Buyer.BetChanger();
        bc.start();
    }

    class BetChanger extends Thread{
        @Override
        public void run() {
            if (Tender.tenderIsAlive){
                for (int i=0;i < 3; i++) {
                    Random rand = new Random();
                    int randomNum = rand.nextInt(100);
                    if (randomNum > 85) {
                        Buyer.this.setBet(bet - randomNum / 10);
                    }
                }
            }
        }
    }
    public void run() {
        try {
            cbar.await();
        } catch (BrokenBarrierException exc) {
            System.out.println(exc);
        } catch (InterruptedException exc) {
            System.out.println(exc);
        }
    }
}
