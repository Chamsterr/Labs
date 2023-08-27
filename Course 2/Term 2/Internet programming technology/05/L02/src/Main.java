import java.util.ArrayList;
import java.util.Comparator;
import java.util.Optional;
import java.util.concurrent.*;
import java.util.Random;
public class Main {
    public static void main(String args[]) throws InterruptedException {
        Tender BA = new Tender();
        CyclicBarrier cb = new CyclicBarrier(3, BA);

        System.out.println("Запуск тендара");

        new Buyer(cb, 130, "Никита");
        new Buyer(cb, 123, "Миша");
        Thread.sleep(5000);
        new Buyer(cb, 117, "Илья");
    }
}
