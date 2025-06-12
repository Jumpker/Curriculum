package src.lesson7;
import java.io.File;

public class MyFile {
    public static void main(String[] args) {
        java.io.File file = new java.io.File("D:\\Jumpker\\MyPrograms\\Curriculum\\Java\\src");

        if (file.exists() && file.isDirectory()) {
            System.out.println("文件夹存在: " + file.getAbsolutePath());
            String[] fs = file.list();
            for (String f : fs) {
                System.out.println(f);
            }
        } else {
            System.out.println("文件不存在或不是文件夹: " + file.getAbsolutePath());
        }

    }
}
