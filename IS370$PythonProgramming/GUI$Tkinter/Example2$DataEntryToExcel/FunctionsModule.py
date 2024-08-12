import openpyxl
import os

def print_data(firstname, lastname, title, age, nationality, numcourses, numsemesters, registration_check):

    print("First name: ", firstname, " Last name: ", lastname)
    print("Title: ", title, " Age: ", age, "Nationality: ", nationality)
    print("Courses: ", numcourses, " Semesters: ", numsemesters)
    print("Registration status: ", registration_check)
    print("--------------------------------------------")


def enter_data(firstname, lastname, title, age, nationality, numcourses, numsemesters, registration_check):

    filepath = "./data.xlsx"
    if not os.path.exists(filepath):
        workbook = openpyxl.Workbook()
        sheet = workbook.active
        heading = ["First name", "Last name", "Title", "Age", "Courses", "Semesters", "Registration status"]
        sheet.append(heading)
        workbook.save(filepath)

    workbook = openpyxl.load_workbook(filepath)
    sheet = workbook.active
    sheet.append([firstname, lastname, title, age, nationality, numcourses, numsemesters, registration_check])
    workbook.save(filepath)





    # print("First name: ", firstname, " Last name: ", lastname)
    # print("Title: ", title, " Age: ", age, "Nationality: ", nationality)
    # print("Courses: ", numcourses, " Semesters: ", numsemesters)
    # print("Registration status: ", registration_check)
    # print("--------------------------------------------")