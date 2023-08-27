public class MaleThread extends Thread
{
    Shower shower;
    public MaleThread(Shower sh){
        shower = sh;
    }

    public static int getNumbersOfMen() {
        return numbersOfMen;
    }

    static int numbersOfMen = 10;
    @Override
    public void run() {
        for (int i = 0; i < numbersOfMen; i++){
            Male male = new Male(i);
            male.takeShower(i);
        }
        System.out.println("Все мужчины все");
    }

    public class Male extends Human{
        public Male(int index){
            super(index);
        }
        void takeShower(int index){
            shower.enterTheShower(this);
        }
        @Override
        public String toString() {
            return "Парень" + Integer.toString(index);
        }

        public int getAllWanted(){
            return MaleThread.getNumbersOfMen();
        }
    }
}
