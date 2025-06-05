package src.Design;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CooldownButton extends JButton {
    private Timer cooldownTimer;
    private Timer progressTimer;
    private int cooldownTimeSeconds;
    private int remainingCooldownTime;
    private Color originalBackgroundColor;

    public CooldownButton(String text, int cooldownTimeSeconds) {
        super(text);
        this.cooldownTimeSeconds = cooldownTimeSeconds;
        this.remainingCooldownTime = 0;
        this.originalBackgroundColor = getBackground();

        // Set initial background to white for the button template
        setBackground(Color.WHITE);
        setOpaque(true);
        setBorderPainted(false);

        // Cooldown timer (for disabling the button)
        cooldownTimer = new Timer(cooldownTimeSeconds * 1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setEnabled(true);
                remainingCooldownTime = 0;
                cooldownTimer.stop();
                progressTimer.stop();
                setBackground(Color.WHITE); // Reset to white after cooldown
            }
        });
        cooldownTimer.setRepeats(false);

        // Progress bar timer (for visual effect)
        progressTimer = new Timer(100, new ActionListener() { // Update every 100ms
            @Override
            public void actionPerformed(ActionEvent e) {
                if (remainingCooldownTime > 0) {
                    remainingCooldownTime -= 100; // Decrease by 100ms
                    float progress = (float) (cooldownTimeSeconds * 1000 - remainingCooldownTime) / (cooldownTimeSeconds * 1000);
                    int grayValue = (int) (255 * (1 - progress)); // From gray (255) to white (0)
                    setBackground(new Color(255, 255, grayValue)); // R, G, B values for gray to white transition
                } else {
                    progressTimer.stop();
                    setBackground(Color.WHITE);
                }
            }
        });
    }

    public void startCooldown() {
        setEnabled(false);
        remainingCooldownTime = cooldownTimeSeconds * 1000;
        setBackground(Color.LIGHT_GRAY); // Start with gray
        cooldownTimer.start();
        progressTimer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (!isEnabled() && remainingCooldownTime > 0) {
            Graphics2D g2 = (Graphics2D) g.create();
            float progress = (float) (cooldownTimeSeconds * 1000 - remainingCooldownTime) / (cooldownTimeSeconds * 1000);
            int width = (int) (getWidth() * progress);
            g2.setColor(Color.WHITE); // The part that becomes white
            g2.fillRect(0, 0, width, getHeight());
            g2.dispose();
        }
    }
}