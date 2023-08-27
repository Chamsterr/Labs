package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

public class Lab08 {
    public static void Task01(){
        URL github = null;
        String githubUrl = "https://github.com/";
        try {
            github = new URL(githubUrl);
        } catch (MalformedURLException e) {
            throw new RuntimeException(e);
        }
        try (BufferedReader d = new BufferedReader(new InputStreamReader(github.openStream()))) {
            String line = "";
            while ((line = d.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }
}
