<h3>Midterm Exam #1, Question 38</h3>
<h4> Reservation Class </h4>

```java
public class Reservation {

	private String customerName;
	private String driveLicenseNumber;
	private String licensePlateNumber;
	private int numberOfDays;
	private int numberOfPeople;

	public Reservation(String customerName, String driveLicenseNumber, String licensePlateNumber,
			int numberOfDays, int numberOfPeople) {
		this.customerName = customerName;
		this.driveLicenseNumber = driveLicenseNumber;
		this.licensePlateNumber = licensePlateNumber;
		this.numberOfPeople = numberOfPeople;
		this.numberOfDays = numberOfDays;
	}

	public int getNumberOfPeople() {
		return numberOfPeople;
	}

	public void setNumberOfPeople(int numberOfPeople) {
		this.numberOfPeople = numberOfPeople;
	}

	public String getCustomerName() {
		return customerName;
	}

	public String getDriveLicenseNumber() {
		return driveLicenseNumber;
	}

	public String getLicensePlageNumber() {
		return licensePlateNumber;
	}

	public int getNumberOfDays() {
		return numberOfDays;
	}
}

```

<h4> Receipt Class </h4>

```java
import java.util.Scanner;

public class Receit {

	private Reservation reservation;
	private final int SEDAN_FARE = 10;
	private final int VAN_FARE = 12;
	private final int RV_FARE = 20;

	public Receit(Reservation reservation) {
		this.reservation = reservation;
	}

	public int getTotalFare() {
		int totalFare = 0;

		Scanner scnr = new Scanner(System.in);
		System.out.println("Enter vehicle type: 1. Sedan, 2: Van, 3. RV");
		int vehicleType = scnr.nextInt();
		System.out.println("Enter number of People: ");
		int numOfPeople = scnr.nextInt();

		if(this.reservation.getNumberOfPeople() != numOfPeople) {
			this.reservation.setNumberOfPeople(numOfPeople);
		}

		if(vehicleType == 1) {
			totalFare = reservation.getNumberOfDays() * ( SEDAN_FARE + numOfPeople);
		} else if(vehicleType == 2) {
			totalFare = reservation.getNumberOfDays() * ( VAN_FARE + numOfPeople);
		} else if(vehicleType == 3) {
			totalFare = reservation.getNumberOfDays() * ( RV_FARE + numOfPeople);
		} else {
			totalFare = -1;
		}
		return totalFare;
	}

	public void printReceipt() {

		if(this.getTotalFare() > 0) {

			System.out.println("Welcome to CIS 112 Park");
			System.out.println("-------------------------------------");
			System.out.println("Customer Name: " + reservation.getCustomerName());
			System.out.println("Driver License: " + reservation.getDriveLicenseNumber());
			System.out.println("License Plate: " + reservation.getLicensePlageNumber());
			System.out.println("Number of Days: " + reservation.getNumberOfDays());
			System.out.println("Number of People: " + reservation.getNumberOfPeople());
			System.out.println();
			System.out.println("Total Fare: " + this.getTotalFare());
			System.out.println("Enjoy your journey!");
		} else {
			System.out.println("INPUT ERROR");
		}
	}
}

```
