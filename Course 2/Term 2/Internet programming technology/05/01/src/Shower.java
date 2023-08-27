import java.util.SortedMap;
import java.util.concurrent.atomic.AtomicInteger;

public class Shower {
    int maxSize;
    int currentSize;

    public Shower(int maxSize) {
        this.maxSize = maxSize;
        this.currentSize = 0;
    }

    public synchronized void enterTheShower(Human obj){
        synchronized(this){
            currentSize++;
            System.out.println(obj.toString());
            if (maxSize == currentSize) {
                try {
                    currentSize = 0;
                    this.notify();
                    if (obj.getAllWanted() != obj.getIndex() + 1){
                        this.wait();
                    }
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
}
