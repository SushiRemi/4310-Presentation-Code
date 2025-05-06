import java.io.*;

public class SyscallTest {
    public static void main(String[] args) {
        String filename = "javafile.txt";
        String content = "Hello from Java!";

        // Write to file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) { //Calls Windows' CreateFile syscall
            writer.write(content); //Calls Windows' WriteFile syscall
            System.out.println("Written to file: " + filename);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Read from file
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) { //Calls Windows' ReadFile syscall
            String line;
            System.out.println("Reading from file:");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
