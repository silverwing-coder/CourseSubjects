<h3> 4.20 </h3>

```java
// read double value from terminal
double x = scnr.nextDouble();

// x to the power power z
Math.pow(z, y);

// x to the power of (y to the power of z)
Math.pow(x, Math.pow(y, z));

// absolute value of y
Math.abs(y);

//square root of (xy to the power of z)
Math.sqrt(Math.pow(x*y, z));

```

<h3> 4.21 </h3>

```java
// read long value from terminal
long phoneNumber = scnr.nextLong();

// get the area code: 800
long areaCode = phoneNumber / 10000000;

// get the next three digits
long nextThree = (phoneNumber % ?????????) / 10000;

// get the last four digits
long nextFour = (phoneNumber % ?????????) % ?????;


```

<h3> 4.22 </h3>

```java
// integer product
int intProduct = (num1 * num2 * num3 * num4);

// integer average
int intAverage = (num1 + num2 + num3 + num4) / 4;

// double product
double doubleProduct = (num1 * num2 * num3 * (????)num4);

// double average
double doubleAverage = (num1 + num2 + num3 + (????)num4) / 4;

// print double value format
System.out.printf("%.3f %.3f\n", doubleProduct, doubleAverage);

```

<h3> 4.23 </h3>

```java
// read the number of people attending
int numPeople  = scnr.nextInt();

// required number of slices: each person eats two slices
int numSlices = numPeople * 2;

// required number of pizzas: each pizza has 12 slices
// if additional slices required, order one more pizza
if((numSlices % 12) != 0){
    numPizzas = numSlices / 12 + 1;
} else {
    numPizzas = numSlices / 12;
}

// pizza price: $ 14.95 each
double cost = numPizzas * 14.95

```

<h3> 4.24 </h3>

```java
// read radius and height
double radius = scnr.nextDouble();
double height = scnr.nextDouble();

// calculate volume: refer to the formula given
double volume = Math.PI * Math.pow(radius, 2) *  height

// calculate area: refer to the formula given
double area = 2* ???? * Math.pow(radius, 2) + 2 * ???? * radius * height

```

<h3> 4.25 </h3>

```java
// read width, height, and cost for a can of paint
double width = scnr.nextDouble();
double height = scnr.nextDouble();
double canCost = scnr.nextDouble();

// calculate wall area
double wallArea = width * height

// calculate paint needed in gallons: one gallon can cover 35o sq-ft
double paintNeeded = wallArea / ???;

// calculate number of paint cans needed: one gallon can cover 35o sq-ft
int cansNeeded;
if(wallArea % 350 > 0){
    cansNeeded = (int) (wallArea / ???) + 1;
}else {
    cansNeeded = (int) (wallArea / ???);
}

// calculate cost:
double paintCost = canCost * (double)cansNeeded

// calculate tax:
double tax = canCost * (double)cansNeeded * 0.07;

```

<h3> 4.26 </h3>

```java
// read first name, last name, and the year born
String fname = scnr.next();
String lname = scnr.next();
int year = scnr.nextInt();

// get the substring of last name based on the length of last name
// if it is less than 5, get the whole string
// if it is more than 5, get only 5 characters
String loginName;
if(lname.length() >= 5){
    loginName = lname.substring(0, 5) + fname.charAt(0);
}else {
    loginName = lname.substring(0, ?) + fname.charAt(0);
}

// last two digit of the year born
int twoDigits = year % 100;

```

<h3> 4.27 </h3>

```java
// read the string from terminal and remove white spaces
String text = scnr.nextLine().trim();

// calculate the start point of substring to get 5 letters
int startIndex = (text.length() - 5) / 2;

// get the middle 5 characters (substring)
String subStr = text.substring(startIndex, startIndex + 5);

```

<h3> 4.28 </h3>
Refer to the link below.

[Regular Expression](https://www.w3schools.com/java/java_regex.asp)

```java
// remove all non-alphabet characters with removeAll() and regular expressions
inputText.removeAll("[^a-zA-Z]+");

```

<h3> 4.29 </h3>

```java
// read string data from terminal
String dateString = sc.nextLine();

// get year, month, day string
String yearString = dateString.substring(0, ?);
String monthString = dateString.substring(5, dateString.indexOf('-', 5));
String dayString = dateString.substring(dateString.indexOf('-', 5) + 1, ?);

// convert string to integer
int year = Integer.parseInt(????);
int month = Integer.parseInt(????);
int day = Integer.parseInt(????);

// convert int data to LocalDate data: must have int type data to use "of" method
LocalDate date = LocalDate.of(year, month, day);

// set the DateTimeFormater format and create an object
// Day-of-Week, Month Day, Year : "EEEE, MMMM d, yyyy"
DateTimeFormatter myFormat = DateTimeFormatter.ofPattern("EEEE, MMMM d, yyyy");

// print LocalDate data following the created format
System.out.println(date.format(????));

```
