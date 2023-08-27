public class FemaleThread extends Thread {
    Shower shower;
    public FemaleThread(Shower sh){
        shower = sh;
    }
    public static int getNumbersOfFemales() {
        return numbersOfWomen;
    }
    static int numbersOfWomen = 10;
    @Override
    public void run() {
        for (int i = 0; i < numbersOfWomen; i++){
            FemaleThread.Female female = new FemaleThread.Female(i);
            female.takeShower(i);
        }
        System.out.println("Все женщины все");
    }

    public class Female extends Human{
        public Female(int index){
            super(index);
        }
        void takeShower(int index){
            shower.enterTheShower(this);
        }

        public int getAllWanted(){
            return FemaleThread.getNumbersOfFemales();
        }
        @Override
        public String toString() {
            return "Девушка " + Integer.toString(index);
        }
    }
}
