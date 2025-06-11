package src.exp7;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Random;

public class Product {
    private String sku;
    private ProductCategory category;
    private LocalDate creationDate;
    private LocalDate expiryDate;
    private double price;

    public Product(ProductCategory category) {
        this.category = category;
        this.creationDate = LocalDate.now();
        this.sku = generateSku(category, creationDate);
        this.expiryDate = calculateExpiryDate(category, creationDate);
        this.price = generatePrice(category);
    }

    private String generateSku(ProductCategory category, LocalDate creationDate) {
        String categoryCode = category.getCategoryCode();
        String datePart = creationDate.format(DateTimeFormatter.ofPattern("yyyyMM"));
        Random random = new Random();
        String randomPart = String.format("%05d", random.nextInt(100000));
        return String.format("%s-%s-%s", categoryCode, datePart, randomPart);
    }

    private LocalDate calculateExpiryDate(ProductCategory category, LocalDate creationDate) {
        int shelfLife = category.getAverageShelfLifeDays();
        if (shelfLife == -1) {
            return null;
        } else {
            return creationDate.plusDays(shelfLife);
        }
    }

    private double generatePrice(ProductCategory category) {
        Random random = new Random();
        double minPrice;
        double maxPrice;

        switch (category) {
            case FOOD:
                minPrice = 10.0;
                maxPrice = 100.0;
                break;
            case ELECTRONICS:
                minPrice = 500.0;
                maxPrice = 5000.0;
                break;
            case CLOTHING:
                minPrice = 50.0;
                maxPrice = 500.0;
                break;
            default:
                minPrice = 1.0;
                maxPrice = 1000.0;
                break;
        }
        return minPrice + (maxPrice - minPrice) * random.nextDouble();
    }

    @Override
    public String toString() {
        String expiryInfo = (expiryDate == null) ? "N/A" : expiryDate.toString();
        return "Product Information:\n" +
               "  SKU: " + sku + "\n" +
               "  Category: " + category + "\n" +
               "  Creation Date: " + creationDate + "\n" +
               "  Expiry Date: " + expiryInfo + "\n" +
               "  Price: " + String.format("%.2f", price);
    }

    // Getters (optional, but good practice)
    public String getSku() {
        return sku;
    }

    public ProductCategory getCategory() {
        return category;
    }

    public LocalDate getCreationDate() {
        return creationDate;
    }

    public LocalDate getExpiryDate() {
        return expiryDate;
    }

    public double getPrice() {
        return price;
    }
}