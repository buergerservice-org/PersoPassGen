
PersoPassGen

Generates a Password from german Personalausweis-data with a leading uppercase and a specialsign

Version: 0.1
Author: buergerservice.org e.V. <KeePerso@buergerservice.org>


-------------
requirements:
-------------
platform independent cause cmake/qt can build Linux and Windows
AusweisApp2 (installed for all users)
cardreader (maybe you can use a new Android Handy as cardreader - connect in AusweisApp2)
for online identification ready Personalausweis - you can test it in AusweisApp2 with "Meine Daten einsehen"
internetaccess


-------------
installation:
-------------
Microsoft wrote in point 6 that its possible to copy the crt-dlls with an release-app: 
https://devblogs.microsoft.com/cppblog/introducing-the-universal-crt/


-----------
how to use:
-----------



----------------------------
known problems and questions
----------------------------


is my PIN safe?
	- the PIN is only sent to AusweisApp2 and not stored. you can use a cardreader with keypad, then the plugin cant see the PIN.

what data of my Personalausweis is used for the key?
	like you can see in the source used are this data
	FamilyNames
	GivenNames
	DateOfBirth
	PlaceOfBirth



---------------
versionhistory:
---------------
0.1 start pilotversion


-----
build
-----
source was build with Visual Studio 2019
with cmake and qt
and our own workflowLibrary/workflowLibraryLinux


-------
license
-------
/*
  Personalausweis Credential Provider for german Personalausweis
  Copyright (C) 2021 buergerservice.org e.V. <KeePerso@buergerservice.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
