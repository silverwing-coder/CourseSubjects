import tkinter
from tkinter import ttk
from tkinter import messagebox
import FunctionsModule as fm

def enter_data():
    if_accepted = accept_var.get()
    if(if_accepted == "Accepted"):

        ''' user info '''
        firstname = first_name_entry.get()
        lastname = last_name_entry.get()
        if firstname and lastname:
            title = title_combo.get()
            age = age_spinbox.get()
            nationality = nationality_combobox.get()

            ''' course info '''
            numcourses = numcourses_spinbox.get()
            numsemesters = numsemesters_spinbox.get()
            registration_check = registration_status_var.get()
            ''' terms info '''
            # terms = terms_check.getboolean()
            # print(terms)

            fm.enter_data(firstname, lastname, title, age, nationality, numcourses,
                          numsemesters, registration_check)
        else:
            tkinter.messagebox.showwarning(title="Error", message="First name and last name are required")
    else:
        tkinter.messagebox.showwarning(title="Error", message="You have not accepted the terms and conditions")


window = tkinter.Tk()

window.title("Data Entry Form")

''' (1) create widget, (2) invoke pack() function'''
frame = tkinter.Frame(window)
frame.pack()


''' user information (label frame) '''
user_info_frame = tkinter.LabelFrame(frame, text="User Information")
user_info_frame.grid(row=0, column=0, padx=20, pady=10)

first_name_label = tkinter.Label(user_info_frame, text="First name")
first_name_label.grid(row=0, column=0)
last_name_label = tkinter.Label(user_info_frame, text="Last name")
last_name_label.grid(row=0, column=1)

first_name_entry = tkinter.Entry(user_info_frame)
last_name_entry = tkinter.Entry(user_info_frame)
first_name_entry.grid(row=1, column=0)
last_name_entry.grid(row=1, column=1)

title_label = tkinter.Label(user_info_frame, text="Title")
title_combo = ttk.Combobox(user_info_frame, values=["Mr.", "Ms.", "Dr."])
title_label.grid(row=0, column=2)
title_combo.grid(row=1, column=2)

age_label = tkinter.Label(user_info_frame, text="Age")
age_spinbox = tkinter.Spinbox(user_info_frame, from_=18, to=110)
age_label.grid(row=2, column=0)
age_spinbox.grid(row=3, column=0)

nationality_label = tkinter.Label(user_info_frame, text="Nationality")
nationality_combobox = ttk.Combobox(user_info_frame, values=["Africa", "Antarctica", "Asia", "Europe", "North America", "South America"])
nationality_label.grid(row=2, column=1)
nationality_combobox.grid(row=3, column=1)

for widget in user_info_frame.winfo_children():
    widget.grid_configure(padx=10, pady=5)

''' courses (label frame) '''
courses_frame = tkinter.LabelFrame(frame)
courses_frame.grid(row=1, column=0, sticky="news", padx=20, pady=10)

registration_status_var = tkinter.StringVar(value="Not registered")
registered_label = tkinter.Label(courses_frame, text="Registration Status")
registered_check = tkinter.Checkbutton(courses_frame, text="Currently Registered",
                                       variable=registration_status_var, onvalue="Registered", offvalue="Not registered")
registered_label.grid(row=0, column=0)
registered_check.grid(row=1, column=0)

numcourses_label = tkinter.Label(courses_frame, text="# Completed Courses")
numcourses_spinbox = tkinter.Spinbox(courses_frame, from_=0, to='infinity')
numcourses_label.grid(row=0, column=1)
numcourses_spinbox.grid(row=1, column=1)

numsemesters_label = tkinter.Label(courses_frame, text="# Semester")
numsemesters_spinbox = tkinter.Spinbox(courses_frame, from_=0, to='infinity')
numsemesters_label.grid(row=0, column=2)
numsemesters_spinbox.grid(row=1, column=2)

for widget in courses_frame.winfo_children():
    widget.grid_configure(padx=10, pady=5)

''' accept terms (label frame) '''
terms_frame = tkinter.LabelFrame(frame, text="Terms & Conditions")
terms_frame.grid(row=2, column=0, sticky="news", padx=20, pady=10)

accept_var = tkinter.StringVar(value="Not accepted")
terms_check = tkinter.Checkbutton(terms_frame, text="I accept the terms and conditions",
                                  variable=accept_var, onvalue="Accepted", offvalue="Not accepted")
terms_check.grid(row=0, column=0, padx=10, pady=5)

''' butons '''
# enter_data = fm.enter_data(first_name_entry)
button = tkinter.Button(frame, text="Enter data", command=enter_data)
button.grid(row=3, column=0, sticky="news", padx=20, pady=20)


window.mainloop()