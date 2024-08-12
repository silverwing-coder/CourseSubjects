<h3>Midterm Exam #2, Question 38</h3>
<h4> Student Class </h4>

```java

package MidTermTest2;

public class Student {
	private long IdNumber;
	private String fullName;
	private double accumulatedGPA;

	public Student(long IdNumber, String fullName, double accumulatedGPA) {
		super();
		this.IdNumber = IdNumber;
		this.fullName = fullName;
		this.accumulatedGPA = accumulatedGPA;
	}

	public long getIdNumber() {
		return IdNumber;
	}

	public String getFullName() {
		return fullName;
	}

	public double getAccumulatedGPA() {
		return accumulatedGPA;
	}
}
```

<br><h4> StudentBinaryReader class </h4>

```java

package MidTermTest2;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class StudentBinaryReader {

    private DataInputStream readData;

    public StudentBinaryReader(String fileName) throws IOException {
        readData = new DataInputStream (new FileInputStream(fileName));  // open the file
    }

    public Student readStudentInfo() throws IOException {
        // If zero bytes are available, the end of the file has been reached
        if (readData.available() == 0) {
            return null;
        }

        byte[] nameBuffer = new byte[20];

        // Read data directly from the binary file
        long studentNumber = readData.readLong();
        readData.read(nameBuffer);  // read the blank padded ASCII data into a buffer
        String studentName = new String(nameBuffer).trim();
        double gpa = readData.readDouble();

        Student student = new Student(studentNumber, studentName, gpa);
        return student;
    }

    public void close() throws IOException {
    	readData.close();
    }
}
```

<br><h4> StudentTextWriter class </h4>

```java

package MidTermTest2;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileOutputStream;

public class StudentTextWriter {
    private PrintWriter writeData;

    public StudentTextWriter(String fileName) throws IOException {
    	writeData = new PrintWriter(new FileOutputStream(fileName));  // open the file
    }

    public  void writeEmployee(Student student) throws IOException {
    	writeData.printf("%d, %s, %.2f\n", student.getIdNumber(), student.getFullName(), student.getAccumulatedGPA());
    }

    public void close() throws IOException {
    	writeData.close();
    }
}
```

<br><h4> ConvertDataFile class </h4>

```java
package MidTermTest2;

import java.io.IOException;

public class CovertDataFile {

	public static void main(String[] args) throws IOException {

		String inFile = args[0];
		String outFile = args[1];
		StudentBinaryReader sReader = new StudentBinaryReader(inFile);
		StudentTextWriter sWriter = new StudentTextWriter(outFile);

		// Add loop to read students one at a time, and write it to the output file
	    Student student = sReader.readStudentInfo();
	    while( student != null) {
	    	sWriter.writeEmployee(student);
	    	student = sReader.readStudentInfo();
	    }
	    // Close the input and output files
	    sReader.close();
	    sWriter.close();
	}
}
```
