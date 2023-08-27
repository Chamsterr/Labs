public abstract class Human {
    int index;
    public int getIndex() {
        return index;
    }
    public abstract int getAllWanted();
    public Human(int index){
        this.index = index;
    }
}
