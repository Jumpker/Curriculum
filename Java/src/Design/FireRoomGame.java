//先存一版
package src.Design;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Map;
import java.util.HashMap;

public class FireRoomGame extends JFrame {

    private JPanel messagePanel;
    private JPanel mainContentPanel;
    private CardLayout cardLayout;
    private JPanel resourcePanel;
    private JPanel buildingPanel; // Changed from shopPanel to buildingPanel
    private JButton currentScaleButton;
    private boolean gamePhase2Triggered = false;
    private Map<String, Integer> resources = new HashMap<>();
    private int roomHeat = 2; // Initial room heat, 0-5 scale
    private String[] roomStatusMessages = {"房间冰冷刺骨.", "房间很冷.", "房间暖和.", "房间很宜人.", "房间很暖.", "房间很热."};

    public FireRoomGame() {
        setTitle("A Dark Room");
        setSize(1000, 700);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // Center the window

        // Set white background and black foreground for all components
        UIManager.put("Panel.background", Color.WHITE);
        UIManager.put("Label.foreground", Color.BLACK);
        UIManager.put("Button.background", Color.WHITE);
        UIManager.put("Button.foreground", Color.BLACK);
        UIManager.put("TextArea.background", Color.WHITE);
        UIManager.put("TextArea.foreground", Color.BLACK);
        UIManager.put("ScrollPane.background", Color.WHITE);
        UIManager.put("ScrollPane.foreground", Color.BLACK);

        setLayout(new BorderLayout());

        // Message Panel (Left - 1/5 width)
        messagePanel = new JPanel();
        messagePanel.setBackground(Color.WHITE);
        messagePanel.setLayout(new BoxLayout(messagePanel, BoxLayout.Y_AXIS));
        JScrollPane messageScrollPane = new JScrollPane(messagePanel);
        messageScrollPane.setPreferredSize(new Dimension(327, getHeight())); // Approximate 1/5 width，现改为320
        messageScrollPane.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        add(messageScrollPane, BorderLayout.WEST);

        // Top Button Panel
        JPanel topButtonPanel = new JPanel();
        topButtonPanel.setBackground(Color.WHITE);
        topButtonPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        add(topButtonPanel, BorderLayout.NORTH);

        JButton fireRoomButton = new JButton("生火间");
        currentScaleButton = new JButton("   /   ");
        JButton longJourneyButton = new JButton("漫漫尘途");

        topButtonPanel.add(fireRoomButton);
        topButtonPanel.add(currentScaleButton);
        topButtonPanel.add(longJourneyButton);

        // Main Content Panel (Center)
        cardLayout = new CardLayout();
        mainContentPanel = new JPanel(cardLayout);
        mainContentPanel.setBackground(Color.WHITE);
        add(mainContentPanel, BorderLayout.CENTER);

        // Initialize resource and shop panels
        resourcePanel = new JPanel();
        resourcePanel.setBackground(Color.WHITE);
        resourcePanel.setBorder(BorderFactory.createTitledBorder("资源面板"));
        resourcePanel.setPreferredSize(new Dimension(250, resourcePanel.getPreferredSize().height)); // Set preferred width to 250
        resourcePanel.setVisible(false);

        buildingPanel = new JPanel(); // Changed from shopPanel to buildingPanel
        buildingPanel.setBackground(Color.WHITE);
        buildingPanel.setBorder(BorderFactory.createTitledBorder("建筑面板")); // Changed title
        buildingPanel.setVisible(false);

        // Initialize scenes
        setupFireRoomScene();
        setupCurrentScaleScene();
        setupLongJourneyScene();

        // Button actions to switch scenes
        fireRoomButton.addActionListener(e -> cardLayout.show(mainContentPanel, "FireRoom"));
        currentScaleButton.addActionListener(e -> cardLayout.show(mainContentPanel, "CurrentScale"));
        longJourneyButton.addActionListener(e -> cardLayout.show(mainContentPanel, "LongJourney"));

        // Initial message
        addMessage("火堆熄灭了.");
        addMessage("房间冰冷刺骨.");

        setVisible(true);

        // Start room status update timer
        startRoomStatusTimer();
    }

    private void startRoomStatusTimer() {
        Timer roomStatusTimer = new Timer(10000, new ActionListener() {
            private int roomStatusCounter = 0;

            @Override
            public void actionPerformed(ActionEvent e) {
                roomHeat = Math.max(0, roomHeat - 1); // Decrease heat by 1 every 20 seconds, minimum 0
                addMessage(roomStatusMessages[Math.min(roomHeat, roomStatusMessages.length)]);
            }
        });
        roomStatusTimer.setRepeats(true);
        roomStatusTimer.start();
    }

    private void setupFireRoomScene() {
        JPanel fireRoomPanel = new JPanel(new BorderLayout());
        fireRoomPanel.setBackground(Color.WHITE);

        // Interaction Panel (Center)
        JPanel interactionPanel = new JPanel();
        interactionPanel.setBackground(Color.WHITE);
        interactionPanel.setBorder(BorderFactory.createTitledBorder("交互面板"));
        // fireRoomPanel.add(interactionPanel, BorderLayout.CENTER); // Removed this line

        // New layout for center: interactionPanel on top, buildingPanel on bottom
        JPanel centerPanel = new JPanel(new GridLayout(2, 1));
        centerPanel.setBackground(Color.WHITE);
        centerPanel.add(interactionPanel);
        centerPanel.add(buildingPanel); // Added buildingPanel below interactionPanel
        fireRoomPanel.add(centerPanel, BorderLayout.CENTER);

        // Game Phase 1: Only "添柴" button
        CooldownButton addFuelButton = new CooldownButton("添柴", 6); // 6 seconds cooldown
        interactionPanel.add(addFuelButton);

        addFuelButton.addActionListener(e -> {
            addFuelButton.startCooldown();

            if (gamePhase2Triggered) {
                int currentWood = resources.getOrDefault("木头", 10);
                if (currentWood >= 1) {
                    resources.put("木头", currentWood - 1);
                    updateResourceDisplay();
                    roomHeat = Math.min(roomStatusMessages.length, roomHeat + 1); // Increase heat by 1, maximum 5
                String[] messages = {"火堆冒出火苗.", "火光映出窗外，射入黑暗之中.", "火堆燃烧着.", "火堆熊熊燃烧."};
                addMessage(messages[(int) (Math.random() * messages.length)]);
                } else {
                    addMessage("木头不够了.");
                }
            } else {
                String[] messages = {"火堆冒出火苗.", "火光映出窗外，射入黑暗之中.", "火堆燃烧着.", "火堆熊熊燃烧."};
                addMessage(messages[(int) (Math.random() * messages.length)]);
            }

            // Game progression based on first click
            if (!gamePhase2Triggered) {
                gamePhase2Triggered = true;
                Timer strangerArrivalTimer = new Timer(10000, ev -> {
                    addMessage("一个衣衫褴褛的陌生人步履蹒跚地步入门来，瘫倒在角落里.");
                    Timer strangerMumbleTimer = new Timer(10000, ev2 -> {
                        addMessage("陌生人瑟瑟发抖，呢喃不已，听不清在说些什么.");
                        Timer strangerCalmTimer = new Timer(10000, ev3 -> {
                            addMessage("角落里的陌生人不再颤抖了，她的呼吸平静了下来.");
                            Timer strangerHelpTimer = new Timer(5000, ev4 -> {
                                addMessage("那名陌生人站在火堆旁。她说她可以帮忙。她说她会建东西.");
                                // Trigger game phase 2
                                triggerGamePhase2();
                            });
                            strangerHelpTimer.setRepeats(false);
                            strangerHelpTimer.start();
                        });
                        strangerCalmTimer.setRepeats(false);
                        strangerCalmTimer.start();
                    });
                    strangerMumbleTimer.setRepeats(false);
                    strangerMumbleTimer.start();
                });
                strangerArrivalTimer.setRepeats(false);
                strangerArrivalTimer.start();
            }
        });

        // Right Panel for Resource (original shopPanel position is now empty)
        JPanel rightPanel = new JPanel();
        rightPanel.setBackground(Color.WHITE);
        rightPanel.setLayout(new GridLayout(2, 1)); // Arrange vertically

        rightPanel.add(resourcePanel);
        // rightPanel.add(shopPanel); // Removed shopPanel from here

        fireRoomPanel.add(rightPanel, BorderLayout.EAST);

        mainContentPanel.add(fireRoomPanel, "FireRoom");
    }

    private void triggerGamePhase2() {
        // Show resource and building panels
        resourcePanel.setVisible(true);
        buildingPanel.setVisible(true); // Changed from shopPanel to buildingPanel

        // Update Current Scale button name
        currentScaleButton.setText("静谧森林");

        // Add initial wood resource
        resources.put("木头", 5);
        updateResourceDisplay();

        // Add "伐木" button to Current Scale scene
        // This requires modifying setupCurrentScaleScene or adding a method to update it
        // For now, let's assume we can add it directly or re-setup the scene
        // Re-setup current scale scene to add the new button
        setupCurrentScaleScene(); // This will re-add the panel to cardLayout
        cardLayout.show(mainContentPanel, "FireRoom"); // Stay in FireRoom after triggering

        // Messages for phase 2
        Timer phase2MessagesTimer = new Timer(15000, e -> {
            addMessage("建造者说他能够制作陷阱来捕捉那些仍在野外活动的野兽.");
            Timer message2Timer = new Timer(5000, ev2 -> {
                addMessage("建造者说他能够制造出货车，用来运载木头.");
                Timer message3Timer = new Timer(5000, ev3 -> {
                    addMessage("建造者说这里有许多流浪者，他们也会来工作.");
                });
                message3Timer.setRepeats(false);
                message3Timer.start();
            });
            message2Timer.setRepeats(false);
            message2Timer.start();
        });
        phase2MessagesTimer.setRepeats(false);
        phase2MessagesTimer.start();

        // Add building options to FireRoom shop panel
        addBuildingOptions();
    }

    private void addBuildingOptions() {
        buildingPanel.setLayout(new BoxLayout(buildingPanel, BoxLayout.Y_AXIS));
        buildingPanel.setBorder(BorderFactory.createTitledBorder("建筑"));

        // Create a panel for hut button and its info label
        JPanel hutPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        HoverInfoButton hutButton = new HoverInfoButton("小屋", "木头-100");
        hutPanel.add(hutButton);
        hutPanel.add(hutButton.getInfoLabel());
        buildingPanel.add(hutPanel);

        // Create a panel for trap button and its info label
        JPanel trapPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        HoverInfoButton trapButton = new HoverInfoButton("陷阱", "木头-10");
        trapPanel.add(trapButton);
        trapPanel.add(trapButton.getInfoLabel());
        buildingPanel.add(trapPanel);

        // Create a panel for cart button and its info label
        JPanel cartPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        HoverInfoButton cartButton = new HoverInfoButton("货车", "木头-30");
        cartPanel.add(cartButton);
        cartPanel.add(cartButton.getInfoLabel());
        buildingPanel.add(cartPanel);

        // Add action listeners for building buttons (logic to be implemented)
        hutButton.addActionListener(e -> buildHut());
        trapButton.addActionListener(e -> buildTrap());
        cartButton.addActionListener(e -> buildCart());

        buildingPanel.revalidate();
        buildingPanel.repaint();
    }

    private void buildHut() {
        // Logic for building hut
        addMessage("建造者在林中建起一栋小屋，他说消息很快就会流传出去.");
        // Check resources, deduct, update count, etc.
    }

    private void buildTrap() {
        // Logic for building trap
        addMessage("陷阱越多，抓到的猎物就越多.");
        // Check resources, deduct, update count, etc.
    }

    private void buildCart() {
        // Logic for building cart
        // Check resources, deduct, update count, remove button, etc.
    }

    private void updateResourceDisplay() {
        // Logic to update resource panel
        resourcePanel.removeAll();
        for (java.util.Map.Entry<String, Integer> entry : resources.entrySet()) {
            resourcePanel.add(new JLabel(entry.getKey() + ": " + entry.getValue()));
        }
        resourcePanel.revalidate();
        resourcePanel.repaint();
    }




    private void setupCurrentScaleScene() {
        JPanel currentScalePanel = new JPanel(new BorderLayout());
        currentScalePanel.setBackground(Color.WHITE);

        // Interaction Panel (Center)
        JPanel interactionPanel = new JPanel(new GridLayout(2, 1)); // Two parts
        interactionPanel.setBackground(Color.WHITE);
        interactionPanel.setBorder(BorderFactory.createTitledBorder("交互面板"));

        JPanel activeEventPanel = new JPanel();
        activeEventPanel.setBackground(Color.WHITE);
        activeEventPanel.setBorder(BorderFactory.createTitledBorder("主动事件"));
        interactionPanel.add(activeEventPanel);

        // Add "伐木" button
        CooldownButton chopWoodButton = new CooldownButton("伐木", 15); // 15 seconds cooldown
        activeEventPanel.add(chopWoodButton);
        chopWoodButton.addActionListener(e -> {
            chopWoodButton.startCooldown();
            resources.put("木头", resources.getOrDefault("木头", 0) + 10);
            updateResourceDisplay();
            addMessage("林地上散落着枯枝败叶.");
        });

        JPanel laborDistributionPanel = new JPanel();
        laborDistributionPanel.setBackground(Color.WHITE);
        laborDistributionPanel.setBorder(BorderFactory.createTitledBorder("人员分工"));
        interactionPanel.add(laborDistributionPanel);

        currentScalePanel.add(interactionPanel, BorderLayout.CENTER);

        // Resource Panel (Right) - Use the global resourcePanel
        JPanel currentScaleResourcePanel = new JPanel(new GridLayout(2, 1)); // Two parts
        currentScaleResourcePanel.setBackground(Color.WHITE);
        currentScaleResourcePanel.setBorder(BorderFactory.createTitledBorder("资源面板"));

        JPanel villagePanel = new JPanel();
        villagePanel.setBackground(Color.WHITE);
        villagePanel.setBorder(BorderFactory.createTitledBorder("村落"));
        currentScaleResourcePanel.add(villagePanel);

        JPanel inventoryPanel = new JPanel(); // This will be the general inventory
        inventoryPanel.setBackground(Color.WHITE);
        inventoryPanel.setBorder(BorderFactory.createTitledBorder("仓库"));
        currentScaleResourcePanel.add(inventoryPanel);

        currentScalePanel.add(currentScaleResourcePanel, BorderLayout.EAST);

        mainContentPanel.add(currentScalePanel, "CurrentScale");
    }

    private void setupLongJourneyScene() {
        JPanel longJourneyPanel = new JPanel();
        longJourneyPanel.setBackground(Color.WHITE);
        longJourneyPanel.add(new JLabel("漫漫尘途 敬请期待."));
        mainContentPanel.add(longJourneyPanel, "LongJourney");
    }

    private void addMessage(String message) {
        JLabel messageLabel = new JLabel(message);
        messageLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        messagePanel.add(messageLabel, 0); // Add to the top
        messagePanel.revalidate();
        messagePanel.repaint();

        // Remove message after 15 seconds
        Timer timer = new Timer(75000, e -> {
            messagePanel.remove(messageLabel);
            messagePanel.revalidate();
            messagePanel.repaint();
        });
        timer.setRepeats(false);
        timer.start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(FireRoomGame::new);
    }
}