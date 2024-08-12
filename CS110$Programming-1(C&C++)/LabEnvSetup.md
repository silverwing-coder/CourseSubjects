<h6>ver. Dec-2022</h6>
<h3>C & C++ Programming Lab Environment Setup </h3>
<h5><i> Prof. Sangmork "SAM" Park (Col(R). ROKAF)</i></h5>
<h5><u><i>School of Arts and Science, Carolina University</i></u></h5>

---

<h3>Windows System</h3>

<h4>Option-1: Visual Studio Code & MinGW</h4>

1. Download install Visual Studio Code

    - Install C/C++ Extension pack

2. Download and install MinGW (GNU for Windows) compiler

    - **From Googles: "MinGW download"**
    - Select all basic setup options <u> including g++ compiler </u>

3. Setup PATH variable: Settings -> System -> About -> Advanced system settings -> Advanced -> Environment Variables -> Path -> Edit -> New -> Enter the path to the folder containing gcc

    ```sh
    # use g++ compiler instead of gcc: Only g++ compiler can compile both .cpp and .c files
    g++ --version

    ```

4. Setup Makefile Environment on PowerShell

    - Open PowerShell with **Admin privelege**

    ```sh
    # check chocolatey installed
    choco
    # install make
    choco install make
    # verify make version
    make --version

    ```

<h4>Option-2: Notepad++ or Atom & MinGW</h4>

1. Download install Notepad++ or Atom IDE

2. Setting up MinGW is the same as above

<h4>Option-3: CodeBlocks with MinGW</h4>

1. Download "codeblocks-x.xmingw-setup.exe" and install

---

<h3>Linux & MacOS System</h3>

1. Download an IDE you choose and install it

2. Use the default g++ compiler in the O.S.

---

<h3>References</h3>

-   C++ compilers (support) : https://en.cppreference.com/w/cpp/compiler_support
