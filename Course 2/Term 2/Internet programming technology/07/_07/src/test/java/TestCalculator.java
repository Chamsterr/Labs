import org.example.Calculator;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Ignore;
import org.junit.jupiter.api.*;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvFileSource;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;

import java.util.concurrent.TimeUnit;

import static org.junit.jupiter.api.Assertions.*;

public class TestCalculator {
    private static Calculator calculator;
    @BeforeAll
    public static void setup(){
        calculator = new Calculator();
        assertNotNull(calculator);
        System.out.println("Калькулятор успешно создан");
    }
    @Test
    public void testAdd(){
        assertEquals(10, calculator.add(5, 5));
    }
    @Disabled("This test is currently disabled")
    @Test
    @Timeout(value = 2, unit = TimeUnit.SECONDS)
    public void testTimeoutExceeded() throws InterruptedException {
        Thread.sleep(1000);
    }
    @Test
    public void testDivByZero() {
        assertThrows(ArithmeticException.class, () -> calculator.div(5, 0));
    }

    @Test
    public void testSub(){
        assertEquals(0, calculator.sub(5, 5));
    }
    @Test
    public void testMul(){
        assertEquals(25, calculator.mul(5, 5));
    }

    @ParameterizedTest
    @CsvSource({ "1, 2, 3", "1, 4, 5", "56, 44, 100" })
        void testWithCsvSource(int a, int b, int result) {
        assertEquals(result, calculator.add(a, b));
    }

    @Test
    public void testDiv(){
        assertEquals(1, calculator.div(5, 5));
    }

    @ParameterizedTest
    @CsvFileSource(resources = "/test_data.csv", numLinesToSkip = 1)
    public void testAdd(int a, int b, int expected) {
        int result = calculator.add(a, b);
        assertEquals(expected, result);
    }
}

class TestConsole{
    @Test
    @DisplayName("Имя теста")
    public void testConsole() {
        System.out.println("Консоль работает нормально...");
    }
}

@RunWith(Suite.class)
@Suite.SuiteClasses({TestCalculator.class, TestConsole.class})
class TestSuite {
}

