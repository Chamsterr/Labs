package by.belstu.it.kovkel.basejava;
import static java.lang.Math.*;

public class TextFunction {
    static int sint;
    Integer _int = (int) 'd';
    final int test10 =1 ;
    public final int test11 = 1;
    public static final int test12 = 1;


    public Integer get_int() {
        return _int;
    }

    public void set_int(Integer _int) {
        this._int = _int;
    }

    public String getValue() {
        return "Hello from first project";
    }

    static public void testInteger(Integer val){
        /**
        * @param Integer
        * @return void
        * */
        val += 1;
    }
    static public void testInt(int val){
        val += 1;
    }
    static public int Print(){
        return sint;
    }
}


