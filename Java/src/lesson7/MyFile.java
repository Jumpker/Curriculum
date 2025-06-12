package src.lesson7;
import java.io.File;

public class MyFile {
    public static void main(String[] args) {
        java.io.File file = new java.io.File("D:\\Jumpker\\MyPrograms\\Curriculum\\Java\\src");
        SearchFile(file, ".java");
    }

    public static void SearchFile(File file, String name) {
        if(file == null || !file.exists()){
            System.out.println("文件不存在");
            return;
        }
        File[] f_temp = file.listFiles();
        if(f_temp != null && f_temp.length > 0){
            for(File f : f_temp){
                if(f.isFile()){
                    if(f.getName().contains(name))
                        System.out.println(f.getAbsolutePath());
                }else if(f.isDirectory()){
                    SearchFile(f, name);
                }
            }
        }
    }
}
