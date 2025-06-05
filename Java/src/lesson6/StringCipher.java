package src.lesson6;

import java.util.Scanner;

public class StringCipher {

    // 加密/解密方法
    public static String cipher(String data, String key, boolean encrypt) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char dataChar = data.charAt(i);
            char keyChar = key.charAt(i % key.length());
            if (encrypt) {
                result.append((char) (dataChar + keyChar)); // 加密：明文每个字符与密码字符的Unicode编码值相加
            } else {
                result.append((char) (dataChar - keyChar)); // 解密：密文每个字符减去密码字符的Unicode编码值
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("输入密码加密：");
        String originalText = scanner.nextLine();

        System.out.print("密码：");
        String encryptionKey = scanner.nextLine();

        String encryptedText = cipher(originalText, encryptionKey, true);
        System.out.println("密文：" + encryptedText);

        System.out.print("输入解密密码：");
        String decryptionKey = scanner.nextLine();

        String decryptedText = cipher(encryptedText, decryptionKey, false);
        System.out.println("明文：" + decryptedText);

        scanner.close();
    }
}