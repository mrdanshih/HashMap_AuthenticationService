# HashMap
This project is a C++ HashMap data structure implementation, along with a usage of the implemented HashMap in a simple authentication service console program.

It avoids all usages of C++ Standard Library containers (e.g. vector, list) and uses Node structs and low-level arrays in the implementation of the HashMap data structure. The HashMap is implemented using the bucket concept (an array) where keys are hashed and their values inserted into. Each bucket index points to a Node entry (when it's not empty), which in turn can point to more node-entries. Thus, each bucket index points to a singly-linked list of items that have the same hash value.

The HashMap.cpp/HashMap.hpp files are the source/header files for the HashMap implementation. The HashMap is used in the Service.cpp/Service.hpp class, which serves as a basic authentication service for usernames as passwords. The main.cpp file creates an instance of the Authentication service and runs it - the Authentication service is a console program that accepts commands without prompting and utilizes the HashMap as a backend for storing information.

## In the authentication service, the following commands are available.

<p>Every command appears on a line by itself, and the output of every command should appear on a line by itself.</p>

<table class="normal">
  <tr class="top">
    <td>Command Format</td>
    <td>Description</td>
  </tr>
  <tr>
    <td><b>CREATE&nbsp;<i>username</i>&nbsp;<i>password</i></b></td>
    <td>Create a new username/password combination and stores it in the program's collection.  If successful, the output is <b>CREATED</b>.  If the username is already stored in the collection, no change is made and the output is <b>EXISTS</b>.  (One key consequence is that the same username cannot appear in the collection more than once.)</td>
  </tr>
  <tr>
    <td><b>LOGIN&nbsp;<i>username</i>&nbsp;<i>password</i></b></td>
    <td>Checks a username/password combination to see if it is valid.  A username/password combination is valid if it exists (i.e., the username is in the collection <i>and</i> is associated with the password), in which case the output is <b>SUCCEEDED</b>.  If the username/password combination does not exist, the output is <b>FAILED</b>.  (Note that there is no distinction between the username not existing and the password being incorrect; either situation would output <b>FAILED</b>.  This is fairly standard &mdash; and wise &mdash; behavior for an authentication service; if you return different error messages when a username does not exist and when a password is wrong, you're letting an attacker know a useful piece of information: whether a username is valid.)</td>
  </tr>
  <tr>
    <td><b>REMOVE&nbsp;<i>username</i></b></td>
    <td>Removes the username/password combination with the given username, if it exists.  If so, the output is <b>REMOVED</b>.  If no username/password combination with the given username exists, the output is <b>NONEXISTENT</b>.</td>
  </tr>
  <tr>
    <td><b>CLEAR</b></td>
    <td>Removes <i>all</i> username/password combinations from the service.  The output is <b>CLEARED</b> (even if there were no username/password combinations at the time).</td>
  </tr>
  <tr>
    <td><b>QUIT</b></td>
    <td>The output of this command is <b>GOODBYE</b>.  Once this command has been processed, the program should end.</td>
  </tr>
</table>


## Also, the following "debug" commands are supported, which allow for more detailed information regarding the HashMap in the backend of the Authentication service

<table class="normal">
  <tr class="top">
    <td>Command Format</td>
    <td>Description</td>
  </tr>
  <tr>
    <td><b>DEBUG&nbsp;ON</b></td>
    <td>Makes the other debug commands available.  Before issuing this command, all other debug commands (except <b>DEBUG ON</b> and <b>DEBUG OFF</b>) should be considered invalid.  If debug commands were not already on, the output is <b>ON NOW</b>; if they were, the output is <b>ON ALREADY</b>.  While in debug mode, all of the user-facing commands remain available.</td>
  </tr>
  <tr>
    <td><b>DEBUG&nbsp;OFF</b></td>
    <td>Makes the other debug commands unavailable.  After issuing this command, all debug commands should be considered invalid except for <b>DEBUG ON</b> and <b>DEBUG OFF</b>.  If debug commands were already on, the output is <b>OFF NOW</b>; if they weren't already on, the output is <b>OFF ALREADY</b>.</td>
  </tr>
  <tr>
    <td><b>LOGIN&nbsp;COUNT</b></td>
    <td>The output is the number of username/password combinations currently being stored.</td>
  </tr>
  <tr>
    <td><b>BUCKET&nbsp;COUNT</b></td>
    <td>The output is the number of buckets in the hash table at present.</td>
  </tr>
  <tr>
    <td><b>LOAD&nbsp;FACTOR</b></td>
    <td>The output is the load factor of the hash table at present.  There is no specific requirement here about the number of decimal places to include in the output; whatever emerges by default if you write a <b>double</b> to <b>std::cout</b> is best.</td>
  </tr>
  <tr>
    <td><b>MAX&nbsp;BUCKET&nbsp;SIZE</b></td>
    <td>The output is the length of the largest bucket (i.e., the one whose linked list contains the largest number of elements) in the hash table.</td>
  </tr>
</table>
