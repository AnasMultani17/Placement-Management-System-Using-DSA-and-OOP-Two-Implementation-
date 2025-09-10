package objs;

import login.CompanySignup;

public class Company extends CompanySignup {
    private String name;
    private String location;
    private String type;
    private int minCtc;
    private int maxCtc;

    public Company(String username, String password, String name, String location, String type, int minCtc, int maxCtc) {
        super(username, password);
        this.name = name;
        this.location = location;
        this.type = type;
        this.minCtc = minCtc;
        this.maxCtc = maxCtc;
    }
    public String getName() {
        return name;
    }

    public String getLocation() {
        return location;
    }

    public String getType() {
        return type;
    }

    public int getMinCtc() {
        return minCtc;
    }

    public int getMaxCtc() {
        return maxCtc;
    }

}
