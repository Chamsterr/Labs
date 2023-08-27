public class Main {
        public static void main(String[] args) {
            Shower shower = new Shower(5);

            MaleThread maleThread = new MaleThread(shower);
            FemaleThread femaleThread = new FemaleThread(shower);

            maleThread.start();
            femaleThread.start();
        }
}
