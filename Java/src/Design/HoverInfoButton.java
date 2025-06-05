package src.Design;

import javax.swing.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;

public class HoverInfoButton extends JButton {
    private String resourceInfo;
    private JLabel infoLabel;

    public HoverInfoButton(String text, String resourceInfo) {
        super(text);
        this.resourceInfo = resourceInfo;
        this.infoLabel = new JLabel();
        this.infoLabel.setVisible(false);

        // Add mouse listeners to show/hide infoLabel
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                infoLabel.setText(resourceInfo);
                infoLabel.setVisible(true);
                // Position the infoLabel next to the button
                // This part might need adjustment based on the actual layout manager
                // For now, we assume it's added to a parent container that can manage its position
            }

            @Override
            public void mouseExited(MouseEvent e) {
                infoLabel.setVisible(false);
            }
        });
    }

    public JLabel getInfoLabel() {
        return infoLabel;
    }
}