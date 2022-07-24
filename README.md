# Morse Code Locker
<!-----

Yay, no errors, warnings, or alerts!

Conversion time: 0.652 seconds.


Using this Markdown file:

1. Paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β33
* Sun Jul 24 2022 08:28:29 GMT-0700 (PDT)
* Source doc: Untitled document
* Tables are currently converted to HTML tables.
----->



**<span style="text-decoration:underline;">What is Morse Code?-</span>**

Morse Code is a code for alphabets, where alphabets are represented as combination of “dits and dahs” or combination of “.” And “-“. The Morse code combination for alphabets is as follows-


<table>
  <tr>
   <td>Letter 
   </td>
   <td>Morse code
   </td>
  </tr>
  <tr>
   <td>A
   </td>
   <td>.-
   </td>
  </tr>
  <tr>
   <td>B
   </td>
   <td>-..
   </td>
  </tr>
  <tr>
   <td>C
   </td>
   <td>-.-.
   </td>
  </tr>
  <tr>
   <td>D
   </td>
   <td>-..
   </td>
  </tr>
  <tr>
   <td>E
   </td>
   <td>.
   </td>
  </tr>
  <tr>
   <td>F
   </td>
   <td>..-.
   </td>
  </tr>
  <tr>
   <td>G
   </td>
   <td>--.
   </td>
  </tr>
  <tr>
   <td>H
   </td>
   <td>….
   </td>
  </tr>
  <tr>
   <td>I
   </td>
   <td>..
   </td>
  </tr>
  <tr>
   <td>J
   </td>
   <td>.---
   </td>
  </tr>
  <tr>
   <td>K
   </td>
   <td>-.-
   </td>
  </tr>
  <tr>
   <td>L
   </td>
   <td>.-..
   </td>
  </tr>
  <tr>
   <td>M
   </td>
   <td>--
   </td>
  </tr>
  <tr>
   <td>N
   </td>
   <td>-.
   </td>
  </tr>
  <tr>
   <td>O
   </td>
   <td>---
   </td>
  </tr>
  <tr>
   <td>P
   </td>
   <td>.--.
   </td>
  </tr>
  <tr>
   <td>R
   </td>
   <td>.-.
   </td>
  </tr>
  <tr>
   <td>S
   </td>
   <td>…
   </td>
  </tr>
  <tr>
   <td>T
   </td>
   <td>–
   </td>
  </tr>
  <tr>
   <td>U
   </td>
   <td>..-
   </td>
  </tr>
  <tr>
   <td>V
   </td>
   <td>…-
   </td>
  </tr>
  <tr>
   <td>W
   </td>
   <td>.--
   </td>
  </tr>
  <tr>
   <td>X
   </td>
   <td>-..-
   </td>
  </tr>
  <tr>
   <td>Y
   </td>
   <td>-.--
   </td>
  </tr>
  <tr>
   <td>Z
   </td>
   <td>--..
   </td>
  </tr>
</table>


In this system the password for the locker is to be entered terms of Morse code. 

**<span style="text-decoration:underline;">Parts Used:</span>**



* Arduino Uno
* Push buttons
* Led
* 330 ohm resistor
* Servo motor
* Jumper Wires
* Bread board

**<span style="text-decoration:underline;">Description for buttons used:</span>**



* Dot Button: It is the button used to enter a “.” Of Morse code
* Dash Button: It is the button used to enter a “-“ Of the Morse code
* Letter Button: It is the button to generate the letter from the Morse code entered, must be pressed before starting the next letter and before enter button.
* Enter Button: It is used to open the locker when the correct password is entered. It is also used to clear the Morse code is wrong password is entered.
* Reset Button: It is used to start the reset mode to reset the password when the locker is open. It needs to pressed again to save the new password.

**<span style="text-decoration:underline;">Working:</span>**

The Morse code uses “.” And “-“ for which the dot button and the dash button are used . Once the combination for a letter is entered using them then by pressing the letter button the letter for the code is generated. Once all the letters are generated and the word for the password is formed then by pressing the enter button the locker will open when we again press the enter button the locker will close. 

To reset the password, the reset button needs to pressed when the locker is opened, the led will glow up and indicate that reset mode is activated. Then using the dot, dash and letter button enter the new password and again press the reset button to save the password, the led will turn low when this happens. The password is saved in the EEPROM so it will remain same even after the system is shut down. 

Please Check the video for further reference!

<p style="text-align: right">
By Indranil Sen</p>

