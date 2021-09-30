# PersoPassGen
With this program you can open a door with your german Personalausweis.  
We use a Raspberry Pi and its GPIO-Pin that switches over a relay the dooropener.    

Version: 0.1 
Author: buergerservice.org e.V. <KeePerso@buergerservice.org>  


![Screenshot1](screenshot1.jpg)

-------------
requirements:
-------------
Raspberry Pi with Raspberry Pi OS bullseye (atm only in testversion avaiable but will be released soon)  
program workflowClient for the admin   
AusweisApp2  
cardreader or smartphone with AusweisApp2 on the same WLAN (connect in AusweisApp2-GUI)  
for online identification ready Personalausweis - you can test it in AusweisApp2 with "Meine Daten einsehen"  
internetaccess  
1 relay  
1 12V-powersupply  
1 dooropener  
Dupont jumper cables   


-------------
installation:
-------------
copy to a directory persodoor   
first start AusweisApp2   
attach cardreader or smartphone with AusweisApp2 on the same WLAN (connect in AusweisApp2-GUI)  
start workflowClient with your PIN (in the same directory where the persodoor-program is installed)    
```
./workflowClient 123456
```
you will be asked if you want to store your PIN. The file will be overwritten. This works only for one person, only this person can open without PIN-input.   
all others should enter n at this point and activate the PIN-input in AusweisApp2 in their smartphone.    
then you will be asked if you want to store your hashkey. it will be attached to the file and other hashkeys if exist.
after that you see the certificate and your data that are read from your Personalausweis.   
now there should be a file PIN.txt and a file hashkey.txt (you see with ls)   
you can start persodoor

connection:
![Connection](connection.jpg)


-----------
how to use:
-----------
start AusweisApp2  
start persodoor from shell 
```
./persodoor
```
it logs to persodoor.log in the same directory  


----------------------------
known problems and questions
----------------------------

is my PIN safe?  
	- you can use a cardreader with keypad or smartphone with activated PIN-input, then the plugin cant see the PIN.  

what data of my Personalausweis is used for the key?  
	like you can see in the source used are this data  
	FamilyNames (or BirthName if set)  
	GivenNames  
	DateOfBirth  
	PlaceOfBirth  
 



---------------
versionhistory:
---------------
0.1 start  


-----
build
-----
use the build-scripts ./build.sh  
