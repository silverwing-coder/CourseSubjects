<h6>ver. Dec-2023</h6>
<h3> Introduction to "JavaFX"</h3>

<br/>:point_right: [Back to README Page](./README.md) </li>

---

<u><h4>Lab Environment Setup </h4></u>

<h5>1. JavaFX on Eclipse </h5>

<ol> 
<li>Download and extract JavaFX SDK from </li>

:point_right: [https://openjfx.io/](https://openjfx.io/) --> " must locate where the SDK packages are extracted "

<br/><li>Install JavaFX extensions on Eclipse </li>

-   Help --> Eclipse Marketplace --> Search "fx" --> e(fx)clipse install --> restart Eclipse

<br/><li>Create user library</li>

-   Window --> Preferences --> Java --> Build Path --> User Libraries --> New --> "JavaFX21" --> Add External JARs --> Go to JavaFX SDK files are extracted --> lib --> Select all executable JAR files
    --> Apply and Close

<br/><li>Create JavaFX project</li>

-   File --> New --> Project --> JavaFX --> JavaFX Project --> "Project-Name" --> Next --> Libraries --> Modulepath --> Add Library --> "User Library --> "JavaFX21" --> Fihish

<br/><li>Configure build path</li>

-   Select JavaFX project --> Build Path --> Configure Build Path --> "JavaFX21" under <u><b>Modulepath</b></u> --> Apply and Close
<!-- -   Remove "JavaFX21" from Classpath and add "JavaFX21" to ModulePath
-   (Optional) Delete module-info.java file -->

<br/><li>Add VM arguments</li>

-   Go to [Starting with JavaFX on JavaFX Documentation](https://openjfx.io/openjfx-docs/)

-   JavaFX and Eclipse --> Non Modular from IDE --> Copy arguments --> Go to JavaFX project --> Run As --> Run Configurations --> Arguments --> Paste in in VM Arguments

</ol><br>

<h5>2. SceneBuilder on Eclipse </h5>
<ol>

<li>Download and install Scene Builder </li>

-   Go to [https://gluonhq.com/products/scene-builder/](https://gluonhq.com/products/scene-builder/), download install following the OS

<br/><li>Create a new FXML document </li>

-   Select package folder --> New --> Other --> JavaFX --> New FXML Document --> Next --> "you-name-it: MainFXA" --> Finish
-   If you have problem for creating a new FXML document,
    -   Help --> Install New Software --> Add --> "you-name-it: e(fx)clipse" && <em>"http://download.eclipse.org/efxclipse/updates-released/3.9.0/site"</em> --> Add --> Install e(fx)clipse packages
    -   Help --> Check for Updates

<br/><li>Link to SceneBuilder executable file </li>

-   Window --> Preferences --> JavaFX --> SceneBuilder executable --> Goto SceneBuilder executable file --> Apply and Close

<br/><li>Open the FXML on SceneBuilder </li>

-   Select FXML file --> Open with SceneBuilder

</ol><br>

<br/><u><h4>Tutoroals / Instructions </h4></u>

<ol>

<li>Tutorial by Bro Code: </li>

[https://www.youtube.com/watch?v=9XJicRt_FaI](https://www.youtube.com/watch?v=9XJicRt_FaI)

</ol><br>
