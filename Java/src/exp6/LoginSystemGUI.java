package src.exp6;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LoginSystemGUI extends JFrame {

    private JTextField usernameField;
    private JPasswordField passwordField;
    private JButton loginButton;
    private JLabel messageLabel;

    public LoginSystemGUI() {
        setTitle("登录系统");
        setSize(350, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // 窗口居中

        // 创建面板并设置布局
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 2, 10, 10)); // 4行2列，水平垂直间距10
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20)); // 设置边距

        // 用户名
        JLabel usernameLabel = new JLabel("用户名:");
        usernameField = new JTextField(15);
        panel.add(usernameLabel);
        panel.add(usernameField);

        // 密码
        JLabel passwordLabel = new JLabel("密码:");
        passwordField = new JPasswordField(15);
        panel.add(passwordLabel);
        panel.add(passwordField);

        // 登录按钮
        loginButton = new JButton("登录");
        panel.add(new JLabel()); // 占位符
        panel.add(loginButton);

        // 消息标签
        messageLabel = new JLabel("");
        messageLabel.setHorizontalAlignment(SwingConstants.CENTER);
        messageLabel.setForeground(Color.RED);
        panel.add(messageLabel);

        add(panel);

        // 设置默认按钮，当在任何文本字段中按下Enter键时，会触发此按钮
        getRootPane().setDefaultButton(loginButton);

        // 添加事件监听器
        ActionListener loginActionListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                if (username.equals("admin") && password.equals("123456")) {
                    messageLabel.setText("登录成功！");
                    messageLabel.setForeground(Color.GREEN);
                } else {
                    messageLabel.setText("用户名与密码不匹配！");
                    messageLabel.setForeground(Color.RED);
                }
            }
        };

        loginButton.addActionListener(loginActionListener);
    }

    public static void main(String[] args) {
        // 确保GUI更新在事件调度线程中进行
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new LoginSystemGUI().setVisible(true);
            }
        });
    }
}