package src.lesson7;
import java.io.File;

public class MyFile {
    public static void main(String[] args) {
        java.io.File file = new java.io.File("D:\\Jumpker\\MyPrograms\\Curriculum\\Java\\src\\lesson7\\MyFile.java");

        if (file.exists()) {
            System.out.println("文件存在: " + file.getAbsolutePath());
        } else {
            System.out.println("文件不存在: " + file.getAbsolutePath());
        }

    }
}
