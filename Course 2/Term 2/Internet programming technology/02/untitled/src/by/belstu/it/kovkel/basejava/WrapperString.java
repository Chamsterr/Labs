package by.belstu.it.kovkel.basejava;

public abstract class WrapperString {
    public String test;

    public void setTest(String test) {
        this.test = test;
    }

    public String getTest() {
        return test;
    }

    public WrapperString() {
    }

    @Override
    public String toString() {
        return "WrapperString{}";
    }

    public void replace (char oldchar, char newchar){
        this.test = this.test.replace(oldchar, newchar);
    }

    public abstract void replace();
}
