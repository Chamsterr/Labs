package com.example.exam;

public class SpecializationValidator {
        public boolean validate(String spec) {
        return spec.matches("1 40 01 01|1 40 05 06|1 98 45 73");
    }
}
