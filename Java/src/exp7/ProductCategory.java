package src.exp7;

public enum ProductCategory {
    FOOD("FD", 365),
    ELECTRONICS("EL", -1),
    CLOTHING("CL", -1);

    private final String categoryCode;
    private final int averageShelfLifeDays;

    ProductCategory(String categoryCode, int averageShelfLifeDays) {
        this.categoryCode = categoryCode;
        this.averageShelfLifeDays = averageShelfLifeDays;
    }

    public String getCategoryCode() {
        return categoryCode;
    }

    public int getAverageShelfLifeDays() {
        return averageShelfLifeDays;
    }
}