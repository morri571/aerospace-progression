# DISCLAIMER
This project was intended to learn web development and automation in node.js. 
This script is in compliance with this website’s “robots.txt” file. Using 
node.js web scraping in another context may not be permitted according to 
different websites. I do not advise scraping against websites terms and I do 
not take responsibility for others doing so. 

# Ticket monitoring script overview
This script was created to attempt to purchase tickets at a very high in 
demand club during a study abroad experience and learn node.js. Tickets 
would sell out in seconds, so using my previous selenium experience I 
used node.js for faster execution.

## user guide
The script can be run using the terminal and typing “node main.js.” Once 
this is running, terminal will display the url of the web app which can be 
navigated to with any browser. The web app features many parameters 
necessary to monitor and purchase the ticket. Once the parameters are 
filled in, simply pressing the start button will open a browser and
monitor the url. Once the HTML element is found, the script will refresh 
and attempt to purchase until successful or until the script is stopped.

## future plans
There is currently an issue when the backend element loads, the script does 
not catch it and it continues refreshing as if it is still monitoring. The 
interesting part about this issue is that stopping and starting the script 
makes it work fine, after the backend html of the ticket is loaded. 
Further testing will be required to fix and diagnose this issue.
